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

namespace Phady\Security\Bundle\Model;

use Phady\Security\Bundle\Model\Repository\RoleRepository;
use Phady\Security\Bundle\Model\Entity\Roles;
use Phady\Util\Uuid;
use Phady\Util\Model as ModelUtil;
use Phady\Util\Text;

/**
  * @class Phady\Security\Bundle\Model\RoleCore
  *
  * @author  Alien Fernández Fuentes <alienfernandez85@gmail.com>
  * @package Core
  * @copyright (c) 2015
  * @version 1.0.0
  */
class RoleCore extends \Phalcon\DI\Injectable
{

    public function __construct(){

    }

    /**
     * @name getRoles - Get role data
     * @param array arrData - Data to filters
     * @param boolean getTotal - Get the total with the filter applied
     * @return array
     */
    public function getRoles(array arrDataFilter, boolean getTotal = false) {
        var arrData, roleRepository, arrRoles, arrTotalRoles;
        //let arrData = [];
        let roleRepository = new RoleRepository();
        let arrRoles = roleRepository->getRoles(arrDataFilter);
        let arrData = ["data" : arrRoles];
        if (getTotal) {
            let arrTotalRoles = roleRepository->getTotalRoles(arrData);
            let arrData["total"] = arrTotalRoles;
        }
        return arrData;
    }


    /**
     * @name persist - Persist role
     * @param array arrData Data to persist
     * @return bool
     */
    public function persist(array arrData) {
        var count, objectPersist, encoder, save;
        boolean persist = true;
        let count = Roles::count(["name = '" . arrData["name"] . "'"]);
        //Edit
        if (array_key_exists("role_id", arrData) && !empty(arrData["role_id"])) {

            let objectPersist = Roles::findFirst(["role_id = '" . arrData["role_id"] . "'"]);
            //Si se modifico la descripcion verificar si es unica la misma
            if (objectPersist->name != arrData["name"]) {
                let persist = (count == 0) ? true : false;
            }
        } else {
            //Add
            let persist = (count == 0) ? true : false;
            let objectPersist = new Roles();
            let arrData["role_code"] = "ROLE_" . strtoupper(arrData["alias"]);
            //let objectPersist->id = Uuid::v4();
            unset(arrData["id"]);
        }

        if (persist) {
            //Assign data to object
            ModelUtil::asssignData(objectPersist, arrData);
            let save = objectPersist->save();
            if (save == false) {
                let objectPersist = [
                    "error_code" : "AppSeguridadMsgCore::MODEL_USUARIO_SAVE_CODE_ERROR",
                    "message" : "AppSeguridadMsgCore::MODEL_USUARIO_SAVE_MSG_ERROR"
                ];
            }
        } else {
            //role exist
            let objectPersist = [
                "error_code" : "AppSeguridadMsgCore::MODEL_EXIST_RECORD_USUARIO_CODE_ERROR",
                "message" : "AppSeguridadMsgCore::MODEL_EXIST_RECORD_USUARIO_MSG_ERROR .  [<strong>{arrData[name]}</strong>]"
            ];
        }

        return objectPersist;
    }

    /**
     * @name deleteRole - Delete role
     * @param  Role id to delete
     * @return bool
     */
    public function deleteRole(roleId) {
        var role, deleted;
        let role = Roles::findFirst(["role_id = '" . roleId . "'"]);

        if (role) {
            let deleted = role->delete();
            return deleted;
        }

        return FALSE;
    }


    /**
     * Get roles by array ids
     *
     * @param array arrRolesId - Array roles
     * @return array
     */
    public function getUserRolesByIds(arrRolesId)
    {
        var rolesStr, roles, key, role, arrRoles;
        let rolesStr = "'" . implode("','", arrRolesId) . "'";
        let roles = Roles::find(["role_id in (". rolesStr .")"])->toArray();
        let arrRoles = [];
        for key, role in roles {
            let arrRoles[] = role["name"];
        }

        return arrRoles;
    }

}

