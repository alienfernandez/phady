
extern zend_class_entry *phady_security_users_userinterface_ce;

ZEPHIR_INIT_CLASS(Phady_Security_Users_UserInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phady_security_users_userinterface_setusername, 0, 0, 1)
	ZEND_ARG_INFO(0, username)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phady_security_users_userinterface_setusernamecanonical, 0, 0, 1)
	ZEND_ARG_INFO(0, usernameCanonical)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phady_security_users_userinterface_setemail, 0, 0, 1)
	ZEND_ARG_INFO(0, email)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phady_security_users_userinterface_setemailcanonical, 0, 0, 1)
	ZEND_ARG_INFO(0, emailCanonical)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phady_security_users_userinterface_setplainpassword, 0, 0, 1)
	ZEND_ARG_INFO(0, password)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phady_security_users_userinterface_setpassword, 0, 0, 1)
	ZEND_ARG_INFO(0, password)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phady_security_users_userinterface_setenabled, 0, 0, 1)
	ZEND_ARG_INFO(0, enabled)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phady_security_users_userinterface_setlocked, 0, 0, 1)
	ZEND_ARG_INFO(0, locked)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phady_security_users_userinterface_setsuperadmin, 0, 0, 1)
	ZEND_ARG_INFO(0, super)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phady_security_users_userinterface_setconfirmationtoken, 0, 0, 1)
	ZEND_ARG_INFO(0, confirmationToken)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phady_security_users_userinterface_setpasswordrequestedat, 0, 0, 0)
	ZEND_ARG_OBJ_INFO(0, date, DateTime, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phady_security_users_userinterface_ispasswordrequestnonexpired, 0, 0, 1)
	ZEND_ARG_INFO(0, ttl)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phady_security_users_userinterface_setlastlogin, 0, 0, 0)
	ZEND_ARG_OBJ_INFO(0, time, DateTime, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phady_security_users_userinterface_hasrole, 0, 0, 1)
	ZEND_ARG_INFO(0, role)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phady_security_users_userinterface_setroles, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, roles, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phady_security_users_userinterface_addrole, 0, 0, 1)
	ZEND_ARG_INFO(0, role)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phady_security_users_userinterface_removerole, 0, 0, 1)
	ZEND_ARG_INFO(0, role)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phady_security_users_userinterface_method_entry) {
	PHP_ABSTRACT_ME(Phady_Security_Users_UserInterface, setUsername, arginfo_phady_security_users_userinterface_setusername)
	PHP_ABSTRACT_ME(Phady_Security_Users_UserInterface, getUsernameCanonical, NULL)
	PHP_ABSTRACT_ME(Phady_Security_Users_UserInterface, setUsernameCanonical, arginfo_phady_security_users_userinterface_setusernamecanonical)
	PHP_ABSTRACT_ME(Phady_Security_Users_UserInterface, getEmail, NULL)
	PHP_ABSTRACT_ME(Phady_Security_Users_UserInterface, setEmail, arginfo_phady_security_users_userinterface_setemail)
	PHP_ABSTRACT_ME(Phady_Security_Users_UserInterface, getEmailCanonical, NULL)
	PHP_ABSTRACT_ME(Phady_Security_Users_UserInterface, setEmailCanonical, arginfo_phady_security_users_userinterface_setemailcanonical)
	PHP_ABSTRACT_ME(Phady_Security_Users_UserInterface, getPlainPassword, NULL)
	PHP_ABSTRACT_ME(Phady_Security_Users_UserInterface, setPlainPassword, arginfo_phady_security_users_userinterface_setplainpassword)
	PHP_ABSTRACT_ME(Phady_Security_Users_UserInterface, setPassword, arginfo_phady_security_users_userinterface_setpassword)
	PHP_ABSTRACT_ME(Phady_Security_Users_UserInterface, isSuperAdmin, NULL)
	PHP_ABSTRACT_ME(Phady_Security_Users_UserInterface, setEnabled, arginfo_phady_security_users_userinterface_setenabled)
	PHP_ABSTRACT_ME(Phady_Security_Users_UserInterface, setLocked, arginfo_phady_security_users_userinterface_setlocked)
	PHP_ABSTRACT_ME(Phady_Security_Users_UserInterface, setSuperAdmin, arginfo_phady_security_users_userinterface_setsuperadmin)
	PHP_ABSTRACT_ME(Phady_Security_Users_UserInterface, getConfirmationToken, NULL)
	PHP_ABSTRACT_ME(Phady_Security_Users_UserInterface, setConfirmationToken, arginfo_phady_security_users_userinterface_setconfirmationtoken)
	PHP_ABSTRACT_ME(Phady_Security_Users_UserInterface, setPasswordRequestedAt, arginfo_phady_security_users_userinterface_setpasswordrequestedat)
	PHP_ABSTRACT_ME(Phady_Security_Users_UserInterface, isPasswordRequestNonExpired, arginfo_phady_security_users_userinterface_ispasswordrequestnonexpired)
	PHP_ABSTRACT_ME(Phady_Security_Users_UserInterface, setLastLogin, arginfo_phady_security_users_userinterface_setlastlogin)
	PHP_ABSTRACT_ME(Phady_Security_Users_UserInterface, hasRole, arginfo_phady_security_users_userinterface_hasrole)
	PHP_ABSTRACT_ME(Phady_Security_Users_UserInterface, setRoles, arginfo_phady_security_users_userinterface_setroles)
	PHP_ABSTRACT_ME(Phady_Security_Users_UserInterface, addRole, arginfo_phady_security_users_userinterface_addrole)
	PHP_ABSTRACT_ME(Phady_Security_Users_UserInterface, removeRole, arginfo_phady_security_users_userinterface_removerole)
	PHP_FE_END
};
