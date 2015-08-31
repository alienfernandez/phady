
extern zend_class_entry *phady_security_core_models_entities_roles_ce;

ZEPHIR_INIT_CLASS(Phady_Security_Core_Models_Entities_Roles);

PHP_METHOD(Phady_Security_Core_Models_Entities_Roles, initialize);
PHP_METHOD(Phady_Security_Core_Models_Entities_Roles, getSource);
PHP_METHOD(Phady_Security_Core_Models_Entities_Roles, init);

ZEPHIR_INIT_FUNCS(phady_security_core_models_entities_roles_method_entry) {
	PHP_ME(Phady_Security_Core_Models_Entities_Roles, initialize, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phady_Security_Core_Models_Entities_Roles, getSource, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phady_Security_Core_Models_Entities_Roles, init, NULL, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
