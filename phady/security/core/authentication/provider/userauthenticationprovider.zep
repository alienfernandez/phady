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
use Phady\Security\Core\User\UserCheckerInterface;
use Phady\Security\Core\Authentication\Token\TokenInterface;
use Phady\Security\Core\Exception\UsernameNotFoundException;
use Phady\Security\Core\Exception\BadCredentialsException;
use Phady\Security\Core\Role\SwitchUserRole;
use Phady\Security\Core\Authentication\Token\UsernamePasswordToken;
use Phady\Security\Core\User\UserInterface;

/**
 * Phady\Security\Core\Authentication\Provider\UserAuthenticationProvider
 *
 */
abstract class UserAuthenticationProvider implements AuthenticationProviderInterface
{

    private hideUserNotFoundExceptions;
    private userChecker;
    private providerKey;

    /**
     * Constructor.
     *
     * @param UserCheckerInterface userChecker                An UserCheckerInterface interface
     * @param string               providerKey                A provider key
     * @param bool                 hideUserNotFoundExceptions Whether to hide user not found exception or not
     *
     * @throws \InvalidArgumentException
     */
    public function __construct(<UserCheckerInterface> userChecker, providerKey, boolean hideUserNotFoundExceptions = true)
    {
        if (empty(providerKey)) {
            throw new \InvalidArgumentException("providerKey must not be empty.");
        }
        let this->userChecker = userChecker;
        let this->providerKey = providerKey;
        let this->hideUserNotFoundExceptions = hideUserNotFoundExceptions;
    }

    /**
     * {@inheritdoc}
     */
    public function authenticate(<TokenInterface> token)
    {
        var e, user, username, authenticatedToken;
        if (!this->supports(token)) {
            return;
        }
        let username = token->getUsername();
        if ("" === username || null === username) {
            let username = "NONE_PROVIDED";
        }

        try {
            let user = this->retrieveUser(username, token);
        } catch UsernameNotFoundException, e {
            if (this->hideUserNotFoundExceptions) {
                throw new BadCredentialsException("Bad credentials.", 0, e);
            }
            e->setUsername(username);
            throw e;
        }
        if (!(user instanceof UserInterface)) {
            throw new \Phady\Security\Exception("retrieveUser() must return a UserInterface.");
        }

        try {

            this->userChecker->checkPreAuth(user);
            this->checkAuthentication(user, token);
            this->userChecker->checkPostAuth(user);
        } catch BadCredentialsException, e {
            if (this->hideUserNotFoundExceptions) {
                throw new BadCredentialsException("Bad credentials.", 0, e);
            }
            throw e;
        }
        let authenticatedToken = new UsernamePasswordToken(user, token->getCredentials(), this->providerKey, this->getRoles(user, token));
        authenticatedToken->setAttributes(token->getAttributes());
        return authenticatedToken;
    }

    /**
     * {@inheritdoc}
     */
    public function supports(<TokenInterface> token)
    {
        return token instanceof UsernamePasswordToken && this->providerKey === token->getProviderKey();
    }

    /**
     * Retrieves roles from user and appends SwitchUserRole if original token contained one.
     *
     * @param UserInterface  user  The user
     * @param TokenInterface token The token
     *
     * @return array The user roles
     */
    public function getRoles(<UserInterface> user, <TokenInterface> token)
    {
        var role, roles;
        let roles = user->getRoles();
        for role in token->getRoles() {
            if (role instanceof SwitchUserRole) {
                let roles[] = role;
                break;
            }
        }
        return roles;
    }

    /**
     * Retrieves the user from an implementation-specific location.
     *
     * @param string                username The username to retrieve
     * @param UsernamePasswordToken token    The Token
     *
     * @return UserInterface The user
     *
     * @throws AuthenticationException if the credentials could not be validated
     */
    abstract protected function retrieveUser(username, <UsernamePasswordToken> token);
    /**
     * Does additional checks on the user and token (like validating the
     * credentials).
     *
     * @param UserInterface         user  The retrieved UserInterface instance
     * @param UsernamePasswordToken token The UsernamePasswordToken token to be authenticated
     *
     * @throws AuthenticationException if the credentials could not be validated
     */
    abstract protected function checkAuthentication(<UserInterface> user, <UsernamePasswordToken> token);
}