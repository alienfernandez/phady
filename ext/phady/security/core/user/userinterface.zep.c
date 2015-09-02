
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * Phady\Security\Core\User\UserInterface
 *
 * Interface
 */
ZEPHIR_INIT_CLASS(Phady_Security_Core_User_UserInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phady\\Security\\Core\\User, UserInterface, phady, security_core_user_userinterface, phady_security_core_user_userinterface_method_entry);

	return SUCCESS;

}

/**
 * Returns the roles granted to the user.
 *
 * <code>
 * public function getRoles()
 * {
 *     return array('ROLE_USER');
 * }
 * </code>
 *
 * Alternatively, the roles might be stored on a ``roles`` property,
 * and populated in any number of different ways when the user object
 * is created.
 *
 * @return Role[] The user roles
 */
ZEPHIR_DOC_METHOD(Phady_Security_Core_User_UserInterface, getRoles);

/**
 * Returns the password used to authenticate the user.
 *
 * This should be the encoded password. On authentication, a plain-text
 * password will be salted, encoded, and then compared to this value.
 *
 * @return string The password
 */
ZEPHIR_DOC_METHOD(Phady_Security_Core_User_UserInterface, getPassword);

/**
 * Returns the salt that was originally used to encode the password.
 *
 * This can return null if the password was not encoded using a salt.
 *
 * @return string|null The salt
 */
ZEPHIR_DOC_METHOD(Phady_Security_Core_User_UserInterface, getSalt);

/**
 * Returns the username used to authenticate the user.
 *
 * @return string The username
 */
ZEPHIR_DOC_METHOD(Phady_Security_Core_User_UserInterface, getUsername);

/**
 * Removes sensitive data from the user.
 *
 * This is important if, at any given point, sensitive information like
 * the plain-text password is stored on this object.
 */
ZEPHIR_DOC_METHOD(Phady_Security_Core_User_UserInterface, eraseCredentials);

