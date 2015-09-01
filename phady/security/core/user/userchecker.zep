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

use Phady\Security\Core\User\UserCheckerInterface;
use Phady\Security\Core\User\UserInterface;
use Phady\Security\Core\User\AdvancedUserInterface;

/**
  * @class Phady\Security\Core\User\User -  Core user for app
  *
  * @author  Alien Fernández Fuentes <alienfernandez85@gmail.com>
  * @package Core
  * @copyright (c) 2015
  * @version 1.0.0
  */
class UserChecker implements UserCheckerInterface {
    
    /**
     * {@inheritdoc}
     */
    public function checkPreAuth(<UserInterface> user)
    {
        if (!(user instanceof AdvancedUserInterface)) {
            return;
        }
        if (!user->isAccountNonLocked()) {
            throw new \Phady\Security\Exception("User account is locked.");
        }
        if (!user->isEnabled()) {
            throw new \Phady\Security\Exception("User account is disabled.");
        }
        if (!user->isAccountNonExpired()) {
            throw new \Phady\Security\Exception("User account has expired.");
        }
    }

    /**
     * {@inheritdoc}
     */
    public function checkPostAuth(<UserInterface> user)
    {
        if (!(user instanceof AdvancedUserInterface)) {
            return;
        }
        if (!user->isCredentialsNonExpired()) {
            throw new \Phady\Security\Exception("User credentials have expired.");
        }
    }
}
