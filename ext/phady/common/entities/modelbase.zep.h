
extern zend_class_entry *phady_common_entities_modelbase_ce;

ZEPHIR_INIT_CLASS(Phady_Common_Entities_ModelBase);

PHP_METHOD(Phady_Common_Entities_ModelBase, onConstruct);
PHP_METHOD(Phady_Common_Entities_ModelBase, init);
PHP_METHOD(Phady_Common_Entities_ModelBase, __set);
PHP_METHOD(Phady_Common_Entities_ModelBase, __get);
PHP_METHOD(Phady_Common_Entities_ModelBase, beforeValidationOnCreate);
PHP_METHOD(Phady_Common_Entities_ModelBase, beforeUpdate);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phady_common_entities_modelbase___set, 0, 0, 2)
	ZEND_ARG_INFO(0, attribute)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phady_common_entities_modelbase___get, 0, 0, 1)
	ZEND_ARG_INFO(0, attribute)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phady_common_entities_modelbase_method_entry) {
	PHP_ME(Phady_Common_Entities_ModelBase, onConstruct, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phady_Common_Entities_ModelBase, init, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Phady_Common_Entities_ModelBase, __set, arginfo_phady_common_entities_modelbase___set, ZEND_ACC_PUBLIC)
	PHP_ME(Phady_Common_Entities_ModelBase, __get, arginfo_phady_common_entities_modelbase___get, ZEND_ACC_PUBLIC)
	PHP_ME(Phady_Common_Entities_ModelBase, beforeValidationOnCreate, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phady_Common_Entities_ModelBase, beforeUpdate, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
