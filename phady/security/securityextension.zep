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
class SecurityExtension extends \Phalcon\Di\Injectable
{

    private requestMatchers = [];
    private listenerPositions = ["pre_auth", "form", "http", "remember_me"];
    private factories = [];
    private userProviderFactories = [];

    public function __construct()
    {
        var position;
        for position in this->listenerPositions {
            let this->factories[position] = [];
        }
    }

    public function loadSecurityConfig(array configs)
    {
        var config;
        let config = []; //Todo CAMBIAR POR ARRAY VIENE FICHERO
        if (!array_filter(configs)) {
            return;
        }


        //this->createFirewalls(config, container);
        //this->createAuthorization(config, container);
        //this->createRoleHierarchy(config, container);

        if (config["encoders"]) {
            this->createEncoders(config["encoders"]);
        }
    }

    private function createEncoders(encoders)
    {
        var encoderMap, classEncoder, encoder;
        let encoderMap = [];
        for classEncoder, encoder in encoders {
            let encoderMap[classEncoder] = this->createEncoder(encoder);
        }
        this->getDI()->set("security.encoder_factory.generic", function (encoderMap) {
            print_r(encoderMap);
            return new \Phady\Security\Core\Encoder\EncoderFactory(encoderMap);
         });
    }

    private function createEncoder(array config)
    {
        // a custom encoder service
        /*
        if (isset(config["id"])) {
            return new Reference(config["id"]);
        }*/

        // plaintext encoder
        if ("plaintext" === config["algorithm"]) {
            this->getDI()->set("security.encoder.plain.class", function (config) {
                return \Phady\Security\Core\Encoder\PlaintextPasswordEncoder(config["ignore_case"]);
             });
            return this->getDI()->get("security.encoder.plain.class");
        }

        // bcrypt encoder
        if ("bcrypt" === config["algorithm"]) {
            this->getDI()->set("security.encoder.bcrypt.class", function (config) {
                return new \Phady\Security\Core\Encoder\BCryptPasswordEncoder(config["cost"]);
             });
            return this->getDI()->get("security.encoder.bcrypt.class");
        }
    }
    //copy namespace Symfony\Bundle\SecurityBundle\DependencyInjection;

}
