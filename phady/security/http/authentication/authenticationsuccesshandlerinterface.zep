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

namespace Phady\Security\Http\Authentication;

use Phady\Security\Core\Authentication\Token\TokenInterface;
use \Phalcon\Http\Request;

/**
 * Phady\Security\Http\Authentication\AuthenticationSuccessHandlerInterface
 *
 * Interface
 */
interface AuthenticationSuccessHandlerInterface
{

    /**
     * This is called when an interactive authentication attempt succeeds. This
     * is called by authentication listeners inheriting from
     * AbstractAuthenticationListener.
     *
     * @param Request        $request
     * @param TokenInterface $token
     *
     * @return Response never null
     */
    public function onAuthenticationSuccess(<Request> request, <TokenInterface> token);
}