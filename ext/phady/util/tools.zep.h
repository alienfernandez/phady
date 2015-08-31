
extern zend_class_entry *phady_util_tools_ce;

ZEPHIR_INIT_CLASS(Phady_Util_Tools);

PHP_METHOD(Phady_Util_Tools, getServerName);
PHP_METHOD(Phady_Util_Tools, getHttpHost);
PHP_METHOD(Phady_Util_Tools, getRequestProtocol);
PHP_METHOD(Phady_Util_Tools, getRemoteAddr);
PHP_METHOD(Phady_Util_Tools, usingSecureMode);
PHP_METHOD(Phady_Util_Tools, getMemoryLimit);
PHP_METHOD(Phady_Util_Tools, getOctets);
PHP_METHOD(Phady_Util_Tools, getHostName);
PHP_METHOD(Phady_Util_Tools, getUserAgent);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phady_util_tools_getoctets, 0, 0, 1)
	ZEND_ARG_INFO(0, option)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phady_util_tools_method_entry) {
	PHP_ME(Phady_Util_Tools, getServerName, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phady_Util_Tools, getHttpHost, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phady_Util_Tools, getRequestProtocol, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phady_Util_Tools, getRemoteAddr, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phady_Util_Tools, usingSecureMode, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phady_Util_Tools, getMemoryLimit, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phady_Util_Tools, getOctets, arginfo_phady_util_tools_getoctets, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phady_Util_Tools, getHostName, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phady_Util_Tools, getUserAgent, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
