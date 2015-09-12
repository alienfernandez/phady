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
        this->container->setShared("security.user_checker", function () {
            return new \Phady\Security\Core\User\UserChecker();
        });

        //Register component security.token_storage
        if (!this->container->has("security.token_storage")){
            this->container->setShared("security.token_storage", function () {
                return new \Phady\Security\Core\Authentication\Token\Storage\TokenStorage();
            });
        }

        //Register component security.authentication.success_handler
        this->container->setShared("security.authentication.success_handler", function () {
            return new \Phady\Security\Http\Authentication\DefaultAuthenticationSuccessHandler();
        });

        //Register component security.authentication.failure_handler
        this->container->setShared("security.authentication.failure_handler", function () {
            return new \Phady\Security\Http\Authentication\DefaultAuthenticationFailureHandler();
        });

        this->container->set("security.authentication.manager", function() {
             return new \Phady\Security\Core\Authentication\AuthenticationProviderManager([]);
        });

        this->container->setShared("security.access.simple_role_voter", function() {
             return new \Phady\Security\Core\Authorization\Voter\RoleVoter("ROLE_");
        });


        this->container->setShared("security.authentication.trust_resolver", function() {
             return new \Phady\Security\Core\Authentication\AuthenticationTrustResolver(
                "Phady\Security\Core\Authentication\Token\AnonymousToken",
                "Phady\Security\Core\Authentication\Token\RememberMeToken"
             );
        });

        let this->securityExtension = new SecurityExtension();

    }

}
