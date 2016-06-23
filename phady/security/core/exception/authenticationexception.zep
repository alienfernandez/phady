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

namespace Phady\Security\Core\Exception;

use Phady\Security\Core\Authentication\Token\TokenInterface;

/**
  * @class Phady\Security\Core\Exception\AuthenticationException
  *
  * @author  Alien Fernández Fuentes <alienfernandez85@gmail.com>
  * @package Core
  * @copyright (c) 2015
  * @version 1.0.0
  */
class AuthenticationException extends \RuntimeException implements \Serializable
{

    private token;

    /**
     * Get the token.
     *
     * @return TokenInterface
     */
    public function getToken()
    {
        return this->token;
    }
    /**
     * Set the token.
     *
     * @param TokenInterface token
     */
    public function setToken(<TokenInterface> token)
    {
        let this->token = token;
    }

    public function serialize()
    {
        return serialize([
            this->token,
            this->code,
            this->message,
            this->file,
            this->line
        ]);
    }
    public function unserialize(str)
    {
        /*list(
            this->token,
            this->code,
            this->message,
            this->file,
            this->line
        ) = unserialize(str);*/
    }

    /**
     * Message key to be used by the translation component.
     *
     * @return string
     */
    public function getMessageKey()
    {
        return "An authentication exception occurred.";
    }
    /**
     * Message data to be used by the translation component.
     *
     * @return array
     */
    public function getMessageData()
    {
        return [];
    }
}
