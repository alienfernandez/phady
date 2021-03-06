
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
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/object.h"


/**
 * Phady\Security\Models\Core\Entities\UserRole
 *
 * Model for Users relation Roles
 */
ZEPHIR_INIT_CLASS(Phady_Security_Core_Models_Entities_UserRole) {

	ZEPHIR_REGISTER_CLASS_EX(Phady\\Security\\Core\\Models\\Entities, UserRole, phady, security_core_models_entities_userrole, phady_common_entities_modelbase_ce, phady_security_core_models_entities_userrole_method_entry, 0);

	/**
	 * @Primary
	 * @var integer
	 */
	zend_declare_property_null(phady_security_core_models_entities_userrole_ce, SL("user_role_id"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var integer
	 */
	zend_declare_property_null(phady_security_core_models_entities_userrole_ce, SL("role_id"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var integer
	 */
	zend_declare_property_null(phady_security_core_models_entities_userrole_ce, SL("user_id"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Phady_Security_Core_Models_Entities_UserRole, initialize) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_1 = NULL, *_2 = NULL, *_3 = NULL;
	zval *_0, *_4;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	zephir_create_array(_0, 1, 0 TSRMLS_CC);
	add_assoc_stringl_ex(_0, SS("alias"), SL("Roles"), 1);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "role_id", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "Phady\\Security\\Models\\Core\\Entities\\Roles", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_STRING(_3, "role_id", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "belongsto", NULL, 0, _1, _2, _3, _0);
	zephir_check_temp_parameter(_1);
	zephir_check_temp_parameter(_2);
	zephir_check_temp_parameter(_3);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_4);
	zephir_create_array(_4, 1, 0 TSRMLS_CC);
	add_assoc_stringl_ex(_4, SS("alias"), SL("Users"), 1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "user_id", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "Phady\\Security\\Models\\Core\\Entities\\Users", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_STRING(_3, "user_id", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "belongsto", NULL, 0, _1, _2, _3, _4);
	zephir_check_temp_parameter(_1);
	zephir_check_temp_parameter(_2);
	zephir_check_temp_parameter(_3);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Physics returns the table name in the database engine
 *
 * @return string
 */
PHP_METHOD(Phady_Security_Core_Models_Entities_UserRole, getSource) {


	RETURN_STRING("phd_sec_user_role", 1);

}

/**
 * Initializes the class. It assigns the attributes that can be obtained and modified.
 */
PHP_METHOD(Phady_Security_Core_Models_Entities_UserRole, init) {

	zval *_1, *_2 = NULL, *_3 = NULL, *_4 = NULL, *_6;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL, *_5 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_PARENT(NULL, phady_security_core_models_entities_userrole_ce, this_ptr, "init", &_0, 56);
	zephir_check_call_status();
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_set"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "user_role_id", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_STRING(_3, "role_id", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_4);
	ZVAL_STRING(_4, "user_id", ZEPHIR_TEMP_PARAM_COPY);
	Z_SET_ISREF_P(_1);
	ZEPHIR_CALL_FUNCTION(NULL, "array_push", &_5, 57, _1, _2, _3, _4);
	zephir_check_temp_parameter(_2);
	zephir_check_temp_parameter(_3);
	zephir_check_temp_parameter(_4);
	Z_UNSET_ISREF_P(_1);
	zephir_check_call_status();
	_6 = zephir_fetch_nproperty_this(this_ptr, SL("_get"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "user_role_id", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_STRING(_3, "role_id", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_STRING(_4, "user_id", ZEPHIR_TEMP_PARAM_COPY);
	Z_SET_ISREF_P(_6);
	ZEPHIR_CALL_FUNCTION(NULL, "array_push", &_5, 57, _6, _2, _3, _4);
	zephir_check_temp_parameter(_2);
	zephir_check_temp_parameter(_3);
	zephir_check_temp_parameter(_4);
	Z_UNSET_ISREF_P(_6);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

