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

namespace Phady\Security\Core\Authentication;

use Phady\Security\Core\Authentication\Model\UserInterface;
use Phalcon\Http\Response;

/**
 * Phady\Security\Core\Authentication\LoginManagerInterface
 *
 * Interface
 */
interface LoginManagerInterface
{

    /**
     * @param string        firewallName
     * @param UserInterface user
     * @param Response|null response
     *
     * @return void
     */
    public function loginUser(firewallName, <UserInterface> user, <Response> response = null);
}