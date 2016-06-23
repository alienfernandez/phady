
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
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/hash.h"
#include "kernel/operators.h"
#include "ext/phalcon/phalcon/mvc/router.zep.h"


/**
  * @class Phady\Route\Router -  Routing componente app
  *
  * @author  Alien Fernández Fuentes <alienfernandez85@gmail.com>
  * @package Core
  * @copyright (c) 2015
  * @version 1.0.0
  */
ZEPHIR_INIT_CLASS(Phady_Route_Router) {

	ZEPHIR_REGISTER_CLASS(Phady\\Route, Router, phady, route_router, phady_route_router_method_entry, 0);

	zend_declare_property_null(phady_route_router_ce, SL("config"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(phady_route_router_ce, SL("router"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(phady_route_router_ce, SL("configRoutes"), ZEND_ACC_PRIVATE TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Phady_Route_Router, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	object_init_ex(_0, phalcon_mvc_router_ce);
	ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("router"), _0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Constructor.
 *
 * @param string config The config route
 * @api
 */
PHP_METHOD(Phady_Route_Router, setConfig) {

	zval *config;

	zephir_fetch_params(0, 1, 0, &config);



	zephir_update_property_this(this_ptr, SL("config"), config TSRMLS_CC);

}

/**
 *
 * @return router
 */
PHP_METHOD(Phady_Route_Router, getRouter) {


	RETURN_MEMBER(this_ptr, "router");

}

/**
 * @name setDefaultRoute - Generate default route system
 * @return void
 */
PHP_METHOD(Phady_Route_Router, setDefaultRoute) {

	zval *_12, *_23;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *configDefaultMod, *_0, *_1, *_2, *_3, *_4, *_5, *_6, *_7, *_8, *_9, *_10, *_11, *_13, *_14, *_15 = NULL, *_16, *_17, *_18, *_19, *_20, *_21, *_22;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
	zephir_array_fetch_string(&_1, _0, SL("routing"), PH_NOISY | PH_READONLY, "phady/route/router.zep", 65 TSRMLS_CC);
	zephir_array_fetch_string(&_2, _1, SL("modules"), PH_NOISY | PH_READONLY, "phady/route/router.zep", 65 TSRMLS_CC);
	ZEPHIR_OBS_VAR(configDefaultMod);
	zephir_array_fetch_string(&configDefaultMod, _2, SL("default"), PH_NOISY, "phady/route/router.zep", 65 TSRMLS_CC);
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("router"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_4);
	ZVAL_BOOL(_4, 1);
	ZEPHIR_CALL_METHOD(NULL, _3, "removeextraslashes", NULL, 0, _4);
	zephir_check_call_status();
	_5 = zephir_fetch_nproperty_this(this_ptr, SL("router"), PH_NOISY_CC);
	zephir_array_fetch_string(&_6, configDefaultMod, SL("name"), PH_NOISY | PH_READONLY, "phady/route/router.zep", 68 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, _5, "setdefaultmodule", NULL, 0, _6);
	zephir_check_call_status();
	_7 = zephir_fetch_nproperty_this(this_ptr, SL("router"), PH_NOISY_CC);
	zephir_array_fetch_string(&_8, configDefaultMod, SL("namespace"), PH_NOISY | PH_READONLY, "phady/route/router.zep", 69 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, _7, "setdefaultnamespace", NULL, 0, _8);
	zephir_check_call_status();
	_9 = zephir_fetch_nproperty_this(this_ptr, SL("router"), PH_NOISY_CC);
	zephir_array_fetch_string(&_10, configDefaultMod, SL("route"), PH_NOISY | PH_READONLY, "phady/route/router.zep", 71 TSRMLS_CC);
	zephir_array_fetch_string(&_11, _10, SL("path"), PH_NOISY | PH_READONLY, "phady/route/router.zep", 71 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_12);
	zephir_create_array(_12, 4, 0 TSRMLS_CC);
	zephir_array_fetch_string(&_13, configDefaultMod, SL("route"), PH_NOISY | PH_READONLY, "phady/route/router.zep", 72 TSRMLS_CC);
	zephir_array_fetch_string(&_14, _13, SL("options"), PH_NOISY | PH_READONLY, "phady/route/router.zep", 72 TSRMLS_CC);
	ZEPHIR_OBS_VAR(_15);
	zephir_array_fetch_string(&_15, _14, SL("module"), PH_NOISY, "phady/route/router.zep", 72 TSRMLS_CC);
	zephir_array_update_string(&_12, SL("module"), &_15, PH_COPY | PH_SEPARATE);
	zephir_array_fetch_string(&_16, configDefaultMod, SL("route"), PH_NOISY | PH_READONLY, "phady/route/router.zep", 73 TSRMLS_CC);
	zephir_array_fetch_string(&_17, _16, SL("options"), PH_NOISY | PH_READONLY, "phady/route/router.zep", 73 TSRMLS_CC);
	ZEPHIR_OBS_NVAR(_15);
	zephir_array_fetch_string(&_15, _17, SL("ns"), PH_NOISY, "phady/route/router.zep", 73 TSRMLS_CC);
	zephir_array_update_string(&_12, SL("namespace"), &_15, PH_COPY | PH_SEPARATE);
	zephir_array_fetch_string(&_18, configDefaultMod, SL("route"), PH_NOISY | PH_READONLY, "phady/route/router.zep", 74 TSRMLS_CC);
	zephir_array_fetch_string(&_19, _18, SL("options"), PH_NOISY | PH_READONLY, "phady/route/router.zep", 74 TSRMLS_CC);
	ZEPHIR_OBS_NVAR(_15);
	zephir_array_fetch_string(&_15, _19, SL("controller"), PH_NOISY, "phady/route/router.zep", 74 TSRMLS_CC);
	zephir_array_update_string(&_12, SL("controller"), &_15, PH_COPY | PH_SEPARATE);
	zephir_array_fetch_string(&_20, configDefaultMod, SL("route"), PH_NOISY | PH_READONLY, "phady/route/router.zep", 75 TSRMLS_CC);
	zephir_array_fetch_string(&_21, _20, SL("options"), PH_NOISY | PH_READONLY, "phady/route/router.zep", 75 TSRMLS_CC);
	ZEPHIR_OBS_NVAR(_15);
	zephir_array_fetch_string(&_15, _21, SL("action"), PH_NOISY, "phady/route/router.zep", 76 TSRMLS_CC);
	zephir_array_update_string(&_12, SL("action"), &_15, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(NULL, _9, "add", NULL, 0, _11, _12);
	zephir_check_call_status();
	_22 = zephir_fetch_nproperty_this(this_ptr, SL("router"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_23);
	zephir_create_array(_23, 3, 0 TSRMLS_CC);
	add_assoc_stringl_ex(_23, SS("namespace"), SL("App\\Common\\Controllers"), 1);
	add_assoc_stringl_ex(_23, SS("controller"), SL("error"), 1);
	add_assoc_stringl_ex(_23, SS("action"), SL("route404"), 1);
	ZEPHIR_CALL_METHOD(NULL, _22, "notfound", NULL, 0, _23);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * @name setSystemRoutes - Build system paths routing config file
 * @param string rootDir - System root directory
 * @return void
 */
PHP_METHOD(Phady_Route_Router, setSystemRoutes) {

	HashTable *_8, *_12;
	HashPosition _7, _11;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval *rootDir_param = NULL, *_0 = NULL, *route = NULL, *arrOptionsRoute = NULL, *index = NULL, *optRoute = NULL, *_4 = NULL, *_5, *_6, **_9, *_10, **_13, *_14, *_15;
	zval *rootDir = NULL, *_2, *_3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &rootDir_param);

	zephir_get_strval(rootDir, rootDir_param);


	ZEPHIR_INIT_VAR(_2);
	ZEPHIR_CONCAT_VS(_2, rootDir, "/config/config.yml");
	ZEPHIR_CALL_CE_STATIC(&_0, phady_config_yaml_ce, "parse", &_1, 13, _2);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("config"), _0 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setdefaultroute", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_3);
	ZEPHIR_CONCAT_VS(_3, rootDir, "/config/routing.yml");
	ZEPHIR_CALL_FUNCTION(&_4, "yaml_parse_file", NULL, 26, _3);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("configRoutes"), _4 TSRMLS_CC);
	_5 = zephir_fetch_nproperty_this(this_ptr, SL("configRoutes"), PH_NOISY_CC);
	zephir_array_fetch_string(&_6, _5, SL("routes"), PH_NOISY | PH_READONLY, "phady/route/router.zep", 100 TSRMLS_CC);
	zephir_is_iterable(_6, &_8, &_7, 0, 0, "phady/route/router.zep", 107);
	for (
	  ; zephir_hash_get_current_data_ex(_8, (void**) &_9, &_7) == SUCCESS
	  ; zephir_hash_move_forward_ex(_8, &_7)
	) {
		ZEPHIR_GET_HVALUE(route, _9);
		ZEPHIR_INIT_NVAR(arrOptionsRoute);
		array_init(arrOptionsRoute);
		zephir_array_fetch_string(&_10, route, SL("options"), PH_NOISY | PH_READONLY, "phady/route/router.zep", 102 TSRMLS_CC);
		zephir_is_iterable(_10, &_12, &_11, 0, 0, "phady/route/router.zep", 105);
		for (
		  ; zephir_hash_get_current_data_ex(_12, (void**) &_13, &_11) == SUCCESS
		  ; zephir_hash_move_forward_ex(_12, &_11)
		) {
			ZEPHIR_GET_HMKEY(index, _12, _11);
			ZEPHIR_GET_HVALUE(optRoute, _13);
			zephir_array_update_zval(&arrOptionsRoute, index, &optRoute, PH_COPY | PH_SEPARATE);
		}
		_14 = zephir_fetch_nproperty_this(this_ptr, SL("router"), PH_NOISY_CC);
		zephir_array_fetch_string(&_15, route, SL("path"), PH_NOISY | PH_READONLY, "phady/route/router.zep", 105 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(NULL, _14, "add", NULL, 0, _15, arrOptionsRoute);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

