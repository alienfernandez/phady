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
 * Phady\Security\Models\Core\Entities\Users
 *
 * Model for Users
 */
class Users extends \Phady\Common\Entities\ModelBase
{

    /**
	 * @Primary
	 * @var integer
	 */
	protected user_id;

    /**
	 * @var string
	 */
	protected firstname;

    /**
	 * @var string
	 */
	protected lastname;

    /**
	 * @var string
	 */
	protected username;

    /**
	 * @var string
	 */
	protected username_canonical;

    /**
	 * @var string
	 */
	protected email;

    /**
	 * @var string
	 */
	protected email_canonical;

    /**
	 * @var numeric(1)
	 */
	protected enabled;

    /**
	 * @var string
	 */
	protected salt;

    /**
	 * @var string
	 */
	protected salt_expiration_date;

	/**
	 *
	 * @var string
	 */
	protected password;

	/**
	 *
	 * @var datetime
	 */
	protected last_login;

	public function initialize() {

	}

	/**
	 * Physics returns the table name in the database engine
	 *
	 * @return string
	 */
	public function getSource() {
		return "phd_sec_users";
	}

	/**
	 * Initializes the class. It assigns the attributes that can be obtained and modified.
	 */
	protected function init() {
		parent::init();
		array_push(this->_set, "user_id", "firstname", "lastname", "username", "username_canonical", "email",
		 		"email_canonical", "enabled", "salt", "salt_expiration_date", "password", "last_login");
		array_push(this->_get, "user_id", "firstname", "lastname", "username", "username_canonical", "email",
				"email_canonical", "enabled", "salt", "salt_expiration_date", "password", "last_login");
	}

}
