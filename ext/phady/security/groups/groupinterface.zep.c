
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * Phady\Security\Groups\GroupInterface
 *
 * Interface for Phady\Security\Groups
 */
ZEPHIR_INIT_CLASS(Phady_Security_Groups_GroupInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phady\\Security\\Groups, GroupInterface, phady, security_groups_groupinterface, phady_security_groups_groupinterface_method_entry);

	return SUCCESS;

}

/**
 * Add new role
 *
 * @param string role
 * @return self
 */
ZEPHIR_DOC_METHOD(Phady_Security_Groups_GroupInterface, addRole);

/**
 * Get Role Id
 *
 * @return integet
 */
ZEPHIR_DOC_METHOD(Phady_Security_Groups_GroupInterface, getId);

/**
 * Get Role Name
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phady_Security_Groups_GroupInterface, getName);

/**
 * Has a role
 *
 * @param string role
 * @return boolean
 */
ZEPHIR_DOC_METHOD(Phady_Security_Groups_GroupInterface, hasRole);

/**
 * Get All Roles
 *
 * @return array
 */
ZEPHIR_DOC_METHOD(Phady_Security_Groups_GroupInterface, getRoles);

/**
 * Remove a Role
 *
 * @return self
 */
ZEPHIR_DOC_METHOD(Phady_Security_Groups_GroupInterface, removeRole);

/**
 * Set a Role Name
 *
 * @param string name
 * @return self
 */
ZEPHIR_DOC_METHOD(Phady_Security_Groups_GroupInterface, setName);

/**
 * Set a Roles
 *
 * @return self
 */
ZEPHIR_DOC_METHOD(Phady_Security_Groups_GroupInterface, setRoles);

