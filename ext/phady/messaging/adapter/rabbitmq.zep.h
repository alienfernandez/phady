
extern zend_class_entry *phady_messaging_adapter_rabbitmq_ce;

ZEPHIR_INIT_CLASS(Phady_Messaging_Adapter_RabbitMQ);

PHP_METHOD(Phady_Messaging_Adapter_RabbitMQ, __construct);
PHP_METHOD(Phady_Messaging_Adapter_RabbitMQ, getConnection);
PHP_METHOD(Phady_Messaging_Adapter_RabbitMQ, getAdapter);
PHP_METHOD(Phady_Messaging_Adapter_RabbitMQ, sendMessageDirect);
PHP_METHOD(Phady_Messaging_Adapter_RabbitMQ, getMessage);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phady_messaging_adapter_rabbitmq___construct, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, config, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phady_messaging_adapter_rabbitmq_sendmessagedirect, 0, 0, 4)
	ZEND_ARG_INFO(0, queue)
	ZEND_ARG_INFO(0, exchange)
	ZEND_ARG_INFO(0, msg)
	ZEND_ARG_INFO(0, msgOptions)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phady_messaging_adapter_rabbitmq_getmessage, 0, 0, 2)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phady_messaging_adapter_rabbitmq_method_entry) {
	PHP_ME(Phady_Messaging_Adapter_RabbitMQ, __construct, arginfo_phady_messaging_adapter_rabbitmq___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phady_Messaging_Adapter_RabbitMQ, getConnection, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phady_Messaging_Adapter_RabbitMQ, getAdapter, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phady_Messaging_Adapter_RabbitMQ, sendMessageDirect, arginfo_phady_messaging_adapter_rabbitmq_sendmessagedirect, ZEND_ACC_PUBLIC)
	PHP_ME(Phady_Messaging_Adapter_RabbitMQ, getMessage, arginfo_phady_messaging_adapter_rabbitmq_getmessage, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
