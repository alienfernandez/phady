
extern zend_class_entry *phady_core_namespacehandler_ce;

ZEPHIR_INIT_CLASS(Phady_Core_NamespaceHandler);

PHP_METHOD(Phady_Core_NamespaceHandler, __construct);
PHP_METHOD(Phady_Core_NamespaceHandler, setModulesNamespace);
PHP_METHOD(Phady_Core_NamespaceHandler, getAllNamespaceApp);
static zend_object_value zephir_init_properties_Phady_Core_NamespaceHandler(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phady_core_namespacehandler___construct, 0, 0, 2)
	ZEND_ARG_INFO(0, scope)
	ZEND_ARG_INFO(0, rootDir)
	ZEND_ARG_ARRAY_INFO(0, modules, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phady_core_namespacehandler_setmodulesnamespace, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, modules, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phady_core_namespacehandler_method_entry) {
	PHP_ME(Phady_Core_NamespaceHandler, __construct, arginfo_phady_core_namespacehandler___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phady_Core_NamespaceHandler, setModulesNamespace, arginfo_phady_core_namespacehandler_setmodulesnamespace, ZEND_ACC_PUBLIC)
	PHP_ME(Phady_Core_NamespaceHandler, getAllNamespaceApp, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
