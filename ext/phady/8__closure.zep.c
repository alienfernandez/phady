
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
#include "ext/phalcon/phalcon/http/response/cookies.zep.h"


ZEPHIR_INIT_CLASS(phady_8__closure) {

	ZEPHIR_REGISTER_CLASS(phady, 8__closure, phady, 8__closure, phady_8__closure_method_entry, ZEND_ACC_FINAL_CLASS);

	return SUCCESS;

}

PHP_METHOD(phady_8__closure, __invoke) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *cookies, *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(cookies);
	object_init_ex(cookies, phalcon_http_response_cookies_ce);
	if (zephir_has_constructor(cookies TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, cookies, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(_0);
	ZVAL_BOOL(_0, 0);
	ZEPHIR_CALL_METHOD(NULL, cookies, "useencryption", NULL, 0, _0);
	zephir_check_call_status();
	RETURN_CCTOR(cookies);

}

