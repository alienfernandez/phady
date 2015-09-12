
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


ZEPHIR_INIT_CLASS(phady_2__closure) {

	ZEPHIR_REGISTER_CLASS(phady, 2__closure, phady, 2__closure, phady_2__closure_method_entry, ZEND_ACC_FINAL_CLASS);

	return SUCCESS;

}

PHP_METHOD(phady_2__closure, __invoke) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *securityListener;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(securityListener);
	object_init_ex(securityListener, phady_security_eventlistener_securitylistener_ce);
	ZEPHIR_CALL_METHOD(NULL, securityListener, "__construct", NULL, 152);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, securityListener, "addsecuritylisteners", NULL, 153);
	zephir_check_call_status();
	RETURN_CCTOR(securityListener);

}

