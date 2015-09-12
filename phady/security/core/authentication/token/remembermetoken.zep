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
use Phady\Security\Core\User\UserInterface;

/**
 * Phady\Security\Core\Authentication\Token\RememberMeToken
 *
 */
class RememberMeToken extends AbstractToken
{
    private key;
    private providerKey;

    /**
     * Constructor.
     *
     * @param UserInterface user
     * @param string        providerKey
     * @param string        key
     *
     * @throws \InvalidArgumentException
     */
    public function __construct(<UserInterface> user, providerKey, key)
    {
        parent::__construct(user->getRoles());

        if (empty(key)) {
            throw new \InvalidArgumentException("key must not be empty.");
        }

        if (empty(providerKey)) {
            throw new \InvalidArgumentException("providerKey must not be empty.");
        }

        let this->providerKey = providerKey;
        let this->key = key;

        this->setUser(user);
        parent::setAuthenticated(true);
    }

    /**
     * {@inheritdoc}
     */
    public function setAuthenticated(authenticated)
    {
        if (authenticated) {
            throw new \LogicException("You cannot set this token to authenticated after creation.");
        }

        parent::setAuthenticated(false);
    }

    /**
     * Returns the provider key.
     *
     * @return string The provider key
     */
    public function getProviderKey()
    {
        return this->providerKey;
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
    public function getCredentials()
    {
        return "";
    }

    /**
     * {@inheritdoc}
     */
    public function serialize()
    {
        return serialize([
            this->key,
            this->providerKey,
            parent::serialize()
        ]);
    }

    /**
     * {@inheritdoc}
     */
    public function unserialize(serialized)
    {
        var unserializeData, parentStr;
        let unserializeData = unserialize(serialized);
        let this->key = unserializeData[0];
        let this->providerKey = unserializeData[1];
        let parentStr = unserializeData[2];
        //list(this->key, this->providerKey, parentStr)
        parent::unserialize(parentStr);
    }
}