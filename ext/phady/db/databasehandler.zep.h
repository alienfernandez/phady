
extern zend_class_entry *phady_db_databasehandler_ce;

ZEPHIR_INIT_CLASS(Phady_Db_DatabaseHandler);

PHP_METHOD(Phady_Db_DatabaseHandler, __construct);
PHP_METHOD(Phady_Db_DatabaseHandler, getAdapter);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phady_db_databasehandler___construct, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, config, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phady_db_databasehandler_method_entry) {
	PHP_ME(Phady_Db_DatabaseHandler, __construct, arginfo_phady_db_databasehandler___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phady_Db_DatabaseHandler, getAdapter, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
