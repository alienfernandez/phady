
extern zend_class_entry *phady_util_file_ce;

ZEPHIR_INIT_CLASS(Phady_Util_File);

PHP_METHOD(Phady_Util_File, downloadFile);
PHP_METHOD(Phady_Util_File, getContentType);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phady_util_file_downloadfile, 0, 0, 3)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, path)
	ZEND_ARG_INFO(0, type)
	ZEND_ARG_INFO(0, contentDisposition)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phady_util_file_getcontenttype, 0, 0, 1)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phady_util_file_method_entry) {
	PHP_ME(Phady_Util_File, downloadFile, arginfo_phady_util_file_downloadfile, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phady_Util_File, getContentType, arginfo_phady_util_file_getcontenttype, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
