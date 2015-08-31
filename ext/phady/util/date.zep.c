
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/string.h"
#include "kernel/object.h"
#include "kernel/concat.h"
#include "kernel/array.h"


/*
+------------------------------------------------------------------------+
| Phady Framework                                                        |
+------------------------------------------------------------------------+
| Copyright (c) 2015                                                     |
+------------------------------------------------------------------------+
| Phady Framework is a complement of Phalcon Framework                   |
|                                                                        |
+------------------------------------------------------------------------+
| Authors: Alien fernandez Fuentes <alienfernandez85@gmail.com>          |
+------------------------------------------------------------------------+
*/
/**
 * Phady\Util\Date
 *
 * Util class for date manipulation
 */
ZEPHIR_INIT_CLASS(Phady_Util_Date) {

	ZEPHIR_REGISTER_CLASS(Phady\\Util, Date, phady, util_date, phady_util_date_method_entry, 0);

	zend_declare_class_constant_string(phady_util_date_ce, SL("FORMAT_DAYWEEK_DAY_MONTH_YEAR"), "%A, %d de %B del %Y" TSRMLS_CC);

	zend_declare_class_constant_string(phady_util_date_ce, SL("FORMAT_DAY_MONTH_YEAR"), "%d de %B del %Y" TSRMLS_CC);

	zend_declare_class_constant_string(phady_util_date_ce, SL("FORMAT_DAYWEEK_DAY_MONTH_YEAR_TIME"), "%A, %d de %B del %Y a las %H:%I" TSRMLS_CC);

	zend_declare_class_constant_string(phady_util_date_ce, SL("DEFAULT_LANGUAGE_DATE"), "es_ES" TSRMLS_CC);

	return SUCCESS;

}

/**
 * @name getDateByLanguage - Get a date given language
 * @param array time date
 * @param array language Language return date
 * @param array format Format return date
 * @return string
 */
PHP_METHOD(Phady_Util_Date, getDateByLanguage) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL, *_5 = NULL;
	zval *time_param = NULL, *language_param = NULL, *format = NULL, *date, _0, *_2 = NULL, *_3 = NULL, *_4 = NULL;
	zval *time = NULL, *language = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &time_param, &language_param, &format);

	if (unlikely(Z_TYPE_P(time_param) != IS_STRING && Z_TYPE_P(time_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'time' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(time_param) == IS_STRING)) {
		zephir_get_strval(time, time_param);
	} else {
		ZEPHIR_INIT_VAR(time);
		ZVAL_EMPTY_STRING(time);
	}
	if (!language_param) {
		ZEPHIR_INIT_VAR(language);
		ZVAL_STRING(language, "es_ES", 1);
	} else {
	if (unlikely(Z_TYPE_P(language_param) != IS_STRING && Z_TYPE_P(language_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'language' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(language_param) == IS_STRING)) {
		zephir_get_strval(language, language_param);
	} else {
		ZEPHIR_INIT_VAR(language);
		ZVAL_EMPTY_STRING(language);
	}
	}
	if (!format) {
		ZEPHIR_INIT_VAR(format);
		ZVAL_STRING(format, "%A, %d de %B del %Y", 1);
	}


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, 6);
	ZEPHIR_CALL_FUNCTION(NULL, "setlocale", &_1, &_0, language);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(date);
	object_init_ex(date, zephir_get_internal_ce(SS("datetime") TSRMLS_CC));
	ZEPHIR_CALL_METHOD(NULL, date, "__construct", NULL, time);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, date, "gettimestamp", NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_3, "strftime", NULL, format, _2);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_4, "ucfirst", &_5, _3);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_FUNCTION("utf8_encode", NULL, _4);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * @name getDateMoment - Get the date as a string in days , months ...
 * @param string datetime date example. 2014-09-28 12:22:44
 * @param boolean showTime Whether to display the time
 * @return string
 */
PHP_METHOD(Phady_Util_Date, getDateMoment) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool showTime;
	zval *datetime_param = NULL, *showTime_param = NULL, *datetimeSpt, *dateCreate, *date, *dateInterval = NULL, *days = NULL, *dayStr = NULL, *_0, *_1 = NULL, *_2, *_3, *_4 = NULL, *_5, *_6;
	zval *datetime = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &datetime_param, &showTime_param);

	zephir_get_strval(datetime, datetime_param);
	if (!showTime_param) {
		showTime = 0;
	} else {
		showTime = zephir_get_boolval(showTime_param);
	}


	ZEPHIR_INIT_VAR(datetimeSpt);
	zephir_fast_explode_str(datetimeSpt, SL(" "), datetime, LONG_MAX TSRMLS_CC);
	ZEPHIR_INIT_VAR(dateCreate);
	object_init_ex(dateCreate, zephir_get_internal_ce(SS("datetime") TSRMLS_CC));
	ZEPHIR_CALL_METHOD(NULL, dateCreate, "__construct", NULL, datetime);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(date);
	object_init_ex(date, zephir_get_internal_ce(SS("datetime") TSRMLS_CC));
	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "now", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, date, "__construct", NULL, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&dateInterval, date, "diff", NULL, dateCreate);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(_1);
	zephir_read_property(&_1, dateInterval, SL("days"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(days, _1);
	ZEPHIR_INIT_VAR(dayStr);
	ZVAL_STRING(dayStr, "", 1);
	if (ZEPHIR_IS_LONG(days, 0)) {
		ZEPHIR_OBS_NVAR(_1);
		zephir_read_property(&_1, dateInterval, SL("h"), PH_NOISY_CC);
		ZEPHIR_OBS_VAR(_2);
		zephir_read_property(&_2, dateInterval, SL("i"), PH_NOISY_CC);
		ZEPHIR_OBS_VAR(_3);
		zephir_read_property(&_3, dateInterval, SL("s"), PH_NOISY_CC);
		if (ZEPHIR_GT_LONG(_1, 0)) {
			ZEPHIR_OBS_VAR(_4);
			zephir_read_property(&_4, dateInterval, SL("h"), PH_NOISY_CC);
			ZEPHIR_INIT_NVAR(dayStr);
			ZEPHIR_CONCAT_SVS(dayStr, "Hace ", _4, " horas");
		} else if (ZEPHIR_GT_LONG(_2, 0)) {
			ZEPHIR_OBS_NVAR(_4);
			zephir_read_property(&_4, dateInterval, SL("i"), PH_NOISY_CC);
			ZEPHIR_INIT_NVAR(dayStr);
			ZEPHIR_CONCAT_SVS(dayStr, "Hace ", _4, " minutos");
		} else if (ZEPHIR_GT_LONG(_3, 0)) {
			ZEPHIR_INIT_NVAR(dayStr);
			ZVAL_STRING(dayStr, "Hace unos segundos", 1);
		}
	} else if (ZEPHIR_IS_LONG(days, 1)) {
		zephir_array_fetch_long(&_5, datetimeSpt, 1, PH_NOISY | PH_READONLY, "phady/util/date.zep", 69 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(dayStr);
		ZEPHIR_CONCAT_SV(dayStr, "Ayer a las ", _5);
	} else {
		ZEPHIR_INIT_NVAR(dayStr);
		ZEPHIR_CONCAT_SVS(dayStr, "Hace ", days, " días");
		if (showTime) {
			zephir_array_fetch_long(&_5, datetimeSpt, 1, PH_NOISY | PH_READONLY, "phady/util/date.zep", 73 TSRMLS_CC);
			ZEPHIR_INIT_VAR(_6);
			ZEPHIR_CONCAT_VSV(_6, dayStr, " a las ", _5);
			ZEPHIR_CPY_WRT(dayStr, _6);
		}
	}
	ZEPHIR_RETURN_CALL_FUNCTION("utf8_decode", NULL, dayStr);
	zephir_check_call_status();
	RETURN_MM();

}

