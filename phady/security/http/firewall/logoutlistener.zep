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
use Phalcon\Http\Request;


use Phady\Security\Core\Authentication\Token\Storage\TokenStorageInterface;
use Phady\Security\Http\Logout\LogoutSuccessHandlerInterface;
use Phady\Security\Http\Logout\LogoutHandlerInterface;

/**
  * @class Phady\Security\Http\Firewall\LogoutListener
  *
  * @author  Alien Fernández Fuentes <alienfernandez85@gmail.com>
  * @package Core
  * @copyright (c) 2015
  * @version 1.0.0
  */
class LogoutListener extends \Phalcon\Di\Injectable implements LogoutSuccessHandlerInterface
{
    private tokenStorage;
    private options;
    private handlers;
    private successHandler;
    private httpUtils;
    private csrfTokenManager;

    /**
     * Constructor.
     *
     * @param TokenStorageInterface         tokenStorage
     * @param LogoutSuccessHandlerInterface successHandler   A LogoutSuccessHandlerInterface instance
     * @param array                         options          An array of options to process a logout attempt
     */
    public function __construct(<TokenStorageInterface> tokenStorage, <LogoutSuccessHandlerInterface> successHandler,
                                array options = [])//, csrfTokenManager = null
    {
        /*if (csrfTokenManager instanceof CsrfProviderInterface) {
            csrfTokenManager = new CsrfProviderAdapter(csrfTokenManager);
        } elseif (null !== csrfTokenManager && !csrfTokenManager instanceof CsrfTokenManagerInterface) {
            throw new InvalidArgumentException("The CSRF token manager should be an instance of CsrfProviderInterface or CsrfTokenManagerInterface.");
        }*/

        let this->tokenStorage = tokenStorage;
        let this->options = array_merge(array(
            "csrf_parameter" => "_csrf_token",
            "intention" => "logout",
            "logout_path" => "/logout",
        ), options);
        let this->successHandler = successHandler;
        //this->csrfTokenManager = csrfTokenManager;
        let this->handlers = [];
    }

    /**
     * Adds a logout handler.
     *
     * @param LogoutHandlerInterface handler
     */
    public function addHandler(<LogoutHandlerInterface> handler)
    {
        let this->handlers[] = handler;
    }

    /**
     * Performs the logout if requested.
     *
     * If a CsrfTokenManagerInterface instance is available, it will be used to
     * validate the request.
     *
     * @throws LogoutException   if the CSRF token is invalid
     * @throws \RuntimeException if the LogoutSuccessHandlerInterface instance does not return a response
     */
    public function handle()
    {
        var request;
        let request = this->getDI()->get("request");

        if (!this->requiresLogout(request)) {
            return;
        }

        /*if (null !== this->csrfTokenManager) {
            csrfToken = request->get(this->options["csrf_parameter"], null, true);

            if (false === this->csrfTokenManager->isTokenValid(new CsrfToken(this->options["intention"], csrfToken))) {
                throw new LogoutException("Invalid CSRF token.");
            }
        }*/

        let response = this->successHandler->onLogoutSuccess(request);
        if (!(response instanceof Response)) {
            throw new \RuntimeException("Logout Success Handler did not return a Response.");
        }

        let token = this->tokenStorage->getToken();
        // handle multiple logout attempts gracefully
        if (token) {
            for handler in this->handlers {
                handler->logout(request, response, token);
            }
        }

        this->tokenStorage->setToken(null);
        //event->setResponse(response);
    }

    /**
     * Whether this request is asking for logout.
     *
     * The default implementation only processed requests to a specific path,
     * but a subclass could change this to logout requests where
     * certain parameters is present.
     *
     * @param Request request
     *
     * @return bool
     */
    protected function requiresLogout(<Request> request)
    {
        return this->options["logout_path"] === rawurldecode(request->getURI());
        //return this->httpUtils->checkRequestPath(request, this->options["logout_path"]);
    }
}
