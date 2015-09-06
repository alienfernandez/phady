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
use Phady\Security\Core\User\UserInterface;
use Phady\Security\Core\Exception\UnsupportedUserException;


/**
 * Phady\Security\Core\Authentication\Provider\EntityUserProvider
 *
 */
class EntityUserProvider implements UserProviderInterface
{

    private classUser;
    private property;
    private metadata;

    public function __construct(classUser, property = null, managerName = null)
    {
        //print_r(classUser);
        //die("eup");
        var entity;
        //let entity = new {classUser}();
        let entity = new {classUser}();
        let this->classUser = entity;
        let this->property = property;
    }

    /**
     * {@inheritdoc}
     */
    public function loadUserByUsername(username)
    {
        var user;
        if (null !== this->property) {
            let user = this->classUser->findFirst([this->property : username]);

        } else {
            if (!(this->classUser instanceof UserProviderInterface)) {
                throw new \InvalidArgumentException(sprintf("The User Class %s must implement UserProviderInterface.", get_class(this->classUser)));
            }

            //user = this->repository->loadUserByUsername(username);
        }

        if (null === user) {
            throw new UsernameNotFoundException(sprintf("User %s not found.", username));
        }

        return user;
    }

    /**
     * {@inheritdoc}
     */
    public function refreshUser(<UserInterface> user)
    {
        var refreshedUser;
        if (user instanceof this->classUser) {

        }else {
            throw new UnsupportedUserException(sprintf("Instances of %s are not supported.", get_class(user)));
        }

        /*if (this->classUser instanceof UserProviderInterface) {
            let refreshedUser = this->repository->refreshUser(user);
        }
         else {
            // The user must be reloaded via the primary key as all other data
            // might have changed without proper persistence in the database.
            // That"s the case when the user has been changed by a form with
            // validation errors.
            if (!id = this->metadata->getIdentifierValues(user)) {
                throw new \InvalidArgumentException("You cannot refresh a user ".
                    "from the EntityUserProvider that does not contain an identifier. ".
                    "The user object has to be serialized with its own identifier ".
                    "mapped by Doctrine."
                );
            }

            refreshedUser = this->repository->find(id);
            if (null === refreshedUser) {
                throw new UsernameNotFoundException(sprintf("User with id %s not found", json_encode(id)));
            }
        }
        */

        //return refreshedUser;
        return true;
    }

    /**
     * {@inheritdoc}
     */
    public function supportsClass(classUser)
    {
        return classUser === this->classUser || is_subclass_of(classUser, this->classUser);
    }
}