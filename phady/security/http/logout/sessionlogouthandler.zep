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
  * @class Phady\Security\Http\Logout\SessionLogoutHandler
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
    public function logout(<Request> request, <TokenInterface> token)
    {

        //echo "<pre>"; print_r(this->getDI()->get("parameters"));die();
        this->getDI()->get("session")->remove(this->getDI()->get("parameters")->security["context_session"]);
    }
}
