
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
#include "kernel/concat.h"
#include "kernel/operators.h"
#include "ext/phalcon/phalcon/mvc/view/engine/volt.zep.h"


ZEPHIR_INIT_CLASS(phady_4__closure) {

	ZEPHIR_REGISTER_CLASS(phady, 4__closure, phady, 4__closure, phady_4__closure_method_entry, ZEND_ACC_FINAL_CLASS);

	return SUCCESS;

}

PHP_METHOD(phady_4__closure, __invoke) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *view, *di, *volt, *voltOptions, *_SERVER, *_0, *_1, *_2, *_3;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);
	zephir_fetch_params(1, 2, 0, &view, &di);



	ZEPHIR_INIT_VAR(volt);
	object_init_ex(volt, phalcon_mvc_view_engine_volt_ce);
	if (zephir_has_constructor(volt TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, volt, "__construct", NULL, 0, view, di);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(voltOptions);
	zephir_create_array(voltOptions, 2, 0 TSRMLS_CC);
	zephir_array_fetch_string(&_0, _SERVER, SL("rootDirOk"), PH_NOISY | PH_READONLY, "phady/core/kernel.zep", 302 TSRMLS_CC);
	zephir_array_fetch_string(&_1, _SERVER, SL("environment"), PH_NOISY | PH_READONLY, "phady/core/kernel.zep", 302 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_2);
	ZEPHIR_CONCAT_VSVS(_2, _0, "/cache/", _1, "/volt/");
	zephir_array_update_string(&voltOptions, SL("compiledPath"), &_2, PH_COPY | PH_SEPARATE);
	add_assoc_stringl_ex(voltOptions, SS("compiledSeparator"), SL("_"), 1);
	zephir_array_fetch_string(&_3, _SERVER, SL("environment"), PH_NOISY | PH_READONLY, "phady/core/kernel.zep", 305 TSRMLS_CC);
	if (ZEPHIR_IS_STRING(_3, "dev")) {
		zephir_array_update_string(&voltOptions, SL("compileAlways"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_CALL_METHOD(NULL, volt, "setoptions", NULL, 0, voltOptions);
	zephir_check_call_status();
	RETURN_CCTOR(volt);

}

