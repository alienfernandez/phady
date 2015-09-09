
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
#include "ext/phalcon/phalcon/mvc/dispatcher.zep.h"


ZEPHIR_INIT_CLASS(phady_3__closure) {

	ZEPHIR_REGISTER_CLASS(phady, 3__closure, phady, 3__closure, phady_3__closure_method_entry, ZEND_ACC_FINAL_CLASS);

	return SUCCESS;

}

PHP_METHOD(phady_3__closure, __invoke) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *dispatcher;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(dispatcher);
	object_init_ex(dispatcher, phalcon_mvc_dispatcher_ce);
	if (zephir_has_constructor(dispatcher TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, dispatcher, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	RETURN_CCTOR(dispatcher);

}

