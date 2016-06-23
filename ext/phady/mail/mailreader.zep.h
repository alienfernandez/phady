
extern zend_class_entry *phady_mail_mailreader_ce;

ZEPHIR_INIT_CLASS(Phady_Mail_MailReader);

PHP_METHOD(Phady_Mail_MailReader, __construct);
PHP_METHOD(Phady_Mail_MailReader, setConnection);
PHP_METHOD(Phady_Mail_MailReader, readMessageByFilter);
PHP_METHOD(Phady_Mail_MailReader, getRecDate);
PHP_METHOD(Phady_Mail_MailReader, containsFromAddress);
PHP_METHOD(Phady_Mail_MailReader, getMessage);
PHP_METHOD(Phady_Mail_MailReader, getMessagePart);
PHP_METHOD(Phady_Mail_MailReader, parseMessage);
PHP_METHOD(Phady_Mail_MailReader, makeResult);
PHP_METHOD(Phady_Mail_MailReader, getUnreadMessages);
static zend_object_value zephir_init_properties_Phady_Mail_MailReader(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phady_mail_mailreader___construct, 0, 0, 2)
	ZEND_ARG_INFO(0, username)
	ZEND_ARG_INFO(0, password)
	ZEND_ARG_INFO(0, mailserver)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phady_mail_mailreader_readmessagebyfilter, 0, 0, 3)
	ZEND_ARG_INFO(0, userInput)
	ZEND_ARG_INFO(0, filterType)
	ZEND_ARG_INFO(0, flag)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phady_mail_mailreader_getrecdate, 0, 0, 1)
	ZEND_ARG_INFO(0, date)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phady_mail_mailreader_containsfromaddress, 0, 0, 2)
	ZEND_ARG_INFO(0, fromAddresses)
	ZEND_ARG_INFO(0, userInput)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phady_mail_mailreader_getmessage, 0, 0, 1)
	ZEND_ARG_INFO(0, messageId)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phady_mail_mailreader_getmessagepart, 0, 0, 3)
	ZEND_ARG_INFO(0, messageId)
	ZEND_ARG_INFO(0, partObj)
	ZEND_ARG_INFO(0, partno)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phady_mail_mailreader_parsemessage, 0, 0, 1)
	ZEND_ARG_INFO(0, messageId)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phady_mail_mailreader_method_entry) {
	PHP_ME(Phady_Mail_MailReader, __construct, arginfo_phady_mail_mailreader___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phady_Mail_MailReader, setConnection, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phady_Mail_MailReader, readMessageByFilter, arginfo_phady_mail_mailreader_readmessagebyfilter, ZEND_ACC_PUBLIC)
	PHP_ME(Phady_Mail_MailReader, getRecDate, arginfo_phady_mail_mailreader_getrecdate, ZEND_ACC_PRIVATE)
	PHP_ME(Phady_Mail_MailReader, containsFromAddress, arginfo_phady_mail_mailreader_containsfromaddress, ZEND_ACC_PRIVATE)
	PHP_ME(Phady_Mail_MailReader, getMessage, arginfo_phady_mail_mailreader_getmessage, ZEND_ACC_PUBLIC)
	PHP_ME(Phady_Mail_MailReader, getMessagePart, arginfo_phady_mail_mailreader_getmessagepart, ZEND_ACC_PUBLIC)
	PHP_ME(Phady_Mail_MailReader, parseMessage, arginfo_phady_mail_mailreader_parsemessage, ZEND_ACC_PUBLIC)
	PHP_ME(Phady_Mail_MailReader, makeResult, NULL, ZEND_ACC_PRIVATE)
	PHP_ME(Phady_Mail_MailReader, getUnreadMessages, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
