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

namespace Phady\Security\Bundle\Services;

use Phady\Security\Bundle\Model\UserCore;

/**
  * @class Phady\Security\Bundle\Services\UserService
  *
  * @author  Alien Fernández Fuentes <alienfernandez85@gmail.com>
  * @package Core
  * @copyright (c) 2015
  * @version 1.0.0
  */
class UserService extends \Phalcon\DI\Injectable
{
    private userCore;

    public function __construct(){
        let this->userCore = new UserCore();
    }

    /**
     * @name getUsers - Get users
     * @param array arrData - Data to filter
     * @param boolean getTotal - Get total users to filter applied
     * @return array
     */
    public function getUsers(array arrData, getTotal = false) -> array {
        return this->userCore->getUsers(arrData, getTotal);
    }
}

