
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
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/time.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "kernel/file.h"
#include "kernel/array.h"
#include "kernel/hash.h"
#include "kernel/string.h"
#include "ext/phalcon/phalcon/di/factorydefault.zep.h"
#include "ext/phalcon/phalcon/di/factorydefault/cli.zep.h"
#include "ext/phalcon/phalcon/loader.zep.h"
#include "ext/phalcon/phalcon/events/manager.zep.h"


/**
  * @class Phady\Core\Kernel -  Kernel system class
  *
  * @author  Alien Fernández Fuentes <alienfernandez85@gmail.com>
  * @package Core
  * @copyright (c) 2015
  * @version 1.0.0
  */
ZEPHIR_INIT_CLASS(Phady_Core_Kernel) {

	ZEPHIR_REGISTER_CLASS(Phady\\Core, Kernel, phady, core_kernel, phady_core_kernel_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * @var array modules - Modules list
	 */
	zend_declare_property_null(phady_core_kernel_ce, SL("modules"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var array ns - ns list
	 */
	zend_declare_property_null(phady_core_kernel_ce, SL("ns"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var string rootDir - Root dir app
	 */
	zend_declare_property_null(phady_core_kernel_ce, SL("rootDir"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var string environment - Environment execution app
	 */
	zend_declare_property_null(phady_core_kernel_ce, SL("environment"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Dependencies container
	 * @var FactoryDefault
	 */
	zend_declare_property_null(phady_core_kernel_ce, SL("container"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var string scope - Scope execution app (cli or mvc)
	 */
	zend_declare_property_null(phady_core_kernel_ce, SL("scope"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var boolean debug - Is debug mode
	 */
	zend_declare_property_null(phady_core_kernel_ce, SL("debug"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var boolean debug - Is booted app
	 */
	zend_declare_property_null(phady_core_kernel_ce, SL("booted"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var array config - Array of file config app
	 */
	zend_declare_property_null(phady_core_kernel_ce, SL("config"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Instance of Command console
	 * @var Phady\Console\Command
	 */
	zend_declare_property_null(phady_core_kernel_ce, SL("command"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phady_core_kernel_ce, SL("startTime"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phady_core_kernel_ce, SL("security"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * const ENVIRONMENT DEVELOPMENT
	 */
	zend_declare_class_constant_string(phady_core_kernel_ce, SL("ENVIRONMENT_DEV"), "dev" TSRMLS_CC);

	/**
	 * const ENVIRONMENT PRODUCTION
	 */
	zend_declare_class_constant_string(phady_core_kernel_ce, SL("ENVIRONMENT_PROD"), "prod" TSRMLS_CC);

	/**
	 * const ENVIRONMENT TEST
	 */
	zend_declare_class_constant_string(phady_core_kernel_ce, SL("ENVIRONMENT_TEST"), "test" TSRMLS_CC);

	/**
	 * const SCOPE CLI
	 */
	zend_declare_class_constant_string(phady_core_kernel_ce, SL("SCOPE_CLI"), "cli" TSRMLS_CC);

	/**
	 * const SCOPE MVC
	 */
	zend_declare_class_constant_string(phady_core_kernel_ce, SL("SCOPE_MVC"), "mvc" TSRMLS_CC);

	/**
	 * Const of version app
	 */
	zend_declare_class_constant_string(phady_core_kernel_ce, SL("VERSION"), "1.0.0" TSRMLS_CC);

	zend_declare_class_constant_string(phady_core_kernel_ce, SL("VERSION_ID"), "10000" TSRMLS_CC);

	zend_declare_class_constant_string(phady_core_kernel_ce, SL("MAJOR_VERSION"), "1" TSRMLS_CC);

	zend_declare_class_constant_string(phady_core_kernel_ce, SL("MINOR_VERSION"), "0" TSRMLS_CC);

	zend_declare_class_constant_string(phady_core_kernel_ce, SL("RELEASE_VERSION"), "0" TSRMLS_CC);

	zend_declare_class_constant_string(phady_core_kernel_ce, SL("EXTRA_VERSION"), "" TSRMLS_CC);

	return SUCCESS;

}

/**
 * Constructor.
 *
 * @param string environment - The environment
 * @param string scope - Scope of execution [mvc | cli]
 * @param boolean debug - Whether to enable debugging or not
 * @param array modules - Array modules app
 * @api
 */
PHP_METHOD(Phady_Core_Kernel, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *modules = NULL;
	zend_bool debug;
	zval *environment_param = NULL, *debug_param = NULL, *scope_param = NULL, *modules_param = NULL, *_0 = NULL, *_1, *_2, *_3, *_4;
	zval *environment = NULL, *scope = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &environment_param, &debug_param, &scope_param, &modules_param);

	if (unlikely(Z_TYPE_P(environment_param) != IS_STRING && Z_TYPE_P(environment_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'environment' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(environment_param) == IS_STRING)) {
		zephir_get_strval(environment, environment_param);
	} else {
		ZEPHIR_INIT_VAR(environment);
		ZVAL_EMPTY_STRING(environment);
	}
	if (unlikely(Z_TYPE_P(scope_param) != IS_STRING && Z_TYPE_P(scope_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'scope' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(scope_param) == IS_STRING)) {
		zephir_get_strval(scope, scope_param);
	} else {
		ZEPHIR_INIT_VAR(scope);
		ZVAL_EMPTY_STRING(scope);
	}
	modules = modules_param;

	if (!debug_param) {
		debug = 0;
	} else {
	if (unlikely(Z_TYPE_P(debug_param) != IS_BOOL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'debug' must be a bool") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	debug = Z_BVAL_P(debug_param);
	}


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "validateexternallibrary", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("debug"), debug ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("scope"), scope TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("booted"), (0) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getrootdir", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("rootDir"), _0 TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("modules"), modules TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	array_init(_1);
	zephir_update_property_this(this_ptr, SL("ns"), _1 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_2);
	object_init_ex(_2, phady_console_command_ce);
	if (zephir_has_constructor(_2 TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, _2, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	zephir_update_property_this(this_ptr, SL("command"), _2 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "readconfigfiles", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setenvironment", NULL, 0, environment);
	zephir_check_call_status();
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("debug"), PH_NOISY_CC);
	if (zephir_is_true(_3)) {
		ZEPHIR_INIT_VAR(_4);
		zephir_microtime(_4, ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
		zephir_update_property_this(this_ptr, SL("startTime"), _4 TSRMLS_CC);
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "boot", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Start the current kernel.
 *
 * @api
 */
PHP_METHOD(Phady_Core_Kernel, boot) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("booted"), PH_NOISY_CC);
	if (ZEPHIR_IS_TRUE(_0)) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "initializecontainer", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "initializenamespace", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "initializedefaultservice", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("booted"), (1) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Initializes the service container.
 *
 * The cached version of the service container is used when fresh, otherwise the
 * container is built.
 * @return FactoryDefault
 */
PHP_METHOD(Phady_Core_Kernel, initializeContainer) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0, *_1 = NULL;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("scope"), PH_NOISY_CC);
	if (ZEPHIR_IS_STRING(_0, "mvc")) {
		ZEPHIR_INIT_VAR(_1);
		object_init_ex(_1, phalcon_di_factorydefault_ce);
		ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("container"), _1 TSRMLS_CC);
	} else {
		ZEPHIR_INIT_NVAR(_1);
		object_init_ex(_1, phalcon_di_factorydefault_cli_ce);
		ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("container"), _1 TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Validate external libs exist
 *
 */
PHP_METHOD(Phady_Core_Kernel, validateExternalLibrary) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval _0, *_1 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "phalcon", 0);
	ZEPHIR_CALL_FUNCTION(&_1, "extension_loaded", NULL, 7, &_0);
	zephir_check_call_status();
	if (!zephir_is_true(_1)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phady_exception_ce, "Phalcon extension isn\\'t installed, follow these instructions to install it: http://docs.phalconphp.com/en/latest/reference/install.html", "phady/core/kernel.zep", 198);
		return;
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Read config files
 *
 */
PHP_METHOD(Phady_Core_Kernel, readConfigFiles) {

	zephir_fcall_cache_entry *_5 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *configFile, *securityFile, *_0, *_1, _2, *_3 = NULL, *_4 = NULL, *_6 = NULL;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("rootDir"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(configFile);
	ZEPHIR_CONCAT_VS(configFile, _0, "/config/config.yml");
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("rootDir"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(securityFile);
	ZEPHIR_CONCAT_VS(securityFile, _1, "/config/security.yml");
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_STRING(&_2, "yaml", 0);
	ZEPHIR_CALL_FUNCTION(&_3, "extension_loaded", NULL, 7, &_2);
	zephir_check_call_status();
	if (!zephir_is_true(_3)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phady_exception_ce, "Yaml extension isn\\'t installed.", "phady/core/kernel.zep", 211);
		return;
	}
	if (!((zephir_file_exists(configFile TSRMLS_CC) == SUCCESS))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phady_exception_ce, "Config file isn\\'t found.", "phady/core/kernel.zep", 214);
		return;
	}
	if (!((zephir_file_exists(securityFile TSRMLS_CC) == SUCCESS))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phady_exception_ce, "Security file isn\\'t found.", "phady/core/kernel.zep", 218);
		return;
	}
	ZEPHIR_CALL_CE_STATIC(&_4, phady_config_yaml_ce, "parse", &_5, 8, configFile);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("config"), _4 TSRMLS_CC);
	ZEPHIR_CALL_CE_STATIC(&_6, phady_config_yaml_ce, "parse", &_5, 8, securityFile);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("security"), _6 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Initializes namespaces.
 *
 */
PHP_METHOD(Phady_Core_Kernel, initializeNamespace) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *nsCore, *loader, *_0, *_1, *_2, *_3 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(loader);
	object_init_ex(loader, phalcon_loader_ce);
	ZEPHIR_CALL_METHOD(NULL, loader, "__construct", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(nsCore);
	object_init_ex(nsCore, phady_core_namespacehandler_ce);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("scope"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("rootDir"), PH_NOISY_CC);
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("modules"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, nsCore, "__construct", NULL, 9, _0, _1, _2);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_3, nsCore, "getallnamespaceapp", NULL, 10);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, loader, "registernamespaces", NULL, 0, _3);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, loader, "register", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Initializes default service.
 *
 */
PHP_METHOD(Phady_Core_Kernel, initializeDefaultService) {

	int _1, _3, _5, _7, _9, ZEPHIR_LAST_CALL_STATUS;
	zval *di, *config = NULL, *securityConfig, *_0, *_SERVER, *_2, *_4, *_6, *_8, *_10, *_11, *_12 = NULL, *_13 = NULL, *_14, *_15 = NULL, *_16, *_17 = NULL, *_18, *_19 = NULL, *_20 = NULL, *eventsManager, *_21 = NULL, *_22, *_23 = NULL, *_24, *_25 = NULL, *_26 = NULL, *_27 = NULL, *_28 = NULL, *_29, *_30 = NULL, *_31, *_32 = NULL, *_33, *_34 = NULL, *_35, *_36, *_37, *securityListener;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);

	ZEPHIR_OBS_VAR(di);
	zephir_read_property_this(&di, this_ptr, SL("container"), PH_NOISY_CC);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(config, _0);
	ZEPHIR_OBS_VAR(securityConfig);
	zephir_read_property_this(&securityConfig, this_ptr, SL("security"), PH_NOISY_CC);
	if (Z_TYPE_P(config) == IS_ARRAY) {
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("rootDir"), PH_NOISY_CC);
	_1 = zephir_maybe_separate_zval(&_SERVER);
	zephir_array_update_string(&_SERVER, SL("rootDirOk"), &_0, PH_COPY | PH_SEPARATE);
	if (_1) {
		ZEND_SET_SYMBOL(&EG(symbol_table), "_SERVER", _SERVER);
	}
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("environment"), PH_NOISY_CC);
	_3 = zephir_maybe_separate_zval(&_SERVER);
	zephir_array_update_string(&_SERVER, SL("environment"), &_2, PH_COPY | PH_SEPARATE);
	if (_3) {
		ZEND_SET_SYMBOL(&EG(symbol_table), "_SERVER", _SERVER);
	}
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
	_5 = zephir_maybe_separate_zval(&_SERVER);
	zephir_array_update_string(&_SERVER, SL("configApp"), &_4, PH_COPY | PH_SEPARATE);
	if (_5) {
		ZEND_SET_SYMBOL(&EG(symbol_table), "_SERVER", _SERVER);
	}
	_6 = zephir_fetch_nproperty_this(this_ptr, SL("security"), PH_NOISY_CC);
	_7 = zephir_maybe_separate_zval(&_SERVER);
	zephir_array_update_string(&_SERVER, SL("securityConfigApp"), &_6, PH_COPY | PH_SEPARATE);
	if (_7) {
		ZEND_SET_SYMBOL(&EG(symbol_table), "_SERVER", _SERVER);
	}
	_8 = zephir_fetch_nproperty_this(this_ptr, SL("container"), PH_NOISY_CC);
	_9 = zephir_maybe_separate_zval(&_SERVER);
	zephir_array_update_string(&_SERVER, SL("containerApp"), &_8, PH_COPY | PH_SEPARATE);
	if (_9) {
		ZEND_SET_SYMBOL(&EG(symbol_table), "_SERVER", _SERVER);
	}
	_10 = zephir_fetch_nproperty_this(this_ptr, SL("scope"), PH_NOISY_CC);
	if (ZEPHIR_IS_STRING(_10, "mvc")) {
		_11 = zephir_fetch_nproperty_this(this_ptr, SL("container"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_12);
		ZEPHIR_INIT_NVAR(_12);
		zephir_create_closure_ex(_12, NULL, phady_0__closure_ce, SS("__invoke") TSRMLS_CC);
		ZEPHIR_INIT_VAR(_13);
		ZVAL_STRING(_13, "router", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, _11, "set", NULL, 0, _13, _12);
		zephir_check_temp_parameter(_13);
		zephir_check_call_status();
		_14 = zephir_fetch_nproperty_this(this_ptr, SL("container"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_13);
		ZEPHIR_INIT_NVAR(_13);
		zephir_create_closure_ex(_13, NULL, phady_1__closure_ce, SS("__invoke") TSRMLS_CC);
		ZEPHIR_INIT_VAR(_15);
		ZVAL_STRING(_15, "dispatcher", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, _14, "setshared", NULL, 0, _15, _13);
		zephir_check_temp_parameter(_15);
		zephir_check_call_status();
		_16 = zephir_fetch_nproperty_this(this_ptr, SL("container"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_15);
		ZVAL_STRING(_15, "dispatcher", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_17, _16, "has", NULL, 0, _15);
		zephir_check_temp_parameter(_15);
		zephir_check_call_status();
		if (zephir_is_true(_17)) {
			_18 = zephir_fetch_nproperty_this(this_ptr, SL("container"), PH_NOISY_CC);
			ZEPHIR_INIT_NVAR(_15);
			ZVAL_STRING(_15, "dispatcher", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_19, _18, "get", NULL, 0, _15);
			zephir_check_temp_parameter(_15);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_20, _19, "geteventsmanager", NULL, 0);
			zephir_check_call_status();
			if (!zephir_is_true(_20)) {
				ZEPHIR_INIT_VAR(eventsManager);
				object_init_ex(eventsManager, phalcon_events_manager_ce);
				if (zephir_has_constructor(eventsManager TSRMLS_CC)) {
					ZEPHIR_CALL_METHOD(NULL, eventsManager, "__construct", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_INIT_NVAR(_15);
				object_init_ex(_15, phady_security_core_authentication_eventlistener_authenticationlistener_ce);
				if (zephir_has_constructor(_15 TSRMLS_CC)) {
					ZEPHIR_CALL_METHOD(NULL, _15, "__construct", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_INIT_VAR(_21);
				ZVAL_STRING(_21, "dispatch:beforeDispatch", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(NULL, eventsManager, "attach", NULL, 0, _21, _15);
				zephir_check_temp_parameter(_21);
				zephir_check_call_status();
				_22 = zephir_fetch_nproperty_this(this_ptr, SL("container"), PH_NOISY_CC);
				ZEPHIR_INIT_NVAR(_21);
				ZVAL_STRING(_21, "dispatcher", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&_23, _22, "get", NULL, 0, _21);
				zephir_check_temp_parameter(_21);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, _23, "seteventsmanager", NULL, 0, eventsManager);
				zephir_check_call_status();
				_24 = zephir_fetch_nproperty_this(this_ptr, SL("container"), PH_NOISY_CC);
				ZEPHIR_INIT_NVAR(_21);
				ZVAL_STRING(_21, "dispatcher", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&_25, _24, "get", NULL, 0, _21);
				zephir_check_temp_parameter(_21);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(_21);
				ZVAL_STRING(_21, "dispatch:beforeDispatch", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(NULL, eventsManager, "fire", NULL, 0, _21, _25);
				zephir_check_temp_parameter(_21);
				zephir_check_call_status();
			}
		}
	}
	_11 = zephir_fetch_nproperty_this(this_ptr, SL("container"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_12);
	ZEPHIR_INIT_NVAR(_12);
	zephir_create_closure_ex(_12, NULL, phady_2__closure_ce, SS("__invoke") TSRMLS_CC);
	ZEPHIR_INIT_NVAR(_13);
	ZVAL_STRING(_13, "db", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, _11, "set", NULL, 0, _13, _12);
	zephir_check_temp_parameter(_13);
	zephir_check_call_status();
	_14 = zephir_fetch_nproperty_this(this_ptr, SL("container"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_13);
	ZEPHIR_INIT_NVAR(_13);
	zephir_create_closure_ex(_13, NULL, phady_3__closure_ce, SS("__invoke") TSRMLS_CC);
	ZEPHIR_INIT_NVAR(_15);
	ZVAL_STRING(_15, "view", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, _14, "set", NULL, 0, _15, _13);
	zephir_check_temp_parameter(_15);
	zephir_check_call_status();
	_16 = zephir_fetch_nproperty_this(this_ptr, SL("container"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_15);
	ZEPHIR_INIT_NVAR(_15);
	zephir_create_closure_ex(_15, NULL, phady_4__closure_ce, SS("__invoke") TSRMLS_CC);
	ZEPHIR_INIT_NVAR(_21);
	ZVAL_STRING(_21, "volt", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_26);
	ZVAL_BOOL(_26, 1);
	ZEPHIR_CALL_METHOD(NULL, _16, "set", NULL, 0, _21, _15, _26);
	zephir_check_temp_parameter(_21);
	zephir_check_call_status();
	_18 = zephir_fetch_nproperty_this(this_ptr, SL("container"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_21);
	ZEPHIR_INIT_NVAR(_21);
	zephir_create_closure_ex(_21, NULL, phady_5__closure_ce, SS("__invoke") TSRMLS_CC);
	ZEPHIR_INIT_NVAR(_26);
	ZVAL_STRING(_26, "flash", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, _18, "set", NULL, 0, _26, _21);
	zephir_check_temp_parameter(_26);
	zephir_check_call_status();
	_22 = zephir_fetch_nproperty_this(this_ptr, SL("container"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_26);
	ZEPHIR_INIT_NVAR(_26);
	zephir_create_closure_ex(_26, NULL, phady_6__closure_ce, SS("__invoke") TSRMLS_CC);
	ZEPHIR_INIT_VAR(_27);
	ZVAL_STRING(_27, "parameters", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, _22, "set", NULL, 0, _27, _26);
	zephir_check_temp_parameter(_27);
	zephir_check_call_status();
	_24 = zephir_fetch_nproperty_this(this_ptr, SL("container"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_27);
	ZEPHIR_INIT_NVAR(_27);
	zephir_create_closure_ex(_27, NULL, phady_7__closure_ce, SS("__invoke") TSRMLS_CC);
	ZEPHIR_INIT_VAR(_28);
	ZVAL_STRING(_28, "cache", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, _24, "set", NULL, 0, _28, _27);
	zephir_check_temp_parameter(_28);
	zephir_check_call_status();
	_29 = zephir_fetch_nproperty_this(this_ptr, SL("container"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_28);
	ZEPHIR_INIT_NVAR(_28);
	zephir_create_closure_ex(_28, NULL, phady_8__closure_ce, SS("__invoke") TSRMLS_CC);
	ZEPHIR_INIT_VAR(_30);
	ZVAL_STRING(_30, "cookies", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, _29, "set", NULL, 0, _30, _28);
	zephir_check_temp_parameter(_30);
	zephir_check_call_status();
	_31 = zephir_fetch_nproperty_this(this_ptr, SL("container"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_30);
	ZEPHIR_INIT_NVAR(_30);
	zephir_create_closure_ex(_30, NULL, phady_9__closure_ce, SS("__invoke") TSRMLS_CC);
	ZEPHIR_INIT_VAR(_32);
	ZVAL_STRING(_32, "registry", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, _31, "set", NULL, 0, _32, _30);
	zephir_check_temp_parameter(_32);
	zephir_check_call_status();
	_33 = zephir_fetch_nproperty_this(this_ptr, SL("container"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_32);
	ZEPHIR_INIT_NVAR(_32);
	zephir_create_closure_ex(_32, NULL, phady_10__closure_ce, SS("__invoke") TSRMLS_CC);
	ZEPHIR_INIT_VAR(_34);
	ZVAL_STRING(_34, "session", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, _33, "set", NULL, 0, _34, _32);
	zephir_check_temp_parameter(_34);
	zephir_check_call_status();
	_35 = zephir_fetch_nproperty_this(this_ptr, SL("container"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_34);
	ZVAL_STRING(_34, "session", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_17, _35, "has", NULL, 0, _34);
	zephir_check_temp_parameter(_34);
	zephir_check_call_status();
	if (zephir_is_true(_17)) {
		_36 = zephir_fetch_nproperty_this(this_ptr, SL("container"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_34);
		ZVAL_STRING(_34, "session", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_19, _36, "get", NULL, 0, _34);
		zephir_check_temp_parameter(_34);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_20, _19, "isstarted", NULL, 0);
		zephir_check_call_status();
		if (!zephir_is_true(_20)) {
			_37 = zephir_fetch_nproperty_this(this_ptr, SL("container"), PH_NOISY_CC);
			ZEPHIR_INIT_NVAR(_34);
			ZVAL_STRING(_34, "session", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_23, _37, "get", NULL, 0, _34);
			zephir_check_temp_parameter(_34);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, _23, "start", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_VAR(securityListener);
	object_init_ex(securityListener, phady_security_eventlistener_securitylistener_ce);
	ZEPHIR_CALL_METHOD(NULL, securityListener, "__construct", NULL, 11);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, securityListener, "addsecuritylisteners", NULL, 12);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns the core parameters.
 *
 * @return array An array of core parameters
 */
PHP_METHOD(Phady_Core_Kernel, getCoreParameters) {

	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_2, *_5;
	HashPosition _1, _4;
	zval *modules, *module = NULL, *parameters, *url, *name = NULL, *data = NULL, *tools, *_0, **_3, **_6, *_7, *_8, *_9 = NULL, *_10 = NULL, *_11 = NULL, *_12 = NULL, *_13 = NULL, *_14, *_15, *_16, *_17, *_18, *_19, *_20, *_21, *_22, *_23, *_24, *_25, *_26, *_27, *_28;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(modules);
	array_init(modules);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("modules"), PH_NOISY_CC);
	zephir_is_iterable(_0, &_2, &_1, 0, 0, "phady/core/kernel.zep", 406);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HVALUE(module, _3);
		zephir_is_iterable(module, &_5, &_4, 0, 0, "phady/core/kernel.zep", 405);
		for (
		  ; zephir_hash_get_current_data_ex(_5, (void**) &_6, &_4) == SUCCESS
		  ; zephir_hash_move_forward_ex(_5, &_4)
		) {
			ZEPHIR_GET_HMKEY(name, _5, _4);
			ZEPHIR_GET_HVALUE(data, _6);
			zephir_array_fetch_string(&_7, data, SL("className"), PH_NOISY | PH_READONLY, "phady/core/kernel.zep", 403 TSRMLS_CC);
			zephir_array_update_zval(&modules, name, &_7, PH_COPY | PH_SEPARATE);
		}
	}
	ZEPHIR_INIT_VAR(parameters);
	object_init_ex(parameters, phady_core_parameter_ce);
	if (zephir_has_constructor(parameters TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, parameters, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(tools);
	object_init_ex(tools, phady_util_tools_ce);
	if (zephir_has_constructor(tools TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, tools, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	_8 = zephir_fetch_nproperty_this(this_ptr, SL("scope"), PH_NOISY_CC);
	if (ZEPHIR_IS_STRING(_8, "mvc")) {
		ZEPHIR_CALL_METHOD(&_9, tools, "gethttphost", NULL, 13);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_10);
		ZVAL_STRING(_10, "http_host", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, parameters, "setparameter", NULL, 14, _10, _9);
		zephir_check_temp_parameter(_10);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_11, tools, "getrequestprotocol", NULL, 15);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_10);
		ZVAL_STRING(_10, "request_protocol", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, parameters, "setparameter", NULL, 14, _10, _11);
		zephir_check_temp_parameter(_10);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_12, tools, "getrequestprotocol", NULL, 15);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_13, tools, "gethttphost", NULL, 13);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(url);
		ZEPHIR_CONCAT_VSV(url, _12, "://", _13);
		ZEPHIR_INIT_NVAR(_10);
		ZVAL_STRING(_10, "url", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, parameters, "setparameter", NULL, 14, _10, url);
		zephir_check_temp_parameter(_10);
		zephir_check_call_status();
	}
	_14 = zephir_fetch_nproperty_this(this_ptr, SL("rootDir"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_10);
	ZVAL_STRING(_10, "root_dir", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, parameters, "setparameter", NULL, 14, _10, _14);
	zephir_check_temp_parameter(_10);
	zephir_check_call_status();
	_15 = zephir_fetch_nproperty_this(this_ptr, SL("environment"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_10);
	ZVAL_STRING(_10, "environment", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, parameters, "setparameter", NULL, 14, _10, _15);
	zephir_check_temp_parameter(_10);
	zephir_check_call_status();
	_16 = zephir_fetch_nproperty_this(this_ptr, SL("debug"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_10);
	ZVAL_STRING(_10, "debug", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, parameters, "setparameter", NULL, 14, _10, _16);
	zephir_check_temp_parameter(_10);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_9, this_ptr, "getcachedir", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_10);
	ZVAL_STRING(_10, "cache_dir", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, parameters, "setparameter", NULL, 14, _10, _9);
	zephir_check_temp_parameter(_10);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_11, this_ptr, "getlogdir", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_10);
	ZVAL_STRING(_10, "log_dir", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, parameters, "setparameter", NULL, 14, _10, _11);
	zephir_check_temp_parameter(_10);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_10);
	ZVAL_STRING(_10, "modules", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, parameters, "setparameter", NULL, 14, _10, modules);
	zephir_check_temp_parameter(_10);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_12, this_ptr, "getcharset", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_10);
	ZVAL_STRING(_10, "charset", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, parameters, "setparameter", NULL, 14, _10, _12);
	zephir_check_temp_parameter(_10);
	zephir_check_call_status();
	_17 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
	zephir_array_fetch_string(&_7, _17, SL("framework"), PH_NOISY | PH_READONLY, "phady/core/kernel.zep", 421 TSRMLS_CC);
	zephir_array_fetch_string(&_18, _7, SL("catalog"), PH_NOISY | PH_READONLY, "phady/core/kernel.zep", 421 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(_10);
	ZVAL_STRING(_10, "catalog", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, parameters, "setparameter", NULL, 14, _10, _18);
	zephir_check_temp_parameter(_10);
	zephir_check_call_status();
	_19 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
	zephir_array_fetch_string(&_20, _19, SL("framework"), PH_NOISY | PH_READONLY, "phady/core/kernel.zep", 422 TSRMLS_CC);
	zephir_array_fetch_string(&_21, _20, SL("datetime"), PH_NOISY | PH_READONLY, "phady/core/kernel.zep", 422 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(_10);
	ZVAL_STRING(_10, "datetime", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, parameters, "setparameter", NULL, 14, _10, _21);
	zephir_check_temp_parameter(_10);
	zephir_check_call_status();
	_22 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
	zephir_array_fetch_string(&_23, _22, SL("mail"), PH_NOISY | PH_READONLY, "phady/core/kernel.zep", 423 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(_10);
	ZVAL_STRING(_10, "mail", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, parameters, "setparameter", NULL, 14, _10, _23);
	zephir_check_temp_parameter(_10);
	zephir_check_call_status();
	_24 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
	zephir_array_fetch_string(&_25, _24, SL("pdf"), PH_NOISY | PH_READONLY, "phady/core/kernel.zep", 424 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(_10);
	ZVAL_STRING(_10, "pdf", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, parameters, "setparameter", NULL, 14, _10, _25);
	zephir_check_temp_parameter(_10);
	zephir_check_call_status();
	_26 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
	zephir_array_fetch_string(&_27, _26, SL("files"), PH_NOISY | PH_READONLY, "phady/core/kernel.zep", 425 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(_10);
	ZVAL_STRING(_10, "files", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, parameters, "setparameter", NULL, 14, _10, _27);
	zephir_check_temp_parameter(_10);
	zephir_check_call_status();
	_28 = zephir_fetch_nproperty_this(this_ptr, SL("container"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_10);
	ZVAL_STRING(_10, "container", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, parameters, "setparameter", NULL, 14, _10, _28);
	zephir_check_temp_parameter(_10);
	zephir_check_call_status();
	RETURN_CCTOR(parameters);

}

/**
 * {@inheritdoc}
 *
 * @api
 */
PHP_METHOD(Phady_Core_Kernel, getRootDir) {

	zval *document_root, *document_root_spl, *_0, *_SERVER, *_1, *_2;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("rootDir"), PH_NOISY_CC);
	if (Z_TYPE_P(_0) == IS_NULL) {
		ZEPHIR_OBS_VAR(document_root);
		zephir_array_fetch_string(&document_root, _SERVER, SL("DOCUMENT_ROOT"), PH_NOISY, "phady/core/kernel.zep", 440 TSRMLS_CC);
		ZEPHIR_INIT_VAR(document_root_spl);
		zephir_fast_explode_str(document_root_spl, SL("web"), document_root, LONG_MAX TSRMLS_CC);
		if (zephir_fast_count_int(document_root_spl TSRMLS_CC) > 0) {
			zephir_array_fetch_long(&_1, document_root_spl, 0, PH_NOISY | PH_READONLY, "phady/core/kernel.zep", 443 TSRMLS_CC);
			ZEPHIR_INIT_VAR(_2);
			ZEPHIR_CONCAT_VS(_2, _1, "app");
			zephir_update_property_this(this_ptr, SL("rootDir"), _2 TSRMLS_CC);
		} else {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phady_exception_ce, "No found root directory.", "phady/core/kernel.zep", 445);
			return;
		}
	}
	RETURN_MM_MEMBER(this_ptr, "rootDir");

}

/**
 * Set evironment
 *
 * @api
 */
PHP_METHOD(Phady_Core_Kernel, setEnvironment) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *environment_param = NULL, _0 = zval_used_for_init, _1 = zval_used_for_init;
	zval *environment = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &environment_param);

	if (unlikely(Z_TYPE_P(environment_param) != IS_STRING && Z_TYPE_P(environment_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'environment' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(environment_param) == IS_STRING)) {
		zephir_get_strval(environment, environment_param);
	} else {
		ZEPHIR_INIT_VAR(environment);
		ZVAL_EMPTY_STRING(environment);
	}


	if (ZEPHIR_IS_STRING(environment, "dev")) {
		ZEPHIR_SINIT_VAR(_0);
		ZVAL_LONG(&_0, 32767);
		ZEPHIR_CALL_FUNCTION(NULL, "error_reporting", NULL, 16, &_0);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_0);
		ZVAL_STRING(&_0, "display_errors", 0);
		ZEPHIR_SINIT_VAR(_1);
		ZVAL_LONG(&_1, 1);
		ZEPHIR_CALL_FUNCTION(NULL, "ini_set", NULL, 17, &_0, &_1);
		zephir_check_call_status();
	} else if (ZEPHIR_IS_STRING(environment, "prod")) {
		ZEPHIR_SINIT_NVAR(_0);
		ZVAL_STRING(&_0, "display_errors", 0);
		ZEPHIR_SINIT_NVAR(_1);
		ZVAL_LONG(&_1, 0);
		ZEPHIR_CALL_FUNCTION(NULL, "ini_set", NULL, 17, &_0, &_1);
		zephir_check_call_status();
	}
	zephir_update_property_this(this_ptr, SL("environment"), environment TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Is debug mode
 *
 * @api
 */
PHP_METHOD(Phady_Core_Kernel, isDebug) {


	RETURN_MEMBER(this_ptr, "debug");

}

/**
 * Get dependencies container
 *
 * @api
 */
PHP_METHOD(Phady_Core_Kernel, getContainer) {


	RETURN_MEMBER(this_ptr, "container");

}

/**
 * Get command cli exec
 *
 * @api
 */
PHP_METHOD(Phady_Core_Kernel, getCommand) {


	RETURN_MEMBER(this_ptr, "command");

}

/**
 * {@inheritdoc}
 *
 * @api
 */
PHP_METHOD(Phady_Core_Kernel, getStartTime) {

	zval *_0, *_1;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("debug"), PH_NOISY_CC);
	if (zephir_is_true(_1)) {
		zephir_read_property_this(&_0, this_ptr, SL("startTime"), PH_NOISY_CC);
	} else {
		ZVAL_STRING(_0, "-INF", 1);
	}
	RETURN_CCTOR(_0);

}

/**
 * {@inheritdoc}
 *
 * @api
 */
PHP_METHOD(Phady_Core_Kernel, getCacheDir) {

	zval *_0, *_1;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("rootDir"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("environment"), PH_NOISY_CC);
	ZEPHIR_CONCAT_VSV(return_value, _0, "/cache/", _1);
	return;

}

/**
 * {@inheritdoc}
 *
 * @api
 */
PHP_METHOD(Phady_Core_Kernel, getLogDir) {

	zval *_0;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("rootDir"), PH_NOISY_CC);
	ZEPHIR_CONCAT_VS(return_value, _0, "/logs");
	return;

}

/**
 * {@inheritdoc}
 *
 * @api
 */
PHP_METHOD(Phady_Core_Kernel, getCharset) {


	RETURN_STRING("UTF-8", 1);

}

/**
 * {@inheritdoc}
 *
 * @api
 */
PHP_METHOD(Phady_Core_Kernel, shutdown) {

	zval *_0;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("booted"), PH_NOISY_CC);
	if (ZEPHIR_IS_FALSE(_0)) {
		RETURN_BOOL(0);
	}
	zephir_update_property_this(this_ptr, SL("booted"), (0) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);

}

/**
 * {@inheritdoc}
 *
 * @api
 */
PHP_METHOD(Phady_Core_Kernel, getEnvironment) {


	RETURN_MEMBER(this_ptr, "environment");

}

/**
 * {@inheritdoc}
 *
 * @api
 */
PHP_METHOD(Phady_Core_Kernel, getModules) {


	RETURN_MEMBER(this_ptr, "modules");

}

PHP_METHOD(Phady_Core_Kernel, serialize) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_1 = NULL;
	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	zephir_create_array(_0, 2, 0 TSRMLS_CC);
	ZEPHIR_OBS_VAR(_1);
	zephir_read_property_this(&_1, this_ptr, SL("environment"), PH_NOISY_CC);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_OBS_NVAR(_1);
	zephir_read_property_this(&_1, this_ptr, SL("debug"), PH_NOISY_CC);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_RETURN_CALL_FUNCTION("serialize", NULL, 1, _0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Phady_Core_Kernel, unserialize) {

	zval *data;

	zephir_fetch_params(0, 1, 0, &data);




}

