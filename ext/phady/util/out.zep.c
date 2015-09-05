
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
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/object.h"


/**
  * @class Phady\Util\Out - Util class for print
  *
  * @author  Alien Fernández Fuentes <alienfernandez85@gmail.com>
  * @package Util
  * @copyright (c) 2015
  * @version 1.0.0
  */
ZEPHIR_INIT_CLASS(Phady_Util_Out) {

	ZEPHIR_REGISTER_CLASS(Phady\\Util, Out, phady, util_out, phady_util_out_method_entry, 0);

	return SUCCESS;

}

/**
 * Display a variable"s contents using nice HTML formatting and will
 * properly display the value of booleans as true or false
 *
 * @see var_dump_plain()
 *
 * @param  mixed var The variable to dump
 * @return string
 */
PHP_METHOD(Phady_Util_Out, dump) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *varToDump, *returnDump = NULL, *expandLevel = NULL, *_0, *_1, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &varToDump, &returnDump, &expandLevel);

	if (!returnDump) {
		returnDump = ZEPHIR_GLOBAL(global_false);
	}
	if (!expandLevel) {
		ZEPHIR_INIT_VAR(expandLevel);
		ZVAL_LONG(expandLevel, 1);
	}


	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, zephir_get_intval(expandLevel));
	ZEPHIR_INIT_VAR(_2);
	ZVAL_LONG(_2, 0);
	ZEPHIR_RETURN_CALL_SELF("var_dump_plain", NULL, 0, varToDump, _1, _2, _0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Display a variable"s contents using nice HTML formatting (Without
 * the <pre> tag) and will properly display the values of variables
 * like booleans and resources. Supports collapsable arrays and objects
 * as well.
 *
 * @param  mixed var The variable to dump
 * @return string
 */
PHP_METHOD(Phady_Util_Out, var_dump_plain) {

	zval *done = NULL;
	int expLevel, depth;
	zval *varToDump, *expLevel_param = NULL, *depth_param = NULL, *done_param = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 2, &varToDump, &expLevel_param, &depth_param, &done_param);

	expLevel = zephir_get_intval(expLevel_param);
	if (!depth_param) {
		depth = 0;
	} else {
		depth = zephir_get_intval(depth_param);
	}
	if (!done_param) {
		ZEPHIR_INIT_VAR(done);
		array_init(done);
	} else {
		zephir_get_arrval(done, done_param);
	}



}

/**
 * Convert entities, while preserving already-encoded entities.
 *
 * @param  string string The text to be converted
 * @return string
 */
PHP_METHOD(Phady_Util_Out, htmlentities) {

	zephir_fcall_cache_entry *_3 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool preserve_encoded_entities;
	zval *text_param = NULL, *preserve_encoded_entities_param = NULL, *translation_table = NULL, _0 = zval_used_for_init, *_1 = NULL, _2 = zval_used_for_init, *_4 = NULL, *_5, *_6 = NULL, *_7, *_8;
	zval *text = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &text_param, &preserve_encoded_entities_param);

	zephir_get_strval(text, text_param);
	if (!preserve_encoded_entities_param) {
		preserve_encoded_entities = 0;
	} else {
		preserve_encoded_entities = zephir_get_boolval(preserve_encoded_entities_param);
	}


	if (preserve_encoded_entities) {
		ZEPHIR_SINIT_VAR(_0);
		ZVAL_STRING(&_0, "HHVM_VERSION", 0);
		ZEPHIR_CALL_FUNCTION(&_1, "defined", NULL, 106, &_0);
		zephir_check_call_status();
		if (zephir_is_true(_1)) {
			ZEPHIR_SINIT_NVAR(_0);
			ZVAL_LONG(&_0, 1);
			ZEPHIR_SINIT_VAR(_2);
			ZVAL_LONG(&_2, 3);
			ZEPHIR_CALL_FUNCTION(&translation_table, "get_html_translation_table", &_3, 107, &_0, &_2);
			zephir_check_call_status();
		} else {
			ZEPHIR_CALL_SELF(&_4, "mbinternalencoding", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_SINIT_NVAR(_0);
			ZVAL_LONG(&_0, 1);
			ZEPHIR_SINIT_NVAR(_2);
			ZVAL_LONG(&_2, 3);
			ZEPHIR_CALL_FUNCTION(&translation_table, "get_html_translation_table", &_3, 107, &_0, &_2, _4);
			zephir_check_call_status();
		}
		ZEPHIR_SINIT_NVAR(_0);
		ZVAL_LONG(&_0, 38);
		ZEPHIR_CALL_FUNCTION(&_4, "chr", NULL, 108, &_0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_5);
		ZVAL_LONG(_5, '&');
		zephir_array_update_zval(&translation_table, _4, &_5, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_FUNCTION(&_6, "strtr", NULL, 109, text, translation_table);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_7);
		ZVAL_STRING(_7, "/&(?![A-Za-z]{0,4}\\w{2,3};|#[0-9]{2,3};)/", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_INIT_VAR(_8);
		ZVAL_STRING(_8, "&amp;", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_RETURN_CALL_FUNCTION("preg_replace", NULL, 110, _7, _8, _6);
		zephir_check_temp_parameter(_7);
		zephir_check_temp_parameter(_8);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_CALL_SELF(&_1, "mbinternalencoding", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_LONG(&_0, 3);
	ZEPHIR_RETURN_CALL_FUNCTION("htmlentities", NULL, 111, text, &_0, _1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Wrapper to prevent errors if the user doesn't have the mbstring
 * extension installed.
 *
 * @param  string encoding
 * @return string
 */
PHP_METHOD(Phady_Util_Out, mbInternalEncoding) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval *encoding = NULL, *_0 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &encoding);

	if (!encoding) {
		encoding = ZEPHIR_GLOBAL(global_null);
	}


	if ((zephir_function_exists_ex(SS("mb_internal_encoding") TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_INIT_VAR(_0);
		if (zephir_is_true(encoding)) {
			ZEPHIR_CALL_FUNCTION(&_0, "mb_internal_encoding", &_1, 112, encoding);
			zephir_check_call_status();
		} else {
			ZEPHIR_CALL_FUNCTION(&_0, "mb_internal_encoding", &_1, 112);
			zephir_check_call_status();
		}
		RETURN_CCTOR(_0);
	}
	RETURN_MM_STRING("UTF-8", 1);

}

