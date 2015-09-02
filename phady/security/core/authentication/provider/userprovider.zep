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
use Phady\Security\Core\Exception\UsernameNotFoundException;
use Phady\Security\Core\Authentication\Model\User;
use Phady\Security\Core\Authentication\Model\UserManagerInterface;
use Phady\Security\Core\User\UserInterface as SecurityUserInterface;
use Phady\Security\Core\Exception\UnsupportedUserException;


/**
 * Phady\Security\Core\Authentication\Provider\UserProvider
 *
 */
class UserProvider implements UserProviderInterface
{

    /**
     * @var UserManagerInterface
     */
    protected userManager;


    /**
     * Constructor.
     *
     * @param UserManagerInterface userManager
     */
    public function __construct(<UserManagerInterface> userManager)
    {
        let this->userManager = userManager;
    }
    /**
     * {@inheritDoc}
     */
    public function loadUserByUsername(string username)
    {
        var user;
        let user = this->findUser(username);
        if (!user) {
            throw new UsernameNotFoundException(sprintf("Username %s does not exist.", username));
        }
        return user;
    }

    /**
     * {@inheritDoc}
     */
    public function refreshUser(<SecurityUserInterface> user)
    {
        var reloadedUser;
        if (!(user instanceof User)) {
            throw new UnsupportedUserException(sprintf("Expected an instance of , but got %s.", get_class(user)));
        }
        if (!this->supportsClass(get_class(user))) {
            throw new UnsupportedUserException(sprintf("Expected an instance of %s, but got %s.", this->userManager->getClass(), get_class(user)));
        }
        let reloadedUser = this->userManager->findUserBy(["id" : user->getId()]);
        if (null === reloadedUser) {
            throw new UsernameNotFoundException(sprintf("User with ID %d could not be reloaded.", user->getId()));
        }
        return reloadedUser;
    }

    /**
     * {@inheritDoc}
     */
    public function supportsClass(suportClass)
    {
        var userClass;
        let userClass = this->userManager->getClass();
        return userClass === suportClass || is_subclass_of(suportClass, userClass);
    }

    /**
     * Finds a user by username.
     *
     * This method is meant to be an extension point for child classes.
     *
     * @param string username
     *
     * @return UserInterface|null
     */
    protected function findUser(username)
    {
        return this->userManager->findUserByUsername(username);
    }
}