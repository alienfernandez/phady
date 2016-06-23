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

namespace Phady\Security\Core\Authentication\Token;

use Phady\Security\Core\Authentication\Token\AbstractToken;

/**
 * Phady\Security\Core\Authentication\Token\AnonymousToken
 *
 */
class AnonymousToken extends AbstractToken
{
    private key;

    /**
     * Constructor.
     *
     * @param string          key   The key shared with the authentication provider
     * @param string          user  The user
     * @param RoleInterface[] roles An array of roles
     */
    public function __construct(key, user, array roles = [])
    {
        parent::__construct(roles);

        let this->key = key;
        this->setUser(user);
        this->setAuthenticated(true);
    }

    /**
     * {@inheritdoc}
     */
    public function getCredentials()
    {
        return "";
    }

    /**
     * Returns the key.
     *
     * @return string The Key
     */
    public function getKey()
    {
        return this->key;
    }

    /**
     * {@inheritdoc}
     */
    public function serialize()
    {
        return serialize([this->key, parent::serialize()]);
    }

    /**
     * {@inheritdoc}
     */
    public function unserialize(serialized)
    {
        //list(this->key, parentStr) = unserialize(serialized);
        //parent::unserialize(parentStr);
    }
}