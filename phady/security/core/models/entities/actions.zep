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
 * Phady\Security\Models\Core\Entities\Actions
 *
 * Model for Actions
 */
class Actions extends \Phady\Common\Entities\ModelBase
{

    /**
	 * @Primary
	 * @var integer
	 */
	protected action_id;

    /**
	 * @var integer
	 */
	protected resource_id;

    /**
	 * @var string
	 */
	protected name;

    /**
	 * @var string
	 */
	protected alias;

	public function initialize() {

	}

	/**
	 * Physics returns the table name in the database engine
	 *
	 * @return string
	 */
	public function getSource() {
		return "phd_sec_actions";
	}

	/**
	 * Initializes the class. It assigns the attributes that can be obtained and modified.
	 */
	protected function init() {
		parent::init();
		array_push(this->_set, "action_id", "resource_id", "alias", "name");
		array_push(this->_get, "action_id", "resource_id", "alias", "name");
	}

}
