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

use Phady\Security\Core\User\UserProviderInterface;
use Phady\Security\Core\User\UserInterface;
use Phady\Security\Core\User\User as UserCore;

/**
  * @class Phady\Security\Core\User\Factory\InMemoryFactory
  * InMemoryFactory creates services for the memory provider.
  *
  * @author  Alien Fernández Fuentes <alienfernandez85@gmail.com>
  * @package Core
  * @copyright (c) 2015
  * @version 1.0.0
  */
class InMemoryFactory extends \Phalcon\Di\Injectable implements UserProviderFactoryInterface
{
    private container;

    public function __construct()
    {
        let this->container = this->getDI();
    }

    public function create(id, config) {
        var memoryProviderFunc, argsProvider, argsFactory, memoryFactoryFunc;
        //"security.user.provider.in_memory.class"
        //Register component security.user.provider.in_memory
        let argsProvider = ["config" : config];
        let memoryProviderFunc = call_user_func_array(function(config) {
             return new \Phady\Security\Core\User\InMemoryUserProvider(config["users"]);
        }, argsProvider);
        this->getDI()->set("security.user.provider.in_memory", memoryProviderFunc);

        //Register component security.user.provider.in_memory
        let argsFactory = ["config" : config, "id": id, "container" : this->getDI()];
        let memoryFactoryFunc = call_user_func_array(function(config, id, container) {
             return new \Phady\Security\Core\Authentication\Provider\DaoAuthenticationProvider(
                         container->get("security.user.provider.in_memory"),
                         new \Phady\Security\Core\User\UserChecker(), id,
                         container->get("security.encoder_factory.generic"));
        }, argsFactory);
        this->getDI()->set(id, memoryFactoryFunc);

        return this->getDI()->get(id);
    }

    public function getKey()
    {
        return "memory";
    }


}