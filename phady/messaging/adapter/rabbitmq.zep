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

use Phady\Messaging\Adapter\MessagingInterface;

/**
  * @class Phady\Messaging\Adapter\RabbitMQ - Messaging class for adapter rabbitmq
  *
  * @author  Alien Fernández Fuentes <alienfernandez85@gmail.com>
  * @package Messaging
  * @copyright (c) 2015
  * @version 1.0.0
  */
class RabbitMQ implements MessagingInterface
{
    const RABBITMQ_MESSAGING = "rabbitmq";
    protected config;
    protected connection;

	public function __construct(array! config)
	{
		//Read the configuration file
        let this->config = config;
        let this->connection = this->getAdapter();
	}

    /**
     * Get connection
     * @return MessagingAdapter Messaging Adapter
     */
    public function getConnection() {
        return this->connection;
    }

	/**
	 * @name getMessagingAdapter - get Messaging Adapter
	 * @return AMQPConnection
	 */
    public function getAdapter() {
        /*var connection;
        let connection = new AMQPConnection(this->config["server"], this->config["port"], this->config["username"], this->config["password"]);
        return connection;*/
        return true;
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
    public function sendMessageDirect(string! queue, string! exchange, var msg, var msgOptions) {
        /*var channel, msg;
        let channel = this->connection->channel();*/
        /*
          name: queue
          passive: false
          durable: true // the queue will survive server restarts
          exclusive: false // the queue can be accessed in other channels
          auto_delete: false //the queue won't be deleted once the channel is closed.
         */
        //channel->queue_declare(queue, false, true, false, false);

        /*
          name: exchange
          type: direct
          passive: false
          durable: true // the exchange will survive server restarts
          auto_delete: false //the exchange won't be deleted once the channel is closed.
         */
        //channel->exchange_declare(exchange, 'direct', false, true, false);

        /*
        channel->queue_bind(queue, exchange);
        let msg = new \PhpAmqpLib\Message\AMQPMessage(msg, msgOptions);
        channel->basic_publish(msg, exchange);
        channel->close();
        this->connection->close();*/
    }

    /**
     * @name getMessage - Get data message
     *
     * @param string data - Data Message
     * @param var options - Options
     * @return AMQPMessage
     */
    public function getMessage(var data, var options) {
        /*
        var msg;
        let msg = new AMQPMessage($data, $options);
        return msg;*/
    }
}
