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

use Phady\Security\Core\Exception\AccountStatusException;

/**
  * @class Phady\Security\Core\Exception\CredentialsExpiredException
  *
  * @author  Alien Fernández Fuentes <alienfernandez85@gmail.com>
  * @package Core
  * @copyright (c) 2015
  * @version 1.0.0
  */
class CredentialsExpiredException extends AccountStatusException
{

    /**
     * {@inheritdoc}
     */
    public function getMessageKey()
    {
        return "Credentials have expired.";
    }

}
