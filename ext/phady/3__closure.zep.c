
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
#include "ext/phalcon/phalcon/mvc/view.zep.h"


ZEPHIR_INIT_CLASS(phady_3__closure) {

	ZEPHIR_REGISTER_CLASS(phady, 3__closure, phady, 3__closure, phady_3__closure_method_entry, ZEND_ACC_FINAL_CLASS);

	return SUCCESS;

}

PHP_METHOD(phady_3__closure, __invoke) {

	zval *_0;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *view;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(view);
	object_init_ex(view, phalcon_mvc_view_ce);
	ZEPHIR_CALL_METHOD(NULL, view, "__construct", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_0);
	zephir_create_array(_0, 1, 0 TSRMLS_CC);
	add_assoc_stringl_ex(_0, SS(".volt"), SL("volt"), 1);
	ZEPHIR_CALL_METHOD(NULL, view, "registerengines", NULL, 0, _0);
	zephir_check_call_status();
	RETURN_CCTOR(view);

}

