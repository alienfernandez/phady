
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
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/string.h"
#include "kernel/concat.h"
#include "kernel/operators.h"
#include "ext/phalcon/phalcon/mvc/model.zep.h"


/**
 * Phady\Common\Entities\ModelBase
 *
 * Base Model
 */
ZEPHIR_INIT_CLASS(Phady_Common_Entities_ModelBase) {

	ZEPHIR_REGISTER_CLASS_EX(Phady\\Common\\Entities, ModelBase, phady, common_entities_modelbase, phalcon_mvc_model_ce, phady_common_entities_modelbase_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * Stores that attributes can be setter
	 *
	 * @var array
	 */
	zend_declare_property_null(phady_common_entities_modelbase_ce, SL("_set"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Stores that attributes can be getter
	 *
	 * @var array
	 */
	zend_declare_property_null(phady_common_entities_modelbase_ce, SL("_get"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Stores the attributes that relate to class with another with different cardinality (one to one , one to many , etc ) .
	 * Preserves the core functionality of Phalcon .
	 * @var type
	 */
	zend_declare_property_null(phady_common_entities_modelbase_ce, SL("_related"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Stores the date the record
	 *
	 * @var timestamp
	 */
	zend_declare_property_null(phady_common_entities_modelbase_ce, SL("create_at"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Stores the last modified date of registration
	 *
	 * @var timestamp
	 */
	zend_declare_property_null(phady_common_entities_modelbase_ce, SL("modify_at"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Stores the ID of the user who created the record
	 *
	 * @var uuid
	 */
	zend_declare_property_null(phady_common_entities_modelbase_ce, SL("create_user"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 *
	 * Stores the identifier of the user who last modified the record.
	 *
	 * @var uuid
	 */
	zend_declare_property_null(phady_common_entities_modelbase_ce, SL("modify_user"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 *
	 * Saves last IP address that made ​​a change and created the record.
	 *
	 * @var uuid
	 */
	zend_declare_property_null(phady_common_entities_modelbase_ce, SL("request_ip"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Performs procedures to initialize the class
 */
PHP_METHOD(Phady_Common_Entities_ModelBase, onConstruct) {

	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(NULL, this_ptr, "init", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Inicializa la clase. Asigna los attributeutos que pueden ser obtenidos
 * y seteados.
 */
PHP_METHOD(Phady_Common_Entities_ModelBase, init) {

	zval *_1 = NULL;
	zval *_0, *_2;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	zephir_create_array(_0, 5, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "create_at", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "modify_at", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "create_user", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "modify_user", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "request_ip", 1);
	zephir_array_fast_append(_0, _1);
	zephir_update_property_this(this_ptr, SL("_set"), _0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_2);
	zephir_create_array(_2, 5, 0 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "create_at", 1);
	zephir_array_fast_append(_2, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "modify_at", 1);
	zephir_array_fast_append(_2, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "create_user", 1);
	zephir_array_fast_append(_2, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "modify_user", 1);
	zephir_array_fast_append(_2, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "request_ip", 1);
	zephir_array_fast_append(_2, _1);
	zephir_update_property_this(this_ptr, SL("_get"), _2 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Method magic to set starting attributeutos allowed .
 *
 * If a validation method executes .
 *
 * If there is a specific method for setting it uses it, otherwise it It sets directly
 *
 * @param string attribute
 * @param string value
 * @throws Exception
 */
PHP_METHOD(Phady_Common_Entities_ModelBase, __set) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool _0, _2;
	zval *attribute_param = NULL, *value, *varName, *validateMethod, *setMethod, *reflectionClass, *reflectionProperty = NULL, *_1, *_3, *_4, *_5 = NULL, *_6, *_7 = NULL;
	zval *attribute = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &attribute_param, &value);

	zephir_get_strval(attribute, attribute_param);


	_0 = zephir_isset_property(this_ptr, SS("_related") TSRMLS_CC);
	if (_0) {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("_related"), PH_NOISY_CC);
		_0 = Z_TYPE_P(_1) == IS_ARRAY;
	}
	_2 = _0;
	if (_2) {
		_3 = zephir_fetch_nproperty_this(this_ptr, SL("_related"), PH_NOISY_CC);
		_2 = zephir_fast_in_array(attribute, _3 TSRMLS_CC);
	}
	if (_2) {
		ZEPHIR_RETURN_CALL_PARENT(phady_common_entities_modelbase_ce, this_ptr, "__get", NULL, 0, attribute);
		zephir_check_call_status();
		RETURN_MM();
	}
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("_set"), PH_NOISY_CC);
	if (zephir_fast_in_array(attribute, _4 TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(_5);
		ZVAL_STRING(_5, "_", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_INIT_VAR(_6);
		ZVAL_STRING(_6, "", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_FUNCTION(&_7, "str_ireplace", NULL, 1, _5, _6, attribute);
		zephir_check_temp_parameter(_5);
		zephir_check_temp_parameter(_6);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(varName);
		zephir_ucfirst(varName, _7);
		ZEPHIR_INIT_VAR(validateMethod);
		ZEPHIR_CONCAT_SV(validateMethod, "validate", varName);
		ZEPHIR_INIT_VAR(setMethod);
		ZEPHIR_CONCAT_SV(setMethod, "set", varName);
		if ((zephir_method_exists(this_ptr, setMethod TSRMLS_CC)  == SUCCESS)) {
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "setmethod", NULL, 0, value);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_VAR(reflectionClass);
			object_init_ex(reflectionClass, zephir_get_internal_ce(SS("reflectionclass") TSRMLS_CC));
			ZEPHIR_CALL_METHOD(NULL, reflectionClass, "__construct", NULL, 2, this_ptr);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&reflectionProperty, reflectionClass, "getproperty", NULL, 3, attribute);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(_5);
			ZVAL_BOOL(_5, 1);
			ZEPHIR_CALL_METHOD(NULL, reflectionProperty, "setaccessible", NULL, 0, _5);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, reflectionProperty, "setvalue", NULL, 0, this_ptr, value);
			zephir_check_call_status();
		}
	}
	ZEPHIR_MM_RESTORE();

}

/**
 *
 * Gets the value of an attribute. If there is a specific method for the attribute is used,
 * otherwise only available directly.
 *
 * @param string attribute
 * @return type
 */
PHP_METHOD(Phady_Common_Entities_ModelBase, __get) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool _0, _2;
	zval *attribute, *methodName, *_1, *_3, *_4, *_5, *_6, *_7, *_8 = NULL, *_9 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &attribute);



	_0 = zephir_isset_property(this_ptr, SS("_related") TSRMLS_CC);
	if (_0) {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("_related"), PH_NOISY_CC);
		_0 = Z_TYPE_P(_1) == IS_ARRAY;
	}
	_2 = _0;
	if (_2) {
		_3 = zephir_fetch_nproperty_this(this_ptr, SL("_related"), PH_NOISY_CC);
		_2 = zephir_fast_in_array(attribute, _3 TSRMLS_CC);
	}
	if (_2) {
		ZEPHIR_RETURN_CALL_PARENT(phady_common_entities_modelbase_ce, this_ptr, "__get", NULL, 0, attribute);
		zephir_check_call_status();
		RETURN_MM();
	}
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("_get"), PH_NOISY_CC);
	if (zephir_fast_in_array(attribute, _4 TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(_5);
		ZEPHIR_INIT_VAR(_6);
		ZVAL_STRING(_6, "_", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_INIT_VAR(_7);
		ZVAL_STRING(_7, "", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_FUNCTION(&_8, "str_ireplace", NULL, 1, _6, _7, attribute);
		zephir_check_temp_parameter(_6);
		zephir_check_temp_parameter(_7);
		zephir_check_call_status();
		zephir_ucfirst(_5, _8);
		ZEPHIR_INIT_VAR(methodName);
		ZEPHIR_CONCAT_SV(methodName, "get", _5);
		if ((zephir_method_exists(this_ptr, methodName TSRMLS_CC)  == SUCCESS)) {
			ZEPHIR_OBS_VAR(_9);
			zephir_read_property(&_9, this_ptr, SL("methodName"), PH_NOISY_CC);
			RETURN_CCTOR(_9);
		} else {
			ZEPHIR_OBS_NVAR(_9);
			zephir_read_property(&_9, this_ptr, SL("attribute"), PH_NOISY_CC);
			RETURN_CCTOR(_9);
		}
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Método que se ejecuta antes de validar al crear un nuevo registro.
 *
 * Se almacena la fecha de creación.
 */
PHP_METHOD(Phady_Common_Entities_ModelBase, beforeValidationOnCreate) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *request = NULL, *_0 = NULL, *_1 = NULL, *_2, _3, *_4 = NULL, *_5 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getdi", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "request", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&request, _0, "get", NULL, 0, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_INIT_ZVAL_NREF(_2);
	ZVAL_LONG(_2, 1);
	zephir_update_property_this(this_ptr, SL("create_user"), _2 TSRMLS_CC);
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_STRING(&_3, "Y-m-d H:i:s", 0);
	ZEPHIR_CALL_FUNCTION(&_4, "date", NULL, 4, &_3);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("create_at"), _4 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_BOOL(_1, 1);
	ZEPHIR_CALL_METHOD(&_5, request, "getclientaddress", NULL, 0, _1);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("request_ip"), _5 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Method that executes before update a record. It stores the date of update
 */
PHP_METHOD(Phady_Common_Entities_ModelBase, beforeUpdate) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *request = NULL, *_0 = NULL, *_1 = NULL, *_2, _3, *_4 = NULL, *_5 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getdi", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "request", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&request, _0, "get", NULL, 0, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_INIT_ZVAL_NREF(_2);
	ZVAL_STRING(_2, "alien", 1);
	zephir_update_property_this(this_ptr, SL("modify_user"), _2 TSRMLS_CC);
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_STRING(&_3, "Y-m-d H:i:s", 0);
	ZEPHIR_CALL_FUNCTION(&_4, "date", NULL, 4, &_3);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("modify_at"), _4 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_BOOL(_1, 1);
	ZEPHIR_CALL_METHOD(&_5, request, "getclientaddress", NULL, 0, _1);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("request_ip"), _5 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

