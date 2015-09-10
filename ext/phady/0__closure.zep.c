
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
#include "kernel/fcall.h"
#include "kernel/memory.h"


ZEPHIR_INIT_CLASS(phady_0__closure) {

	ZEPHIR_REGISTER_CLASS(phady, 0__closure, phady, 0__closure, phady_0__closure_method_entry, ZEND_ACC_FINAL_CLASS);

	return SUCCESS;

}

PHP_METHOD(phady_0__closure, __invoke) {

	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	object_init_ex(return_value, phady_security_firewall_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 139);
	zephir_check_call_status();
	RETURN_MM();

}

