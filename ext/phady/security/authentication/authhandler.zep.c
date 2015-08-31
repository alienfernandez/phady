
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
#include "kernel/object.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/hash.h"


/**
  * @class Phady\Security\Authentication\AuthHandler -  Authentication handlers for app
  *
  * @author  Alien Fernández Fuentes <alienfernandez85@gmail.com>
  * @package Core
  * @copyright (c) 2015
  * @version 1.0.0
  */
ZEPHIR_INIT_CLASS(Phady_Security_Authentication_AuthHandler) {

	ZEPHIR_REGISTER_CLASS(Phady\\Security\\Authentication, AuthHandler, phady, security_authentication_authhandler, phady_security_authentication_authhandler_method_entry, ZEND_ACC_FINAL_CLASS);

	/**
	 * @var array securityConfig - Config security
	 */
	zend_declare_property_null(phady_security_authentication_authhandler_ce, SL("securityConfig"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * @param array config - Config db
 */
PHP_METHOD(Phady_Security_Authentication_AuthHandler, __construct) {

	zval *configSecurity_param = NULL;
	zval *configSecurity = NULL;

	zephir_fetch_params(0, 1, 0, &configSecurity_param);

	configSecurity = configSecurity_param;



	zephir_update_property_this(this_ptr, SL("securityConfig"), configSecurity TSRMLS_CC);

}

/**
 * @name checkCredentials - Verifies user credentials
 * @param array credentials - Array Credentials
 *              [username] - User name
 * @return boolean
 */
PHP_METHOD(Phady_Security_Authentication_AuthHandler, checkCredentials) {

	zend_bool _4, _5, _9, _12;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *credentials_param = NULL, *arrErrors = NULL, *password = NULL, *userData, *checkStatus = NULL, *auth = NULL, *_0, *_1, *_2, *_3, _6, *_7, *_8 = NULL, _10, *_11 = NULL, _13;
	zval *credentials = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &credentials_param);

	credentials = credentials_param;



	ZEPHIR_INIT_VAR(arrErrors);
	array_init(arrErrors);
	ZEPHIR_INIT_VAR(userData);
	array_init(userData);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("securityConfig"), PH_NOISY_CC);
	zephir_array_fetch_string(&_1, _0, SL("security"), PH_NOISY | PH_READONLY, "phady/security/authentication/authhandler.zep", 57 TSRMLS_CC);
	zephir_array_fetch_string(&_2, _1, SL("encoding_format"), PH_NOISY | PH_READONLY, "phady/security/authentication/authhandler.zep", 57 TSRMLS_CC);
	zephir_array_fetch_string(&_3, credentials, SL("password"), PH_NOISY | PH_READONLY, "phady/security/authentication/authhandler.zep", 57 TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(&password, "hash", NULL, 41, _2, _3);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&checkStatus, this_ptr, "checkuserflags", NULL, 42, userData);
	zephir_check_call_status();
	_4 = zephir_is_true(checkStatus);
	if (_4) {
		_4 = Z_TYPE_P(checkStatus) == IS_ARRAY;
	}
	_5 = _4;
	if (_5) {
		ZEPHIR_SINIT_VAR(_6);
		ZVAL_STRING(&_6, "error_code", 0);
		_5 = zephir_array_key_exists(checkStatus, &_6 TSRMLS_CC);
	}
	zephir_array_fetch_string(&_7, userData, SL("Clave"), PH_NOISY | PH_READONLY, "phady/security/authentication/authhandler.zep", 63 TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(&_8, "strcmp", NULL, 43, password, _7);
	zephir_check_call_status();
	_9 = !zephir_is_true(userData);
	if (!(_9)) {
		ZEPHIR_SINIT_VAR(_10);
		ZVAL_STRING(&_10, "user_id", 0);
		_9 = !(zephir_array_key_exists(userData, &_10 TSRMLS_CC));
	}
	if (_5) {
		ZEPHIR_INIT_VAR(_11);
		zephir_fast_array_merge(_11, &(arrErrors), &(checkStatus) TSRMLS_CC);
		ZEPHIR_CPY_WRT(arrErrors, _11);
	} else if (!ZEPHIR_IS_LONG_IDENTICAL(_8, 0)) {
		ZEPHIR_INIT_NVAR(_11);
		ZVAL_STRING(_11, "INCORRECT_CREDENTIALS", 1);
		zephir_array_update_string(&arrErrors, SL("error_code"), &_11, PH_COPY | PH_SEPARATE);
	} else if (_9) {
		ZEPHIR_INIT_NVAR(_11);
		ZVAL_STRING(_11, "INCORRECT_CREDENTIALS", 1);
		zephir_array_update_string(&arrErrors, SL("error_code"), &_11, PH_COPY | PH_SEPARATE);
	}
	_12 = zephir_is_true(arrErrors);
	if (!(_12)) {
		ZEPHIR_SINIT_VAR(_13);
		ZVAL_STRING(&_13, "error_code", 0);
		_12 = zephir_array_key_exists(arrErrors, &_13 TSRMLS_CC);
	}
	if (_12) {
		ZEPHIR_CPY_WRT(auth, arrErrors);
	} else {
		ZEPHIR_INIT_NVAR(auth);
		ZVAL_BOOL(auth, 1);
	}
	RETURN_CCTOR(auth);

}

/**
 * Check user status
 *
 * @param array user
 */
PHP_METHOD(Phady_Security_Authentication_AuthHandler, checkUserFlags) {

	zend_bool _1;
	zval *user_param = NULL, *arrStatus, *_0, *_2, *_3, *_4 = NULL, *_5;
	zval *user = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &user_param);

	zephir_get_arrval(user, user_param);
	ZEPHIR_INIT_VAR(arrStatus);
	array_init(arrStatus);


	zephir_array_fetch_string(&_0, user, SL("status_code"), PH_NOISY | PH_READONLY, "phady/security/authentication/authhandler.zep", 90 TSRMLS_CC);
	_1 = ZEPHIR_IS_STRING(_0, "INACTIVE");
	if (!(_1)) {
		zephir_array_fetch_string(&_2, user, SL("status_code"), PH_NOISY | PH_READONLY, "phady/security/authentication/authhandler.zep", 90 TSRMLS_CC);
		_1 = ZEPHIR_IS_STRING(_2, "LOCKED");
	}
	if (_1) {
		zephir_array_fetch_string(&_3, user, SL("status_code"), PH_NOISY | PH_READONLY, "phady/security/authentication/authhandler.zep", 91 TSRMLS_CC);
		if (ZEPHIR_IS_STRING(_3, "INACTIVE")) {
			ZEPHIR_INIT_VAR(_4);
			ZVAL_STRING(_4, "INACTIVE_USER_CODE", 1);
			zephir_array_update_string(&arrStatus, SL("error_code"), &_4, PH_COPY | PH_SEPARATE);
		}
		zephir_array_fetch_string(&_5, user, SL("status_code"), PH_NOISY | PH_READONLY, "phady/security/authentication/authhandler.zep", 94 TSRMLS_CC);
		if (ZEPHIR_IS_STRING(_5, "LOCKED")) {
			ZEPHIR_INIT_NVAR(_4);
			ZVAL_STRING(_4, "LOCKED_USER_CODE", 1);
			zephir_array_update_string(&arrStatus, SL("error_code"), &_4, PH_COPY | PH_SEPARATE);
		}
	}
	RETURN_CCTOR(arrStatus);

}

/**
 * Obtener los datos que se van a modificar en la session
 *
 * @param array userData
 * @return \stdClass
 */
PHP_METHOD(Phady_Security_Authentication_AuthHandler, getDataSession) {

	HashTable *_2;
	HashPosition _1;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *userData_param = NULL, *user, *tmpRoles, *vRol = NULL, *auth, *_0 = NULL, **_3, *_4 = NULL, *_5, *_6, *_7, *_8, *_9;
	zval *userData = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &userData_param, &user);

	userData = userData_param;



	ZEPHIR_INIT_VAR(tmpRoles);
	array_init(tmpRoles);
	ZEPHIR_CALL_METHOD(&_0, user, "getroles", NULL, 0);
	zephir_check_call_status();
	zephir_is_iterable(_0, &_2, &_1, 0, 0, "phady/security/authentication/authhandler.zep", 113);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HVALUE(vRol, _3);
		ZEPHIR_OBS_NVAR(_4);
		zephir_read_property(&_4, vRol, SL("RolId"), PH_NOISY_CC);
		zephir_array_append(&tmpRoles, _4, PH_SEPARATE, "phady/security/authentication/authhandler.zep", 111);
	}
	ZEPHIR_INIT_VAR(auth);
	object_init(auth);
	zephir_array_fetch_string(&_5, userData, SL("user_id"), PH_NOISY | PH_READONLY, "phady/security/authentication/authhandler.zep", 114 TSRMLS_CC);
	zephir_update_property_zval(auth, SL("user_id"), _5 TSRMLS_CC);
	zephir_array_fetch_string(&_6, userData, SL("contact_id"), PH_NOISY | PH_READONLY, "phady/security/authentication/authhandler.zep", 115 TSRMLS_CC);
	zephir_update_property_zval(auth, SL("contact_id"), _6 TSRMLS_CC);
	zephir_array_fetch_string(&_7, userData, SL("username"), PH_NOISY | PH_READONLY, "phady/security/authentication/authhandler.zep", 116 TSRMLS_CC);
	zephir_update_property_zval(auth, SL("username"), _7 TSRMLS_CC);
	zephir_array_fetch_string(&_8, userData, SL("name"), PH_NOISY | PH_READONLY, "phady/security/authentication/authhandler.zep", 117 TSRMLS_CC);
	zephir_update_property_zval(auth, SL("name"), _8 TSRMLS_CC);
	zephir_array_fetch_string(&_9, userData, SL("email"), PH_NOISY | PH_READONLY, "phady/security/authentication/authhandler.zep", 118 TSRMLS_CC);
	zephir_update_property_zval(auth, SL("email"), _9 TSRMLS_CC);
	zephir_update_property_zval(auth, SL("roles"), tmpRoles TSRMLS_CC);
	RETURN_CCTOR(auth);

}

