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

namespace Phady\Security\Core\User;

use Phady\Security\Core\User\UserProviderInterface;
use Phady\Security\Core\User\UserInterface;
use Phady\Security\Core\User\User as UserCore;
use Phady\Security\Core\Exception\UsernameNotFoundException;

/**
  * @class Phady\Security\Core\User\InMemoryUserProvider
  *
  * @author  Alien Fernández Fuentes <alienfernandez85@gmail.com>
  * @package Core
  * @copyright (c) 2015
  * @version 1.0.0
  */
class InMemoryUserProvider implements UserProviderInterface
{
    private users;
    
    /**
     * Constructor.
     *
     * The user array is a hash where the keys are usernames and the values are
     * an array of attributes: "password", "enabled", and "roles".
     *
     * @param array users An array of users
     */
    public function __construct(array users = [])
    {
        var username, attributes, password, enabled, roles, user;
        for username, attributes in users {
            let password = isset(attributes["password"]) ? attributes["password"] : null;
            let enabled = isset(attributes["enabled"]) ? attributes["enabled"] : true;
            let roles = isset(attributes["roles"]) ? attributes["roles"] : [];
            let user = new User(username, password, roles, enabled, true, true, true);
            this->createUser(user);
        }
    }

    /**
     * Adds a new User to the provider.
     *
     * @param UserInterface user A UserInterface instance
     *
     * @throws \LogicException
     */
    public function createUser(<UserInterface> user)
    {
        if (isset(this->users[strtolower(user->getUsername())])) {
            throw new \LogicException("Another user with the same username already exists.");
        }
        let this->users[strtolower(user->getUsername())] = user;
    }
    
    /**
     * {@inheritdoc}
     */
    public function loadUserByUsername(username)
    {
        var ex, user;
        if (!isset(this->users[strtolower(username)])) {
            let ex = new UsernameNotFoundException(sprintf("Username %s does not exist.", username));
            ex->setUsername(username);
            throw ex;
        }
        let user = this->users[strtolower(username)];
        return new UserCore(user->getUsername(), user->getPassword(), user->getRoles(), user->isEnabled(), user->isAccountNonExpired(),
                user->isCredentialsNonExpired(), user->isAccountNonLocked());
    }


    /**
     * {@inheritdoc}
     */
    public function refreshUser(<UserInterface> user)
    {
        if (!(user instanceof UserCore)) {
            throw new \Phady\Security\Exception(sprintf("Instances of %s are not supported.", get_class(user)));
        }
        return this->loadUserByUsername(user->getUsername());
    }

    /**
     * {@inheritdoc}
     */
    public function supportsClass(string classSuport)
    {
        return (classSuport == "Phady\\Security\\Core\\User\\User");
    }

}