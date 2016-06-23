
extern zend_class_entry *phady_messaging_adapter_messaginginterface_ce;

ZEPHIR_INIT_CLASS(Phady_Messaging_Adapter_MessagingInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phady_messaging_adapter_messaginginterface_sendmessagedirect, 0, 0, 4)
	ZEND_ARG_INFO(0, queue)
	ZEND_ARG_INFO(0, exchange)
	ZEND_ARG_INFO(0, msg)
	ZEND_ARG_INFO(0, msgOptions)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phady_messaging_adapter_messaginginterface_getmessage, 0, 0, 2)
	ZEND_ARG_INFO(0, datam)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phady_messaging_adapter_messaginginterface_method_entry) {
	PHP_ABSTRACT_ME(Phady_Messaging_Adapter_MessagingInterface, getAdapter, NULL)
	PHP_ABSTRACT_ME(Phady_Messaging_Adapter_MessagingInterface, sendMessageDirect, arginfo_phady_messaging_adapter_messaginginterface_sendmessagedirect)
	PHP_ABSTRACT_ME(Phady_Messaging_Adapter_MessagingInterface, getMessage, arginfo_phady_messaging_adapter_messaginginterface_getmessage)
	PHP_FE_END
};
