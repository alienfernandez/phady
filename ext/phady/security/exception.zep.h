
extern zend_class_entry *phady_security_exception_ce;

ZEPHIR_INIT_CLASS(Phady_Security_Exception);

PHP_METHOD(Phady_Security_Exception, __toString);

ZEPHIR_INIT_FUNCS(phady_security_exception_method_entry) {
	PHP_ME(Phady_Security_Exception, __toString, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
