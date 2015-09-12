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

namespace Phady\Common\Controllers;

use Phalcon\Mvc\Controller as ControllerMVC;

/**
 * Phady\Common\Controllers\AccessDeniedController
 *
 * Base Controller
 */
class AccessDeniedController extends \Phalcon\Di\Injectable
{
    /**
     * initialize the class.
     * @name initialize
     * @return NULL
     */
    public function initialize() {
        \Phalcon\Tag::prependTitle("Access Denied");
    }

    public function indexAction() {

        echo "<style>.centered {position:absolute; top: 0;bottom: 0;left: 0;right: 0;margin: auto;height: 256px;width: 100%;}</style>" .
             "<div class=centered>" .
             "    <center>" .
             //"          <img src=/images/access_denied.png>" .
             "          <br>" .
             "          You do not have permissions to access this page. If you think you should have access contact an administrator." .
             "          <br>" .
             "          Go to <a href=/login>Login</a>" .
             "      </center>" .
             "</div>";
    }

}
