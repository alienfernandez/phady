
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
#include "ext/date/php_date.h"
#include "kernel/string.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/concat.h"
#include "kernel/array.h"


/**
  * @class Phady\Util\DateTime - Util class for date and time manipulation
  *
  * @author  Alien Fernández Fuentes <alienfernandez85@gmail.com>
  * @package Util
  * @copyright (c) 2015
  * @version 1.0.0
  */
ZEPHIR_INIT_CLASS(Phady_Util_DateTime) {

	ZEPHIR_REGISTER_CLASS(Phady\\Util, DateTime, phady, util_datetime, phady_util_datetime_method_entry, 0);

	zend_declare_class_constant_string(phady_util_datetime_ce, SL("FORMAT_DAYWEEK_DAY_MONTH_YEAR"), "%A, %d de %B del %Y" TSRMLS_CC);

	zend_declare_class_constant_string(phady_util_datetime_ce, SL("FORMAT_DAY_MONTH_YEAR"), "%d de %B del %Y" TSRMLS_CC);

	zend_declare_class_constant_string(phady_util_datetime_ce, SL("FORMAT_DAYWEEK_DAY_MONTH_YEAR_TIME"), "%A, %d de %B del %Y a las %H:%I" TSRMLS_CC);

	zend_declare_class_constant_string(phady_util_datetime_ce, SL("DEFAULT_LANGUAGE_DATE"), "es_ES" TSRMLS_CC);

	zend_declare_class_constant_string(phady_util_datetime_ce, SL("DATEFORMAT_FIXED"), "%Y-%m-%d %H:%M:%S" TSRMLS_CC);

	zend_declare_class_constant_string(phady_util_datetime_ce, SL("DATEONLYFORMAT_FIXED"), "%Y-%m-%d" TSRMLS_CC);

	return SUCCESS;

}

/**
 * @name getDateByLanguage - Get a date given language
 * @param array time date
 * @param array language Language return date
 * @param array format Format return date
 * @return string
 */
PHP_METHOD(Phady_Util_DateTime, getDateByLanguage) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *time_param = NULL, *language_param = NULL, *format = NULL, *date, _0, *_1, *_2 = NULL, *_3 = NULL;
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
	ZEPHIR_CALL_FUNCTION(NULL, "setlocale", NULL, 62, &_0, language);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(date);
	object_init_ex(date, php_date_get_date_ce());
	ZEPHIR_CALL_METHOD(NULL, date, "__construct", NULL, 0, time);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_CALL_METHOD(&_2, date, "gettimestamp", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_3, "strftime", NULL, 63, format, _2);
	zephir_check_call_status();
	zephir_ucfirst(_1, _3);
	ZEPHIR_RETURN_CALL_FUNCTION("utf8_encode", NULL, 64, _1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * @name getDateMoment - Get the date as a string in days , months ...
 * @param string datetime date example. 2014-09-28 12:22:44
 * @param boolean showTime Whether to display the time
 * @return string
 */
PHP_METHOD(Phady_Util_DateTime, getDateMoment) {

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
	object_init_ex(dateCreate, php_date_get_date_ce());
	ZEPHIR_CALL_METHOD(NULL, dateCreate, "__construct", NULL, 0, datetime);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(date);
	object_init_ex(date, php_date_get_date_ce());
	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "now", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, date, "__construct", NULL, 0, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&dateInterval, date, "diff", NULL, 0, dateCreate);
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
		zephir_array_fetch_long(&_5, datetimeSpt, 1, PH_NOISY | PH_READONLY, "phady/util/datetime.zep", 75 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(dayStr);
		ZEPHIR_CONCAT_SV(dayStr, "Ayer a las ", _5);
	} else {
		ZEPHIR_INIT_NVAR(dayStr);
		ZEPHIR_CONCAT_SVS(dayStr, "Hace ", days, " días");
		if (showTime) {
			zephir_array_fetch_long(&_5, datetimeSpt, 1, PH_NOISY | PH_READONLY, "phady/util/datetime.zep", 79 TSRMLS_CC);
			ZEPHIR_INIT_VAR(_6);
			ZEPHIR_CONCAT_VSV(_6, dayStr, " a las ", _5);
			ZEPHIR_CPY_WRT(dayStr, _6);
		}
	}
	ZEPHIR_RETURN_CALL_FUNCTION("utf8_decode", NULL, 65, dayStr);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Return a the number of days in the given month/year.
 *
 * @param integer month The (human) month number to check.
 * @param integer year  The year number to check.
 *
 * @return integer The number of days in the given month/year
 */
PHP_METHOD(Phady_Util_DateTime, getDaysInMonth) {

	zend_bool _0;
	zval *month_param = NULL, *year_param = NULL, *days, *d = NULL, *_1 = NULL;
	int month, year;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &month_param, &year_param);

	month = zephir_get_intval(month_param);
	year = zephir_get_intval(year_param);


	_0 = month < 1;
	if (!(_0)) {
		_0 = month > 12;
	}
	if (_0) {
		RETURN_MM_LONG(0);
	}
	ZEPHIR_INIT_VAR(days);
	zephir_create_array(days, 12, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, 31);
	zephir_array_fast_append(days, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_LONG(_1, 28);
	zephir_array_fast_append(days, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_LONG(_1, 31);
	zephir_array_fast_append(days, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_LONG(_1, 30);
	zephir_array_fast_append(days, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_LONG(_1, 31);
	zephir_array_fast_append(days, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_LONG(_1, 30);
	zephir_array_fast_append(days, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_LONG(_1, 31);
	zephir_array_fast_append(days, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_LONG(_1, 31);
	zephir_array_fast_append(days, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_LONG(_1, 30);
	zephir_array_fast_append(days, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_LONG(_1, 31);
	zephir_array_fast_append(days, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_LONG(_1, 30);
	zephir_array_fast_append(days, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_LONG(_1, 31);
	zephir_array_fast_append(days, _1);
	ZEPHIR_OBS_VAR(d);
	zephir_array_fetch_long(&d, days, (month - 1), PH_NOISY, "phady/util/datetime.zep", 100 TSRMLS_CC);
	if (month == 2) {
		if (zephir_safe_mod_long_long(year, 4 TSRMLS_CC) == 0) {
			if (zephir_safe_mod_long_long(year, 100 TSRMLS_CC) == 0) {
				if (zephir_safe_mod_long_long(year, 400 TSRMLS_CC) == 0) {
					ZEPHIR_INIT_NVAR(d);
					ZVAL_LONG(d, 29);
				}
			} else {
				ZEPHIR_INIT_NVAR(d);
				ZVAL_LONG(d, 29);
			}
		}
	}
	RETURN_CCTOR(d);

}

/**
 * Return an array of weekdays for the given month.
 *
 * @param integer month The (human) month number to check.
 * @param integer year  The year number to check.
 *
 * @return integer The number of days in the given month/year.
 */
PHP_METHOD(Phady_Util_DateTime, getWeekdaysInMonth) {

	zephir_fcall_cache_entry *_10 = NULL, *_11 = NULL;
	zend_bool _2;
	zval *month_param = NULL, *year_param = NULL, *nDays = NULL, *weekdays, *i = NULL, *time = NULL, *tDate = NULL, *_0, *_1, *_4 = NULL, _5 = zval_used_for_init, _6 = zval_used_for_init, _7 = zval_used_for_init, _8 = zval_used_for_init, _9 = zval_used_for_init, *_12;
	int month, year, ZEPHIR_LAST_CALL_STATUS, _3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &month_param, &year_param);

	month = zephir_get_intval(month_param);
	year = zephir_get_intval(year_param);


	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, month);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, year);
	ZEPHIR_CALL_SELF(&nDays, "getdaysinmonth", NULL, 0, _0, _1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(weekdays);
	zephir_create_array(weekdays, 1, 0 TSRMLS_CC);
	zephir_array_fast_append(weekdays, nDays);
	ZEPHIR_CPY_WRT(_4, nDays);
	_3 = 1;
	_2 = 0;
	if (ZEPHIR_GE_LONG(_4, _3)) {
		while (1) {
			if (_2) {
				_3++;
				if (!(ZEPHIR_GE_LONG(_4, _3))) {
					break;
				}
			} else {
				_2 = 1;
			}
			ZEPHIR_INIT_NVAR(i);
			ZVAL_LONG(i, _3);
			ZEPHIR_SINIT_NVAR(_5);
			ZVAL_LONG(&_5, 12);
			ZEPHIR_SINIT_NVAR(_6);
			ZVAL_LONG(&_6, 0);
			ZEPHIR_SINIT_NVAR(_7);
			ZVAL_LONG(&_7, 0);
			ZEPHIR_SINIT_NVAR(_8);
			ZVAL_LONG(&_8, month);
			ZEPHIR_SINIT_NVAR(_9);
			ZVAL_LONG(&_9, year);
			ZEPHIR_CALL_FUNCTION(&time, "mktime", &_10, 66, &_5, &_6, &_7, &_8, i, &_9);
			zephir_check_call_status();
			ZEPHIR_CALL_FUNCTION(&tDate, "getdate", &_11, 67, time);
			zephir_check_call_status();
			zephir_array_fetch_string(&_12, tDate, SL("wday"), PH_NOISY | PH_READONLY, "phady/util/datetime.zep", 132 TSRMLS_CC);
			zephir_array_update_zval(&weekdays, i, &_12, PH_COPY | PH_SEPARATE);
		}
	}
	RETURN_CCTOR(weekdays);

}

/**
 * Return the translated name of a specific timezone if exists.
 *
 * @param integer tz Timezone identifier.
 *
 * @return string Timezone translation (hour value).
 */
PHP_METHOD(Phady_Util_DateTime, getTimezoneText) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *tz = NULL, *timezones = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &tz);

	if (!tz) {
		tz = ZEPHIR_GLOBAL(global_null);
	}


	if (!(zephir_is_numeric(tz))) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_CALL_SELF(&timezones, "gettimezones", NULL, 0);
	zephir_check_call_status();
	if (zephir_array_isset(timezones, tz)) {
		zephir_array_fetch(&_0, timezones, tz, PH_NOISY | PH_READONLY, "phady/util/datetime.zep", 153 TSRMLS_CC);
		RETURN_CTOR(_0);
	}
	RETURN_MM_STRING("(Unknown timezone)", 1);

}

/**
 * Return the translated list of timezones.
 *
 * @return array Timezones values and gettext strings.
 */
PHP_METHOD(Phady_Util_DateTime, getTimezones) {


	zephir_create_array(return_value, 38, 0 TSRMLS_CC);
	add_assoc_stringl_ex(return_value, SS("-12"), SL("((GMT -12:00 hours) Baker Island)"), 1);
	add_assoc_stringl_ex(return_value, SS("-11"), SL("((GMT -11:00 hours) Midway Island, Samoa)"), 1);
	add_assoc_stringl_ex(return_value, SS("-10"), SL("((GMT -10:00 hours) Hawaii)"), 1);
	add_assoc_stringl_ex(return_value, SS("-9.5"), SL("((GMT -9:30 hours) French Polynesia)"), 1);
	add_assoc_stringl_ex(return_value, SS("-9"), SL("((GMT -9:00 hours) Alaska)"), 1);
	add_assoc_stringl_ex(return_value, SS("-8"), SL("((GMT -8:00 hours) Pacific Time (US & Canada))"), 1);
	add_assoc_stringl_ex(return_value, SS("-7"), SL("((GMT -7:00 hours) Mountain Time (US & Canada))"), 1);
	add_assoc_stringl_ex(return_value, SS("-6"), SL("((GMT -6:00 hours) Central Time (US & Canada), Mexico City)"), 1);
	add_assoc_stringl_ex(return_value, SS("-5"), SL("((GMT -5:00 hours) Eastern Time (US & Canada), Bogota, Lima, Quito)"), 1);
	add_assoc_stringl_ex(return_value, SS("-4"), SL("((GMT -4:00 hours) Atlantic Time (Canada), Caracas, La Paz)"), 1);
	add_assoc_stringl_ex(return_value, SS("-3.5"), SL("((GMT -3:30 hours) Newfoundland)"), 1);
	add_assoc_stringl_ex(return_value, SS("-3"), SL("((GMT -3:00 hours) Brazil, Buenos Aires, Georgetown)"), 1);
	add_assoc_stringl_ex(return_value, SS("-2"), SL("((GMT -2:00 hours) Mid-Atlantic)"), 1);
	add_assoc_stringl_ex(return_value, SS("-1"), SL("((GMT -1:00 hours) Azores, Cape Verde Islands)"), 1);
	add_index_stringl(return_value, 0, SL("((GMT) Western Europe Time, London, Lisbon, Casablanca, Monrovia)"), 1);
	add_index_stringl(return_value, 1, SL("((GMT +1:00 hours) CET (Central Europe Time), Brussels, Copenhagen, Madrid, Paris)"), 1);
	add_index_stringl(return_value, 2, SL("((GMT +2:00 hours) EET (Eastern Europe Time), Kaliningrad, South Africa)"), 1);
	add_index_stringl(return_value, 3, SL("((GMT +3:00 hours) Baghdad, Kuwait, Riyadh, Moscow, St. Petersburg)"), 1);
	add_assoc_stringl_ex(return_value, SS("3.5"), SL("((GMT +3:30 hours) Tehran)"), 1);
	add_index_stringl(return_value, 4, SL("((GMT +4:00 hours) Abu Dhabi, Muscat, Baku, Tbilisi)"), 1);
	add_assoc_stringl_ex(return_value, SS("4.5"), SL("((GMT +4:30 hours) Kabul)"), 1);
	add_index_stringl(return_value, 5, SL("((GMT +5:00 hours) Ekaterinburg, Islamabad, Karachi, Tashkent)"), 1);
	add_assoc_stringl_ex(return_value, SS("5.5"), SL("((GMT +5:30 hours) Bombay, Calcutta, Madras, New Delhi)"), 1);
	add_assoc_stringl_ex(return_value, SS("5.75"), SL("((GMT +5:45 hours) Kathmandu)"), 1);
	add_index_stringl(return_value, 6, SL("((GMT +6:00 hours) Almaty, Dhaka, Colombo)"), 1);
	add_assoc_stringl_ex(return_value, SS("6.5"), SL("((GMT +6:30 hours) Cocos Islands, Myanmar)"), 1);
	add_index_stringl(return_value, 7, SL("((GMT +7:00 hours) Bangkok, Hanoi, Jakarta)"), 1);
	add_index_stringl(return_value, 8, SL("((GMT +8:00 hours) Beijing, Perth, Singapore, Hong Kong, Chongqing, Urumqi, Taipei)"), 1);
	add_index_stringl(return_value, 9, SL("((GMT +9:00 hours) Tokyo, Seoul, Osaka, Sapporo, Yakutsk)"), 1);
	add_assoc_stringl_ex(return_value, SS("9.5"), SL("((GMT +9:30 hours) Adelaide, Darwin)"), 1);
	add_index_stringl(return_value, 10, SL("((GMT +10:00 hours) EAST (East Australian Standard))"), 1);
	add_assoc_stringl_ex(return_value, SS("10.5"), SL("((GMT +10:30 hours) Lord Howe Island (NSW, Australia))"), 1);
	add_index_stringl(return_value, 11, SL("((GMT +11:00 hours) Magadan, Solomon Islands, New Caledonia)"), 1);
	add_assoc_stringl_ex(return_value, SS("11.5"), SL("((GMT +11:30 hours) Norfolk Island)"), 1);
	add_index_stringl(return_value, 12, SL("((GMT +12:00 hours) Auckland, Wellington, Fiji, Kamchatka, Marshall Island)"), 1);
	add_assoc_stringl_ex(return_value, SS("12.75"), SL("((GMT +12:45 hours) Chatham Islands)"), 1);
	add_index_stringl(return_value, 13, SL("((GMT +13:00 hours Tonga, Kiribati (Phoenix Islands))"), 1);
	add_index_stringl(return_value, 14, SL("((GMT +14:00 hours) Kiribati (Line Islands))"), 1);
	return;

}

