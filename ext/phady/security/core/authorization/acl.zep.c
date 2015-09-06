
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
#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/hash.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "ext/phalcon/phalcon/mvc/user/component.zep.h"


/**
  * @class Phady\Security\Core\Authorization\Acl -  Authorization handlers for app
  *
  * @author  Alien Fernández Fuentes <alienfernandez85@gmail.com>
  * @package Core
  * @copyright (c) 2015
  * @version 1.0.0
  */
ZEPHIR_INIT_CLASS(Phady_Security_Core_Authorization_Acl) {

	ZEPHIR_REGISTER_CLASS_EX(Phady\\Security\\Core\\Authorization, Acl, phady, security_core_authorization_acl, phalcon_mvc_user_component_ce, phady_security_core_authorization_acl_method_entry, 0);

	/**
	 * ACL Object
	 *
	 * @var \Phalcon\Acl\Adapter\Memory
	 */
	zend_declare_property_null(phady_security_core_authorization_acl_ce, SL("acl"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 *
	 * Name of the module that is using this component.
	 *
	 * @var string
	 */
	zend_declare_property_null(phady_security_core_authorization_acl_ce, SL("moduleName"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * Defines resources considered as "private". Are defined as
	 * controller => actions que requiere autenticación
	 *
	 * @var array
	 */
	zend_declare_property_null(phady_security_core_authorization_acl_ce, SL("resources"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * Accessible to everyone
	 * @var array
	 */
	zend_declare_property_null(phady_security_core_authorization_acl_ce, SL("publicResources"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 *
	 * Prefix acl.
	 *
	 * @const string
	 */
	zend_declare_class_constant_string(phady_security_core_authorization_acl_ce, SL("PREFIX_ACL_APP"), "app-acl-" TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Phady_Security_Core_Authorization_Acl, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_2 = NULL, *_3;
	zval *_0, *_1 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	zephir_create_array(_0, 5, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	zephir_create_array(_1, 1, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "*", 1);
	zephir_array_fast_append(_1, _2);
	zephir_array_update_string(&_0, SL("index"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(_1);
	zephir_create_array(_1, 1, 0 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "*", 1);
	zephir_array_fast_append(_1, _2);
	zephir_array_update_string(&_0, SL("login"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(_1);
	zephir_create_array(_1, 1, 0 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "*", 1);
	zephir_array_fast_append(_1, _2);
	zephir_array_update_string(&_0, SL("portal"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(_1);
	zephir_create_array(_1, 1, 0 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "*", 1);
	zephir_array_fast_append(_1, _2);
	zephir_array_update_string(&_0, SL("directorio"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(_1);
	zephir_create_array(_1, 1, 0 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "activar", 1);
	zephir_array_fast_append(_1, _2);
	zephir_array_update_string(&_0, SL("seguridad"), &_1, PH_COPY | PH_SEPARATE);
	zephir_update_property_this(this_ptr, SL("publicResources"), _0 TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_3);
	ZVAL_STRING(_3, "common", 1);
	zephir_update_property_this(this_ptr, SL("moduleName"), _3 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "loadresources", NULL, 77);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Check if a controller is private or not
 *
 * @param string controllerName
 * @return boolean
 */
PHP_METHOD(Phady_Security_Core_Authorization_Acl, isPrivate) {

	zval *controllerName, *_0;

	zephir_fetch_params(0, 1, 0, &controllerName);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("resources"), PH_NOISY_CC);
	RETURN_BOOL(zephir_array_isset(_0, controllerName));

}

/**
 * It checks if the current role has access to a resource
 *
 * @param string rol
 * @param string controller
 * @param string action
 * @return boolean
 */
PHP_METHOD(Phady_Security_Core_Authorization_Acl, isAllowed) {

	zend_bool _6;
	zephir_fcall_cache_entry *_4 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_1;
	HashPosition _0;
	zval *rol, *controller, *action, *value = NULL, *roles = NULL, **_2, *_3 = NULL, *_5 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &rol, &controller, &action);



	if (!(Z_TYPE_P(rol) == IS_ARRAY)) {
		ZEPHIR_INIT_VAR(roles);
		zephir_create_array(roles, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(roles, rol);
	} else {
		ZEPHIR_CPY_WRT(roles, rol);
	}
	zephir_is_iterable(roles, &_1, &_0, 0, 0, "phady/security/core/authorization/acl.zep", 112);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HVALUE(value, _2);
		ZEPHIR_CALL_METHOD(&_3, this_ptr, "getacl", &_4, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_5, _3, "isallowed", NULL, 0, value, controller, action);
		zephir_check_call_status();
		_6 = zephir_is_true(_5);
		if (!(_6)) {
			_6 = ZEPHIR_IS_STRING(controller, "error");
		}
		if (_6) {
			RETURN_MM_BOOL(1);
		}
	}
	RETURN_MM_BOOL(0);

}

/**
 * Obtener la lista ACL
 *
 * @return \Phalcon\Acl\Adapter\Memory
 */
PHP_METHOD(Phady_Security_Core_Authorization_Acl, getAcl) {

	zval *acpName, *_0, *_1;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("acl"), PH_NOISY_CC);
	if (Z_TYPE_P(_0) == IS_OBJECT) {
		RETURN_MM_MEMBER(this_ptr, "acl");
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("moduleName"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(acpName);
	ZEPHIR_CONCAT_SV(acpName, "app-acl-", _1);
	RETURN_MM_MEMBER(this_ptr, "acl");

}

/**
 * Carga los recursos y sus acciones desde la base de datos
 * para el modulo actual
 *
 * @return void
 */
PHP_METHOD(Phady_Security_Core_Authorization_Acl, loadResources) {

	zval *result;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(result);
	array_init(result);
	zephir_update_property_this(this_ptr, SL("resources"), result TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

