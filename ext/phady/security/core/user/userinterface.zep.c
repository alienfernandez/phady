
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * Phady\Security\Users\UserInterface
 *
 * Interface for Phady\Security\Users
 */
ZEPHIR_INIT_CLASS(Phady_Security_Core_User_UserInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phady\\Security\\Core\\User, UserInterface, phady, security_core_user_userinterface, phady_security_core_user_userinterface_method_entry);

	zend_declare_class_constant_string(phady_security_core_user_userinterface_ce, SL("ROLE_DEFAULT"), "ROLE_USER" TSRMLS_CC);

	zend_declare_class_constant_string(phady_security_core_user_userinterface_ce, SL("ROLE_SUPER_ADMIN"), "ROLE_SUPER_ADMIN" TSRMLS_CC);

	return SUCCESS;

}

/**
 * Set a User Name
 *
 * @param string username
 * @return self
 */
ZEPHIR_DOC_METHOD(Phady_Security_Core_User_UserInterface, setUsername);

/**
 * Gets the canonical username in search and sort queries.
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phady_Security_Core_User_UserInterface, getUsernameCanonical);

/**
 * Sets the canonical username.
 *
 * @param string usernameCanonical
 *
 * @return self
 */
ZEPHIR_DOC_METHOD(Phady_Security_Core_User_UserInterface, setUsernameCanonical);

/**
 * Gets email.
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phady_Security_Core_User_UserInterface, getEmail);

/**
 * Sets the email.
 *
 * @param string email
 *
 * @return self
 */
ZEPHIR_DOC_METHOD(Phady_Security_Core_User_UserInterface, setEmail);

/**
 * Gets the canonical email in search and sort queries.
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phady_Security_Core_User_UserInterface, getEmailCanonical);

/**
 * Sets the canonical email.
 *
 * @param string emailCanonical
 *
 * @return self
 */
ZEPHIR_DOC_METHOD(Phady_Security_Core_User_UserInterface, setEmailCanonical);

/**
 * Gets the plain password.
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phady_Security_Core_User_UserInterface, getPlainPassword);

/**
 * Sets the plain password.
 *
 * @param string password
 *
 * @return self
 */
ZEPHIR_DOC_METHOD(Phady_Security_Core_User_UserInterface, setPlainPassword);

/**
 * Sets the hashed password.
 *
 * @param string password
 *
 * @return self
 */
ZEPHIR_DOC_METHOD(Phady_Security_Core_User_UserInterface, setPassword);

/**
 * Tells if the the given user has the super admin role.
 *
 * @return boolean
 */
ZEPHIR_DOC_METHOD(Phady_Security_Core_User_UserInterface, isSuperAdmin);

/**
 * @param boolean enabled
 *
 * @return self
 */
ZEPHIR_DOC_METHOD(Phady_Security_Core_User_UserInterface, setEnabled);

/**
 * Sets the locking status of the user.
 *
 * @param boolean locked
 *
 * @return self
 */
ZEPHIR_DOC_METHOD(Phady_Security_Core_User_UserInterface, setLocked);

/**
 * Sets the super admin status
 *
 * @param boolean super
 *
 * @return self
 */
ZEPHIR_DOC_METHOD(Phady_Security_Core_User_UserInterface, setSuperAdmin);

/**
 * Gets the confirmation token.
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phady_Security_Core_User_UserInterface, getConfirmationToken);

/**
 * Sets the confirmation token
 *
 * @param string confirmationToken
 *
 * @return self
 */
ZEPHIR_DOC_METHOD(Phady_Security_Core_User_UserInterface, setConfirmationToken);

/**
 * Sets the timestamp that the user requested a password reset.
 *
 * @param null|\DateTime date
 *
 * @return self
 */
ZEPHIR_DOC_METHOD(Phady_Security_Core_User_UserInterface, setPasswordRequestedAt);

/**
 * Checks whether the password reset request has expired.
 *
 * @param integer ttl Requests older than this many seconds will be considered expired
 *
 * @return boolean true if the user's password request is non expired, false otherwise
 */
ZEPHIR_DOC_METHOD(Phady_Security_Core_User_UserInterface, isPasswordRequestNonExpired);

/**
 * Sets the last login time
 *
 * @param \DateTime time
 *
 * @return self
 */
ZEPHIR_DOC_METHOD(Phady_Security_Core_User_UserInterface, setLastLogin);

/**
 * Never use this to check if this user has access to anything!
 *
 * Use the SecurityContext, or an implementation of AccessDecisionManager
 * instead, e.g.
 *
 *  securityContext->isGranted('ROLE_USER');
 *
 * @param string role
 *
 * @return boolean
 */
ZEPHIR_DOC_METHOD(Phady_Security_Core_User_UserInterface, hasRole);

/**
 * Sets the roles of the user.
 *
 * This overwrites any previous roles.
 *
 * @param array roles
 *
 * @return self
 */
ZEPHIR_DOC_METHOD(Phady_Security_Core_User_UserInterface, setRoles);

/**
 * Adds a role to the user.
 *
 * @param string role
 *
 * @return self
 */
ZEPHIR_DOC_METHOD(Phady_Security_Core_User_UserInterface, addRole);

/**
 * Removes a role to the user.
 *
 * @param string role
 *
 * @return self
 */
ZEPHIR_DOC_METHOD(Phady_Security_Core_User_UserInterface, removeRole);

