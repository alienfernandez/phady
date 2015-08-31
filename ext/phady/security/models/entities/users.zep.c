
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
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/memory.h"


/**
 * Phady\Security\Models\Entities\Users
 *
 * Model for Users
 */
ZEPHIR_INIT_CLASS(Phady_Security_Models_Entities_Users) {

	ZEPHIR_REGISTER_CLASS_EX(Phady\\Security\\Models\\Entities, Users, phady, security_models_entities_users, phady_common_entities_modelbase_ce, phady_security_models_entities_users_method_entry, 0);

	/**
	 * @Primary
	 * @var integer
	 */
	zend_declare_property_null(phady_security_models_entities_users_ce, SL("user_id"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var string
	 */
	zend_declare_property_null(phady_security_models_entities_users_ce, SL("firstname"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var string
	 */
	zend_declare_property_null(phady_security_models_entities_users_ce, SL("lastname"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var string
	 */
	zend_declare_property_null(phady_security_models_entities_users_ce, SL("username"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var string
	 */
	zend_declare_property_null(phady_security_models_entities_users_ce, SL("username_canonical"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var string
	 */
	zend_declare_property_null(phady_security_models_entities_users_ce, SL("email"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var string
	 */
	zend_declare_property_null(phady_security_models_entities_users_ce, SL("email_canonical"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var numeric(1)
	 */
	zend_declare_property_null(phady_security_models_entities_users_ce, SL("enabled"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var string
	 */
	zend_declare_property_null(phady_security_models_entities_users_ce, SL("salt"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 *
	 * @var string
	 */
	zend_declare_property_null(phady_security_models_entities_users_ce, SL("password"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 *
	 * @var datetime
	 */
	zend_declare_property_null(phady_security_models_entities_users_ce, SL("last_login"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Phady_Security_Models_Entities_Users, initialize) {



}

/**
 * Physics returns the table name in the database engine
 *
 * @return string
 */
PHP_METHOD(Phady_Security_Models_Entities_Users, getSource) {


	RETURN_STRING("phd_user", 1);

}

/**
 * Initializes the class. It assigns the attributes that can be obtained and modified.
 */
PHP_METHOD(Phady_Security_Models_Entities_Users, init) {

	zval *_1, *_2 = NULL, *_3 = NULL, *_4 = NULL, *_5 = NULL, *_6 = NULL, *_7 = NULL, *_8 = NULL, *_9 = NULL, *_10 = NULL, *_11 = NULL, *_12 = NULL, *_14;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL, *_13 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_PARENT(NULL, phady_security_models_entities_users_ce, this_ptr, "init", &_0, 45);
	zephir_check_call_status();
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_set"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "user_id", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_STRING(_3, "firstname", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_4);
	ZVAL_STRING(_4, "lastname", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_5);
	ZVAL_STRING(_5, "username", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_6);
	ZVAL_STRING(_6, "username_canonical", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_7);
	ZVAL_STRING(_7, "email", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_8);
	ZVAL_STRING(_8, "email_canonical", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_9);
	ZVAL_STRING(_9, "enabled", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_10);
	ZVAL_STRING(_10, "salt", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_11);
	ZVAL_STRING(_11, "password", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_12);
	ZVAL_STRING(_12, "last_login", ZEPHIR_TEMP_PARAM_COPY);
	Z_SET_ISREF_P(_1);
	ZEPHIR_CALL_FUNCTION(NULL, "array_push", &_13, 46, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12);
	zephir_check_temp_parameter(_2);
	zephir_check_temp_parameter(_3);
	zephir_check_temp_parameter(_4);
	zephir_check_temp_parameter(_5);
	zephir_check_temp_parameter(_6);
	zephir_check_temp_parameter(_7);
	zephir_check_temp_parameter(_8);
	zephir_check_temp_parameter(_9);
	zephir_check_temp_parameter(_10);
	zephir_check_temp_parameter(_11);
	zephir_check_temp_parameter(_12);
	Z_UNSET_ISREF_P(_1);
	zephir_check_call_status();
	_14 = zephir_fetch_nproperty_this(this_ptr, SL("_get"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "user_id", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_STRING(_3, "firstname", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_STRING(_4, "lastname", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_5);
	ZVAL_STRING(_5, "username", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_6);
	ZVAL_STRING(_6, "username_canonical", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_7);
	ZVAL_STRING(_7, "email", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_8);
	ZVAL_STRING(_8, "email_canonical", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_9);
	ZVAL_STRING(_9, "enabled", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_10);
	ZVAL_STRING(_10, "salt", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_11);
	ZVAL_STRING(_11, "password", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_12);
	ZVAL_STRING(_12, "last_login", ZEPHIR_TEMP_PARAM_COPY);
	Z_SET_ISREF_P(_14);
	ZEPHIR_CALL_FUNCTION(NULL, "array_push", &_13, 46, _14, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12);
	zephir_check_temp_parameter(_2);
	zephir_check_temp_parameter(_3);
	zephir_check_temp_parameter(_4);
	zephir_check_temp_parameter(_5);
	zephir_check_temp_parameter(_6);
	zephir_check_temp_parameter(_7);
	zephir_check_temp_parameter(_8);
	zephir_check_temp_parameter(_9);
	zephir_check_temp_parameter(_10);
	zephir_check_temp_parameter(_11);
	zephir_check_temp_parameter(_12);
	Z_UNSET_ISREF_P(_14);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

