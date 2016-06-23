
extern zend_class_entry *phady_messaging_messaging_ce;

ZEPHIR_INIT_CLASS(Phady_Messaging_Messaging);

PHP_METHOD(Phady_Messaging_Messaging, getConnection);
PHP_METHOD(Phady_Messaging_Messaging, getMessagingAdapter);

ZEPHIR_INIT_FUNCS(phady_messaging_messaging_method_entry) {
	PHP_ME(Phady_Messaging_Messaging, getConnection, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phady_Messaging_Messaging, getMessagingAdapter, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
