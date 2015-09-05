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

namespace Phady\Security\EventListener;

use Phalcon\Events\Event;
use Phalcon\Mvc\Dispatcher;
use Phady\Security\SecurityExtension;

/**
  * @class Phady\Security\EventListener\SecurityListener
  *
  * @author  Alien Fernández Fuentes <alienfernandez85@gmail.com>
  * @package Core
  * @copyright (c) 2015
  * @version 1.0.0
  */
class SecurityListener extends \Phalcon\Di\Injectable
{

    private container;
    private securityExtension;

    public function __construct()
    {
        let this->container = this->getDI();
    }

    public function addSecurityListeners()
    {
        //TODO delete _SERVER

        //Register component security.user_checker
        this->container->set("security.user_checker", function () {
            return new \Phady\Security\Core\User\UserChecker();
        });

        //Register component security.token_storage
        this->container->set("security.token_storage", function () {
            return new \Phady\Security\Core\Authentication\Token\Storage\TokenStorage();
        });

        //Register component security.authentication.success_handler
        this->container->set("security.authentication.success_handler", function () {
            return new \Phady\Security\Http\Authentication\DefaultAuthenticationSuccessHandler();
        });

        //Register component security.authentication.failure_handler
        this->container->set("security.authentication.failure_handler", function () {
            return new \Phady\Security\Http\Authentication\DefaultAuthenticationFailureHandler();
        });

        //Register component login manager service
        this->container->set("security.login_manager", function () {
            var loginManager, userChecker, container;
            let container = _SERVER["containerApp"];
            let userChecker = new \Phady\Security\Core\User\UserChecker();
            let loginManager = new \Phady\Security\Core\Authentication\LoginManager(container->get("security.token_storage"), userChecker, _SERVER["containerApp"]);
            return loginManager;
        });

        let this->securityExtension = new SecurityExtension();

    }

}
