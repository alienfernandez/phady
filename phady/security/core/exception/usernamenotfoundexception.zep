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

use Phalcon\Exception;

/**
  * @class Phady\Security\Core\Exception\UsernameNotFoundException
  *
  * @author  Alien Fernández Fuentes <alienfernandez85@gmail.com>
  * @package Core
  * @copyright (c) 2015
  * @version 1.0.0
  */
class UsernameNotFoundException extends \Exception
{

    private username;

    /**
     * Rewrite the error message
     * @return string
     */
    public function __toString() {
        return sprintf("[Phady Security Error] %s", this->getMessage());
    }
    
    /**
     * {@inheritdoc}
     */
    public function getMessageKey()
    {
        return "Username could not be found.";
    }
    /**
     * Get the username.
     *
     * @return string
     */
    public function getUsername()
    {
        return this->username;
    }
    /**
     * Set the username.
     *
     * @param string username
     */
    public function setUsername(string username)
    {
        let this->username = username;
    }

    /**
     * {@inheritdoc}
     */
    public function getMessageData()
    {
        return ["{{ username }}" : this->username];
    }

}
