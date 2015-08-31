
extern zend_class_entry *phady_security_calculator_ce;

ZEPHIR_INIT_CLASS(Phady_Security_Calculator);

PHP_METHOD(Phady_Security_Calculator, sum);
PHP_METHOD(Phady_Security_Calculator, doSomething);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phady_security_calculator_sum, 0, 0, 2)
	ZEND_ARG_INFO(0, a)
	ZEND_ARG_INFO(0, b)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phady_security_calculator_method_entry) {
	PHP_ME(Phady_Security_Calculator, sum, arginfo_phady_security_calculator_sum, ZEND_ACC_PUBLIC)
	PHP_ME(Phady_Security_Calculator, doSomething, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
  PHP_FE_END
};
