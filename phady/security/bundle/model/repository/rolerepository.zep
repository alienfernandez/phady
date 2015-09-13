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

namespace Phady\Security\Bundle\Model\Repository;

/**
  * @class Phady\Security\Bundle\Model\Repository\RoleRepository
  *
  * @author  Alien Fernández Fuentes <alienfernandez85@gmail.com>
  * @package Core
  * @copyright (c) 2015
  * @version 1.0.0
  */
class RoleRepository extends \Phalcon\DI\Injectable
{

    // Get search filter
    static public function getFilter(array arrData, select = false) {
        var arrFilter, arrValues, search, filter;
        let arrFilter = [];
        let arrValues = [];

        if (array_key_exists("id", arrData)) {
            let arrFilter [] = "role.role_id = :id:";
            let arrValues ["id"] = arrData["id"];
        }
        if (array_key_exists("name", arrData)) {
            let arrFilter [] = "role.name = :name:";
            let arrValues ["name"] = arrData["name"];
        }
        if (array_key_exists("role_code", arrData)) {
            let arrFilter [] = "role.role_code = :role_code:";
            let arrValues ["role_code"] = arrData["role_code"];
        }
        let filter = implode(" AND ", arrFilter);
        return (arrFilter) ? ["filter" : filter, "values" : arrValues] : ["filter" : "", "values" : []];
    }


    /**
     * @name getRoles - Get roles given the array of filter
     * @param array arrDataFilter - Array filter
     *              [create_at] - Date
     *              [start] - Start date
     *              [limit] - Limit items per page
     * @return array
     */
    public function getRoles(array arrDataFilter) -> array {
    	var getFilter, qbuild, roles;
        let getFilter = self::getFilter(arrDataFilter);
        let qbuild = this->getDI()->get("modelsManager")->createBuilder();

        if (getFilter) {
            if (array_key_exists("filter", getFilter) && getFilter["filter"]) {
                qbuild->where(getFilter["filter"]);
            }
        }
        let roles = qbuild->columns(["role.role_id", "role.name", "role.alias", "role.role_code", "role.description",
                "role.init_path"])
            ->addFrom("\Phady\Security\Bundle\Model\Entity\Roles", "role")
            ->getQuery()
            ->execute(getFilter["values"])
            ->toArray();

        return roles;
    }

    /**
     * @name getTotalRoles - Get total roles given the array of filter
     * @param array arrDataFilter - Array filter
     *              [create_at] - Date
     * @return array
     */
    public function getTotalRoles(array arrDataFilter) -> array {
    	var getFilter, qbuild, count;
        let getFilter = self::getFilter(arrDataFilter);
        let qbuild = this->getDI()->get("modelsManager")->createBuilder();

        if (getFilter) {
            if (array_key_exists("filter", getFilter) && getFilter["filter"]) {
                qbuild->where(getFilter["filter"]);
            }
        }
        let count = qbuild->columns(["COUNT(role.role_id) as total"])
            ->addFrom("\Phady\Security\Bundle\Model\Entity\Roles", "role")
            ->getQuery()
            ->execute(getFilter["values"])
            ->toArray();

        return count[0]["total"];
    }
}

