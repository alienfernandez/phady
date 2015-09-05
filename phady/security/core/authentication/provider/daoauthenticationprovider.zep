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

use Phady\Security\Core\Authentication\Provider\UserAuthenticationProvider;
use Phady\Security\Core\Authentication\AuthenticationManagerInterface;
use Phady\Security\Core\Authentication\Token\TokenInterface;
use Phady\Security\Core\User\UserProviderInterface;
use Phady\Security\Core\User\UserCheckerInterface;
use Phady\Security\Core\Encoder\EncoderFactoryInterface;
use Phady\Security\Core\User\UserInterface;
use Phady\Security\Core\Authentication\Token\UsernamePasswordToken;
use Phady\Security\Core\Exception\BadCredentialsException;
use Phady\Security\Core\Exception\AuthenticationServiceException;

/**
 * Phady\Security\Core\Authentication\Provider\DaoAuthenticationProvider
 *
 */
class DaoAuthenticationProvider extends UserAuthenticationProvider
{

    private encoderFactory;
    private userProvider;

    /**
     * Constructor.
     *
     * @param UserProviderInterface   userProvider               An UserProviderInterface instance
     * @param UserCheckerInterface    userChecker                An UserCheckerInterface instance
     * @param string                  providerKey                The provider key
     * @param EncoderFactoryInterface encoderFactory             An EncoderFactoryInterface instance
     * @param bool                    hideUserNotFoundExceptions Whether to hide user not found exception or not
     */
    public function __construct(<UserProviderInterface> userProvider, <UserCheckerInterface> userChecker,
                        providerKey, <EncoderFactoryInterface> encoderFactory, boolean hideUserNotFoundExceptions = true)
    {
        parent::__construct(userChecker, providerKey, hideUserNotFoundExceptions);

        let this->encoderFactory = encoderFactory;
        let this->userProvider = userProvider;
    }

    /**
     * {@inheritdoc}
     */
    protected function checkAuthentication(<UserInterface> user, <UsernamePasswordToken> token)
    {
        var currentUser, presentedPassword;
        let currentUser = token->getUser();
        if (currentUser instanceof UserInterface) {
            if (currentUser->getPassword() !== user->getPassword()) {
                throw new BadCredentialsException("The credentials were changed from another session.");
            }
        } else {

            let presentedPassword = token->getCredentials();
            if ("" === presentedPassword) {
                throw new BadCredentialsException("The presented password cannot be empty.");
            }

            if (!this->encoderFactory->getEncoder(user)->isPasswordValid(user->getPassword(), presentedPassword, user->getSalt())) {
                throw new BadCredentialsException("The presented password is invalid.");
            }
        }
    }

    /**
     * {@inheritdoc}
     */
    protected function retrieveUser(username, <UsernamePasswordToken> token)
    {

        var user, e, ex;
        let user = token->getUser();
        if (user instanceof UserInterface) {
            return user;
        }

        try {
            let user = this->userProvider->loadUserByUsername(username);


            if (user instanceof UserInterface) {
                return user;
            }else {
                throw new AuthenticationServiceException("The user provider must return a UserInterface object.");
            }

        } catch UsernameNotFoundException, e {
            e->setUsername(username);
            throw e;
        } catch \Exception, ex {
            let ex = new AuthenticationServiceException(ex->getMessage(), 0, ex);
            ex->setToken(token);
            throw ex;
        }
    }
}