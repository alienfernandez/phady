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

use Phady\Security\Core\Exception\AuthenticationException;

/**
  * @class Phady\Security\Core\Exception\AuthenticationServiceException
  *
  * @author  Alien Fernández Fuentes <alienfernandez85@gmail.com>
  * @package Core
  * @copyright (c) 2015
  * @version 1.0.0
  */
class AuthenticationServiceException extends AuthenticationException
{

    /**
     * {@inheritdoc}
     */
    public function getMessageKey()
    {
        return "Authentication request could not be processed due to a system problem.";
    }
}
