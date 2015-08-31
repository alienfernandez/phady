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

namespace Phady\Security\Core\Exception;

use Phalcon\Exception;

/**
  * @class Phady\Security\Core\Exception\UsernameNotFoundException
  *
  * @author  Alien Fernández Fuentes <alienfernandez85@gmail.com>
  * @package Core
  * @copyright (c) 2015
  * @version 1.0.0
  */
class UsernameNotFoundException extends \Exception
{

    /**
     * Rewrite the error message
     * @return string
     */
    public function __toString() {
        return sprintf("[Phady Security Error] %s", this->getMessage());
    }

}
