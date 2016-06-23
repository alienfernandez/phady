
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/string.h"
#include "kernel/array.h"
#include "kernel/operators.h"
#include "ext/phalcon/phalcon/di/injectable.zep.h"


/**
 * Phady\Common\Controllers\ControllerBase
 *
 * Base Controller
 */
ZEPHIR_INIT_CLASS(Phady_Common_Controllers_ControllerBase) {

	ZEPHIR_REGISTER_CLASS_EX(Phady\\Common\\Controllers, ControllerBase, phady, common_controllers_controllerbase, phalcon_di_injectable_ce, phady_common_controllers_controllerbase_method_entry, 0);

	zend_declare_class_constant_string(phady_common_controllers_controllerbase_ce, SL("LOGIN_URI"), "login" TSRMLS_CC);

	zend_declare_class_constant_string(phady_common_controllers_controllerbase_ce, SL("PORTAL_URI"), "portal" TSRMLS_CC);

	return SUCCESS;

}

/**
 * initialize the class.
 * @name initialize
 * @return NULL
 */
PHP_METHOD(Phady_Common_Controllers_ControllerBase, initialize) {

	zval *_0, *_1, *_SERVER, *_2, _3;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);

	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_INIT_VAR(_1);
	zephir_array_fetch_string(&_2, _SERVER, SL("HTTP_USER_AGENT"), PH_NOISY | PH_READONLY, "phady/common/controllers/controllerbase.zep", 38 TSRMLS_CC);
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_STRING(&_3, "/(?i)msie [1-8]/", 0);
	zephir_preg_match(_1, &_3, _2, _0, 0, 0 , 0  TSRMLS_CC);
	if (zephir_is_true(_1)) {
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phady_Common_Controllers_ControllerBase, beforeExecuteRoute) {

	zval *dispatcher;

	zephir_fetch_params(0, 1, 0, &dispatcher);




}

