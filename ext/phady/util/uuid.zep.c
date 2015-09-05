
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
#include "kernel/math.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/string.h"
#include "kernel/concat.h"


/**
  * @class Phady\Util\Uuid - Util class for generate uuid
  *
  * @author  Alien Fernández Fuentes <alienfernandez85@gmail.com>
  * @package Util
  * @copyright (c) 2015
  * @version 1.0.0
  */
ZEPHIR_INIT_CLASS(Phady_Util_Uuid) {

	ZEPHIR_REGISTER_CLASS(Phady\\Util, Uuid, phady, util_uuid, phady_util_uuid_method_entry, 0);

	return SUCCESS;

}

/**
 * Generates version 1: MAC address
 */
PHP_METHOD(Phady_Util_Uuid, v1) {



}

/**
 *
 * Generate v4 UUID
 *
 * Version 4 UUIDs are pseudo-random.
 */
PHP_METHOD(Phady_Util_Uuid, v4) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24;

	ZEPHIR_MM_GROW();

	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, 0);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_LONG(&_1, 0xffff);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_LONG(&_2, 0);
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_LONG(&_3, 0xffff);
	ZEPHIR_SINIT_VAR(_4);
	ZVAL_LONG(&_4, 0);
	ZEPHIR_SINIT_VAR(_5);
	ZVAL_LONG(&_5, 0xffff);
	ZEPHIR_SINIT_VAR(_6);
	ZVAL_LONG(&_6, 0);
	ZEPHIR_SINIT_VAR(_7);
	ZVAL_LONG(&_7, 0x0fff);
	ZEPHIR_SINIT_VAR(_8);
	ZVAL_LONG(&_8, 0);
	ZEPHIR_SINIT_VAR(_9);
	ZVAL_LONG(&_9, 0x3fff);
	ZEPHIR_SINIT_VAR(_10);
	ZVAL_LONG(&_10, 0);
	ZEPHIR_SINIT_VAR(_11);
	ZVAL_LONG(&_11, 0xffff);
	ZEPHIR_SINIT_VAR(_12);
	ZVAL_LONG(&_12, 0);
	ZEPHIR_SINIT_VAR(_13);
	ZVAL_LONG(&_13, 0xffff);
	ZEPHIR_SINIT_VAR(_14);
	ZVAL_LONG(&_14, 0);
	ZEPHIR_SINIT_VAR(_15);
	ZVAL_LONG(&_15, 0xffff);
	ZEPHIR_SINIT_VAR(_16);
	ZVAL_STRING(&_16, "%04x%04x-%04x-%04x-%04x-%04x%04x%04x", 0);
	ZEPHIR_SINIT_VAR(_17);
	ZVAL_LONG(&_17, zephir_mt_rand(zephir_get_intval(&_0), zephir_get_intval(&_1) TSRMLS_CC));
	ZEPHIR_SINIT_VAR(_18);
	ZVAL_LONG(&_18, zephir_mt_rand(zephir_get_intval(&_2), zephir_get_intval(&_3) TSRMLS_CC));
	ZEPHIR_SINIT_VAR(_19);
	ZVAL_LONG(&_19, zephir_mt_rand(zephir_get_intval(&_4), zephir_get_intval(&_5) TSRMLS_CC));
	ZEPHIR_SINIT_VAR(_20);
	ZVAL_LONG(&_20, (zephir_mt_rand(zephir_get_intval(&_6), zephir_get_intval(&_7) TSRMLS_CC) | 0x4000));
	ZEPHIR_SINIT_VAR(_21);
	ZVAL_LONG(&_21, (zephir_mt_rand(zephir_get_intval(&_8), zephir_get_intval(&_9) TSRMLS_CC) | 0x8000));
	ZEPHIR_SINIT_VAR(_22);
	ZVAL_LONG(&_22, zephir_mt_rand(zephir_get_intval(&_10), zephir_get_intval(&_11) TSRMLS_CC));
	ZEPHIR_SINIT_VAR(_23);
	ZVAL_LONG(&_23, zephir_mt_rand(zephir_get_intval(&_12), zephir_get_intval(&_13) TSRMLS_CC));
	ZEPHIR_SINIT_VAR(_24);
	ZVAL_LONG(&_24, zephir_mt_rand(zephir_get_intval(&_14), zephir_get_intval(&_15) TSRMLS_CC));
	ZEPHIR_RETURN_CALL_FUNCTION("sprintf", NULL, 23, &_16, &_17, &_18, &_19, &_20, &_21, &_22, &_23, &_24);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Generate v5 UUID
 *
 * Version 5 UUIDs are named based. They require a namespace (another
 * valid UUID) and a value (the name). Given the same namespace and
 * name, the output is always the same.
 *
 * @param uuid $namespace
 * @param string $name
 */
PHP_METHOD(Phady_Util_Uuid, v5) {

	zval *ns_param = NULL, *name_param = NULL;
	zval *ns = NULL, *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &ns_param, &name_param);

	zephir_get_strval(ns, ns_param);
	zephir_get_strval(name, name_param);



}

PHP_METHOD(Phady_Util_Uuid, is_valid) {

	zval *_2;
	zval *uuid, *_0, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &uuid);



	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_INIT_VAR(_2);
	ZEPHIR_CONCAT_SS(_2, "/^\\{?[0-9a-f]{8}\\-?[0-9a-f]{4}\\-?[0-9a-f]{4}\\-?", "[0-9a-f]{4}\\-?[0-9a-f]{12}\\}?$/i");
	zephir_preg_match(_1, _2, uuid, _0, 0, 0 , 0  TSRMLS_CC);
	RETURN_MM_BOOL(ZEPHIR_IS_LONG_IDENTICAL(_1, 1));

}

