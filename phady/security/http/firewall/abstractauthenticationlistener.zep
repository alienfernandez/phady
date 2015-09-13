/*
+------------------------------------------------------------------------+
| Phady Framework                                                        |
+------------------------------------------------------------------------+
| Copyright (c) 2015                                                     |
+------------------------------------------------------------------------+
| Phady Framework is a complement of Phalcon Framework                   |
|                                                                        |
+------------------------------------------------------------------------+
| Authors: Alien fernandez Fuentes <alienfernandez85@gmail.com>          |
+------------------------------------------------------------------------+
*/

namespace Phady\Security\Http\Firewall;

use Phady\Security\Http\Firewall\ListenerInterface;
use Phady\Security\Core\Authentication\Token\Storage\TokenStorageInterface;
use Phady\Security\Core\Authentication\AuthenticationManagerInterface;
use Phady\Security\Http\Authentication\AuthenticationSuccessHandlerInterface;
use Phady\Security\Http\Authentication\AuthenticationFailureHandlerInterface;
use Phalcon\Http\Response;
use Phalcon\Http\Request;
use Phady\Security\Core\Exception\AuthenticationException;
use Phady\Security\Core\Authentication\Token\UsernamePasswordToken;
use Phady\Security\Core\Authentication\Token\TokenInterface;
use Phady\Security\Core\Security;
use Phady\Security\Http\Event\InteractiveLoginEvent;
use Phady\Security\Http\SecurityEvents;
use Phady\Security\Core\Authentication\Token\AnonymousToken;

/**
  * @class Phady\Security\Http\Firewall\AbstractAuthenticationListener
  *
  * @author  Alien Fernández Fuentes <alienfernandez85@gmail.com>
  * @package Core
  * @copyright (c) 2015
  * @version 1.0.0
  */
abstract class AbstractAuthenticationListener extends \Phalcon\Di\Injectable implements ListenerInterface
{

   protected options;
   protected logger;
   protected authenticationManager;
   protected providerKey;
   protected httpUtils;

   private tokenStorage;
   private sessionStrategy;
   private dispatcher;
   private successHandler;
   private failureHandler;
   private rememberMeServices;

   /**
    * Constructor.
    *
    * @param TokenStorageInterface                  tokenStorage          A TokenStorageInterface instance
    * @param AuthenticationManagerInterface         authenticationManager An AuthenticationManagerInterface instance
    * @param HttpUtils                              httpUtils             An HttpUtilsInterface instance
    * @param string                                 providerKey
    * @param AuthenticationSuccessHandlerInterface  successHandler
    * @param AuthenticationFailureHandlerInterface  failureHandler
    * @param array                                  options               An array of options for the processing of a
    *                                                                      successful, or failed authentication attempt
    * @param LoggerInterface                        logger                A LoggerInterface instance
    * @param EventDispatcherInterface               dispatcher            An EventDispatcherInterface instance
    *
    * @throws \InvalidArgumentException
    */
   public function __construct(<TokenStorageInterface> tokenStorage, <AuthenticationManagerInterface> authenticationManager,
        providerKey, <AuthenticationSuccessHandlerInterface> successHandler, <AuthenticationFailureHandlerInterface> failureHandler,
        array options = [])
   {
       if (empty(providerKey)) {
           throw new \InvalidArgumentException("providerKey must not be empty.");
       }

       let this->tokenStorage = tokenStorage;
       let this->authenticationManager = authenticationManager;
       let this->providerKey = providerKey;
       let this->successHandler = successHandler;
       let this->failureHandler = failureHandler;
       let this->options = array_merge([
           "check_path" : "/login_check",
           "login_path" : "/login",
           "always_use_default_target_path" : false,
           "default_target_path" : "/",
           "target_path_parameter" : "_target_path",
           "use_referer" : false,
           "failure_path" : null,
           "failure_forward" : false,
           "require_previous_session" : true
       ], options);
       //let this->logger = logger;
       let this->dispatcher = this->getDI()->get("dispatcher");
       //let this->httpUtils = httpUtils;
   }

    /**
     * Sets the RememberMeServices implementation to use.
     *
     * @param RememberMeServicesInterface rememberMeServices
     */
    public function setRememberMeServices(rememberMeServices)
    {
        //let this->rememberMeServices = rememberMeServices;
    }

    /**
     * Sets the authenticationManager.
     *
     */
    public function setauthenticationManager(authenticationManager)
    {
        let this->authenticationManager = authenticationManager;
    }

    /**
     * Handles form based authentication.
     *
     *
     * @throws \RuntimeException
     * @throws SessionUnavailableException
     */
    final public function handle()
    {

        var request, returnValue, response, e;
        let request = this->getDI()->get("request");

        if (!this->requiresAuthentication(request)) {
            return;
        }

        if (!this->getDI()->has("session")) {
            throw new \RuntimeException("This authentication method requires a session.");
        }
        try {
            /*
            if (this->options["require_previous_session"] && !request->hasPreviousSession()) {
                throw new SessionUnavailableException("Your session has timed out, or you have disabled cookies.");
            }*/

            let returnValue = this->attemptAuthentication(request);

            if (null === returnValue) {
                return;
            }

            if (returnValue instanceof TokenInterface) {
                let response = this->onSuccess(request, returnValue);
            } elseif (returnValue instanceof Response) {
                let response = returnValue;
            } else {
                throw new \RuntimeException("attemptAuthentication() must either return a Response, an implementation of TokenInterface, or null.");
            }

        } catch AuthenticationException, e {
            let response = this->onFailure(request, e);
        }
    }


    /**
     * Whether this request requires authentication.
     *
     * The default implementation only processes requests to a specific path,
     * but a subclass could change this to only authenticate requests where a
     * certain parameters is present.
     *
     * @param Request request
     *
     * @return bool
     */
    protected function requiresAuthentication(<Request> request)
    {
        /*if ('/' !== substr(this->options["check_path"], 0, 1)) {
            try {
                // matching a request is more powerful than matching a URL path + context, so try that first
                if ($this->urlMatcher instanceof RequestMatcherInterface) {
                    $parameters = $this->urlMatcher->matchRequest($request);
                } else {
                    $parameters = $this->urlMatcher->match($request->getPathInfo());
                }

                return $path === $parameters['_route'];
            } catch (MethodNotAllowedException $e) {
                return false;
            } catch (ResourceNotFoundException $e) {
                return false;
            }
        }*/
        return this->options["check_path"] === rawurldecode(request->getURI());
    }

    /**
     * Performs authentication.
     *
     * @param Request request A Request instance
     *
     * @return TokenInterface|Response|null The authenticated token, null if full authentication is not possible, or a Response
     *
     * @throws AuthenticationException if the authentication fails
     */
    abstract protected function attemptAuthentication(<Request> request);

    public function onFailure(<Request> request, <AuthenticationException> failed)
    {
        var response, token;
        /*
        if (null !== this->logger) {
            this->logger->info("Authentication request failed.", array("exception" => failed));
        }*/

        let token = this->tokenStorage->getToken();
        if (token instanceof UsernamePasswordToken && this->providerKey === token->getProviderKey()) {
            this->tokenStorage->setToken(null);
            this->getDI()->remove("security.token_storage");
            this->getDI()->set("security.token_storage", this->tokenStorage);
        }

        let response = this->failureHandler->onAuthenticationFailure(request, failed);

        if (!(response instanceof Response)) {
            throw new \RuntimeException("Authentication Failure Handler did not return a Response.");
        }

        return response;
    }


    public function onSuccess(<Request> request, <TokenInterface> token)
    {
        var session, response, loginEvent;
        //if (null !== this->logger) {
        //    this->logger->info("User has been authenticated successfully.", ["username" : token->getUsername()]);
        //}

        this->tokenStorage->setToken(token);
        this->getDI()->remove("security.token_storage");
        this->getDI()->set("security.token_storage", this->tokenStorage);

        let session = this->getDI()->get("session");
        session->remove(Security::AUTHENTICATION_ERROR);
        session->remove(Security::LAST_USERNAME);


        if ((null === token) || (token instanceof AnonymousToken)) {
            session->remove(this->getDI()->get("parameters")->security["context_session"]);
        } else {
            session->set("_security_main", serialize(token));
            /*if (null !== this->logger) {
                this->logger->debug("Stored the security token in the session.", array("key" => this->sessionKey));
            }*/
        }

        if (this->getDI()->has("dispatcher")) {
            let loginEvent = new InteractiveLoginEvent(request, token);
            this->getDI()->get("dispatcher")->getEventsManager()->attach(SecurityEvents::INTERACTIVE_LOGIN, loginEvent);
        }

        let response = this->successHandler->onAuthenticationSuccess(request, token);

        if (!(response instanceof Response)) {
            throw new \RuntimeException("Authentication Success Handler did not return a Response.");
        }

        /*
        if (null !== this->rememberMeServices) {
            this->rememberMeServices->loginSuccess(request, response, token);
        }*/

        return response;
    }
}
