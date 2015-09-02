
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
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"


/**
  * @class Phady\Messaging\Adapter\RabbitMQ - Messaging class for adapter rabbitmq
  *
  * @author  Alien Fernández Fuentes <alienfernandez85@gmail.com>
  * @package Messaging
  * @copyright (c) 2015
  * @version 1.0.0
  */
ZEPHIR_INIT_CLASS(Phady_Messaging_Adapter_RabbitMQ) {

	ZEPHIR_REGISTER_CLASS(Phady\\Messaging\\Adapter, RabbitMQ, phady, messaging_adapter_rabbitmq, phady_messaging_adapter_rabbitmq_method_entry, 0);

	zend_declare_property_null(phady_messaging_adapter_rabbitmq_ce, SL("config"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phady_messaging_adapter_rabbitmq_ce, SL("connection"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_class_constant_string(phady_messaging_adapter_rabbitmq_ce, SL("RABBITMQ_MESSAGING"), "rabbitmq" TSRMLS_CC);

	zend_class_implements(phady_messaging_adapter_rabbitmq_ce TSRMLS_CC, 1, phady_messaging_adapter_messaginginterface_ce);
	return SUCCESS;

}

PHP_METHOD(Phady_Messaging_Adapter_RabbitMQ, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *config_param = NULL, *_0 = NULL;
	zval *config = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &config_param);

	config = config_param;



	zephir_update_property_this(this_ptr, SL("config"), config TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getadapter", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("connection"), _0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Get connection
 * @return MessagingAdapter Messaging Adapter
 */
PHP_METHOD(Phady_Messaging_Adapter_RabbitMQ, getConnection) {


	RETURN_MEMBER(this_ptr, "connection");

}

/**
 * @name getMessagingAdapter - get Messaging Adapter
 * @return AMQPConnection
 */
PHP_METHOD(Phady_Messaging_Adapter_RabbitMQ, getAdapter) {


	RETURN_BOOL(1);

}

/**
 * Send message to messaging system
 *
 * @param string queue - Queue name
 * @param string exchange - Exchange type
 * @param string msg - Message
 * @param string msgOptions - Message options
 * @return void
 */
PHP_METHOD(Phady_Messaging_Adapter_RabbitMQ, sendMessageDirect) {

	zval *queue_param = NULL, *exchange_param = NULL, *msg, *msgOptions;
	zval *queue = NULL, *exchange = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &queue_param, &exchange_param, &msg, &msgOptions);

	if (unlikely(Z_TYPE_P(queue_param) != IS_STRING && Z_TYPE_P(queue_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'queue' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(queue_param) == IS_STRING)) {
		zephir_get_strval(queue, queue_param);
	} else {
		ZEPHIR_INIT_VAR(queue);
		ZVAL_EMPTY_STRING(queue);
	}
	if (unlikely(Z_TYPE_P(exchange_param) != IS_STRING && Z_TYPE_P(exchange_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'exchange' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(exchange_param) == IS_STRING)) {
		zephir_get_strval(exchange, exchange_param);
	} else {
		ZEPHIR_INIT_VAR(exchange);
		ZVAL_EMPTY_STRING(exchange);
	}



}

/**
 * @name getMessage - Get data message
 *
 * @param string data - Data Message
 * @param var options - Options
 * @return AMQPMessage
 */
PHP_METHOD(Phady_Messaging_Adapter_RabbitMQ, getMessage) {

	zval *data, *options;

	zephir_fetch_params(0, 2, 0, &data, &options);




}

