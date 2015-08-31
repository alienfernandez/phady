
extern zend_class_entry *phady_security_core_models_exception_ce;

ZEPHIR_INIT_CLASS(Phady_Security_Core_Models_Exception);

PHP_METHOD(Phady_Security_Core_Models_Exception, __toString);

ZEPHIR_INIT_FUNCS(phady_security_core_models_exception_method_entry) {
	PHP_ME(Phady_Security_Core_Models_Exception, __toString, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
