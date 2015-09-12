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

/**
  * @class Phady\Security\Http\Logout\LogoutHandlerInterface
  *
  * @author  Alien Fernández Fuentes <alienfernandez85@gmail.com>
  * @package Core
  * @copyright (c) 2015
  * @version 1.0.0
  */
interface LogoutHandlerInterface
{

    /**
     * This method is called by the LogoutListener when a user has requested
     * to be logged out. Usually, you would unset session variables, or remove
     * cookies, etc.
     *
     * @param Request        request
     * @param Response       response
     * @param TokenInterface token
     */
    public function logout(<Request> request, <Response> response, <TokenInterface> token);
}
