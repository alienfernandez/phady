
extern zend_class_entry *phady_security_authentication_authhandler_ce;

ZEPHIR_INIT_CLASS(Phady_Security_Authentication_AuthHandler);

PHP_METHOD(Phady_Security_Authentication_AuthHandler, __construct);
PHP_METHOD(Phady_Security_Authentication_AuthHandler, checkCredentials);
PHP_METHOD(Phady_Security_Authentication_AuthHandler, checkUserFlags);
PHP_METHOD(Phady_Security_Authentication_AuthHandler, getDataSession);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phady_security_authentication_authhandler___construct, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, configSecurity, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phady_security_authentication_authhandler_checkcredentials, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, credentials, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phady_security_authentication_authhandler_checkuserflags, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, user, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phady_security_authentication_authhandler_getdatasession, 0, 0, 2)
	ZEND_ARG_ARRAY_INFO(0, userData, 0)
	ZEND_ARG_INFO(0, user)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phady_security_authentication_authhandler_method_entry) {
	PHP_ME(Phady_Security_Authentication_AuthHandler, __construct, arginfo_phady_security_authentication_authhandler___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phady_Security_Authentication_AuthHandler, checkCredentials, arginfo_phady_security_authentication_authhandler_checkcredentials, ZEND_ACC_PUBLIC)
	PHP_ME(Phady_Security_Authentication_AuthHandler, checkUserFlags, arginfo_phady_security_authentication_authhandler_checkuserflags, ZEND_ACC_PUBLIC)
	PHP_ME(Phady_Security_Authentication_AuthHandler, getDataSession, arginfo_phady_security_authentication_authhandler_getdatasession, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
