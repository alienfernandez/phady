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

use Phady\Security\Core\User\UserProviderInterface;
use Phady\Security\Core\Authentication\SimpleAuthenticatorInterface;
use Phady\Security\Core\Authentication\Provider\AuthenticationProviderInterface;
use Phady\Security\Core\Authentication\Token\TokenInterface;
use Phady\Security\Core\Exception\AuthenticationException;

/**
 * Phady\Security\Core\Authentication\Provider\SimpleAuthenticationProvider
 *
 */
class SimpleAuthenticationProvider implements AuthenticationProviderInterface
{

    private simpleAuthenticator;
    private userProvider;
    private providerKey;

    public function __construct(<SimpleAuthenticatorInterface> simpleAuthenticator, <UserProviderInterface> userProvider, providerKey)
    {
        let this->simpleAuthenticator = simpleAuthenticator;
        let this->userProvider = userProvider;
        let this->providerKey = providerKey;
    }

    public function authenticate(<TokenInterface> token)
    {
        var authToken;
        let authToken = this->simpleAuthenticator->authenticateToken(token, this->userProvider, this->providerKey);

        if (authToken instanceof TokenInterface) {
            return authToken;
        }

        throw new AuthenticationException("Simple authenticator failed to return an authenticated token.");
    }

    public function supports(<TokenInterface> token)
    {
        return this->simpleAuthenticator->supportsToken(token, this->providerKey);
    }
}