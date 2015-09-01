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

namespace Phady\Security\Groups;

/**
 * Phady\Security\Groups\GroupInterface
 *
 * Interface for Phady\Security\Groups
 */
interface GroupInterface
{

	/**
	 * Add new role
	 *
	 * @param string role
	 * @return self
	 */
	public function addRole(role);

	/**
	* Get Role Id
	*
	* @return integet
	*/
	public function getId();

	/**
	* Get Role Name
	*
	* @return string
	*/
	public function getName();


	/**
	* Has a role
	*
	* @param string role
	* @return boolean
	*/
	public function hasRole(role);

	/**
	* Get All Roles
	*
	* @return array
	*/
	public function getRoles();

	/**
	* Remove a Role
	*
	* @return self
	*/
	public function removeRole(role);

	/**
	* Set a Role Name
	*
    * @param string name
	* @return self
	*/
	public function setName(name);

	/**
	* Set a Roles
	*
	* @return self
	*/
	public function setRoles(array roles);

}
