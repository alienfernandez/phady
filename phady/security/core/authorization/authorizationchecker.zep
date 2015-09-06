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

namespace Phady\Security\Core\Authorization;

use Phady\Security\Core\Authorization\AuthorizationCheckerInterface;
use Phady\Security\Core\Authentication\Token\TokenInterface;
use Phady\Security\Core\Authentication\Token\Storage\TokenStorageInterface;
use Phady\Security\Core\Authentication\AuthenticationManagerInterface;
use Phady\Security\Core\Authorization\AccessDecisionManagerInterface;
use Phady\Security\Core\Exception\AuthenticationCredentialsNotFoundException;

/**
  * @class Phady\Security\Core\Authorization\AuthorizationChecker
  *
  * @author  Alien Fernández Fuentes <alienfernandez85@gmail.com>
  * @package Core
  * @copyright (c) 2015
  * @version 1.0.0
  */
class AuthorizationChecker implements AuthorizationCheckerInterface
{
    private tokenStorage;
    private accessDecisionManager;
    private authenticationManager;
    private alwaysAuthenticate;

    /**
     * Constructor.
     *
     * @param TokenStorageInterface          tokenStorage
     * @param AuthenticationManagerInterface authenticationManager An AuthenticationManager instance
     * @param AccessDecisionManagerInterface accessDecisionManager An AccessDecisionManager instance
     * @param bool                           alwaysAuthenticate
     */
    public function __construct(<TokenStorageInterface> tokenStorage, <AuthenticationManagerInterface> authenticationManager,
                                <AccessDecisionManagerInterface> accessDecisionManager, alwaysAuthenticate = false)
    {
        let this->tokenStorage = tokenStorage;
        let this->authenticationManager = authenticationManager;
        let this->accessDecisionManager = accessDecisionManager;
        let this->alwaysAuthenticate = alwaysAuthenticate;
    }

    /**
     * {@inheritdoc}
     *
     * @throws AuthenticationCredentialsNotFoundException when the token storage has no authentication token.
     */
    final public function isGranted(attributes, objectSecure = null)
    {
        var token;
        let token = this->tokenStorage->getToken();
        if (null === token) {
            throw new AuthenticationCredentialsNotFoundException("The token storage contains no authentication token. One possible reason may be that there is no firewall configured for this URL.");
        }

        if (this->alwaysAuthenticate || !token->isAuthenticated()) {
            let token = this->authenticationManager->authenticate(token);
            this->tokenStorage->setToken(token);
        }

        if (!is_array(attributes)) {
            let attributes = [attributes];
        }

        return this->accessDecisionManager->decide(token, attributes, objectSecure);
    }
}
