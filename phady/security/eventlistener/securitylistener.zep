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

        //Register component security.encoder_factory.generic
        this->container->set("security.encoder_factory.generic", function () {
            return new \Phady\Security\Core\Encoder\EncoderFactory([]);
        });


        //Register component security.authentication.manager
        this->container->set("security.authentication.manager", function () {
            var authProvider, usersData, keyProvider, provider, keyGroup, providerGroup, container, securityConfigApp, providersList;
            let container = _SERVER["containerApp"];
            let securityConfigApp = _SERVER["securityConfigApp"];
            let providersList = [];
            //Phady\Security\Core\Authentication\Provider\UserAuthenticationProvider

            for keyGroup, providerGroup in securityConfigApp["security"]["providers"] {
                for keyProvider, provider in providerGroup {
                    if (keyProvider === "memory") {
                        for usersData in provider {
                        //Phady\Security\Core\Authentication\Provider\DaoAuthenticationProvider
                            let providersList[] = new \Phady\Security\Core\Authentication\Provider\DaoAuthenticationProvider(
                                null, container->get("security.user_checker"), "key", container->get("security.encoder_factory.generic")
                            );
                        }
                    }
                }

            }

            print_r(providersList);
            let authProvider = new \Phady\Security\Core\Authentication\AuthenticationProviderManager(providersList);
            return authProvider;
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

        //Register component login manager service
        this->container->set("security.authentication.listener.form", function () {
            var container, listenForm;
            let container = _SERVER["containerApp"];

            let listenForm = new \Phady\Security\Http\Firewall\UsernamePasswordFormAuthenticationListener(
                    container->get("security.token_storage"), container->get("security.authentication.manager"),
                    "key", container->get("security.authentication.success_handler"), container->get("security.authentication.failure_handler"),
                    [], null);
            return listenForm;
        });



    }

}
