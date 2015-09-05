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
use Phady\Security\Core\Exception\UsernameNotFoundException;
use Phady\Security\Core\Exception\UnsupportedUserException;

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
        var username, user, userId, inMemoryProvider;
        //definition = container->setDefinition(id, new DefinitionDecorator("security.user.provider.in_memory"));
        //"security.user.provider.in_memory.class"

        //let this->container["security.user.provider.in_memory"] = new \Phady\Security\Core\User\InMemoryUserProvider(config["users"]);
        this->container->set("security.user.provider.in_memory", function (config) {
            return new \Phady\Security\Core\User\InMemoryUserProvider(config["users"]);
        });

        this->container->set(id, function (config) {
            var userProvider, container;
            let container = _SERVER["containerApp"];
            let userProvider = new \Phady\Security\Core\User\InMemoryUserProvider(config["users"]);
            return new \Phady\Security\Core\Authentication\Provider\DaoAuthenticationProvider(userProvider,
                        new \Phady\Security\Core\User\UserChecker(), "key",
                        _SERVER["security.encoder_factory.generic"]);
        });
    }

    public function getKey()
    {
        return "memory";
    }


}