
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


ZEPHIR_INIT_CLASS(phady_1__closure) {

	ZEPHIR_REGISTER_CLASS(phady, 1__closure, phady, 1__closure, phady_1__closure_method_entry, ZEND_ACC_FINAL_CLASS);

	return SUCCESS;

}

PHP_METHOD(phady_1__closure, __invoke) {

	zval *parameters;

	zephir_fetch_params(0, 1, 0, &parameters);



	RETVAL_ZVAL(parameters, 1, 0);
	return;

}

