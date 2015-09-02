
extern zend_class_entry *phady_security_core_user_userinterface_ce;

ZEPHIR_INIT_CLASS(Phady_Security_Core_User_UserInterface);

ZEPHIR_INIT_FUNCS(phady_security_core_user_userinterface_method_entry) {
	PHP_ABSTRACT_ME(Phady_Security_Core_User_UserInterface, getRoles, NULL)
	PHP_ABSTRACT_ME(Phady_Security_Core_User_UserInterface, getPassword, NULL)
	PHP_ABSTRACT_ME(Phady_Security_Core_User_UserInterface, getSalt, NULL)
	PHP_ABSTRACT_ME(Phady_Security_Core_User_UserInterface, getUsername, NULL)
	PHP_ABSTRACT_ME(Phady_Security_Core_User_UserInterface, eraseCredentials, NULL)
	PHP_FE_END
};
