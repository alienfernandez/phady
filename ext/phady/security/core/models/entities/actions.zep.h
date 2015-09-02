
extern zend_class_entry *phady_security_core_models_entities_actions_ce;

ZEPHIR_INIT_CLASS(Phady_Security_Core_Models_Entities_Actions);

PHP_METHOD(Phady_Security_Core_Models_Entities_Actions, initialize);
PHP_METHOD(Phady_Security_Core_Models_Entities_Actions, getSource);
PHP_METHOD(Phady_Security_Core_Models_Entities_Actions, init);

ZEPHIR_INIT_FUNCS(phady_security_core_models_entities_actions_method_entry) {
	PHP_ME(Phady_Security_Core_Models_Entities_Actions, initialize, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phady_Security_Core_Models_Entities_Actions, getSource, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phady_Security_Core_Models_Entities_Actions, init, NULL, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
