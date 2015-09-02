
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
#include "ext/phalcon/phalcon/events/manager.zep.h"
#include "ext/phalcon/phalcon/mvc/dispatcher.zep.h"


ZEPHIR_INIT_CLASS(phady_1__closure) {

	ZEPHIR_REGISTER_CLASS(phady, 1__closure, phady, 1__closure, phady_1__closure_method_entry, ZEND_ACC_FINAL_CLASS);

	return SUCCESS;

}

PHP_METHOD(phady_1__closure, __invoke) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *dispatcher, *eventsManager, *_0, *_1 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(eventsManager);
	object_init_ex(eventsManager, phalcon_events_manager_ce);
	if (zephir_has_constructor(eventsManager TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, eventsManager, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(_0);
	object_init_ex(_0, phady_security_core_authentication_eventlistener_authenticationlistener_ce);
	if (zephir_has_constructor(_0 TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "dispatch:beforeDispatch", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, eventsManager, "attach", NULL, 0, _1, _0);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(dispatcher);
	object_init_ex(dispatcher, phalcon_mvc_dispatcher_ce);
	if (zephir_has_constructor(dispatcher TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, dispatcher, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "dispatch:beforeDispatch", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, eventsManager, "fire", NULL, 0, _1, dispatcher);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	RETURN_CCTOR(dispatcher);

}

