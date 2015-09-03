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

use Phady\Security\Core\Authentication\Token\TokenInterface;
use Phady\Security\Core\User\UserProviderInterface;

/**
 * Phady\Security\Core\Authentication\SimpleAuthenticatorInterface
 *
 * Interface
 */
interface SimpleAuthenticatorInterface
{

    public function authenticateToken(<TokenInterface> token, <UserProviderInterface> userProvider, providerKey);

    public function supportsToken(<TokenInterface> token, providerKey);
}