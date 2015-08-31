
extern zend_class_entry *phady_exception_ce;

ZEPHIR_INIT_CLASS(Phady_Exception);

PHP_METHOD(Phady_Exception, __toString);

ZEPHIR_INIT_FUNCS(phady_exception_method_entry) {
	PHP_ME(Phady_Exception, __toString, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
