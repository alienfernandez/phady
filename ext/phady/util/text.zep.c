
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
#include "kernel/string.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/fcall.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/array.h"
#include "kernel/hash.h"
#include "kernel/object.h"


/**
  * @class Phady\Util\Text - Util class for text manipulation
  *
  * @author  Alien Fernández Fuentes <alienfernandez85@gmail.com>
  * @package Util
  * @copyright (c) 2015
  * @version 1.0.0
  */
ZEPHIR_INIT_CLASS(Phady_Util_Text) {

	ZEPHIR_REGISTER_CLASS(Phady\\Util, Text, phady, util_text, phady_util_text_method_entry, 0);

	zend_declare_class_constant_string(phady_util_text_ce, SL("BACKGROUND_COLOR_DEFAULT"), "#D82EE8" TSRMLS_CC);

	zend_declare_class_constant_string(phady_util_text_ce, SL("COLOR_DEFAULT"), "#FFFFFF" TSRMLS_CC);

	zend_declare_class_constant_string(phady_util_text_ce, SL("BREAK_DEFAULT"), "." TSRMLS_CC);

	zend_declare_class_constant_string(phady_util_text_ce, SL("PAD_DEFAULT"), "..." TSRMLS_CC);

	return SUCCESS;

}

/**
 * @name highlight - Highlight text to display as html
 *
 * @param string text Text highlight
 * @param string query Sub searched string
 * @param boolean first Whether to search only by First Letter
 * @param string background_color Background color of the highlighted
 * @param string color Font color of the highlighted
 * @return string
 */
PHP_METHOD(Phady_Util_Text, highlight) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_9 = NULL;
	zend_bool first, _0;
	zval *text_param = NULL, *query_param = NULL, *first_param = NULL, *background_color_param = NULL, *color_param = NULL, *posResultQuery, *subStrQuery = NULL, *strQuery = NULL, *_1 = NULL, *_2, *_3 = NULL, *_4, *_5 = NULL, _6 = zval_used_for_init, *_8 = NULL, _10, *_11;
	zval *text = NULL, *query = NULL, *background_color = NULL, *color = NULL, *_7 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 2, &text_param, &query_param, &first_param, &background_color_param, &color_param);

	if (unlikely(Z_TYPE_P(text_param) != IS_STRING && Z_TYPE_P(text_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'text' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(text_param) == IS_STRING)) {
		zephir_get_strval(text, text_param);
	} else {
		ZEPHIR_INIT_VAR(text);
		ZVAL_EMPTY_STRING(text);
	}
	if (unlikely(Z_TYPE_P(query_param) != IS_STRING && Z_TYPE_P(query_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'query' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(query_param) == IS_STRING)) {
		zephir_get_strval(query, query_param);
	} else {
		ZEPHIR_INIT_VAR(query);
		ZVAL_EMPTY_STRING(query);
	}
	first = zephir_get_boolval(first_param);
	if (!background_color_param) {
		ZEPHIR_INIT_VAR(background_color);
		ZVAL_STRING(background_color, "#D82EE8", 1);
	} else {
		zephir_get_strval(background_color, background_color_param);
	}
	if (!color_param) {
		ZEPHIR_INIT_VAR(color);
		ZVAL_STRING(color, "#FFFFFF", 1);
	} else {
		zephir_get_strval(color, color_param);
	}


	_0 = zephir_is_true(text);
	if (_0) {
		_0 = zephir_is_true(query);
	}
	if (_0) {
		ZEPHIR_INIT_VAR(_2);
		zephir_fast_strtolower(_2, text);
		ZEPHIR_INIT_VAR(_4);
		zephir_fast_strtolower(_4, query);
		ZEPHIR_INIT_VAR(posResultQuery);
		zephir_fast_strpos(posResultQuery, _2, _4, 0 );
		if (first == 0) {
			if (Z_TYPE_P(posResultQuery) != IS_NULL) {
				ZEPHIR_SINIT_VAR(_6);
				ZVAL_LONG(&_6, zephir_fast_strlen_ev(query));
				ZEPHIR_INIT_VAR(subStrQuery);
				zephir_substr(subStrQuery, text, zephir_get_intval(posResultQuery), zephir_get_intval(&_6), 0);
				ZEPHIR_INIT_VAR(_7);
				ZEPHIR_CONCAT_SVS(_7, "/", query, "/i");
				ZEPHIR_INIT_VAR(_8);
				ZEPHIR_CONCAT_SVSVSVS(_8, "<span style=background:", background_color, ";color:", color, ";border:1px dotted;margin-right:0px><strong>", subStrQuery, "</strong></span>");
				ZEPHIR_CALL_FUNCTION(&strQuery, "preg_replace", &_9, 112, _7, _8, text);
				zephir_check_call_status();
			} else {
				ZEPHIR_INIT_NVAR(strQuery);
				ZVAL_STRING(strQuery, "", 1);
			}
		} else {
			ZEPHIR_SINIT_NVAR(_6);
			ZVAL_LONG(&_6, 0);
			ZEPHIR_SINIT_VAR(_10);
			ZVAL_LONG(&_10, 1);
			ZEPHIR_INIT_NVAR(subStrQuery);
			zephir_substr(subStrQuery, text, 0 , 1 , 0);
			if (ZEPHIR_IS_LONG(posResultQuery, 0)) {
				ZEPHIR_INIT_LNVAR(_7);
				ZEPHIR_CONCAT_SVS(_7, "/", query, "/i");
				ZEPHIR_INIT_LNVAR(_8);
				ZEPHIR_CONCAT_SVSVSVS(_8, "<span style=background:", background_color, ";color:", color, ";border:1px dotted;margin-right:0px><strong>", subStrQuery, "</strong></span>");
				ZEPHIR_INIT_VAR(_11);
				ZVAL_LONG(_11, 1);
				ZEPHIR_CALL_FUNCTION(&strQuery, "preg_replace", &_9, 112, _7, _8, text, _11);
				zephir_check_call_status();
			} else {
				ZEPHIR_CPY_WRT(strQuery, text);
			}
		}
	} else {
		ZEPHIR_CPY_WRT(strQuery, text);
	}
	RETURN_CCTOR(strQuery);

}

/**
 * @name truncate - Truncate a string
 *
 * @param string text - String truncated
 * @param int limit - limit to truncate
 * @param string str_break - string to break
 * @param string pad - filling the end of the string
 * @return string
 */
PHP_METHOD(Phady_Util_Text, truncate) {

	int limit;
	zval *text_param = NULL, *limit_param = NULL, *str_break_param = NULL, *pad_param = NULL, *breakpoint, *trcText = NULL, *_0 = NULL, _1 = zval_used_for_init, *_2 = NULL, _3 = zval_used_for_init, *_4 = NULL;
	zval *text = NULL, *str_break = NULL, *pad = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 2, &text_param, &limit_param, &str_break_param, &pad_param);

	if (unlikely(Z_TYPE_P(text_param) != IS_STRING && Z_TYPE_P(text_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'text' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(text_param) == IS_STRING)) {
		zephir_get_strval(text, text_param);
	} else {
		ZEPHIR_INIT_VAR(text);
		ZVAL_EMPTY_STRING(text);
	}
	if (unlikely(Z_TYPE_P(limit_param) != IS_LONG)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'limit' must be a long/integer") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	limit = Z_LVAL_P(limit_param);
	if (!str_break_param) {
		ZEPHIR_INIT_VAR(str_break);
		ZVAL_STRING(str_break, ".", 1);
	} else {
		zephir_get_strval(str_break, str_break_param);
	}
	if (!pad_param) {
		ZEPHIR_INIT_VAR(pad);
		ZVAL_STRING(pad, "...", 1);
	} else {
		zephir_get_strval(pad, pad_param);
	}


	ZEPHIR_CPY_WRT(trcText, text);
	if (limit <= zephir_fast_strlen_ev(text)) {
		if (str_break && Z_STRLEN_P(str_break)) {
			ZEPHIR_SINIT_VAR(_1);
			ZVAL_LONG(&_1, limit);
			ZEPHIR_INIT_VAR(breakpoint);
			zephir_fast_strpos(breakpoint, text, str_break, zephir_get_intval(&_1) );
			if (!ZEPHIR_IS_FALSE(breakpoint)) {
				if (ZEPHIR_LT_LONG(breakpoint, ((zephir_fast_strlen_ev(text) - 1)))) {
					ZEPHIR_SINIT_VAR(_3);
					ZVAL_LONG(&_3, 0);
					ZEPHIR_INIT_VAR(_4);
					zephir_substr(_4, text, 0 , zephir_get_intval(breakpoint), 0);
					ZEPHIR_INIT_NVAR(trcText);
					ZEPHIR_CONCAT_VV(trcText, _4, pad);
				}
			}
		} else {
			ZEPHIR_SINIT_NVAR(_1);
			ZVAL_LONG(&_1, 0);
			ZEPHIR_SINIT_NVAR(_3);
			ZVAL_LONG(&_3, limit);
			ZEPHIR_INIT_NVAR(_4);
			zephir_substr(_4, text, 0 , zephir_get_intval(&_3), 0);
			ZEPHIR_INIT_NVAR(trcText);
			ZEPHIR_CONCAT_VV(trcText, _4, pad);
		}
	}
	RETURN_CCTOR(trcText);

}

/**
 * @name findAndReplaceUrlTags - Search mail and url and replace the complete url
 *
 * @param array text String to replace
 * @return string
 */
PHP_METHOD(Phady_Util_Text, findAndReplaceUrlTags) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_3 = NULL;
	zval *text_param = NULL, *sanitate = NULL, *_0 = NULL, *_1 = NULL, *_2 = NULL;
	zval *text = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &text_param);

	if (unlikely(Z_TYPE_P(text_param) != IS_STRING && Z_TYPE_P(text_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'text' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(text_param) == IS_STRING)) {
		zephir_get_strval(text, text_param);
	} else {
		ZEPHIR_INIT_VAR(text);
		ZVAL_EMPTY_STRING(text);
	}


	ZEPHIR_INIT_VAR(sanitate);
	zephir_fast_trim(sanitate, text, NULL , ZEPHIR_TRIM_BOTH TSRMLS_CC);
	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "(((f|ht){1}tp://)[-a-zA-Z0-9@:%_+.~#?&//=]+)", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "<a href=0>0</a>", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_FUNCTION(&_2, "preg_replace", &_3, 112, _0, _1, sanitate);
	zephir_check_temp_parameter(_0);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(sanitate, _2);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "(((f|ht){1}tps://)[-a-zA-Z0-9@:%_+.~#?&//=]+)", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "<a href=0> 0</a>", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_FUNCTION(&_2, "preg_replace", &_3, 112, _0, _1, sanitate);
	zephir_check_temp_parameter(_0);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(sanitate, _2);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "/w{3}.[a-zA-Z0-9_-]*.[a-z]*.[a-z]*/", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, " 1<a href=http://0>0</a>", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_FUNCTION(&_2, "preg_replace", &_3, 112, _0, _1, sanitate);
	zephir_check_temp_parameter(_0);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(sanitate, _2);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "([_.0-9a-z-]+@([0-9a-z][0-9a-z-]+.).[a-z]{2,3})", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "<a href=mailto: 0> 0</a>", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_FUNCTION(&_2, "preg_replace", &_3, 112, _0, _1, sanitate);
	zephir_check_temp_parameter(_0);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(sanitate, _2);
	RETURN_CCTOR(sanitate);

}

/**
 * Transform a snake_case string into a camelCase string.
 *
 * @param string snake the string to convert
 * @return string
 */
PHP_METHOD(Phady_Util_Text, snakeToCamel) {

	zephir_fcall_cache_entry *_7 = NULL, *_10 = NULL;
	int _1, _2, ZEPHIR_LAST_CALL_STATUS;
	zend_bool _0;
	zval *snake_param = NULL, *pieces, *count, *str = NULL, *i = NULL, *p = NULL, _3 = zval_used_for_init, _4 = zval_used_for_init, *_5 = NULL, *_6 = NULL, _8 = zval_used_for_init, *_9 = NULL, *_11 = NULL;
	zval *snake = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &snake_param);

	zephir_get_strval(snake, snake_param);


	ZEPHIR_INIT_VAR(pieces);
	zephir_fast_explode_str(pieces, SL("_"), snake, LONG_MAX TSRMLS_CC);
	ZEPHIR_INIT_VAR(count);
	ZVAL_LONG(count, zephir_fast_count_int(pieces TSRMLS_CC));
	if (ZEPHIR_IS_LONG(count, 1)) {
		RETURN_CTOR(snake);
	}
	ZEPHIR_OBS_VAR(str);
	zephir_array_fetch_long(&str, pieces, 0, PH_NOISY, "phady/util/text.zep", 131 TSRMLS_CC);
	_2 = (zephir_get_numberval(count) - 1);
	_1 = 1;
	_0 = 0;
	if (_1 <= _2) {
		while (1) {
			if (_0) {
				_1++;
				if (!(_1 <= _2)) {
					break;
				}
			} else {
				_0 = 1;
			}
			ZEPHIR_INIT_NVAR(i);
			ZVAL_LONG(i, _1);
			ZEPHIR_OBS_NVAR(p);
			zephir_array_fetch(&p, pieces, i, PH_NOISY, "phady/util/text.zep", 133 TSRMLS_CC);
			ZEPHIR_SINIT_NVAR(_3);
			ZVAL_LONG(&_3, 0);
			ZEPHIR_SINIT_NVAR(_4);
			ZVAL_LONG(&_4, 1);
			ZEPHIR_INIT_NVAR(_5);
			zephir_substr(_5, p, 0 , 1 , 0);
			ZEPHIR_CALL_FUNCTION(&_6, "mb_strtoupper", &_7, 117, _5);
			zephir_check_call_status();
			ZEPHIR_SINIT_NVAR(_8);
			ZVAL_LONG(&_8, 1);
			ZEPHIR_CALL_FUNCTION(&_9, "mb_substr", &_10, 118, p, &_8);
			zephir_check_call_status();
			ZEPHIR_INIT_LNVAR(_11);
			ZEPHIR_CONCAT_VVV(_11, str, _6, _9);
			ZEPHIR_CPY_WRT(str, _11);
		}
	}
	RETURN_CCTOR(str);

}

/**
 * Transform a camelCase string into a snake_case string.
 *
 * @param string camel the string to convert
 * @return string
 */
PHP_METHOD(Phady_Util_Text, camelToSnake) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *camel_param = NULL, *_0, *_1, *_2 = NULL;
	zval *camel = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &camel_param);

	zephir_get_strval(camel, camel_param);


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "/([A-Z])/u", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "_1", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_FUNCTION(&_2, "preg_replace", NULL, 112, _0, _1, camel);
	zephir_check_temp_parameter(_0);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_FUNCTION("mb_strtolower", NULL, 119, _2);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Transform a text to uppercase.
 *
 * @deprecated	Use {@link mb_strtoupper} instead.
 *
 * @param text the text to transform.
 * @param encoding the character encoding to use. default is {@link mb_internal_encoding()}.
 * @return	the text in uppercase.
 */
PHP_METHOD(Phady_Util_Text, toUpper) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *text_param = NULL, *encoding = NULL, *enc = NULL;
	zval *text = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &text_param, &encoding);

	zephir_get_strval(text, text_param);
	if (!encoding) {
		encoding = ZEPHIR_GLOBAL(global_null);
	}


	if (Z_TYPE_P(encoding) == IS_STRING) {
		ZEPHIR_CPY_WRT(enc, encoding);
	} else {
		ZEPHIR_CALL_FUNCTION(&enc, "mb_internal_encoding", NULL, 114);
		zephir_check_call_status();
	}
	ZEPHIR_RETURN_CALL_FUNCTION("mb_strtoupper", NULL, 117, text, enc);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Transform a text to lowercase.
 *
 * @deprecated	Use {@link mb_strtolower} instead.
 *
 * @param text the text to transform.
 * @param encoding the character encoding to use. default is {@link mb_internal_encoding()}.
 * @return	the text in lowercase.
 */
PHP_METHOD(Phady_Util_Text, toLower) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *text_param = NULL, *encoding = NULL, *enc = NULL;
	zval *text = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &text_param, &encoding);

	zephir_get_strval(text, text_param);
	if (!encoding) {
		encoding = ZEPHIR_GLOBAL(global_null);
	}


	if (Z_TYPE_P(encoding) == IS_STRING) {
		ZEPHIR_CPY_WRT(enc, encoding);
	} else {
		ZEPHIR_CALL_FUNCTION(&enc, "mb_internal_encoding", NULL, 114);
		zephir_check_call_status();
	}
	ZEPHIR_RETURN_CALL_FUNCTION("mb_strtolower", NULL, 119, text, enc);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Transform all the letters to lowercase and just the first letter of each word to uppercase.
 *
 * This method can be replaced by {@code mb_convert_case( "your text here", MB_CASE_TITLE )} when
 * the {@code exceptions} parameter is not given.
 *
 * How to use it:
 * #( "john von neumann", array( " von " ) ) ==> "John von Neumann"
 * #( "JOHN VON NEUMANN", array( " von " ) ) ==> "John von Neumann"
 * #( "maria da silva e castro", array( " da ", " e " ) ) ==> "Maria da Silva e Castro"
 *
 * @see {@link commonNameExceptions}.
 *
 * @param text text to transform.
 * @param exceptions array of words to ignore exceptions.
 * @param encoding the character encoding to use. default is {@link mb_internal_encoding()}.
 * @return	the transformed text.
 */
PHP_METHOD(Phady_Util_Text, upperCaseFirst) {

	HashTable *_3;
	HashPosition _2;
	zephir_fcall_cache_entry *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *exceptions = NULL;
	zval *text_param = NULL, *exceptions_param = NULL, *encoding = NULL, *enc = NULL, *newText = NULL, *e = NULL, _0 = zval_used_for_init, **_4, *_5 = NULL, *_6 = NULL, *_7 = NULL;
	zval *text = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &text_param, &exceptions_param, &encoding);

	zephir_get_strval(text, text_param);
	if (!exceptions_param) {
		ZEPHIR_INIT_VAR(exceptions);
		array_init(exceptions);
	} else {
		zephir_get_arrval(exceptions, exceptions_param);
	}
	if (!encoding) {
		encoding = ZEPHIR_GLOBAL(global_null);
	}


	if (Z_TYPE_P(encoding) == IS_STRING) {
		ZEPHIR_CPY_WRT(enc, encoding);
	} else {
		ZEPHIR_CALL_FUNCTION(&enc, "mb_internal_encoding", NULL, 114);
		zephir_check_call_status();
	}
	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, 2);
	ZEPHIR_CALL_FUNCTION(&newText, "mb_convert_case", &_1, 120, text, &_0, enc);
	zephir_check_call_status();
	if (zephir_fast_count_int(exceptions TSRMLS_CC) < 1) {
		RETURN_CCTOR(newText);
	}
	zephir_is_iterable(exceptions, &_3, &_2, 0, 0, "phady/util/text.zep", 209);
	for (
	  ; zephir_hash_get_current_data_ex(_3, (void**) &_4, &_2) == SUCCESS
	  ; zephir_hash_move_forward_ex(_3, &_2)
	) {
		ZEPHIR_GET_HVALUE(e, _4);
		ZEPHIR_INIT_NVAR(_5);
		ZEPHIR_SINIT_NVAR(_0);
		ZVAL_LONG(&_0, 2);
		ZEPHIR_CALL_FUNCTION(&_6, "mb_convert_case", &_1, 120, e, &_0, enc);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_0);
		ZVAL_LONG(&_0, 1);
		ZEPHIR_CALL_FUNCTION(&_7, "mb_convert_case", &_1, 120, e, &_0, enc);
		zephir_check_call_status();
		zephir_fast_str_replace(&_5, _6, _7, newText TSRMLS_CC);
		ZEPHIR_CPY_WRT(newText, _5);
	}
	RETURN_CCTOR(newText);

}

/**
 * Count the instances of needle in the given string
 *
 * Why is this function here? PHP has a builtin substr_count()
 * to do the same.
 *
 * @param string haystack The string to search.
 * @param string needle   The needle to search for and count.
 *
 * @return integer The numer of instances of needle in string
 */
PHP_METHOD(Phady_Util_Text, countInstances) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *haystack_param = NULL, *needle_param = NULL;
	zval *haystack = NULL, *needle = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &haystack_param, &needle_param);

	zephir_get_strval(haystack, haystack_param);
	zephir_get_strval(needle, needle_param);


	ZEPHIR_RETURN_CALL_FUNCTION("mb_substr_count", NULL, 121, haystack, needle);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Translate html input newlines to <br /> sequences.
 *
 * This function is necessary as inputted strings will contain
 * "\n\r" instead of just "\n".
 *
 * @param string text The string to operate on.
 *
 * @return string The converted string.
 */
PHP_METHOD(Phady_Util_Text, nl2html) {

	zval *text_param = NULL, *str = NULL, _0, _1, *_2, _3, _4;
	zval *text = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &text_param);

	zephir_get_strval(text, text_param);


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "\n", 0);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "<br />", 0);
	ZEPHIR_INIT_VAR(str);
	zephir_fast_str_replace(&str, &_0, &_1, text TSRMLS_CC);
	ZEPHIR_INIT_VAR(_2);
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_STRING(&_3, "\r", 0);
	ZEPHIR_SINIT_VAR(_4);
	ZVAL_STRING(&_4, "", 0);
	zephir_fast_str_replace(&_2, &_3, &_4, str TSRMLS_CC);
	ZEPHIR_CPY_WRT(str, _2);
	RETURN_CCTOR(str);

}

/**
 * Tokenize a string according to the given parameters.
 *
 * This function just wraps explode to provide a more java-similar syntax.
 *
 * @param string  text    The string to tokenize.
 * @param string  delimeter The delimeter to use.
 * @param int max       The maximal number of tokens to generate (optional) (default=999999).
 *
 * @return array The token array.
 */
PHP_METHOD(Phady_Util_Text, tokenize) {

	int max;
	zval *text_param = NULL, *delimeter_param = NULL, *max_param = NULL, _0;
	zval *text = NULL, *delimeter = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &text_param, &delimeter_param, &max_param);

	zephir_get_strval(text, text_param);
	zephir_get_strval(delimeter, delimeter_param);
	if (!max_param) {
		max = 999999;
	} else {
		max = zephir_get_intval(max_param);
	}


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, max);
	zephir_fast_explode(return_value, delimeter, text, zephir_get_intval(&_0)  TSRMLS_CC);
	RETURN_MM();

}

/**
 * Case-Insensitive version of strpos (standard only available in PHP 5)
 *
 * @param string  haystack The string to search.
 * @param string  needle   The string to search for.
 * @param int offset   The search start offset position (optional) (default=0).
 *
 * @return array The token array.
 */
PHP_METHOD(Phady_Util_Text, stripos) {

	zephir_fcall_cache_entry *_1 = NULL;
	int offset, ZEPHIR_LAST_CALL_STATUS;
	zval *haystack_param = NULL, *needle_param = NULL, *offset_param = NULL, *_0 = NULL, *_2 = NULL, _3;
	zval *haystack = NULL, *needle = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &haystack_param, &needle_param, &offset_param);

	zephir_get_strval(haystack, haystack_param);
	zephir_get_strval(needle, needle_param);
	if (!offset_param) {
		offset = 0;
	} else {
		offset = zephir_get_intval(offset_param);
	}


	ZEPHIR_CALL_FUNCTION(&_0, "mb_strtoupper", &_1, 117, haystack);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_2, "mb_strtoupper", &_1, 117, needle);
	zephir_check_call_status();
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_LONG(&_3, offset);
	ZEPHIR_RETURN_CALL_FUNCTION("mb_strpos", NULL, 122, _0, _2, &_3);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns the left x chars of a string.
 *
 * If the string is longer than x, the whole string is returned.
 *
 * @param string  text The string to operate on.
 * @param int left   The number of chars to return.
 *
 * @return string A part of the supplied string.
 */
PHP_METHOD(Phady_Util_Text, left) {

	int left, ZEPHIR_LAST_CALL_STATUS;
	zval *text_param = NULL, *left_param = NULL, *len = NULL, _0, _1, *_2 = NULL;
	zval *text = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &text_param, &left_param);

	zephir_get_strval(text, text_param);
	if (!left_param) {
		left = 0;
	} else {
		left = zephir_get_intval(left_param);
	}


	ZEPHIR_CALL_FUNCTION(&len, "mb_strlen", NULL, 123, text);
	zephir_check_call_status();
	if (ZEPHIR_GT_LONG(len, left)) {
		ZEPHIR_SINIT_VAR(_0);
		ZVAL_LONG(&_0, 0);
		ZEPHIR_SINIT_VAR(_1);
		ZVAL_LONG(&_1, left);
		ZEPHIR_CALL_FUNCTION(&_2, "mb_substr", NULL, 118, text, &_0, &_1);
		zephir_check_call_status();
		zephir_get_strval(text, _2);
	}
	RETURN_CTOR(text);

}

/**
 * Returns the right x chars of a string.
 *
 * If the string is longer than x, the whole string is returned.
 *
 * @param string  text The string to operate on.
 * @param integer right  The number of chars to return.
 *
 * @return string A part of the supplied string.
 */
PHP_METHOD(Phady_Util_Text, right) {

	int right, ZEPHIR_LAST_CALL_STATUS;
	zval *text_param = NULL, *right_param = NULL, *len = NULL, _0, _1, *_2 = NULL;
	zval *text = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &text_param, &right_param);

	zephir_get_strval(text, text_param);
	if (!right_param) {
		right = 0;
	} else {
		right = zephir_get_intval(right_param);
	}


	ZEPHIR_CALL_FUNCTION(&len, "mb_strlen", NULL, 123, text);
	zephir_check_call_status();
	if (ZEPHIR_GT_LONG(len, right)) {
		ZEPHIR_SINIT_VAR(_0);
		ZVAL_LONG(&_0, (zephir_get_numberval(len) - right));
		ZEPHIR_SINIT_VAR(_1);
		ZVAL_LONG(&_1, right);
		ZEPHIR_CALL_FUNCTION(&_2, "mb_substr", NULL, 118, text, &_0, &_1);
		zephir_check_call_status();
		zephir_get_strval(text, _2);
	}
	RETURN_CTOR(text);

}

/**
 * Compares two strings.
 *
 * This method implements a constant-time algorithm to compare strings.
 * Regardless of the used implementation, it will leak length information.
 *
 * @param string knownString The string of known length to compare against
 * @param string userInput   The string that the user can control
 *
 * @return bool true if the two strings are the same, false otherwise
 */
PHP_METHOD(Phady_Util_Text, equals) {

	zval *_0 = NULL, *_1 = NULL;
	int result, ZEPHIR_LAST_CALL_STATUS;
	zval *knownString = NULL, *userInput = NULL, *knownLen = NULL, *userLen = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &knownString, &userInput);

	ZEPHIR_SEPARATE_PARAM(knownString);
	ZEPHIR_SEPARATE_PARAM(userInput);


	if (!(Z_TYPE_P(knownString) == IS_STRING)) {
		zephir_get_strval(_0, knownString);
		ZEPHIR_CPY_WRT(knownString, _0);
	}
	if (!(Z_TYPE_P(userInput) == IS_STRING)) {
		zephir_get_strval(_1, userInput);
		ZEPHIR_CPY_WRT(userInput, _1);
	}
	if ((zephir_function_exists_ex(SS("hash_equals") TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_RETURN_CALL_FUNCTION("hash_equals", NULL, 0, knownString, userInput);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_CALL_SELF(&knownLen, "safestrlen", NULL, 0, knownString);
	zephir_check_call_status();
	ZEPHIR_CALL_SELF(&userLen, "safestrlen", NULL, 0, userInput);
	zephir_check_call_status();
	if (!ZEPHIR_IS_IDENTICAL(userLen, knownLen)) {
		RETURN_MM_BOOL(0);
	}
	result = 0;
	RETURN_MM_BOOL(ZEPHIR_IS_IDENTICAL(knownString, userInput));

}

/**
 * Returns the number of bytes in a string.
 *
 * @param string string The string whose length we wish to obtain
 *
 * @return int
 */
PHP_METHOD(Phady_Util_Text, safeStrlen) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *text_param = NULL, *funcExists = NULL, _0;
	zval *text = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &text_param);

	zephir_get_strval(text, text_param);


	ZEPHIR_INIT_VAR(funcExists);
	ZVAL_NULL(funcExists);
	if (Z_TYPE_P(funcExists) == IS_NULL) {
		ZEPHIR_INIT_NVAR(funcExists);
		ZVAL_BOOL(funcExists, (zephir_function_exists_ex(SS("mb_strlen") TSRMLS_CC) == SUCCESS));
	}
	if (zephir_is_true(funcExists)) {
		ZEPHIR_SINIT_VAR(_0);
		ZVAL_STRING(&_0, "8bit", 0);
		ZEPHIR_RETURN_CALL_FUNCTION("mb_strlen", NULL, 123, text, &_0);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_MM_LONG(zephir_fast_strlen_ev(text));

}

