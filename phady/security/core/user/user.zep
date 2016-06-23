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

use Phady\Security\Core\User\AdvancedUserInterface;

/**
  * @class Phady\Security\Core\User\User -  Core user for app
  *
  * @author  Alien Fernández Fuentes <alienfernandez85@gmail.com>
  * @package Core
  * @copyright (c) 2015
  * @version 1.0.0
  */
final class User implements AdvancedUserInterface {
    
    private username;
    private password;
    private enabled;
    private accountNonExpired;
    private credentialsNonExpired;
    private accountNonLocked;
    private roles;
    
    public function __construct(username, password, array roles = [], boolean enabled = true, boolean userNonExpired = true,
                                boolean credentialsNonExpired = true, boolean userNonLocked = true)
    {
        if ("" === username || null === username) {
            throw new \InvalidArgumentException("The username cannot be empty.");
        }

        let this->username = username;
        let this->password = password;
        let this->enabled = enabled;
        let this->accountNonExpired = userNonExpired;
        let this->credentialsNonExpired = credentialsNonExpired;
        let this->accountNonLocked = userNonLocked;
        let this->roles = roles;
    }

    public function __toString()
    {
        return this->getUsername();
    }

    /**
     * {@inheritdoc}
     */
    public function getRoles()
    {
        return this->roles;
    }

    /**
     * {@inheritdoc}
     */
    public function getPassword()
    {
        return this->password;
    }

    /**
     * {@inheritdoc}
     */
    public function getSalt()
    {
    }

    /**
     * {@inheritdoc}
     */
    public function getUsername()
    {
        return this->username;
    }

    /**
     * {@inheritdoc}
     */
    public function isAccountNonExpired()
    {
        return this->accountNonExpired;
    }

    /**
     * {@inheritdoc}
     */
    public function isAccountNonLocked()
    {
        return this->accountNonLocked;
    }

    /**
     * {@inheritdoc}
     */
    public function isCredentialsNonExpired()
    {
        return this->credentialsNonExpired;
    }

    /**
     * {@inheritdoc}
     */
    public function isEnabled()
    {
        return this->enabled;
    }

    /**
     * {@inheritdoc}
     */
    public function eraseCredentials()
    {
    }
}
