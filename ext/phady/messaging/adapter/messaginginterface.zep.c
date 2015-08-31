
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
  * @interface Phady\Messaging\Adapter\MessagingInterface - Messaging interface for all messaging adapter
  *
  * @author  Alien Fernández Fuentes <alienfernandez85@gmail.com>
  * @package Messaging
  * @copyright (c) 2015
  * @version 1.0.0
  */
ZEPHIR_INIT_CLASS(Phady_Messaging_Adapter_MessagingInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phady\\Messaging\\Adapter, MessagingInterface, phady, messaging_adapter_messaginginterface, phady_messaging_adapter_messaginginterface_method_entry);

	return SUCCESS;

}

/**
 * @return MessagingAdapter Messaging Adapter
 */
ZEPHIR_DOC_METHOD(Phady_Messaging_Adapter_MessagingInterface, getAdapter);

/**
 * Send message to messaging system
 *
 * @param string queue - Queue name
 * @param string exchange - Exchange type
 * @param string msg - Message
 * @param string msgOptions - Message options
 * @return void
 */
ZEPHIR_DOC_METHOD(Phady_Messaging_Adapter_MessagingInterface, sendMessageDirect);

/**
 *
 * @return Message Message Data
 */
ZEPHIR_DOC_METHOD(Phady_Messaging_Adapter_MessagingInterface, getMessage);

