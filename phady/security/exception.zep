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

namespace Phady\Security;

use Phalcon\Exception;


/**
 * @class Phady\Security\Exception
 *
 * Exceptions thrown in Phady\Security will use this class
 *
 */
class Exception extends \Exception
{

    /**
     * Rewrite the error message
     * @return string
     */
    public function __toString() {
        return sprintf("[Phady Security Error] %s", this->getMessage());
    }
}