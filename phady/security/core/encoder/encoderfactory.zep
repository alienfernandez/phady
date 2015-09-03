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

namespace Phady\Security\Core\Encoder;

use Phady\Security\Core\Encoder\EncoderFactoryInterface;
use Phady\Security\Core\Encoder\EncoderAwareInterface;

/**
  * @class Phady\Security\Core\Encoder\EncoderFactory
  *
  * @author  Alien Fernández Fuentes <alienfernandez85@gmail.com>
  * @package Core
  * @copyright (c) 2015
  * @version 1.0.0
  */
class EncoderFactory implements EncoderFactoryInterface
{
    private encoders;

    public function __construct(array encoders)
    {
        let this->encoders = encoders;
    }

    /**
     * {@inheritdoc}
     */
    public function getEncoder(user)
    {
        var encoderKey, encoderName, classEncoder, encoder;
        let encoderKey = null;
        let encoderName = user->getEncoderName();
        if (user instanceof EncoderAwareInterface && (null !== encoderName)) {
            if (!array_key_exists(encoderName, this->encoders)) {
                throw new \RuntimeException(sprintf("The encoder %s was not configured.", encoderName));
            }

            let encoderKey = encoderName;
        } else {
            for classEncoder, encoder in this->encoders {
                if ((is_object(user) && user instanceof classEncoder) || (!is_object(user) && (is_subclass_of(user, classEncoder) || user == classEncoder))) {
                    let encoderKey = classEncoder;
                    break;
                }
            }
        }

        if (null === encoderKey) {
            throw new \RuntimeException(sprintf("No encoder has been configured for account %s.", is_object(user) ? get_class(user) : user));
        }

        if (!(this->encoders[encoderKey] instanceof PasswordEncoderInterface)) {
            let this->encoders[encoderKey] = this->createEncoder(this->encoders[encoderKey]);
        }

        return this->encoders[encoderKey];
    }

    /**
     * Creates the actual encoder instance.
     *
     * @param array config
     *
     * @return PasswordEncoderInterface
     *
     * @throws \InvalidArgumentException
     */
    private function createEncoder(array config)
    {
        var reflection;
        if (!isset(config["class"])) {
            throw new \InvalidArgumentException(sprintf("class must be set in %s.", json_encode(config)));
        }
        if (!isset(config["arguments"])) {
            throw new \InvalidArgumentException(sprintf("arguments must be set in %s.", json_encode(config)));
        }

        let reflection = new \ReflectionClass(config["class"]);

        return reflection->newInstanceArgs(config["arguments"]);
    }
}
