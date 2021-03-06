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
 * Phady\Common\Controllers\ControllerBase
 *
 * Base Controller
 */
class ControllerBase extends \Phalcon\Di\Injectable
{

    const LOGIN_URI = "login";

    const PORTAL_URI = "portal";

    /**
     * initialize the class.
     * @name initialize
     * @return NULL
     */
    public function initialize() {
        //\Phalcon\Tag::prependTitle("RUOS | ");
        // Navegador IE antiguo
        if (preg_match("/(?i)msie [1-8]/", _SERVER["HTTP_USER_AGENT"])) {
            // if IE<=8
            /*
            this->flash->error("We have detected an old version of your browser. For proper operation of the system, use either an updated version of the following browsers: "
                . "<a href='http://www.mozilla.org/es-ES/firefox/new/' target='_blank'>Mozilla Firefox</a>, "
                . "<a href='https://www.google.com/intl/es/chrome/browser/?hl=es' target='_blank'>Google Chrome</a> o "
                . "<a href='http://windows.microsoft.com/es-419/internet-explorer/ie-11-worldwide-languages' target='_blank'>Internet Explorer</a>"
            );
            */
        }
    }
    
    public function beforeExecuteRoute(dispatcher) {

    }


}
