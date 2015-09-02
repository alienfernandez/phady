
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
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/memory.h"
#include "kernel/hash.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"


/**
  * @class Phady\Messaging\Messaging - Messaging class for
  *
  * @author  Alien Fernández Fuentes <alienfernandez85@gmail.com>
  * @package Messaging
  * @copyright (c) 2015
  * @version 1.0.0
  */
ZEPHIR_INIT_CLASS(Phady_Messaging_Messaging) {

	ZEPHIR_REGISTER_CLASS(Phady\\Messaging, Messaging, phady, messaging_messaging, phady_messaging_messaging_method_entry, 0);

	zend_declare_property_null(phady_messaging_messaging_ce, SL("config"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phady_messaging_messaging_ce, SL("connection"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_class_constant_string(phady_messaging_messaging_ce, SL("RABBITMQ_MESSAGING"), "rabbitmq" TSRMLS_CC);

	return SUCCESS;

}

/**
 * Get connection
 * @return MessagingAdapter Messaging Adapter
 */
PHP_METHOD(Phady_Messaging_Messaging, getConnection) {


	RETURN_MEMBER(this_ptr, "connection");

}

/**
 * @name getMessagingAdapter - get Messaging Adapter
 * @return string
 */
PHP_METHOD(Phady_Messaging_Messaging, getMessagingAdapter) {

	zephir_fcall_cache_entry *_4 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_2;
	HashPosition _1;
	zval *configMessaging, *adapter, *key = NULL, *messaging = NULL, *rabbitmqServer = NULL, *_0, **_3;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
	zephir_array_fetch_string(&configMessaging, _0, SL("messaging"), PH_NOISY | PH_READONLY, "phady/messaging/messaging.zep", 47 TSRMLS_CC);
	ZEPHIR_INIT_VAR(adapter);
	object_init(adapter);
	zephir_is_iterable(configMessaging, &_2, &_1, 0, 0, "phady/messaging/messaging.zep", 63);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HMKEY(key, _2, _1);
		ZEPHIR_GET_HVALUE(messaging, _3);
		do {
			if (ZEPHIR_IS_STRING(key, "rabbitmq")) {
				ZEPHIR_INIT_NVAR(rabbitmqServer);
				object_init_ex(rabbitmqServer, phady_messaging_adapter_rabbitmq_ce);
				ZEPHIR_CALL_METHOD(NULL, rabbitmqServer, "__construct", &_4, 48, messaging);
				zephir_check_call_status();
				zephir_update_property_zval(adapter, SL("rabbitmq"), rabbitmqServer TSRMLS_CC);
				break;
			}
			ZEPHIR_INIT_NVAR(rabbitmqServer);
			object_init_ex(rabbitmqServer, phady_messaging_adapter_rabbitmq_ce);
			ZEPHIR_CALL_METHOD(NULL, rabbitmqServer, "__construct", &_4, 48, messaging);
			zephir_check_call_status();
			zephir_update_property_zval(adapter, SL("rabbitmq"), rabbitmqServer TSRMLS_CC);
			break;
		} while(0);

	}
	RETURN_CCTOR(adapter);

}

