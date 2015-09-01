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

namespace Phady\Security\Core\Models\Entities;

/**
 * Phady\Security\Models\Core\Entities\UserRole
 *
 * Model for Users relation Roles
 */
class UserRole extends \Phady\Common\Entities\ModelBase
{

    /**
	 * @Primary
	 * @var integer
	 */
	protected user_role_id;

    /**
	 * @var integer
	 */
	protected role_id;

    /**
	 * @var integer
	 */
	protected user_id;

	public function initialize() {
		this->belongsTo("role_id", "Phady\Security\Models\Core\Entities\Roles", "role_id", ["alias" : "Roles"]);
		this->belongsTo("user_id", "Phady\Security\Models\Core\Entities\Users", "user_id", ["alias" : "Users"]);
	}

	/**
	 * Physics returns the table name in the database engine
	 *
	 * @return string
	 */
	public function getSource() {
		return "phd_sec_user_role";
	}

	/**
	 * Initializes the class. It assigns the attributes that can be obtained and modified.
	 */
	protected function init() {
		parent::init();
		array_push(this->_set, "user_role_id", "role_id", "user_id");
		array_push(this->_get, "user_role_id", "role_id", "user_id");
	}

}
