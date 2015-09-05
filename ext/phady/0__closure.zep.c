
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/array.h"


ZEPHIR_INIT_CLASS(phady_0__closure) {

	ZEPHIR_REGISTER_CLASS(phady, 0__closure, phady, 0__closure, phady_0__closure_method_entry, ZEND_ACC_FINAL_CLASS);

	return SUCCESS;

}

PHP_METHOD(phady_0__closure, __invoke) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *routeCore, *_SERVER, *_0;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);

	ZEPHIR_INIT_VAR(routeCore);
	object_init_ex(routeCore, phady_route_router_ce);
	ZEPHIR_CALL_METHOD(NULL, routeCore, "__construct", NULL, 127);
	zephir_check_call_status();
	zephir_array_fetch_string(&_0, _SERVER, SL("rootDirOk"), PH_NOISY | PH_READONLY, "phady/core/kernel.zep", 264 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, routeCore, "setsystemroutes", NULL, 128, _0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(routeCore, "getrouter", NULL, 129);
	zephir_check_call_status();
	RETURN_MM();

}

