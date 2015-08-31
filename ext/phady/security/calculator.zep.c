
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/operators.h"
#include "kernel/memory.h"


/*
+------------------------------------------------------------------------+
| Phady Framework                                                        |
+------------------------------------------------------------------------+
| Copyright (c) 2015                                                     |
+------------------------------------------------------------------------+
| Phady Framework is a complement of Phalcon Framework                   |
|                                                                        |
+------------------------------------------------------------------------+
| Authors: Alien fernandez Fuentes <alienfernandez85@gmail.com>          |
+------------------------------------------------------------------------+
*/
/**
 *
 */
ZEPHIR_INIT_CLASS(Phady_Security_Calculator) {

	ZEPHIR_REGISTER_CLASS(Phady\\Security, Calculator, phady, security_calculator, phady_security_calculator_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Phady_Security_Calculator, sum) {

	zval *a, *b;

	zephir_fetch_params(0, 2, 0, &a, &b);



	zephir_add_function_ex(return_value, a, b TSRMLS_CC);
	return;

}

PHP_METHOD(Phady_Security_Calculator, doSomething) {



}

