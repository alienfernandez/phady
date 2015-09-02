
extern zend_class_entry *phady_security_core_models_entities_userrole_ce;

ZEPHIR_INIT_CLASS(Phady_Security_Core_Models_Entities_UserRole);

PHP_METHOD(Phady_Security_Core_Models_Entities_UserRole, initialize);
PHP_METHOD(Phady_Security_Core_Models_Entities_UserRole, getSource);
PHP_METHOD(Phady_Security_Core_Models_Entities_UserRole, init);

ZEPHIR_INIT_FUNCS(phady_security_core_models_entities_userrole_method_entry) {
	PHP_ME(Phady_Security_Core_Models_Entities_UserRole, initialize, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phady_Security_Core_Models_Entities_UserRole, getSource, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phady_Security_Core_Models_Entities_UserRole, init, NULL, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
