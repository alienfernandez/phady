
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
#include "kernel/array.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/string.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"


/**
  * @class Phady\Util\Tools - Util class tools for app, server vars, ini values, etc...
  *
  * @author  Alien Fernández Fuentes <alienfernandez85@gmail.com>
  * @package Util
  * @copyright (c) 2015
  * @version 1.0.0
  */
ZEPHIR_INIT_CLASS(Phady_Util_Tools) {

	ZEPHIR_REGISTER_CLASS(Phady\\Util, Tools, phady, util_tools, phady_util_tools_method_entry, 0);

	zend_declare_class_constant_string(phady_util_tools_ce, SL("REQUEST_PROTOCOL_HTTP"), "http" TSRMLS_CC);

	zend_declare_class_constant_string(phady_util_tools_ce, SL("REQUEST_PROTOCOL_HTTPS"), "https" TSRMLS_CC);

	return SUCCESS;

}

/**
 * Get the server variable SERVER_NAME
 *
 * @return string server name
 */
PHP_METHOD(Phady_Util_Tools, getServerName) {

	zend_bool _0;
	zval *server = NULL, *_SERVER, *_1;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);
	ZEPHIR_INIT_VAR(server);
	ZVAL_STRING(server, "", 1);

	_0 = zephir_array_isset_string(_SERVER, SS("HTTP_X_FORWARDED_SERVER"));
	if (_0) {
		zephir_array_fetch_string(&_1, _SERVER, SL("HTTP_X_FORWARDED_SERVER"), PH_NOISY | PH_READONLY, "phady/util/tools.zep", 37 TSRMLS_CC);
		_0 = zephir_is_true(_1);
	}
	if (_0) {
		ZEPHIR_OBS_NVAR(server);
		zephir_array_fetch_string(&server, _SERVER, SL("HTTP_X_FORWARDED_SERVER"), PH_NOISY, "phady/util/tools.zep", 38 TSRMLS_CC);
	} else {
		ZEPHIR_OBS_NVAR(server);
		zephir_array_fetch_string(&server, _SERVER, SL("SERVER_NAME"), PH_NOISY, "phady/util/tools.zep", 40 TSRMLS_CC);
	}
	RETURN_CCTOR(server);

}

/**
 * Get the server variable HTTP_HOST
 *
 * @return string host http name
 */
PHP_METHOD(Phady_Util_Tools, getHttpHost) {

	zend_bool _0;
	zval *server = NULL, *_SERVER, *_1;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);
	ZEPHIR_INIT_VAR(server);
	ZVAL_STRING(server, "", 1);

	_0 = zephir_array_isset_string(_SERVER, SS("HTTP_HOST"));
	if (_0) {
		zephir_array_fetch_string(&_1, _SERVER, SL("HTTP_HOST"), PH_NOISY | PH_READONLY, "phady/util/tools.zep", 53 TSRMLS_CC);
		_0 = zephir_is_true(_1);
	}
	if (_0) {
		ZEPHIR_OBS_NVAR(server);
		zephir_array_fetch_string(&server, _SERVER, SL("HTTP_HOST"), PH_NOISY, "phady/util/tools.zep", 54 TSRMLS_CC);
	}
	RETURN_CCTOR(server);

}

/**
 * Get the protocol used by the app - http|https
 *
 * @return string
 */
PHP_METHOD(Phady_Util_Tools, getRequestProtocol) {

	zval *_SERVER, *_1, _2, *_4, _6, *_8, _10, *_12, *_14, *_15;
	zend_bool isSecure = 0, _0, _3, _5, _7, _9, _11, _13;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);

	_0 = zephir_array_isset_string(_SERVER, SS("HTTPS"));
	if (_0) {
		zephir_array_fetch_string(&_1, _SERVER, SL("HTTPS"), PH_NOISY | PH_READONLY, "phady/util/tools.zep", 66 TSRMLS_CC);
		_0 = ZEPHIR_IS_STRING(_1, "on");
	}
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_STRING(&_2, "HTTP_X_FORWARDED_PROTO", 0);
	_3 = zephir_array_key_exists(_SERVER, &_2 TSRMLS_CC);
	if (_3) {
		ZEPHIR_OBS_VAR(_4);
		zephir_array_fetch_string(&_4, _SERVER, SL("HTTP_X_FORWARDED_PROTO"), PH_NOISY, "phady/util/tools.zep", 68 TSRMLS_CC);
		_3 = !(ZEPHIR_IS_EMPTY(_4));
	}
	_5 = _3;
	if (_5) {
		ZEPHIR_SINIT_VAR(_6);
		ZVAL_STRING(&_6, "HTTP_X_FORWARDED_PROTO", 0);
		_7 = zephir_array_key_exists(_SERVER, &_6 TSRMLS_CC);
		if (_7) {
			zephir_array_fetch_string(&_8, _SERVER, SL("HTTP_X_FORWARDED_PROTO"), PH_NOISY | PH_READONLY, "phady/util/tools.zep", 69 TSRMLS_CC);
			_7 = ZEPHIR_IS_STRING(_8, "https");
		}
		_5 = _7;
	}
	_9 = _5;
	if (!(_9)) {
		ZEPHIR_SINIT_VAR(_10);
		ZVAL_STRING(&_10, "HTTP_X_FORWARDED_SSL", 0);
		_11 = zephir_array_key_exists(_SERVER, &_10 TSRMLS_CC);
		if (_11) {
			ZEPHIR_OBS_VAR(_12);
			zephir_array_fetch_string(&_12, _SERVER, SL("HTTP_X_FORWARDED_SSL"), PH_NOISY, "phady/util/tools.zep", 70 TSRMLS_CC);
			_11 = !(ZEPHIR_IS_EMPTY(_12));
		}
		_13 = _11;
		if (_13) {
			zephir_array_fetch_string(&_14, _SERVER, SL("HTTP_X_FORWARDED_SSL"), PH_NOISY | PH_READONLY, "phady/util/tools.zep", 71 TSRMLS_CC);
			_13 = ZEPHIR_IS_STRING(_14, "on");
		}
		_9 = _13;
	}
	if (_0) {
		isSecure = 1;
	} else if (_9) {
		isSecure = 1;
	}
	ZEPHIR_INIT_VAR(_15);
	if (isSecure) {
		ZVAL_STRING(_15, "http", 1);
	} else {
		ZVAL_STRING(_15, "https", 1);
	}
	RETURN_CCTOR(_15);

}

/**
 * Get the server variable REMOTE_ADDR, or the first ip of HTTP_X_FORWARDED_FOR (when using proxy)
 *
 * @return string $remote_addr ip of client
 */
PHP_METHOD(Phady_Util_Tools, getRemoteAddr) {

	zend_bool _0, _2, _3, _9, _15, _21;
	zval *ips, *remoteAddr = NULL, *_SERVER, *_1, *_4, *_5, *_6, *_7, _8, *_10, *_11, *_12, *_13, _14, *_16, *_17, *_18, *_19, _20, *_22, *_23, *_24, *_25, _26, *_27, _28, *_29, *_30;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);

	_0 = zephir_array_isset_string(_SERVER, SS("HTTP_X_FORWARDED_FOR"));
	if (_0) {
		zephir_array_fetch_string(&_1, _SERVER, SL("HTTP_X_FORWARDED_FOR"), PH_NOISY | PH_READONLY, "phady/util/tools.zep", 86 TSRMLS_CC);
		_0 = zephir_is_true(_1);
	}
	_2 = _0;
	if (_2) {
		_3 = !(zephir_array_isset_string(_SERVER, SS("REMOTE_ADDR")));
		if (!(_3)) {
			ZEPHIR_INIT_VAR(_4);
			ZEPHIR_INIT_VAR(_5);
			ZEPHIR_INIT_VAR(_6);
			zephir_array_fetch_string(&_7, _SERVER, SL("REMOTE_ADDR"), PH_NOISY | PH_READONLY, "phady/util/tools.zep", 87 TSRMLS_CC);
			zephir_fast_trim(_6, _7, NULL , ZEPHIR_TRIM_BOTH TSRMLS_CC);
			ZEPHIR_SINIT_VAR(_8);
			ZVAL_STRING(&_8, "/^127\\..*/i", 0);
			zephir_preg_match(_5, &_8, _6, _4, 0, 0 , 0  TSRMLS_CC);
			_3 = zephir_is_true(_5);
		}
		_9 = _3;
		if (!(_9)) {
			ZEPHIR_INIT_VAR(_10);
			ZEPHIR_INIT_VAR(_11);
			ZEPHIR_INIT_VAR(_12);
			zephir_array_fetch_string(&_13, _SERVER, SL("REMOTE_ADDR"), PH_NOISY | PH_READONLY, "phady/util/tools.zep", 87 TSRMLS_CC);
			zephir_fast_trim(_12, _13, NULL , ZEPHIR_TRIM_BOTH TSRMLS_CC);
			ZEPHIR_SINIT_VAR(_14);
			ZVAL_STRING(&_14, "/^172\\.16.*/i", 0);
			zephir_preg_match(_11, &_14, _12, _10, 0, 0 , 0  TSRMLS_CC);
			_9 = zephir_is_true(_11);
		}
		_15 = _9;
		if (!(_15)) {
			ZEPHIR_INIT_VAR(_16);
			ZEPHIR_INIT_VAR(_17);
			ZEPHIR_INIT_VAR(_18);
			zephir_array_fetch_string(&_19, _SERVER, SL("REMOTE_ADDR"), PH_NOISY | PH_READONLY, "phady/util/tools.zep", 88 TSRMLS_CC);
			zephir_fast_trim(_18, _19, NULL , ZEPHIR_TRIM_BOTH TSRMLS_CC);
			ZEPHIR_SINIT_VAR(_20);
			ZVAL_STRING(&_20, "/^192\\.168\\.*/i", 0);
			zephir_preg_match(_17, &_20, _18, _16, 0, 0 , 0  TSRMLS_CC);
			_15 = zephir_is_true(_17);
		}
		_21 = _15;
		if (!(_21)) {
			ZEPHIR_INIT_VAR(_22);
			ZEPHIR_INIT_VAR(_23);
			ZEPHIR_INIT_VAR(_24);
			zephir_array_fetch_string(&_25, _SERVER, SL("REMOTE_ADDR"), PH_NOISY | PH_READONLY, "phady/util/tools.zep", 88 TSRMLS_CC);
			zephir_fast_trim(_24, _25, NULL , ZEPHIR_TRIM_BOTH TSRMLS_CC);
			ZEPHIR_SINIT_VAR(_26);
			ZVAL_STRING(&_26, "/^10\\..*/i", 0);
			zephir_preg_match(_23, &_26, _24, _22, 0, 0 , 0  TSRMLS_CC);
			_21 = zephir_is_true(_23);
		}
		_2 = _21;
	}
	if (_2) {
		zephir_array_fetch_string(&_27, _SERVER, SL("HTTP_X_FORWARDED_FOR"), PH_NOISY | PH_READONLY, "phady/util/tools.zep", 90 TSRMLS_CC);
		ZEPHIR_SINIT_VAR(_28);
		ZVAL_STRING(&_28, ",", 0);
		ZEPHIR_INIT_VAR(_29);
		zephir_fast_strpos(_29, _27, &_28, 0 );
		if (zephir_is_true(_29)) {
			zephir_array_fetch_string(&_30, _SERVER, SL("HTTP_X_FORWARDED_FOR"), PH_NOISY | PH_READONLY, "phady/util/tools.zep", 92 TSRMLS_CC);
			ZEPHIR_INIT_VAR(ips);
			zephir_fast_explode_str(ips, SL(","), _30, LONG_MAX TSRMLS_CC);
			ZEPHIR_OBS_VAR(remoteAddr);
			zephir_array_fetch_long(&remoteAddr, ips, 0, PH_NOISY, "phady/util/tools.zep", 93 TSRMLS_CC);
		} else {
			ZEPHIR_OBS_NVAR(remoteAddr);
			zephir_array_fetch_string(&remoteAddr, _SERVER, SL("HTTP_X_FORWARDED_FOR"), PH_NOISY, "phady/util/tools.zep", 96 TSRMLS_CC);
		}
	} else {
		ZEPHIR_OBS_NVAR(remoteAddr);
		zephir_array_fetch_string(&remoteAddr, _SERVER, SL("REMOTE_ADDR"), PH_NOISY, "phady/util/tools.zep", 99 TSRMLS_CC);
	}
	RETURN_CCTOR(remoteAddr);

}

/**
 * Check if the current page use SSL connection on not
 *
 * @return bool uses SSL
 */
PHP_METHOD(Phady_Util_Tools, usingSecureMode) {

	zval *_SERVER, *_0, *_2 = NULL, *_3;
	zend_bool secureMode, _1;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);

	if (zephir_array_isset_string(_SERVER, SS("HTTPS"))) {
		zephir_array_fetch_string(&_0, _SERVER, SL("HTTPS"), PH_NOISY | PH_READONLY, "phady/util/tools.zep", 113 TSRMLS_CC);
		_1 = ZEPHIR_IS_LONG(_0, 1);
		if (!(_1)) {
			ZEPHIR_INIT_VAR(_2);
			zephir_array_fetch_string(&_3, _SERVER, SL("HTTPS"), PH_NOISY | PH_READONLY, "phady/util/tools.zep", 113 TSRMLS_CC);
			zephir_fast_strtolower(_2, _3);
			_1 = ZEPHIR_IS_STRING(_2, "on");
		}
		secureMode = _1;
	} else if (zephir_array_isset_string(_SERVER, SS("SSL"))) {
		zephir_array_fetch_string(&_0, _SERVER, SL("SSL"), PH_NOISY | PH_READONLY, "phady/util/tools.zep", 117 TSRMLS_CC);
		_1 = ZEPHIR_IS_LONG(_0, 1);
		if (!(_1)) {
			ZEPHIR_INIT_NVAR(_2);
			zephir_array_fetch_string(&_3, _SERVER, SL("SSL"), PH_NOISY | PH_READONLY, "phady/util/tools.zep", 117 TSRMLS_CC);
			zephir_fast_strtolower(_2, _3);
			_1 = ZEPHIR_IS_STRING(_2, "on");
		}
		secureMode = _1;
	} else {
		secureMode = 0;
	}
	RETURN_MM_BOOL(secureMode);

}

/**
 * getMemoryLimit allow to get the memory limit in octet
 *
 * @return int the memory limit value in octet
 */
PHP_METHOD(Phady_Util_Tools, getMemoryLimit) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *memory_limit = NULL, *getOctect = NULL, _0;

	ZEPHIR_MM_GROW();

	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "memory_limit", 0);
	ZEPHIR_CALL_FUNCTION(&memory_limit, "ini_get", NULL, 135, &_0);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "print_r", NULL, 27, memory_limit);
	zephir_check_call_status();
	ZEPHIR_CALL_SELF(&getOctect, "getoctets", NULL, 0, memory_limit);
	zephir_check_call_status();
	RETURN_CCTOR(getOctect);

}

/**
 * getOctet allow to gets the value of a configuration option in octet
 *
 * @return int the value of a configuration option in octet
 */
PHP_METHOD(Phady_Util_Tools, getOctets) {

	int size, ZEPHIR_LAST_CALL_STATUS;
	zval *option, *_0, *_1, _2, *_3, *_4, _5, *_6, *_7, _8, *_9 = NULL, *_10 = NULL, *_11 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &option);



	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_STRING(&_2, "/[0-9]+k/i", 0);
	zephir_preg_match(_1, &_2, option, _0, 0, 0 , 0  TSRMLS_CC);
	ZEPHIR_INIT_VAR(_3);
	ZEPHIR_INIT_VAR(_4);
	ZEPHIR_SINIT_VAR(_5);
	ZVAL_STRING(&_5, "/[0-9]+m/i", 0);
	zephir_preg_match(_4, &_5, option, _3, 0, 0 , 0  TSRMLS_CC);
	ZEPHIR_INIT_VAR(_6);
	ZEPHIR_INIT_VAR(_7);
	ZEPHIR_SINIT_VAR(_8);
	ZVAL_STRING(&_8, "/[0-9]+g/i", 0);
	zephir_preg_match(_7, &_8, option, _6, 0, 0 , 0  TSRMLS_CC);
	if (zephir_is_true(_1)) {
		ZEPHIR_INIT_VAR(_9);
		ZVAL_STRING(_9, "/m/i", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_INIT_VAR(_10);
		ZVAL_STRING(_10, "", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_FUNCTION(&_11, "preg_replace", NULL, 122, _9, _10, option);
		zephir_check_temp_parameter(_9);
		zephir_check_temp_parameter(_10);
		zephir_check_call_status();
		size = (zephir_get_intval(_11) * 1024);
	} else if (zephir_is_true(_4)) {
		ZEPHIR_INIT_NVAR(_9);
		ZVAL_STRING(_9, "/m/i", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_INIT_NVAR(_10);
		ZVAL_STRING(_10, "", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_FUNCTION(&_11, "preg_replace", NULL, 122, _9, _10, option);
		zephir_check_temp_parameter(_9);
		zephir_check_temp_parameter(_10);
		zephir_check_call_status();
		size = (1048576 * zephir_get_intval(_11));
	} else if (zephir_is_true(_7)) {
		ZEPHIR_INIT_NVAR(_9);
		ZVAL_STRING(_9, "/g/i", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_INIT_NVAR(_10);
		ZVAL_STRING(_10, "", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_FUNCTION(&_11, "preg_replace", NULL, 122, _9, _10, option);
		zephir_check_temp_parameter(_9);
		zephir_check_temp_parameter(_10);
		zephir_check_call_status();
		size = ((1048576 * 1024) * zephir_get_intval(_11));
	} else {
		size = zephir_get_numberval(option);
	}
	RETURN_MM_LONG(size);

}

/**
 * getHostName Get host name
 *
 * @return string
 */
PHP_METHOD(Phady_Util_Tools, getHostName) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *computerName = NULL, *hostname, _0, *_1 = NULL, *_2 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "COMPUTERNAME", 0);
	ZEPHIR_CALL_FUNCTION(&computerName, "getenv", NULL, 136, &_0);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_1, "gethostname", NULL, 137);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(hostname);
	ZEPHIR_CONCAT_VSV(hostname, _1, "|", computerName);
	ZEPHIR_INIT_VAR(_2);
	if (zephir_is_true(hostname)) {
		ZEPHIR_CPY_WRT(_2, hostname);
	} else {
		ZVAL_STRING(_2, "Desconocido", 1);
	}
	RETURN_CCTOR(_2);

}

/**
 * getUserAgent Get user agent
 *
 * @return string
 */
PHP_METHOD(Phady_Util_Tools, getUserAgent) {

	zval *_0, *_SERVER;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);

	ZEPHIR_INIT_VAR(_0);
	if (zephir_array_isset_string(_SERVER, SS("HTTP_USER_AGENT"))) {
		zephir_array_fetch_string(&_0, _SERVER, SL("HTTP_USER_AGENT"), PH_NOISY, "phady/util/tools.zep", 181 TSRMLS_CC);
	} else {
		ZVAL_STRING(_0, "Desconocido", 1);
	}
	RETURN_CCTOR(_0);

}

