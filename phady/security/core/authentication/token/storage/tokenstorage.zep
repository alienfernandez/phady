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

namespace Phady\Security\Core\Authentication\Token\Storage;

use Phady\Security\Core\Authentication\Token\Storage\TokenStorageInterface;
use Phady\Security\Core\Authentication\Token\TokenInterface;

/**
 * Phady\Security\Core\Authentication\Token\Storage\AbstractToken
 *
 * Interface
 */
class TokenStorage implements TokenStorageInterface
{

    private token;

    /**
     * {@inheritdoc}
     */
    public function getToken()
    {
        return this->token;
    }

    /**
     * {@inheritdoc}
     */
    public function setToken(<TokenInterface> token = null)
    {
        let this->token = token;
    }
}