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
 * Phady\Security\Models\Core\Entities\Resources
 *
 * Model for Resources
 */
class Resources extends \Phady\Common\Entities\ModelBase
{

    /**
	 * @Primary
	 * @var integer
	 */
	protected resource_id;

    /**
	 * @Primary
	 * @var integer
	 */
	protected module_id;

    /**
	 * @var string
	 */
	protected name;

	public function initialize() {

	}

	/**
	 * Physics returns the table name in the database engine
	 *
	 * @return string
	 */
	public function getSource() {
		return "phd_sec_resources";
	}

	/**
	 * Initializes the class. It assigns the attributes that can be obtained and modified.
	 */
	protected function init() {
		parent::init();
		array_push(this->_set, "resource_id", "module_id", "name");
		array_push(this->_get, "resource_id", "module_id", "name");
	}

}
