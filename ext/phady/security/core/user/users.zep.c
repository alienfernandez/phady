
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
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/operators.h"
#include "ext/phalcon/phalcon/mvc/user/component.zep.h"


/**
  * @class Phady\Security\Core\User\Users -  Core users for app
  *
  * @author  Alien Fernández Fuentes <alienfernandez85@gmail.com>
  * @package Core
  * @copyright (c) 2015
  * @version 1.0.0
  */
ZEPHIR_INIT_CLASS(Phady_Security_Core_User_Users) {

	ZEPHIR_REGISTER_CLASS_EX(Phady\\Security\\Core\\User, Users, phady, security_core_user_users, phalcon_mvc_user_component_ce, phady_security_core_user_users_method_entry, 0);

	return SUCCESS;

}

/**
 * @name getUsers - Get user data
 * @param array arrData - Data to filters
 * @param boolean getTotal - Get the total with the filter applied
 * @return array
 */
PHP_METHOD(Phady_Security_Core_User_Users, getUsers) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool getTotal;
	zval *arrDataFilter_param = NULL, *getTotal_param = NULL, *arrData, *userRepository, *arrUsers = NULL, *arrTotalUsers = NULL;
	zval *arrDataFilter = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &arrDataFilter_param, &getTotal_param);

	zephir_get_arrval(arrDataFilter, arrDataFilter_param);
	if (!getTotal_param) {
		getTotal = 0;
	} else {
		getTotal = zephir_get_boolval(getTotal_param);
	}


	ZEPHIR_INIT_VAR(userRepository);
	object_init_ex(userRepository, phady_security_core_models_repositories_users_ce);
	if (zephir_has_constructor(userRepository TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, userRepository, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&arrUsers, userRepository, "getusers", NULL, 70, arrDataFilter);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(arrData);
	zephir_create_array(arrData, 1, 0 TSRMLS_CC);
	zephir_array_update_string(&arrData, SL("data"), &arrUsers, PH_COPY | PH_SEPARATE);
	if (getTotal) {
		ZEPHIR_CALL_METHOD(&arrTotalUsers, userRepository, "gettotalusers", NULL, 71, arrData);
		zephir_check_call_status();
		zephir_array_update_string(&arrData, SL("total"), &arrTotalUsers, PH_COPY | PH_SEPARATE);
	}
	RETURN_CCTOR(arrData);

}

