
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
#include "kernel/object.h"
#include "kernel/exit.h"


ZEPHIR_INIT_CLASS(phady_4__closure) {

	ZEPHIR_REGISTER_CLASS(phady, 4__closure, phady, 4__closure, phady_4__closure_method_entry, ZEND_ACC_FINAL_CLASS);

	return SUCCESS;

}

PHP_METHOD(phady_4__closure, __invoke) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *config, *dbCore, *exception = NULL, *_0 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &config);




	/* try_start_1: */

		ZEPHIR_INIT_VAR(dbCore);
		object_init_ex(dbCore, phady_db_databasehandler_ce);
		ZEPHIR_CALL_METHOD(NULL, dbCore, "__construct", NULL, 141, config);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_RETURN_CALL_METHOD(dbCore, "getadapter", NULL, 142);
		zephir_check_call_status_or_jump(try_end_1);
		RETURN_MM();

	try_end_1:

	if (EG(exception)) {
		ZEPHIR_CPY_WRT(exception, EG(exception));
		if (zephir_instance_of_ev(exception, phady_exception_ce TSRMLS_CC)) {
			zend_clear_exception(TSRMLS_C);
			ZEPHIR_CALL_METHOD(&_0, exception, "getmessage", NULL, 0);
			zephir_check_call_status();
			zend_print_zval(_0, 0);
			zephir_exit_empty();
			ZEPHIR_MM_RESTORE();
		}
	}
	ZEPHIR_MM_RESTORE();

}

