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

namespace Phady\Security;

use Phalcon\Events\Event;
use Phalcon\Di\Injectable;
use Phady\Security\Core\User\Factory\UserProviderFactoryInterface;
use Phady\Security\Core\User\Factory\InMemoryFactory;
use Phady\Security\Core\User\Factory\EntityFactory;

/**
  * @class Phady\Security\SecurityExtension
  *
  * @author  Alien Fernández Fuentes <alienfernandez85@gmail.com>
  * @package Core
  * @copyright (c) 2015
  * @version 1.0.0
  */
class PhadyUserExtension extends \Phalcon\Di\Injectable
{
    private container;

    public function __construct()
    {
        let this->container = this->getDI();
        //this->loadPhadyUserConfig(["security"]);
    }

    public function loadPhadyUserConfig(array config)
    {
        if (array_key_exists("phady_user", config) && config["phady_user"]) {
            this->addConfig(config["phady_user"]);
        }
    }

    private function addConfig(configPhadyUser)
    {
        switch (configPhadyUser["db_driver"]) {
            case "orm":
                /*this->container->set("phady_user.user_provider.username", function () {
                    print_r(encoderMap);
                    return new \Phady\Security\Core\Encoder\EncoderFactory(encoderMap);
                 });*/
                break;

            case "mongodb":
                //container->getDefinition("fos_user.user_listener")->addTag("doctrine_mongodb.odm.event_subscriber");
                break;

            default:
                break;
        }

    }

}
