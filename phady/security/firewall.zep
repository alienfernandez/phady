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

namespace Phady\Security;

use Phalcon\Http\Request;
use Phady\Security\Http\Firewall\ExceptionListener;
use Phady\Security\Http\FirewallMapInterface;
use Phalcon\Events\Event;
use Phalcon\Mvc\Dispatcher;
use Phady\Security\Core\Exception\AuthenticationException;
use Phady\Security\Core\Exception\AccountStatusException;

/**
  * @class Phady\Security\Firewall
  *
  * @author  Alien Fernández Fuentes <alienfernandez85@gmail.com>
  * @package Core
  * @copyright (c) 2015
  * @version 1.0.0
  */
class Firewall extends \Phalcon\Di\Injectable
{
    private map = [];
    private dispatcher;
    private exceptionListeners;
    private authenticationEntryPoint;
    private tokenStorage;


    /**
     * Constructor.
     *
     * @param FirewallMapInterface     map        A FirewallMapInterface instance
     * @param EventDispatcherInterface dispatcher An EventDispatcherInterface instance
     */
     //<FirewallMapInterface> map
    public function __construct()
    {
        let this->exceptionListeners = new \SplObjectStorage();
    }

    /**
     * Set map
     *
     */
    public function setMap(<FirewallMapInterface> map)
    {
        let this->map = map;
    }

    /**
     * Handles security.
     *
     */
    public function beforeExecuteRoute(<Event> event, <Dispatcher> dispatcher, exception1) {
        //Symfony\Component\Security\Http\Firewall\ChannelListener - Symfony\Component\Security\Http\Firewall\ContextListener
        //- Symfony\Component\Security\Http\Firewall\LogoutListener - Symfony\Component\Security\Http\Firewall\UsernamePasswordFormAuthenticationListener
        //- Symfony\Component\Security\Http\Firewall\AnonymousAuthenticationListener - Symfony\Component\Security\Http\Firewall\AccessListener -
        var exception, request, listeners, exceptionListener, listenersMap, listener;
        let request = this->getDI()->get("request");
        let this->map = this->getDI()->get("security.firewall.map");
        let this->authenticationEntryPoint = this->getDI()->get("security.authentication.form_entry_point");
        let this->tokenStorage = this->getDI()->get("security.token_storage");

        /*let controllerName = dispatcher->getControllerName();
        let actionName = dispatcher->getActionName();
        */
        // register listeners for this firewall
        let listenersMap = this->map->getListeners(request);

        try {
            //If uri is entry point
            if (this->authenticationEntryPoint->getLoginPath() != request->getURI()){
                // initiate the listener
                for listener in listenersMap[0] {
                    //echo "<pre>"; print_r(this->getDI()->get(listener)); die();
                    this->getDI()->get(listener)->handle();
                }
            }
        }
        catch \Exception, exception {
            print_r(get_class(exception) . " - " . exception->getMessage());die();
            if (exception instanceof AuthenticationException) {
                this->handleAuthenticationException(request, exception);
            }
        }
    }


    public function handleAuthenticationException(<Request> request, <AuthenticationException> exception)
    {
        /*if (null !== this->logger) {
            this->logger->info("An AuthenticationException was thrown; redirecting to authentication entry point.", array("exception" => exception));
        }*/
        this->startAuthentication(request, exception);
    }

    /**
     * @param Request                 request
     * @param AuthenticationException authException
     *
     * @return Response
     *
     * @throws AuthenticationException
     */
    private function startAuthentication(<Request> request, <AuthenticationException> authException)
    {
        if (null === this->authenticationEntryPoint) {
            throw authException;
        }

        /*if (null !== this->logger) {
            this->logger->debug("Calling Authentication entry point.");
        }*/

        /*
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

        return this->authenticationEntryPoint->start(request, authException);
    }
}
