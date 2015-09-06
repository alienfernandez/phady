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
use Phady\Security\Core\Exception\LockedException;
use Phady\Security\Core\Exception\DisabledException;
use Phady\Security\Core\Exception\AccountExpiredException;
use Phady\Security\Core\Exception\CredentialsExpiredException;

/**
  * @class Phady\Security\Core\User\UserChecker
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
        var ex;
        if (user instanceof AdvancedUserInterface) {

            if (!user->isAccountNonLocked()) {
                let ex = new LockedException("User account is locked.");
                ex->setUser(user);
                throw ex;
            }

            if (!user->isEnabled()) {
                let ex = new DisabledException("User account is disabled.");
                ex->setUser(user);
                throw ex;
            }
            if (!user->isAccountNonExpired()) {
                let ex = new AccountExpiredException("User account has expired.");
                ex->setUser(user);
                throw ex;
            }
        } else {
            return;
        }
    }

    /**
     * {@inheritdoc}
     */
    public function checkPostAuth(<UserInterface> user)
    {
        if (user instanceof AdvancedUserInterface) {
            if (!user->isCredentialsNonExpired()) {
                throw new CredentialsExpiredException("User credentials have expired.");
            }
        }else {
            return;
        }
    }
}
