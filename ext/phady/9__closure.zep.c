
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
#include "kernel/operators.h"


ZEPHIR_INIT_CLASS(phady_9__closure) {

	ZEPHIR_REGISTER_CLASS(phady, 9__closure, phady, 9__closure, phady_9__closure_method_entry, ZEND_ACC_FINAL_CLASS);

	return SUCCESS;

}

PHP_METHOD(phady_9__closure, __invoke) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *session, *_0 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(session);
	object_init_ex(session, zephir_get_internal_ce(SS("phalcon\\session\\adapter\\files") TSRMLS_CC));
	ZEPHIR_CALL_METHOD(NULL, session, "__construct", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_0, "session_id", NULL, 76);
	zephir_check_call_status();
	if (ZEPHIR_IS_STRING(_0, "")) {
		ZEPHIR_CALL_METHOD(NULL, session, "start", NULL, 0);
		zephir_check_call_status();
	}
	RETURN_CCTOR(session);

}

