
extern zend_class_entry *phady_security_authorization_acl_ce;

ZEPHIR_INIT_CLASS(Phady_Security_Authorization_Acl);

PHP_METHOD(Phady_Security_Authorization_Acl, __construct);
PHP_METHOD(Phady_Security_Authorization_Acl, isPrivate);
PHP_METHOD(Phady_Security_Authorization_Acl, isAllowed);
PHP_METHOD(Phady_Security_Authorization_Acl, getAcl);
PHP_METHOD(Phady_Security_Authorization_Acl, loadResources);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phady_security_authorization_acl_isprivate, 0, 0, 1)
	ZEND_ARG_INFO(0, controllerName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phady_security_authorization_acl_isallowed, 0, 0, 3)
	ZEND_ARG_INFO(0, rol)
	ZEND_ARG_INFO(0, controller)
	ZEND_ARG_INFO(0, action)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phady_security_authorization_acl_method_entry) {
	PHP_ME(Phady_Security_Authorization_Acl, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phady_Security_Authorization_Acl, isPrivate, arginfo_phady_security_authorization_acl_isprivate, ZEND_ACC_PUBLIC)
	PHP_ME(Phady_Security_Authorization_Acl, isAllowed, arginfo_phady_security_authorization_acl_isallowed, ZEND_ACC_PUBLIC)
	PHP_ME(Phady_Security_Authorization_Acl, getAcl, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phady_Security_Authorization_Acl, loadResources, NULL, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
