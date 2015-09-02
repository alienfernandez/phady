
extern zend_class_entry *phady_security_core_models_entities_modules_ce;

ZEPHIR_INIT_CLASS(Phady_Security_Core_Models_Entities_Modules);

PHP_METHOD(Phady_Security_Core_Models_Entities_Modules, initialize);
PHP_METHOD(Phady_Security_Core_Models_Entities_Modules, getSource);
PHP_METHOD(Phady_Security_Core_Models_Entities_Modules, init);

ZEPHIR_INIT_FUNCS(phady_security_core_models_entities_modules_method_entry) {
	PHP_ME(Phady_Security_Core_Models_Entities_Modules, initialize, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phady_Security_Core_Models_Entities_Modules, getSource, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phady_Security_Core_Models_Entities_Modules, init, NULL, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
