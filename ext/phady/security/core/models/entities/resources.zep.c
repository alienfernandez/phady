
#ifdef HAVE_CONFIG_H
#include "../../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../../php_ext.h"
#include "../../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/memory.h"


/**
 * Phady\Security\Models\Core\Entities\Resources
 *
 * Model for Resources
 */
ZEPHIR_INIT_CLASS(Phady_Security_Core_Models_Entities_Resources) {

	ZEPHIR_REGISTER_CLASS_EX(Phady\\Security\\Core\\Models\\Entities, Resources, phady, security_core_models_entities_resources, phady_common_entities_modelbase_ce, phady_security_core_models_entities_resources_method_entry, 0);

	/**
	 * @Primary
	 * @var integer
	 */
	zend_declare_property_null(phady_security_core_models_entities_resources_ce, SL("resource_id"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @Primary
	 * @var integer
	 */
	zend_declare_property_null(phady_security_core_models_entities_resources_ce, SL("module_id"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var string
	 */
	zend_declare_property_null(phady_security_core_models_entities_resources_ce, SL("name"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Phady_Security_Core_Models_Entities_Resources, initialize) {



}

/**
 * Physics returns the table name in the database engine
 *
 * @return string
 */
PHP_METHOD(Phady_Security_Core_Models_Entities_Resources, getSource) {


	RETURN_STRING("phd_sec_resources", 1);

}

/**
 * Initializes the class. It assigns the attributes that can be obtained and modified.
 */
PHP_METHOD(Phady_Security_Core_Models_Entities_Resources, init) {

	zval *_1, *_2 = NULL, *_3 = NULL, *_4 = NULL, *_6;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL, *_5 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_PARENT(NULL, phady_security_core_models_entities_resources_ce, this_ptr, "init", &_0, 82);
	zephir_check_call_status();
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_set"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "resource_id", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_STRING(_3, "module_id", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_4);
	ZVAL_STRING(_4, "name", ZEPHIR_TEMP_PARAM_COPY);
	Z_SET_ISREF_P(_1);
	ZEPHIR_CALL_FUNCTION(NULL, "array_push", &_5, 83, _1, _2, _3, _4);
	zephir_check_temp_parameter(_2);
	zephir_check_temp_parameter(_3);
	zephir_check_temp_parameter(_4);
	Z_UNSET_ISREF_P(_1);
	zephir_check_call_status();
	_6 = zephir_fetch_nproperty_this(this_ptr, SL("_get"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "resource_id", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_STRING(_3, "module_id", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_STRING(_4, "name", ZEPHIR_TEMP_PARAM_COPY);
	Z_SET_ISREF_P(_6);
	ZEPHIR_CALL_FUNCTION(NULL, "array_push", &_5, 83, _6, _2, _3, _4);
	zephir_check_temp_parameter(_2);
	zephir_check_temp_parameter(_3);
	zephir_check_temp_parameter(_4);
	Z_UNSET_ISREF_P(_6);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

