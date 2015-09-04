
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
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/hash.h"
#include "ext/phalcon/phalcon/mvc/application.zep.h"


/**
  * @class Phady\Core\KernelMvc -  Kernel mvc
  *
  * @author  Alien Fernández Fuentes <alienfernandez85@gmail.com>
  * @package Core
  * @copyright (c) 2015
  * @version 1.0.0
  */
ZEPHIR_INIT_CLASS(Phady_Core_KernelMvc) {

	ZEPHIR_REGISTER_CLASS_EX(Phady\\Core, KernelMvc, phady, core_kernelmvc, phady_core_kernel_ce, phady_core_kernelmvc_method_entry, 0);

	/**
	 * @var <Phalcon\Mvc\Application> application - Instance of app
	 */
	zend_declare_property_null(phady_core_kernelmvc_ce, SL("application"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * @param string environment - development environment [dev | prod | test]
 * @param string scope - Scope of execution [mvc | cli]
 * @param string debug - Whether to enable debugging or not
 * @param array modules - Array modules
 */
PHP_METHOD(Phady_Core_KernelMvc, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *modules = NULL;
	zend_bool debug;
	zval *environment_param = NULL, *debug_param = NULL, *scope_param = NULL, *modules_param = NULL, *_1, *_2, *_3;
	zval *environment = NULL, *scope = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &environment_param, &debug_param, &scope_param, &modules_param);

	zephir_get_strval(environment, environment_param);
	zephir_get_strval(scope, scope_param);
	modules = modules_param;

	if (!debug_param) {
		debug = 0;
	} else {
		debug = zephir_get_boolval(debug_param);
	}


	ZEPHIR_CALL_PARENT(NULL, phady_core_kernelmvc_ce, this_ptr, "__construct", &_0, 35, environment, (debug ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false)), scope, modules);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_1);
	object_init_ex(_1, phalcon_mvc_application_ce);
	ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("application"), _1 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "initializemodules", NULL, 0);
	zephir_check_call_status();
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("application"), PH_NOISY_CC);
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("container"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _2, "setdi", NULL, 0, _3);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Initializes modules.
 *
 */
PHP_METHOD(Phady_Core_KernelMvc, initializeModules) {

	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_2;
	HashPosition _1;
	zval *module = NULL, *_0, **_3, *_4, *_5 = NULL;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("modules"), PH_NOISY_CC);
	zephir_is_iterable(_0, &_2, &_1, 0, 0, "phady/core/kernelmvc.zep", 57);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HVALUE(module, _3);
		_4 = zephir_fetch_nproperty_this(this_ptr, SL("application"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_5);
		ZVAL_BOOL(_5, 1);
		ZEPHIR_CALL_METHOD(NULL, _4, "registermodules", NULL, 0, module, _5);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * @var <Phalcon\Mvc\Application> Get instance app
 */
PHP_METHOD(Phady_Core_KernelMvc, getApplication) {


	RETURN_MEMBER(this_ptr, "application");

}

