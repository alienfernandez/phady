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
       //let this->dispatcher = dispatcher;
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

        /*
        if (!request->hasSession()) {
            throw new \RuntimeException("This authentication method requires a session.");
        }*/

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
                //this->sessionStrategy->onAuthentication(request, returnValue);

                let response = this->onSuccess(request, returnValue);
            } elseif (returnValue instanceof Response) {
                let response = returnValue;
            } else {
                throw new \RuntimeException("attemptAuthentication() must either return a Response, an implementation of TokenInterface, or null.");
            }
        } catch AuthenticationException, e {
            let response = this->onFailure(request, e);
        }

        //event->setResponse(response);
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
        //return this->httpUtils->checkRequestPath(request, this->options["check_path"]);
        return true;
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

    private function onFailure(<Request> request, <AuthenticationException> failed)
    {
        var response, token;
        /*
        if (null !== this->logger) {
            this->logger->info("Authentication request failed.", array("exception" => failed));
        }*/

        let token = this->tokenStorage->getToken();
        if (token instanceof UsernamePasswordToken && this->providerKey === token->getProviderKey()) {
            this->tokenStorage->setToken(null);
        }

        let response = this->failureHandler->onAuthenticationFailure(request, failed);

        if (!(response instanceof Response)) {
            throw new \RuntimeException("Authentication Failure Handler did not return a Response.");
        }

        return response;
    }


    private function onSuccess(<Request> request, <TokenInterface> token)
    {
        var session, response;
        if (null !== this->logger) {
            this->logger->info("User has been authenticated successfully.", ["username" : token->getUsername()]);
        }

        this->tokenStorage->setToken(token);

        //let session = request->getSession();
        //session->remove(Security::AUTHENTICATION_ERROR);
        //session->remove(Security::LAST_USERNAME);

        /*
        if (null !== this->dispatcher) {
            loginEvent = new InteractiveLoginEvent(request, token);
            this->dispatcher->dispatch(SecurityEvents::INTERACTIVE_LOGIN, loginEvent);
        }*/

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
