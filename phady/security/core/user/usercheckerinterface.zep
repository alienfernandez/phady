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

use Phady\Security\Core\User\UserInterface;

/**
 * Phady\Security\Core\User\UserCheckerInterface
 *
 * Interface
 */
interface UserCheckerInterface
{

    /**
     * Checks the user account before authentication.
     *
     * @param UserInterface user a UserInterface instance
     */
    public function checkPreAuth(<UserInterface> user);

    /**
     * Checks the user account after authentication.
     *
     * @param UserInterface user a UserInterface instance
     */
    public function checkPostAuth(<UserInterface> user);
}