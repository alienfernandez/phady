
extern zend_class_entry *phady_config_yaml_ce;

ZEPHIR_INIT_CLASS(Phady_Config_Yaml);

PHP_METHOD(Phady_Config_Yaml, parse);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phady_config_yaml_parse, 0, 0, 1)
	ZEND_ARG_INFO(0, filePath)
	ZEND_ARG_ARRAY_INFO(0, callbacks, 1)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phady_config_yaml_method_entry) {
	PHP_ME(Phady_Config_Yaml, parse, arginfo_phady_config_yaml_parse, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
