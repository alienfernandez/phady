
extern zend_class_entry *phady_core_kernel_ce;

ZEPHIR_INIT_CLASS(Phady_Core_Kernel);

PHP_METHOD(Phady_Core_Kernel, __construct);
PHP_METHOD(Phady_Core_Kernel, boot);
PHP_METHOD(Phady_Core_Kernel, initializeContainer);
PHP_METHOD(Phady_Core_Kernel, validateExternalLibrary);
PHP_METHOD(Phady_Core_Kernel, readConfigFiles);
PHP_METHOD(Phady_Core_Kernel, initializeNamespace);
PHP_METHOD(Phady_Core_Kernel, initializeDefaultService);
PHP_METHOD(Phady_Core_Kernel, getCoreParameters);
PHP_METHOD(Phady_Core_Kernel, getRootDir);
PHP_METHOD(Phady_Core_Kernel, setEnvironment);
PHP_METHOD(Phady_Core_Kernel, isDebug);
PHP_METHOD(Phady_Core_Kernel, getContainer);
PHP_METHOD(Phady_Core_Kernel, getCommand);
PHP_METHOD(Phady_Core_Kernel, getStartTime);
PHP_METHOD(Phady_Core_Kernel, getCacheDir);
PHP_METHOD(Phady_Core_Kernel, getLogDir);
PHP_METHOD(Phady_Core_Kernel, getCharset);
PHP_METHOD(Phady_Core_Kernel, shutdown);
PHP_METHOD(Phady_Core_Kernel, getEnvironment);
PHP_METHOD(Phady_Core_Kernel, getModules);
PHP_METHOD(Phady_Core_Kernel, serialize);
PHP_METHOD(Phady_Core_Kernel, unserialize);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phady_core_kernel___construct, 0, 0, 3)
	ZEND_ARG_INFO(0, environment)
	ZEND_ARG_INFO(0, debug)
	ZEND_ARG_INFO(0, scope)
	ZEND_ARG_ARRAY_INFO(0, modules, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phady_core_kernel_setenvironment, 0, 0, 1)
	ZEND_ARG_INFO(0, environment)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phady_core_kernel_unserialize, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phady_core_kernel_method_entry) {
	PHP_ME(Phady_Core_Kernel, __construct, arginfo_phady_core_kernel___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phady_Core_Kernel, boot, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phady_Core_Kernel, initializeContainer, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Phady_Core_Kernel, validateExternalLibrary, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Phady_Core_Kernel, readConfigFiles, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Phady_Core_Kernel, initializeNamespace, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Phady_Core_Kernel, initializeDefaultService, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Phady_Core_Kernel, getCoreParameters, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Phady_Core_Kernel, getRootDir, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phady_Core_Kernel, setEnvironment, arginfo_phady_core_kernel_setenvironment, ZEND_ACC_PUBLIC)
	PHP_ME(Phady_Core_Kernel, isDebug, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phady_Core_Kernel, getContainer, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phady_Core_Kernel, getCommand, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phady_Core_Kernel, getStartTime, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phady_Core_Kernel, getCacheDir, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phady_Core_Kernel, getLogDir, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phady_Core_Kernel, getCharset, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phady_Core_Kernel, shutdown, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phady_Core_Kernel, getEnvironment, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phady_Core_Kernel, getModules, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phady_Core_Kernel, serialize, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phady_Core_Kernel, unserialize, arginfo_phady_core_kernel_unserialize, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
