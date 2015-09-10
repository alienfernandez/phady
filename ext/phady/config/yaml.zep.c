
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
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "kernel/file.h"
#include "ext/spl/spl_exceptions.h"


/**
 * Phady\Config\Yaml
 *
 * Reads YAML files and converts them to Phady\Config objects.
 *
 * Given the following configuration file:
 *
 *<code>
 * phady
 *   baseuri: /phady/
 * models:
 *   metadata: memory
 *</code>
 *
 * You can read it as follows:
 *
 *<code>
 * $config = new Phady\Config\Yaml();
 * $config->parse("path/config.yaml")
 * echo $config->phady->baseuri;
 * echo $config->models->metadata;
 *</code>
 *
 */
ZEPHIR_INIT_CLASS(Phady_Config_Yaml) {

	ZEPHIR_REGISTER_CLASS(Phady\\Config, Yaml, phady, config_yaml, phady_config_yaml_method_entry, 0);

	return SUCCESS;

}

/**
 * Phady\Config\Yaml constructor
 *
 * @param  string                    $filePath
 * @param  array                     $callbacks
 * @throws \Phady\Exception
 */
PHP_METHOD(Phady_Config_Yaml, parse) {

	zephir_fcall_cache_entry *_4 = NULL;
	int ZEPHIR_LAST_CALL_STATUS, ndocs = 0;
	zval *callbacks = NULL;
	zval *filePath_param = NULL, *callbacks_param = NULL, *yamlConfig = NULL, _0, *_1 = NULL, *_2 = NULL, *_3 = NULL, *_5;
	zval *filePath = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &filePath_param, &callbacks_param);

	if (unlikely(Z_TYPE_P(filePath_param) != IS_STRING && Z_TYPE_P(filePath_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'filePath' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(filePath_param) == IS_STRING)) {
		zephir_get_strval(filePath, filePath_param);
	} else {
		ZEPHIR_INIT_VAR(filePath);
		ZVAL_EMPTY_STRING(filePath);
	}
	if (!callbacks_param) {
	ZEPHIR_INIT_VAR(callbacks);
	array_init(callbacks);
	} else {
	callbacks = callbacks_param;

	}


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "yaml", 0);
	ZEPHIR_CALL_FUNCTION(&_1, "extension_loaded", NULL, 7, &_0);
	zephir_check_call_status();
	if (!(zephir_is_true(_1))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phady_exception_ce, "Yaml extension not loaded", "phady/config/yaml.zep", 42);
		return;
	}
	if (!ZEPHIR_IS_STRING_IDENTICAL(callbacks, "")) {
		ZEPHIR_INIT_VAR(_2);
		ZVAL_LONG(_2, 0);
		ZEPHIR_INIT_VAR(_3);
		ZVAL_LONG(_3, ndocs);
		Z_SET_ISREF_P(_3);
		ZEPHIR_CALL_FUNCTION(&yamlConfig, "yaml_parse_file", &_4, 29, filePath, _2, _3, callbacks);
		Z_UNSET_ISREF_P(_3);
		zephir_check_call_status();
	} else {
		ZEPHIR_CALL_FUNCTION(&yamlConfig, "yaml_parse_file", &_4, 29, filePath);
		zephir_check_call_status();
	}
	if (ZEPHIR_IS_FALSE_IDENTICAL(yamlConfig)) {
		ZEPHIR_INIT_NVAR(_2);
		object_init_ex(_2, phady_exception_ce);
		ZEPHIR_INIT_NVAR(_3);
		zephir_basename(_3, filePath TSRMLS_CC);
		ZEPHIR_INIT_VAR(_5);
		ZEPHIR_CONCAT_SVS(_5, "Configuration file ", _3, " can't be loaded");
		ZEPHIR_CALL_METHOD(NULL, _2, "__construct", NULL, 30, _5);
		zephir_check_call_status();
		zephir_throw_exception_debug(_2, "phady/config/yaml.zep", 53 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_CCTOR(yamlConfig);

}

