
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
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/string.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "ext/phalcon/phalcon/di/injectable.zep.h"


/**
 * Phady\Security\Core\Models\Repositories\Users
 *
 * Repository for Users
 */
ZEPHIR_INIT_CLASS(Phady_Security_Core_Models_Repositories_Users) {

	ZEPHIR_REGISTER_CLASS_EX(Phady\\Security\\Core\\Models\\Repositories, Users, phady, security_core_models_repositories_users, phalcon_di_injectable_ce, phady_security_core_models_repositories_users_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Phady_Security_Core_Models_Repositories_Users, getFilter) {

	zval *arrData, *select = NULL, *arrFilter, *arrValues, *filter, _0, *_1 = NULL, *_2, *_3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &arrData, &select);

	if (!select) {
		select = ZEPHIR_GLOBAL(global_false);
	}


	ZEPHIR_INIT_VAR(arrFilter);
	array_init(arrFilter);
	ZEPHIR_INIT_VAR(arrValues);
	array_init(arrValues);
	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "user_id", 0);
	if (zephir_array_key_exists(arrData, &_0 TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(_1);
		ZVAL_STRING(_1, "user.user_id = :user_id:", 1);
		zephir_array_append(&arrFilter, _1, PH_SEPARATE, "phady/security/core/models/repositories/users.zep", 31);
		zephir_array_fetch_string(&_2, arrData, SL("user_id"), PH_NOISY | PH_READONLY, "phady/security/core/models/repositories/users.zep", 32 TSRMLS_CC);
		zephir_array_update_string(&arrValues, SL("user_id"), &_2, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_INIT_VAR(filter);
	zephir_fast_join_str(filter, SL(" AND "), arrFilter TSRMLS_CC);
	ZEPHIR_INIT_NVAR(_1);
	if (zephir_is_true(arrFilter)) {
		zephir_create_array(_1, 2, 0 TSRMLS_CC);
		zephir_array_update_string(&_1, SL("filter"), &filter, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_1, SL("values"), &arrValues, PH_COPY | PH_SEPARATE);
	} else {
		zephir_create_array(_1, 2, 0 TSRMLS_CC);
		add_assoc_stringl_ex(_1, SS("filter"), SL(""), 1);
		ZEPHIR_INIT_VAR(_3);
		array_init(_3);
		zephir_array_update_string(&_1, SL("values"), &_3, PH_COPY | PH_SEPARATE);
	}
	RETURN_CCTOR(_1);

}

/**
 * @name getUsers - Get users given the array of filter
 * @param array arrDataFilter - Array filter
 *              [create_at] - Date
 *              [start] - Start date
 *              [limit] - Limit items per page
 * @return array
 */
PHP_METHOD(Phady_Security_Core_Models_Repositories_Users, getUsers) {

	zend_bool _4;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *arrDataFilter_param = NULL, *getFilter = NULL, *qbuild = NULL, *users = NULL, *_0 = NULL, *_1 = NULL, *_2 = NULL, _3, *_5, *_6, *_7 = NULL, *_9 = NULL, *_10, *_11 = NULL, *_12 = NULL;
	zval *arrDataFilter = NULL, *_8;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &arrDataFilter_param);

	zephir_get_arrval(arrDataFilter, arrDataFilter_param);


	ZEPHIR_CALL_SELF(&getFilter, "getfilter", NULL, 0, arrDataFilter);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getdi", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "modelsManager", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_1, _0, "get", NULL, 0, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&qbuild, _1, "createbuilder", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(getFilter)) {
		ZEPHIR_SINIT_VAR(_3);
		ZVAL_STRING(&_3, "filter", 0);
		_4 = zephir_array_key_exists(getFilter, &_3 TSRMLS_CC);
		if (_4) {
			zephir_array_fetch_string(&_5, getFilter, SL("filter"), PH_NOISY | PH_READONLY, "phady/security/core/models/repositories/users.zep", 53 TSRMLS_CC);
			_4 = zephir_is_true(_5);
		}
		if (_4) {
			zephir_array_fetch_string(&_6, getFilter, SL("filter"), PH_NOISY | PH_READONLY, "phady/security/core/models/repositories/users.zep", 54 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(NULL, qbuild, "where", NULL, 0, _6);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_VAR(_8);
	zephir_create_array(_8, 6, 0 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "user.user_id", 1);
	zephir_array_fast_append(_8, _2);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "user.username", 1);
	zephir_array_fast_append(_8, _2);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "user.enabled", 1);
	zephir_array_fast_append(_8, _2);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "user.salt", 1);
	zephir_array_fast_append(_8, _2);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "user.salt_expiration_date", 1);
	zephir_array_fast_append(_8, _2);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "user.email", 1);
	zephir_array_fast_append(_8, _2);
	ZEPHIR_CALL_METHOD(&_7, qbuild, "columns", NULL, 0, _8);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "\\Phady\\Security\\Core\\Models\\Entities\\Users", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_10);
	ZVAL_STRING(_10, "user", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_9, _7, "addfrom", NULL, 0, _2, _10);
	zephir_check_temp_parameter(_2);
	zephir_check_temp_parameter(_10);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_11, _9, "getquery", NULL, 0);
	zephir_check_call_status();
	zephir_array_fetch_string(&_5, getFilter, SL("values"), PH_NOISY | PH_READONLY, "phady/security/core/models/repositories/users.zep", 61 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_12, _11, "execute", NULL, 0, _5);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&users, _12, "toarray", NULL, 0);
	zephir_check_call_status();
	RETURN_CCTOR(users);

}

/**
 * @name getTotalUsers - Get total users given the array of filter
 * @param array arrDataFilter - Array filter
 *              [create_at] - Date
 * @return array
 */
PHP_METHOD(Phady_Security_Core_Models_Repositories_Users, getTotalUsers) {

	zend_bool _4;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *arrDataFilter_param = NULL, *getFilter = NULL, *qbuild = NULL, *count = NULL, *_0 = NULL, *_1 = NULL, *_2 = NULL, _3, *_5, *_6, *_7 = NULL, *_9 = NULL, *_10, *_11 = NULL, *_12 = NULL, *_13;
	zval *arrDataFilter = NULL, *_8;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &arrDataFilter_param);

	zephir_get_arrval(arrDataFilter, arrDataFilter_param);


	ZEPHIR_CALL_SELF(&getFilter, "getfilter", NULL, 0, arrDataFilter);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getdi", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "modelsManager", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_1, _0, "get", NULL, 0, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&qbuild, _1, "createbuilder", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(getFilter)) {
		ZEPHIR_SINIT_VAR(_3);
		ZVAL_STRING(&_3, "filter", 0);
		_4 = zephir_array_key_exists(getFilter, &_3 TSRMLS_CC);
		if (_4) {
			zephir_array_fetch_string(&_5, getFilter, SL("filter"), PH_NOISY | PH_READONLY, "phady/security/core/models/repositories/users.zep", 79 TSRMLS_CC);
			_4 = zephir_is_true(_5);
		}
		if (_4) {
			zephir_array_fetch_string(&_6, getFilter, SL("filter"), PH_NOISY | PH_READONLY, "phady/security/core/models/repositories/users.zep", 80 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(NULL, qbuild, "where", NULL, 0, _6);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_VAR(_8);
	zephir_create_array(_8, 1, 0 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "COUNT(user.user_id) as total", 1);
	zephir_array_fast_append(_8, _2);
	ZEPHIR_CALL_METHOD(&_7, qbuild, "columns", NULL, 0, _8);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "\\Phady\\Security\\Core\\Models\\Entities\\Users", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_10);
	ZVAL_STRING(_10, "user", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_9, _7, "addfrom", NULL, 0, _2, _10);
	zephir_check_temp_parameter(_2);
	zephir_check_temp_parameter(_10);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_11, _9, "getquery", NULL, 0);
	zephir_check_call_status();
	zephir_array_fetch_string(&_5, getFilter, SL("values"), PH_NOISY | PH_READONLY, "phady/security/core/models/repositories/users.zep", 86 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_12, _11, "execute", NULL, 0, _5);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&count, _12, "toarray", NULL, 0);
	zephir_check_call_status();
	zephir_array_fetch_long(&_6, count, 0, PH_NOISY | PH_READONLY, "phady/security/core/models/repositories/users.zep", 89 TSRMLS_CC);
	zephir_array_fetch_string(&_13, _6, SL("total"), PH_NOISY | PH_READONLY, "phady/security/core/models/repositories/users.zep", 89 TSRMLS_CC);
	RETURN_CTOR(_13);

}

