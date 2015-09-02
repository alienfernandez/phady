
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"


/**
 * @class Phady\Security\Core\Models\Exception
 *
 * Exceptions thrown in Phady will use this class
 *
 */
ZEPHIR_INIT_CLASS(Phady_Security_Core_Models_Exception) {

	ZEPHIR_REGISTER_CLASS_EX(Phady\\Security\\Core\\Models, Exception, phady, security_core_models_exception, zend_exception_get_default(TSRMLS_C), phady_security_core_models_exception_method_entry, 0);

	return SUCCESS;

}

/**
 * Rewrite the error message
 * @return string
 */
PHP_METHOD(Phady_Security_Core_Models_Exception, __toString) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0 = NULL, _1;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmessage", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "[Phady Model Error] %s", 0);
	ZEPHIR_RETURN_CALL_FUNCTION("sprintf", NULL, 20, &_1, _0);
	zephir_check_call_status();
	RETURN_MM();

}

