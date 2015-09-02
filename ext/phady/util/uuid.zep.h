
extern zend_class_entry *phady_util_uuid_ce;

ZEPHIR_INIT_CLASS(Phady_Util_Uuid);

PHP_METHOD(Phady_Util_Uuid, v1);
PHP_METHOD(Phady_Util_Uuid, v4);
PHP_METHOD(Phady_Util_Uuid, v5);
PHP_METHOD(Phady_Util_Uuid, is_valid);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phady_util_uuid_v5, 0, 0, 2)
	ZEND_ARG_INFO(0, ns)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phady_util_uuid_is_valid, 0, 0, 1)
	ZEND_ARG_INFO(0, uuid)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phady_util_uuid_method_entry) {
	PHP_ME(Phady_Util_Uuid, v1, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phady_Util_Uuid, v4, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phady_Util_Uuid, v5, arginfo_phady_util_uuid_v5, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phady_Util_Uuid, is_valid, arginfo_phady_util_uuid_is_valid, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
