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


use Phady\Security\Core\Authentication\Token\Storage\TokenStorageInterface;
use Phady\Security\Core\Authentication\AuthenticationTrustResolverInterface;
use Phady\Security\Http\EntryPoint\AuthenticationEntryPointInterface;
use Phady\Security\Http\Authorization\AccessDeniedHandlerInterface;

/**
  * @class Phady\Security\Http\Firewall\ExceptionListener
  * ExceptionListener catches authentication exception and converts them to
  * Response instances.
  *
  * @author  Alien Fernández Fuentes <alienfernandez85@gmail.com>
  * @package Core
  * @copyright (c) 2015
  * @version 1.0.0
  */
class ExceptionListener extends \Phalcon\Di\Injectable
{

    private tokenStorage;
    private providerKey;
    private accessDeniedHandler;
    private authenticationEntryPoint;
    private authenticationTrustResolver;
    private errorPage;
    private logger;
    private httpUtils;
    private stateless;

    public function __construct(<TokenStorageInterface> tokenStorage, <AuthenticationTrustResolverInterface> trustResolver,
                        providerKey, <AuthenticationEntryPointInterface> authenticationEntryPoint = null, errorPage = null,
                        <AccessDeniedHandlerInterface> accessDeniedHandler = null, stateless = false)
    {
        let this->tokenStorage = tokenStorage;
        let this->accessDeniedHandler = accessDeniedHandler;
        let this->providerKey = providerKey;
        let this->authenticationEntryPoint = authenticationEntryPoint;
        let this->authenticationTrustResolver = trustResolver;
        let this->errorPage = errorPage;
        //this->logger = logger;
        let this->stateless = stateless;
    }


    /**
     * Handles exceptions security.
     *
     */
    public function beforeException(<Event> event, <Dispatcher> dispatcher, exception) {
        if (exception instanceof AuthenticationException) {
            return this->handleAuthenticationException(exception);
        }
        /*elseif (exception instanceof AccessDeniedException) {
            return this->handleAccessDeniedException(event, exception);
        } elseif (exception instanceof LogoutException) {
            return this->handleLogoutException(exception);
        }*/
    }

    private function handleAuthenticationException(<AuthenticationException> exception)
    {
        var e;
        /*if (null !== this->logger) {
            this->logger->info("An AuthenticationException was thrown; redirecting to authentication entry point.", array("exception" => exception));
        }*/

        try {
            this->startAuthentication(exception);
        } catch \Exception, e {
            echo e;
        }
    }


    /**
     * @param Request                 request
     * @param AuthenticationException authException
     *
     * @return Response
     *
     * @throws AuthenticationException
     */
    private function startAuthentication(<AuthenticationException> authException)
    {
        if (null === this->authenticationEntryPoint) {
            throw authException;
        }

        /*if (null !== this->logger) {
            this->logger->debug("Calling Authentication entry point.");
        }

        if (!this->stateless) {
            this->setTargetPath(request);
        }*/

        if (authException instanceof AccountStatusException) {
            // remove the security token to prevent infinite redirect loops
            this->tokenStorage->setToken(null);

            /*if (null !== this->logger) {
                this->logger->info("The security token was removed due to an AccountStatusException.", array("exception" => authException));
            }*/
        }

        return this->authenticationEntryPoint->start(this->getDI()->get("request"), authException);
    }

    /**
     * @param Request request
     */
    protected function setTargetPath(<Request> request)
    {
        // session isn"t required when using HTTP basic authentication mechanism for example
        /*if (request->hasSession() && request->isMethodSafe() && !request->isXmlHttpRequest()) {
            request->getSession()->set("_security.".this->providerKey.".target_path", request->getURI());
        }*/
    }

}
