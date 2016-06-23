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

namespace Phady\Messaging;

use Phady\Messaging\Adapter\RabbitMQ;

/**
  * @class Phady\Messaging\Messaging - Messaging class for
  *
  * @author  Alien Fernández Fuentes <alienfernandez85@gmail.com>
  * @package Messaging
  * @copyright (c) 2015
  * @version 1.0.0
  */
class Messaging
{
    const RABBITMQ_MESSAGING = "rabbitmq";
    protected config;
    protected connection;

    /**
     * Get connection
     * @return MessagingAdapter Messaging Adapter
     */
    public function getConnection() {
        return this->connection;
    }

	/**
	 * @name getMessagingAdapter - get Messaging Adapter
	 * @return string
	 */
    public function getMessagingAdapter() {
        var configMessaging, adapter, key, messaging, rabbitmqServer;

        let configMessaging = this->config["messaging"];
        //print_r($arrConfigDb);die;
        let adapter = new \stdClass();
        for key, messaging in configMessaging {
            switch key {
                case self::RABBITMQ_MESSAGING :
                    let rabbitmqServer = new RabbitMQ(messaging);
                    let adapter->rabbitmq = rabbitmqServer;
                    break;
                default :
                    let rabbitmqServer = new RabbitMQ(messaging);
                    let adapter->rabbitmq = rabbitmqServer;
                    break;
            }
        }

        return adapter;
    }
}
