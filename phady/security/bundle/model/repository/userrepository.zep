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
  * @class Phady\Security\Bundle\Model\Repository\UserRepository
  *
  * @author  Alien Fernández Fuentes <alienfernandez85@gmail.com>
  * @package Core
  * @copyright (c) 2015
  * @version 1.0.0
  */
class UserRepository extends \Phalcon\DI\Injectable
{

    // Get search filter
    static public function getFilter(array arrData, select = false) {
        var arrFilter, arrValues, search, filter;
        let arrFilter = [];
        let arrValues = [];

        if (array_key_exists("search", arrData) && arrData["search"]["value"]) {
            if (select) {
                let arrFilter [] = "(user.username iLIKE :search:)";
            }
            else {
                let arrFilter [] = "(user.username iLIKE :search:)";
            }
            let search = strtolower(arrData["search"]["value"]);
            //Para que en el filtro no busque dentro de una subcadena
            let arrValues ["search"] = (array_key_exists("nocontiene", arrData)) ? search : "%{". search . "}%";
        }

        if (array_key_exists("id", arrData)) {
            let arrFilter [] = "user.id = :id:";
            let arrValues ["id"] = arrData["id"];
        }
        if (array_key_exists("salt", arrData)) {
            let arrFilter [] = "user.salt = :salt:";
            let arrValues ["salt"] = arrData["salt"];
        }
        let filter = implode(" AND ", arrFilter);
        return (arrFilter) ? ["filter" : filter, "values" : arrValues] : ["filter" : "", "values" : []];
    }


    /**
     * @name getUsers - Get users given the array of filter
     * @param array arrDataFilter - Array filter
     *              [create_at] - Date
     *              [start] - Start date
     *              [limit] - Limit items per page
     * @return array
     */
    public function getUsers(array arrDataFilter) -> array {
    	var getFilter, qbuild, users;
        let getFilter = self::getFilter(arrDataFilter);
        let qbuild = this->getDI()->get("modelsManager")->createBuilder();

        if (getFilter) {
            if (array_key_exists("filter", getFilter) && getFilter["filter"]) {
                qbuild->where(getFilter["filter"]);
            }
        }
        let users = qbuild->columns(["user.id", "user.username", "user.enabled", "user.salt",
                "user.email"])
            ->addFrom("\Phady\Security\Core\Models\Entities\Users", "user")
            ->getQuery()
            ->execute(getFilter["values"])
            ->toArray();

        return users;
    }

    /**
     * @name getTotalUsers - Get total users given the array of filter
     * @param array arrDataFilter - Array filter
     *              [create_at] - Date
     * @return array
     */
    public function getTotalUsers(array arrDataFilter) -> array {
    	var getFilter, qbuild, count;
        let getFilter = self::getFilter(arrDataFilter);
        let qbuild = this->getDI()->get("modelsManager")->createBuilder();

        if (getFilter) {
            if (array_key_exists("filter", getFilter) && getFilter["filter"]) {
                qbuild->where(getFilter["filter"]);
            }
        }
        let count = qbuild->columns(["COUNT(user.id) as total"])
            ->addFrom("\Phady\Security\Core\Models\Entities\Users", "user")
            ->getQuery()
            ->execute(getFilter["values"])
            ->toArray();

        return count[0]["total"];
    }
}

