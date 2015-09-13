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

namespace Phady\Security\Bundle\Model\Entity;

/**
 * Phady\Security\Bundle\Model\Entity\Roles
 *
 * Model for Users
 */
class Roles extends \Phady\Common\Entities\ModelBase
{

    /**
	 * @Primary
	 * @var integer
	 */
	protected role_id;

    /**
	 * @var string
	 */
	protected name;

    /**
	 * @var string
	 */
	protected alias;

    /**
	 * @var string
	 */
	protected description;

    /**
	 * @var string
	 */
	protected role_code;

    /**
	 * @var string
	 */
	protected init_path;

	public function initialize() {

	}

	/**
	 * Physics returns the table name in the database engine
	 *
	 * @return string
	 */
	public function getSource() {
		return "phd_security_roles";
	}

	/**
	 * Initializes the class. It assigns the attributes that can be obtained and modified.
	 */
	protected function init() {
		parent::init();
		array_push(this->_set, "role_id", "name", "alias", "description", "role_code", "init_path");
		array_push(this->_get, "role_id", "name", "alias", "description", "role_code", "init_path");
	}

}
