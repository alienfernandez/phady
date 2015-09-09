
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
#include "ext/phalcon/phalcon/flash/session.zep.h"


ZEPHIR_INIT_CLASS(phady_6__closure) {

	ZEPHIR_REGISTER_CLASS(phady, 6__closure, phady, 6__closure, phady_6__closure_method_entry, ZEND_ACC_FINAL_CLASS);

	return SUCCESS;

}

PHP_METHOD(phady_6__closure, __invoke) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0;
	zval *flash;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(flash);
	object_init_ex(flash, phalcon_flash_session_ce);
	if (zephir_has_constructor(flash TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(_0);
		zephir_create_array(_0, 3, 0 TSRMLS_CC);
		add_assoc_stringl_ex(_0, SS("error"), SL("alert alert-danger"), 1);
		add_assoc_stringl_ex(_0, SS("success"), SL("alert alert-success"), 1);
		add_assoc_stringl_ex(_0, SS("notice"), SL("alert alert-info"), 1);
		ZEPHIR_CALL_METHOD(NULL, flash, "__construct", NULL, 0, _0);
		zephir_check_call_status();
	}
	RETURN_CCTOR(flash);

}

