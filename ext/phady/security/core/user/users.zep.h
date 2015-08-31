
extern zend_class_entry *phady_security_core_user_users_ce;

ZEPHIR_INIT_CLASS(Phady_Security_Core_User_Users);

PHP_METHOD(Phady_Security_Core_User_Users, getUsers);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phady_security_core_user_users_getusers, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, arrDataFilter, 0)
	ZEND_ARG_INFO(0, getTotal)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phady_security_core_user_users_method_entry) {
	PHP_ME(Phady_Security_Core_User_Users, getUsers, arginfo_phady_security_core_user_users_getusers, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
