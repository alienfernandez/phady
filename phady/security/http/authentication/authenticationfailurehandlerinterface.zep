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

use Phady\Security\Core\Exception\AuthenticationException;
use \Phalcon\Http\Request;

/**
 * Phady\Security\Http\Authentication\AuthenticationFailureHandlerInterface
 *
 * Interface
 */
interface AuthenticationFailureHandlerInterface
{

    /**
     * This is called when an interactive authentication attempt fails. This is
     * called by authentication listeners inheriting from
     * AbstractAuthenticationListener.
     *
     * @param Request                 $request
     * @param AuthenticationException $exception
     *
     * @return Response The response to return, never null
     */
    public function onAuthenticationSuccess(<Request> request, <AuthenticationException> exception);
}