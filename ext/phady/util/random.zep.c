
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
#include "kernel/time.h"
#include "kernel/string.h"
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/math.h"
#include "kernel/hash.h"


/**
  * @class Phady\Util\Random - Util class for random string, int ...
  *
  * @author  Alien Fernández Fuentes <alienfernandez85@gmail.com>
  * @package Util
  * @copyright (c) 2015
  * @version 1.0.0
  */
ZEPHIR_INIT_CLASS(Phady_Util_Random) {

	ZEPHIR_REGISTER_CLASS(Phady\\Util, Random, phady, util_random, phady_util_random_method_entry, 0);

	return SUCCESS;

}

/**
 * Return a seed value for the srand() function
 *
 * @deprecated Since 1.3.0, as this is not required since PHP 4.2.0.
 *
 * @return The resulting seed value
 */
PHP_METHOD(Phady_Util_Random, getSeed) {

	zval *expMicrotime, *_0, *_1, _2, *_3 = NULL;
	int factor, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	factor = 95717;
	ZEPHIR_INIT_VAR(_0);
	zephir_microtime(_0, NULL TSRMLS_CC);
	ZEPHIR_INIT_VAR(expMicrotime);
	zephir_fast_explode_str(expMicrotime, SL(" "), _0, LONG_MAX TSRMLS_CC);
	ZEPHIR_OBS_VAR(_1);
	zephir_array_fetch_long(&_1, expMicrotime, 0, PH_NOISY, "phady/util/random.zep", 40 TSRMLS_CC);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_DOUBLE(&_2, zephir_safe_div_long_double((double) (zephir_get_numberval(_1) * factor), 3.1415926535898 TSRMLS_CC));
	ZEPHIR_CALL_FUNCTION(&_3, "strrev", NULL, 145, &_2);
	zephir_check_call_status();
	RETURN_MM_DOUBLE(zephir_get_doubleval(_3));

}

/**
 * Return a random integer between floor and ceil (inclusive).
 *
 * @param int floor The lower bound.
 * @param int ceil  The upper bound.
 *
 * @return The resulting random integer
 */
PHP_METHOD(Phady_Util_Random, getInteger) {

	zval *floor_param = NULL, *ceil_param = NULL, *diff, *inc, _0;
	int floor, ceil;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &floor_param, &ceil_param);

	floor = zephir_get_intval(floor_param);
	ceil = zephir_get_intval(ceil_param);


	ZEPHIR_INIT_VAR(diff);
	ZVAL_LONG(diff, (ceil - floor));
	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, 0);
	ZEPHIR_INIT_VAR(inc);
	ZVAL_LONG(inc, zephir_mt_rand(zephir_get_intval(&_0), zephir_get_intval(diff) TSRMLS_CC));
	RETURN_MM_LONG((floor + zephir_get_numberval(inc)));

}

/**
 * Return a random string of specified length.
 *
 * This function uses md5() to generate the string.
 *
 * @param int length The length of string to generate.
 *
 * @return The resulting random integer.
 */
PHP_METHOD(Phady_Util_Random, getRandomString) {

	zephir_fcall_cache_entry *_2 = NULL;
	zval *length_param = NULL, *res, *_0 = NULL, *_1 = NULL, *_3 = NULL, *_4 = NULL, _5, _6;
	int length, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &length_param);

	length = zephir_get_intval(length_param);
	ZEPHIR_INIT_VAR(res);
	ZVAL_STRING(res, "", 1);


	while (1) {
		if (!(zephir_fast_strlen_ev(res) < length)) {
			break;
		}
		ZEPHIR_INIT_NVAR(_0);
		ZEPHIR_INIT_NVAR(_3);
		ZVAL_LONG(_3, 0);
		ZEPHIR_INIT_NVAR(_4);
		ZVAL_LONG(_4, 100000);
		ZEPHIR_CALL_SELF(&_1, "getinteger", &_2, 0, _3, _4);
		zephir_check_call_status();
		zephir_md5(_0, _1);
		zephir_concat_self(&res, _0 TSRMLS_CC);
	}
	ZEPHIR_SINIT_VAR(_5);
	ZVAL_LONG(&_5, 0);
	ZEPHIR_SINIT_VAR(_6);
	ZVAL_LONG(&_6, length);
	zephir_substr(return_value, res, 0 , zephir_get_intval(&_6), 0);
	RETURN_MM();

}

/**
 * Return a random string
 *
 * @param int minLen            The minimum string length.
 * @param int maxLen            The maximum string length.
 * @param boolean leadingCapital Whether or not the string should start with a capital letter (optional) (default=true).
 * @param boolean useUpper       Whether or not to also use uppercase letters (optional) (default=true).
 * @param boolean useLower       Whether or not to also use lowercase letters (optional) (default=true).
 * @param boolean useSpace       Whether or not to also use whitespace letters (optional) (default=true).
 * @param boolean useNumber      Whether or not to also use numeric characters (optional) (default=false).
 * @param boolean useSpecial     Whether or not to also use special characters (optional) (default=false).
 * @param boolean seed           Whether or not to seed the random number generator (unused since 1.3.0) (optional) (default=false) seeding not required for PHP>4.2.0.
 * @param array   dontuse        Array of characters not to use (optional) (default=null) eg dontuse=array("a", "b", "c");.
 *
 * @return The resulting random string.
 */
PHP_METHOD(Phady_Util_Random, getString) {

	HashTable *_5;
	HashPosition _4;
	zephir_fcall_cache_entry *_3 = NULL, *_14 = NULL;
	zend_bool leadingCapital, useUpper, useLower, useSpace, useNumber, useSpecial, seed, _7, _10;
	zval *minLen_param = NULL, *maxLen_param = NULL, *leadingCapital_param = NULL, *useUpper_param = NULL, *useLower_param = NULL, *useSpace_param = NULL, *useNumber_param = NULL, *useSpecial_param = NULL, *seed_param = NULL, *dontuse = NULL, *rnd = NULL, *len = NULL, *i = NULL, *charExp, *chars = NULL, *upper, *lower, *number, *special, _0 = zval_used_for_init, _1, *_2 = NULL, **_6, *_8 = NULL, *_9 = NULL, *_12 = NULL, *_13;
	int minLen, maxLen, clen, ZEPHIR_LAST_CALL_STATUS, _11;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 8, &minLen_param, &maxLen_param, &leadingCapital_param, &useUpper_param, &useLower_param, &useSpace_param, &useNumber_param, &useSpecial_param, &seed_param, &dontuse);

	minLen = zephir_get_intval(minLen_param);
	maxLen = zephir_get_intval(maxLen_param);
	if (!leadingCapital_param) {
		leadingCapital = 1;
	} else {
		leadingCapital = zephir_get_boolval(leadingCapital_param);
	}
	if (!useUpper_param) {
		useUpper = 1;
	} else {
		useUpper = zephir_get_boolval(useUpper_param);
	}
	if (!useLower_param) {
		useLower = 1;
	} else {
		useLower = zephir_get_boolval(useLower_param);
	}
	if (!useSpace_param) {
		useSpace = 0;
	} else {
		useSpace = zephir_get_boolval(useSpace_param);
	}
	if (!useNumber_param) {
		useNumber = 0;
	} else {
		useNumber = zephir_get_boolval(useNumber_param);
	}
	if (!useSpecial_param) {
		useSpecial = 0;
	} else {
		useSpecial = zephir_get_boolval(useSpecial_param);
	}
	if (!seed_param) {
		seed = 0;
	} else {
		seed = zephir_get_boolval(seed_param);
	}
	if (!dontuse) {
		dontuse = ZEPHIR_GLOBAL(global_null);
	}
	ZEPHIR_INIT_VAR(rnd);
	ZVAL_STRING(rnd, "", 1);
	ZEPHIR_INIT_VAR(chars);
	ZVAL_STRING(chars, "", 1);
	ZEPHIR_INIT_VAR(upper);
	ZVAL_STRING(upper, "ABCDEFGHIJKLMNOPQRSTUVWXYZ", 1);
	ZEPHIR_INIT_VAR(lower);
	ZVAL_STRING(lower, "abcdefghijklmnopqrstuvwxyz", 1);
	ZEPHIR_INIT_VAR(number);
	ZVAL_STRING(number, "0123456789", 1);
	ZEPHIR_INIT_VAR(special);
	ZVAL_STRING(special, "~@#%^*()_+-={}|][", 1);


	if (useLower) {
		zephir_concat_self(&chars, lower TSRMLS_CC);
	}
	if (useUpper) {
		zephir_concat_self(&chars, upper TSRMLS_CC);
	}
	if (useNumber) {
		zephir_concat_self(&chars, number TSRMLS_CC);
	}
	if (useSpecial) {
		zephir_concat_self(&chars, special TSRMLS_CC);
	}
	if (useSpace) {
		ZEPHIR_SINIT_VAR(_0);
		ZVAL_LONG(&_0, 0);
		ZEPHIR_SINIT_VAR(_1);
		ZVAL_DOUBLE(&_1, (zephir_safe_mod_long_long(zephir_fast_strlen_ev(chars), 10 TSRMLS_CC)));
		ZEPHIR_CALL_FUNCTION(&_2, "range", &_3, 55, &_0, &_1);
		zephir_check_call_status();
		zephir_is_iterable(_2, &_5, &_4, 0, 0, "phady/util/random.zep", 124);
		for (
		  ; zephir_hash_get_current_data_ex(_5, (void**) &_6, &_4) == SUCCESS
		  ; zephir_hash_move_forward_ex(_5, &_4)
		) {
			ZEPHIR_GET_HVALUE(i, _6);
			zephir_concat_self_str(&chars, SL(" ") TSRMLS_CC);
		}
	}
	_7 = !(Z_TYPE_P(dontuse) == IS_NULL);
	if (_7) {
		_7 = Z_TYPE_P(dontuse) == IS_ARRAY;
	}
	if (_7) {
		ZEPHIR_INIT_VAR(_8);
		ZEPHIR_SINIT_NVAR(_0);
		ZVAL_STRING(&_0, "", 0);
		zephir_fast_str_replace(&_8, dontuse, &_0, chars TSRMLS_CC);
		ZEPHIR_CPY_WRT(chars, _8);
	}
	ZEPHIR_INIT_NVAR(_8);
	ZVAL_LONG(_8, minLen);
	ZEPHIR_INIT_VAR(_9);
	ZVAL_LONG(_9, maxLen);
	ZEPHIR_CALL_SELF(&len, "getinteger", NULL, 0, _8, _9);
	zephir_check_call_status();
	clen = (zephir_fast_strlen_ev(chars) - 1);
	ZEPHIR_INIT_VAR(charExp);
	zephir_fast_explode_str(charExp, SL(""), chars, LONG_MAX TSRMLS_CC);
	ZEPHIR_CPY_WRT(_12, len);
	_11 = 0;
	_10 = 0;
	if (ZEPHIR_GE_LONG(_12, _11)) {
		while (1) {
			if (_10) {
				_11++;
				if (!(ZEPHIR_GE_LONG(_12, _11))) {
					break;
				}
			} else {
				_10 = 1;
			}
			ZEPHIR_INIT_NVAR(i);
			ZVAL_LONG(i, _11);
			ZEPHIR_INIT_NVAR(_8);
			ZVAL_LONG(_8, 0);
			ZEPHIR_INIT_NVAR(_9);
			ZVAL_LONG(_9, clen);
			ZEPHIR_CALL_SELF(&_2, "getinteger", &_14, 0, _8, _9);
			zephir_check_call_status();
			zephir_array_fetch(&_13, charExp, _2, PH_NOISY | PH_READONLY, "phady/util/random.zep", 136 TSRMLS_CC);
			zephir_concat_self(&rnd, _13 TSRMLS_CC);
		}
	}
	if (leadingCapital) {
		ZEPHIR_INIT_NVAR(_8);
		zephir_ucfirst(_8, rnd);
		ZEPHIR_CPY_WRT(rnd, _8);
	}
	RETURN_CCTOR(rnd);

}

/**
 * Return a random string suitable for use as a password or password-like code.
 *
 * The string should conform to the constraints of the current password requirements:
 * suitable for human use (readable and unambiguous), within the specified minimum and maximum lengths.
 *
 * @param integer minLength The minimum length of the string to return; optional; default = 5; constrained to 1 <= minLength <= 25.
 * @param integer maxLength The maximum length of the string to return; optional; default = minLength; constrained to minLength <= maxLength <= 25.
 *
 * @return string|bool A random string suitable for human-use as a password or password-like code; false on error.
 */
PHP_METHOD(Phady_Util_Random, getStringForPassword) {

	zval *_11;
	zephir_fcall_cache_entry *_6 = NULL;
	zend_bool _1, _2, _8, _9;
	zval *minLength_param = NULL, *maxLength_param = NULL, _0, *_3 = NULL, *_4 = NULL, *_5 = NULL, _7, *_10 = NULL, *_12, *_13, *_14, *_15, *_16, *_17, *_18;
	int minLength, maxLength, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &minLength_param, &maxLength_param);

	if (!minLength_param) {
		minLength = 5;
	} else {
		minLength = zephir_get_intval(minLength_param);
	}
	if (!maxLength_param) {
		maxLength = 0;
	} else {
		maxLength = zephir_get_intval(maxLength_param);
	}


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, minLength);
	_1 = !(zephir_is_numeric(&_0));
	if (!(_1)) {
		_1 = (minLength != minLength);
	}
	_2 = _1;
	if (!(_2)) {
		_2 = (minLength <= 0);
	}
	if (_2) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_INIT_VAR(_3);
	ZVAL_LONG(_3, minLength);
	ZEPHIR_INIT_VAR(_4);
	ZVAL_LONG(_4, 25);
	ZEPHIR_CALL_FUNCTION(&_5, "min", &_6, 146, _3, _4);
	zephir_check_call_status();
	minLength = zephir_get_numberval(_5);
	ZEPHIR_SINIT_VAR(_7);
	ZVAL_LONG(&_7, maxLength);
	_8 = !(zephir_is_numeric(&_7));
	if (!(_8)) {
		_8 = (maxLength != maxLength);
	}
	_9 = _8;
	if (!(_9)) {
		_9 = (maxLength <= 0);
	}
	if (maxLength == 0) {
		maxLength = minLength;
	} else if (_9) {
		RETURN_MM_BOOL(0);
	} else if (maxLength <= minLength) {
		maxLength = minLength;
	} else {
		ZEPHIR_INIT_NVAR(_3);
		ZVAL_LONG(_3, maxLength);
		ZEPHIR_INIT_NVAR(_4);
		ZVAL_LONG(_4, 25);
		ZEPHIR_CALL_FUNCTION(&_10, "min", &_6, 146, _3, _4);
		zephir_check_call_status();
		maxLength = zephir_get_numberval(_10);
	}
	ZEPHIR_INIT_VAR(_11);
	zephir_create_array(_11, 10, 0 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_LONG(_3, 0);
	zephir_array_fast_append(_11, _3);
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_STRING(_3, "o", 1);
	zephir_array_fast_append(_11, _3);
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_STRING(_3, "O", 1);
	zephir_array_fast_append(_11, _3);
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_STRING(_3, "l", 1);
	zephir_array_fast_append(_11, _3);
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_LONG(_3, 1);
	zephir_array_fast_append(_11, _3);
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_STRING(_3, "i", 1);
	zephir_array_fast_append(_11, _3);
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_STRING(_3, "I", 1);
	zephir_array_fast_append(_11, _3);
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_STRING(_3, "j", 1);
	zephir_array_fast_append(_11, _3);
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_STRING(_3, "!", 1);
	zephir_array_fast_append(_11, _3);
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_STRING(_3, "|", 1);
	zephir_array_fast_append(_11, _3);
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_LONG(_3, minLength);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_LONG(_4, maxLength);
	ZEPHIR_INIT_VAR(_12);
	ZVAL_BOOL(_12, 0);
	ZEPHIR_INIT_VAR(_13);
	ZVAL_BOOL(_13, 0);
	ZEPHIR_INIT_VAR(_14);
	ZVAL_BOOL(_14, 1);
	ZEPHIR_INIT_VAR(_15);
	ZVAL_BOOL(_15, 0);
	ZEPHIR_INIT_VAR(_16);
	ZVAL_BOOL(_16, 1);
	ZEPHIR_INIT_VAR(_17);
	ZVAL_BOOL(_17, 0);
	ZEPHIR_INIT_VAR(_18);
	ZVAL_BOOL(_18, 0);
	ZEPHIR_RETURN_CALL_SELF("getstring", NULL, 0, _3, _4, _12, _13, _14, _15, _16, _17, _18, _11);
	zephir_check_call_status();
	RETURN_MM();

}

