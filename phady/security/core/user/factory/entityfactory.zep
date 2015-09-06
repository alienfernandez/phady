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

namespace Phady\Security\Core\User\Factory;



/**
  * @class Phady\Security\Core\User\Factory\EntityFactory
  * EntityFactory creates services for Phalcon ORM user provider..
  *
  * @author  Alien Fernández Fuentes <alienfernandez85@gmail.com>
  * @package Core
  * @copyright (c) 2015
  * @version 1.0.0
  */
class EntityFactory extends \Phalcon\Di\Injectable implements UserProviderFactoryInterface
{

    private key;
    private providerId;

    public function __construct(key, providerId)
    {
        let this->key = key;
        let this->providerId = providerId;
    }

    public function create(id, config)
    {
        //Register component phalcon.orm.security.user.provider
        this->getDI()->set("phalcon.orm.security.user.provider", function (config) {
            string configName;
            let configName = (array_key_exists("manager_name", config)) ? config["manager_name"] : "";
            return new \Phady\Security\Core\Authentication\Provider\EntityUserProvider(config["class"], config["property"], configName);
        });

        this->getDI()->set(id, function (config) {
            var userProvider, container, configName;
            let container = _SERVER["containerApp"];
            let configName = (array_key_exists("manager_name", config)) ? config["manager_name"] : "";
            let userProvider = new \Phady\Security\Core\Authentication\Provider\EntityUserProvider(config["class"], config["property"], configName);
            return new \Phady\Security\Core\Authentication\Provider\DaoAuthenticationProvider(userProvider,
                        new \Phady\Security\Core\User\UserChecker(), "key",
                        _SERVER["security.encoder_factory.generic"]);
        });
    }

    public function getKey()
    {
        return this->key;
    }

}