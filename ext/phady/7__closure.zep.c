
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


ZEPHIR_INIT_CLASS(phady_7__closure) {

	ZEPHIR_REGISTER_CLASS(phady, 7__closure, phady, 7__closure, phady_7__closure_method_entry, ZEND_ACC_FINAL_CLASS);

	return SUCCESS;

}

PHP_METHOD(phady_7__closure, __invoke) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *cache, *_SERVER, *_0;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);

	ZEPHIR_INIT_VAR(cache);
	object_init_ex(cache, phady_cache_cachehandler_ce);
	zephir_array_fetch_string(&_0, _SERVER, SL("configApp"), PH_NOISY | PH_READONLY, "phady/core/kernel.zep", 344 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, cache, "__construct", NULL, 107, _0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(cache, "getadapter", NULL, 108);
	zephir_check_call_status();
	RETURN_MM();

}

