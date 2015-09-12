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

namespace Phady\Security\Http\Logout;

use Phalcon\Http\Request;
use Phalcon\Http\Response;
use Phady\Security\Core\Authentication\Token\TokenInterface;
use Phady\Security\Http\Logout\LogoutHandlerInterface;

/**
  * @class Phady\Security\Http\Logout\DefaultLogoutSuccessHandler
  *
  * @author  Alien Fernández Fuentes <alienfernandez85@gmail.com>
  * @package Core
  * @copyright (c) 2015
  * @version 1.0.0
  */
class SessionLogoutHandler extends \Phalcon\Di\Injectable implements LogoutHandlerInterface
{

    /**
     * Invalidate the current session.
     *
     * @param Request        request
     * @param Response       response
     * @param TokenInterface token
     */
    public function logout(<Request> request, <Response> response, <TokenInterface> token)
    {
        this->getDI()->get("session")->destroy();
    }
}
