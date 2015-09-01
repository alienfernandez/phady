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

namespace Phady\Security\Core\User;


/**
  * @class Phady\Security\Core\User\Users -  Core users for app
  *
  * @author  Alien Fernández Fuentes <alienfernandez85@gmail.com>
  * @package Core
  * @copyright (c) 2015
  * @version 1.0.0
  */
class Users extends \Phalcon\Mvc\User\Component
{

    /**
     * @name getUsers - Get user data
     * @param array arrData - Data to filters
     * @param boolean getTotal - Get the total with the filter applied
     * @return array
     */
    public function getUsers(array arrDataFilter, boolean getTotal = false) {
        var arrData, userRepository, arrUsers, arrTotalUsers;
        //let arrData = [];
        let userRepository = new \Phady\Security\Core\Models\Repositories\Users();
        let arrUsers = userRepository->getUsers(arrDataFilter);
        let arrData = ["data" : arrUsers];
        if (getTotal) {
            let arrTotalUsers = userRepository->getTotalUsers(arrData);
            let arrData["total"] = arrTotalUsers;
        }
        return arrData;
    }
}
