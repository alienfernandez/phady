
extern zend_class_entry *phady_core_kernelmvc_ce;

ZEPHIR_INIT_CLASS(Phady_Core_KernelMvc);

PHP_METHOD(Phady_Core_KernelMvc, __construct);
PHP_METHOD(Phady_Core_KernelMvc, initializeModules);
PHP_METHOD(Phady_Core_KernelMvc, getApplication);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phady_core_kernelmvc___construct, 0, 0, 3)
	ZEND_ARG_INFO(0, environment)
	ZEND_ARG_INFO(0, debug)
	ZEND_ARG_INFO(0, scope)
	ZEND_ARG_ARRAY_INFO(0, modules, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phady_core_kernelmvc_method_entry) {
	PHP_ME(Phady_Core_KernelMvc, __construct, arginfo_phady_core_kernelmvc___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phady_Core_KernelMvc, initializeModules, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Phady_Core_KernelMvc, getApplication, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
