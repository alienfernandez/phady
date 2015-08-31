
extern zend_class_entry *phady_util_date_ce;

ZEPHIR_INIT_CLASS(Phady_Util_Date);

PHP_METHOD(Phady_Util_Date, getDateByLanguage);
PHP_METHOD(Phady_Util_Date, getDateMoment);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phady_util_date_getdatebylanguage, 0, 0, 1)
	ZEND_ARG_INFO(0, time)
	ZEND_ARG_INFO(0, language)
	ZEND_ARG_INFO(0, format)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phady_util_date_getdatemoment, 0, 0, 1)
	ZEND_ARG_INFO(0, datetime)
	ZEND_ARG_INFO(0, showTime)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phady_util_date_method_entry) {
	PHP_ME(Phady_Util_Date, getDateByLanguage, arginfo_phady_util_date_getdatebylanguage, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phady_Util_Date, getDateMoment, arginfo_phady_util_date_getdatemoment, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
  PHP_FE_END
};
