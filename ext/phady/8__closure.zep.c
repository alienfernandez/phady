
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


ZEPHIR_INIT_CLASS(phady_8__closure) {

	ZEPHIR_REGISTER_CLASS(phady, 8__closure, phady, 8__closure, phady_8__closure_method_entry, ZEND_ACC_FINAL_CLASS);

	return SUCCESS;

}

PHP_METHOD(phady_8__closure, __invoke) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *config, *cache;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &config);



	ZEPHIR_INIT_VAR(cache);
	object_init_ex(cache, phady_cache_cachehandler_ce);
	ZEPHIR_CALL_METHOD(NULL, cache, "__construct", NULL, 153, config);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(cache, "getadapter", NULL, 154);
	zephir_check_call_status();
	RETURN_MM();

}

