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

namespace Phady\Security\Core\Models\Repositories;

/**
 * Phady\Security\Core\Models\Repositories\Users
 *
 * Repository for Users
 */
class Users extends \Phalcon\DI\Injectable
{

    // Returns the filter for searches
	static public function getFilter(arrData, select = false) {
		var arrFilter, arrValues, filter;
		let arrFilter = [];
		let arrValues = [];

		if (array_key_exists("user_id", arrData)) {
			let arrFilter [] = "user.user_id = :user_id:";
			let arrValues ["user_id"] = arrData["user_id"];
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
        let users = qbuild->columns(["user.user_id", "user.username", "user.enabled", "user.salt", "user.salt_expiration_date",
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
        let count = qbuild->columns(["COUNT(user.user_id) as total"])
            ->addFrom("\Phady\Security\Core\Models\Entities\Users", "user")
            ->getQuery()
            ->execute(getFilter["values"])
            ->toArray();

        return count[0]["total"];
    }

}
