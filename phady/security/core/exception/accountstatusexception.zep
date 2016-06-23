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

use Phady\Security\Core\Exception\AuthenticationException;
use Phady\Security\Core\User\UserInterface;

/**
  * @class Phady\Security\Core\Exception\AccountStatusException
  *
  * @author  Alien Fernández Fuentes <alienfernandez85@gmail.com>
  * @package Core
  * @copyright (c) 2015
  * @version 1.0.0
  */
abstract class AccountStatusException extends AuthenticationException
{
    private user;

    /**
     * Get the user.
     *
     * @return UserInterface
     */
    public function getUser()
    {
        return this->user;
    }

    /**
     * Set the user.
     *
     * @param UserInterface user
     */
    public function setUser(<UserInterface> user)
    {
        let this->user = user;
    }

    /**
     * {@inheritdoc}
     */
    public function serialize()
    {
        return serialize([
            this->user,
            parent::serialize()
        ]);
    }

    /**
     * {@inheritdoc}
     */
    public function unserialize(str)
    {
        //list(this->user, parentData) = unserialize(str);

        //parent::unserialize(parentData);
    }

}
