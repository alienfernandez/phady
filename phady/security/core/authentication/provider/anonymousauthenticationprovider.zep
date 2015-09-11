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

namespace Phady\Security\Core\Authentication\Provider;

use Phady\Security\Core\Authentication\Provider\AuthenticationProviderInterface;
use Phady\Security\Core\Exception\BadCredentialsException;
use Phady\Security\Core\Authentication\Token\TokenInterface;
use Phady\Security\Core\Authentication\Token\AnonymousToken;

/**
 * Phady\Security\Core\Authentication\Provider\AnonymousAuthenticationProvider
 *
 */
class AnonymousAuthenticationProvider implements AuthenticationProviderInterface
{
    private key;

    /**
     * Constructor.
     *
     * @param string key The key shared with the authentication token
     */
    public function __construct(key)
    {
        let this->key = key;
    }

    /**
     * {@inheritdoc}
     */
    public function authenticate(<TokenInterface> token)
    {
        if (!this->supports(token)) {
            return;
        }

        if (this->key !== token->getKey()) {
            throw new BadCredentialsException("The Token does not contain the expected key.");
        }

        return token;
    }

    /**
     * {@inheritdoc}
     */
    public function supports(<TokenInterface> token)
    {
        return token instanceof AnonymousToken;
    }
}