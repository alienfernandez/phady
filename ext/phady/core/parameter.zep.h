
extern zend_class_entry *phady_core_parameter_ce;

ZEPHIR_INIT_CLASS(Phady_Core_Parameter);

PHP_METHOD(Phady_Core_Parameter, setParameter);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phady_core_parameter_setparameter, 0, 0, 2)
	ZEND_ARG_INFO(0, param)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phady_core_parameter_method_entry) {
	PHP_ME(Phady_Core_Parameter, setParameter, arginfo_phady_core_parameter_setparameter, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
