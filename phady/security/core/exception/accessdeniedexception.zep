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

/**
  * @class Phady\Security\Core\Exception\AccessDeniedException
  *
  * @author  Alien Fernández Fuentes <alienfernandez85@gmail.com>
  * @package Core
  * @copyright (c) 2015
  * @version 1.0.0
  */
class AccessDeniedException extends \RuntimeException
{

    /**
     * Rewrite the error message
     * @return string
     */
     public function __construct(message = "Access Denied.", previous = null) {
        parent::__construct(message, 403, previous);
    }

}
