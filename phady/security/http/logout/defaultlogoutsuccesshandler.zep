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
use Phady\Security\Http\Logout\LogoutSuccessHandlerInterface;

/**
  * @class Phady\Security\Http\Logout\DefaultLogoutSuccessHandler
  *
  * @author  Alien Fernández Fuentes <alienfernandez85@gmail.com>
  * @package Core
  * @copyright (c) 2015
  * @version 1.0.0
  */
class DefaultLogoutSuccessHandler extends \Phalcon\Di\Injectable implements LogoutSuccessHandlerInterface
{
    protected targetUrl;

    /**
     * @param string    targetUrl
     */
    public function __construct(targetUrl = "/")
    {
        let this->targetUrl = targetUrl;
    }

    /**
     * {@inheritdoc}
     */
    public function onLogoutSuccess(<Request> request)
    {
        return this->getDI()->get("response")->redirect(this->targetUrl);
    }
}
