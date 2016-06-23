
extern zend_class_entry *phady_security_core_models_entities_users_ce;

ZEPHIR_INIT_CLASS(Phady_Security_Core_Models_Entities_Users);

PHP_METHOD(Phady_Security_Core_Models_Entities_Users, initialize);
PHP_METHOD(Phady_Security_Core_Models_Entities_Users, getSource);
PHP_METHOD(Phady_Security_Core_Models_Entities_Users, init);

ZEPHIR_INIT_FUNCS(phady_security_core_models_entities_users_method_entry) {
	PHP_ME(Phady_Security_Core_Models_Entities_Users, initialize, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phady_Security_Core_Models_Entities_Users, getSource, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phady_Security_Core_Models_Entities_Users, init, NULL, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
