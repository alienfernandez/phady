
extern zend_class_entry *phady_util_out_ce;

ZEPHIR_INIT_CLASS(Phady_Util_Out);

PHP_METHOD(Phady_Util_Out, dump);
PHP_METHOD(Phady_Util_Out, var_dump_plain);
PHP_METHOD(Phady_Util_Out, htmlentities);
PHP_METHOD(Phady_Util_Out, mbInternalEncoding);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phady_util_out_dump, 0, 0, 1)
	ZEND_ARG_INFO(0, varToDump)
	ZEND_ARG_INFO(0, returnDump)
	ZEND_ARG_INFO(0, expandLevel)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phady_util_out_var_dump_plain, 0, 0, 2)
	ZEND_ARG_INFO(0, varToDump)
	ZEND_ARG_INFO(0, expLevel)
	ZEND_ARG_INFO(0, depth)
	ZEND_ARG_ARRAY_INFO(0, done, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phady_util_out_htmlentities, 0, 0, 1)
	ZEND_ARG_INFO(0, text)
	ZEND_ARG_INFO(0, preserve_encoded_entities)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phady_util_out_mbinternalencoding, 0, 0, 0)
	ZEND_ARG_INFO(0, encoding)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phady_util_out_method_entry) {
	PHP_ME(Phady_Util_Out, dump, arginfo_phady_util_out_dump, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phady_Util_Out, var_dump_plain, arginfo_phady_util_out_var_dump_plain, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phady_Util_Out, htmlentities, arginfo_phady_util_out_htmlentities, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phady_Util_Out, mbInternalEncoding, arginfo_phady_util_out_mbinternalencoding, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_FE_END
};
