
extern zend_class_entry *phady_util_datetime_ce;

ZEPHIR_INIT_CLASS(Phady_Util_DateTime);

PHP_METHOD(Phady_Util_DateTime, getDateByLanguage);
PHP_METHOD(Phady_Util_DateTime, getDateMoment);
PHP_METHOD(Phady_Util_DateTime, getDaysInMonth);
PHP_METHOD(Phady_Util_DateTime, getWeekdaysInMonth);
PHP_METHOD(Phady_Util_DateTime, getTimezoneText);
PHP_METHOD(Phady_Util_DateTime, getTimezones);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phady_util_datetime_getdatebylanguage, 0, 0, 1)
	ZEND_ARG_INFO(0, time)
	ZEND_ARG_INFO(0, language)
	ZEND_ARG_INFO(0, format)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phady_util_datetime_getdatemoment, 0, 0, 1)
	ZEND_ARG_INFO(0, datetime)
	ZEND_ARG_INFO(0, showTime)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phady_util_datetime_getdaysinmonth, 0, 0, 2)
	ZEND_ARG_INFO(0, month)
	ZEND_ARG_INFO(0, year)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phady_util_datetime_getweekdaysinmonth, 0, 0, 2)
	ZEND_ARG_INFO(0, month)
	ZEND_ARG_INFO(0, year)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phady_util_datetime_gettimezonetext, 0, 0, 0)
	ZEND_ARG_INFO(0, tz)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phady_util_datetime_method_entry) {
	PHP_ME(Phady_Util_DateTime, getDateByLanguage, arginfo_phady_util_datetime_getdatebylanguage, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phady_Util_DateTime, getDateMoment, arginfo_phady_util_datetime_getdatemoment, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phady_Util_DateTime, getDaysInMonth, arginfo_phady_util_datetime_getdaysinmonth, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phady_Util_DateTime, getWeekdaysInMonth, arginfo_phady_util_datetime_getweekdaysinmonth, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phady_Util_DateTime, getTimezoneText, arginfo_phady_util_datetime_gettimezonetext, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phady_Util_DateTime, getTimezones, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
