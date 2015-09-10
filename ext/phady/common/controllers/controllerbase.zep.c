
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/string.h"
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/hash.h"
#include "ext/phalcon/phalcon/di/injectable.zep.h"


/**
 * Phady\Common\Controllers\ControllerBase
 *
 * Base Controller
 */
ZEPHIR_INIT_CLASS(Phady_Common_Controllers_ControllerBase) {

	ZEPHIR_REGISTER_CLASS_EX(Phady\\Common\\Controllers, ControllerBase, phady, common_controllers_controllerbase, phalcon_di_injectable_ce, phady_common_controllers_controllerbase_method_entry, 0);

	zend_declare_class_constant_string(phady_common_controllers_controllerbase_ce, SL("LOGIN_URI"), "login" TSRMLS_CC);

	zend_declare_class_constant_string(phady_common_controllers_controllerbase_ce, SL("PORTAL_URI"), "portal" TSRMLS_CC);

	return SUCCESS;

}

/**
 * initialize the class.
 * @name initialize
 * @return NULL
 */
PHP_METHOD(Phady_Common_Controllers_ControllerBase, initialize) {

	zval *_0, *_1, *_SERVER, *_2, _3;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);

	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_INIT_VAR(_1);
	zephir_array_fetch_string(&_2, _SERVER, SL("HTTP_USER_AGENT"), PH_NOISY | PH_READONLY, "phady/common/controllers/controllerbase.zep", 38 TSRMLS_CC);
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_STRING(&_3, "/(?i)msie [1-8]/", 0);
	zephir_preg_match(_1, &_3, _2, _0, 0, 0 , 0  TSRMLS_CC);
	if (zephir_is_true(_1)) {
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phady_Common_Controllers_ControllerBase, beforeExecuteRoute) {

	HashTable *_5;
	HashPosition _4;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *dispatcher, *map = NULL, *request = NULL, *listenersMap = NULL, *listener = NULL, *_0 = NULL, *_1 = NULL, *_2 = NULL, *controllerName = NULL, *actionName = NULL, *_3, **_6, *_7 = NULL, *_8 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &dispatcher);



	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getdi", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "request", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&request, _0, "get", NULL, 0, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "getdi", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "security.firewall.map", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&map, _2, "get", NULL, 0, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&listenersMap, map, "getlisteners", NULL, 0, request);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&controllerName, dispatcher, "getcontrollername", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&actionName, dispatcher, "getactionname", NULL, 0);
	zephir_check_call_status();
	zephir_array_fetch_long(&_3, listenersMap, 0, PH_NOISY | PH_READONLY, "phady/common/controllers/controllerbase.zep", 73 TSRMLS_CC);
	zephir_is_iterable(_3, &_5, &_4, 0, 0, "phady/common/controllers/controllerbase.zep", 81);
	for (
	  ; zephir_hash_get_current_data_ex(_5, (void**) &_6, &_4) == SUCCESS
	  ; zephir_hash_move_forward_ex(_5, &_4)
	) {
		ZEPHIR_GET_HVALUE(listener, _6);
		ZEPHIR_CALL_METHOD(&_7, this_ptr, "getdi", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_8, _7, "get", NULL, 0, listener);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _8, "handle", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

