/*
+------------------------------------------------------------------------+
| Phady Framework                                                        |
+------------------------------------------------------------------------+
| Copyright (c) 2015                                                     |
+------------------------------------------------------------------------+
| Phady Framework is a complement of Phalcon Framework                   |
|                                                                        |
+------------------------------------------------------------------------+
| Authors: Alien fernandez Fuentes <alienfernandez85@gmail.com>          |
+------------------------------------------------------------------------+
*/

namespace Phady\Messaging\Adapter;

/**
  * @interface Phady\Messaging\Adapter\MessagingInterface - Messaging interface for all messaging adapter
  *
  * @author  Alien Fernández Fuentes <alienfernandez85@gmail.com>
  * @package Messaging
  * @copyright (c) 2015
  * @version 1.0.0
  */
interface MessagingInterface
{

    /**
     * @return MessagingAdapter Messaging Adapter
     */
	public function getAdapter();

    /**
     * Send message to messaging system
     *
	 * @param string queue - Queue name
	 * @param string exchange - Exchange type
	 * @param string msg - Message
	 * @param string msgOptions - Message options
     * @return void
     */
    public function sendMessageDirect(queue, exchange, msg, msgOptions);

    /**
     *
     * @return Message Message Data
     */
    public function getMessage(datam, options);

}
