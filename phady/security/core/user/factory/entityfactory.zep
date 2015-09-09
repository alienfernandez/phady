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
        var args, ormProviderFunc, entityFactoryFunc;
        //Register component phalcon.orm.security.user.provider
        let args = ["config" : config];
        let ormProviderFunc = call_user_func_array(function(config) {
             string configName;
             let configName = (array_key_exists("manager_name", config)) ? config["manager_name"] : "";
             return new \Phady\Security\Core\Authentication\Provider\EntityUserProvider(config["class"], config["property"], configName);
        }, args);
        this->getDI()->set("phalcon.orm.security.user.provider", ormProviderFunc);

        let args = ["config" : config, "id": id];
        let entityFactoryFunc = call_user_func_array(function(config, id) {
             var container;
             let container = _SERVER["containerApp"];
             return new \Phady\Security\Core\Authentication\Provider\DaoAuthenticationProvider(
                         container->get("phalcon.orm.security.user.provider"),
                         new \Phady\Security\Core\User\UserChecker(), id,
                         container->get("security.encoder_factory.generic"));
        }, args);
        this->getDI()->set(id, entityFactoryFunc);
        return this->getDI()->get(id);
    }

    public function getKey()
    {
        return this->key;
    }

}