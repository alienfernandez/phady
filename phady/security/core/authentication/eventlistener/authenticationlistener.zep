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

namespace Phady\Security\Core\Authentication\EventListener;

use Phalcon\Mvc\User\Plugin;
use Phalcon\Events\Event;
use Phalcon\Mvc\Dispatcher;

/**
  * @class Phady\Security\Core\Authentication\EventListener\AuthenticationListener
  *
  * @author  Alien Fernández Fuentes <alienfernandez85@gmail.com>
  * @package Core
  * @copyright (c) 2015
  * @version 1.0.0
  */
class AuthenticationListener extends \Phalcon\Di\Injectable
{
    private loginManager;
    private firewallName;


    public function beforeDispatch(<Event> event, <Dispatcher> dispatcher, exception)
    {
        let this->loginManager = this->getDI()->get("loginManager");
        let this->firewallName = "firewall_default";
        echo "<pre>";
        print_r(this->getDI());
        //print_r(dispatcher);
        print_r("before dispatch...");
    }


    public function authenticate(eventName = null) {
        /*
        if (!event->getUser()->isEnabled()) {
            return;
        }
        try {
            this->loginManager->loginUser(this->firewallName, event->getUser(), event->getResponse());
            eventDispatcher->dispatch(FOSUserEvents::SECURITY_IMPLICIT_LOGIN, new UserEvent(event->getUser(), event->getRequest()));
        } catch (AccountStatusException ex) {
            // We simply do not authenticate users which do not pass the user
            // checker (not enabled, expired, etc.).
        }*/
    }
}
