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

namespace Phady\Security\Core\Authentication\Model;

use Phady\Security\Core\Authentication\Model\UserInterface;
/**
 * Phady\Security\Core\Authentication\Model\UserManagerInterface
 *
 * Interface
 */
interface UserManagerInterface
{

    /**
     * Creates an empty user instance.
     *
     * @return UserInterface
     */
    public function createUser();

    /**
     * Deletes a user.
     *
     * @param UserInterface user
     *
     * @return void
     */
    public function deleteUser(<UserInterface> user);

    /**
     * Finds one user by the given criteria.
     *
     * @param array criteria
     *
     * @return UserInterface
     */
    public function findUserBy(array criteria);

    /**
     * Find a user by its username.
     *
     * @param string username
     *
     * @return UserInterface or null if user does not exist
     */
    public function findUserByUsername(username);

    /**
     * Finds a user by its email.
     *
     * @param string email
     *
     * @return UserInterface or null if user does not exist
     */
    public function findUserByEmail(email);

    /**
     * Finds a user by its username or email.
     *
     * @param string usernameOrEmail
     *
     * @return UserInterface or null if user does not exist
     */
    public function findUserByUsernameOrEmail(usernameOrEmail);

    /**
     * Finds a user by its confirmationToken.
     *
     * @param string token
     *
     * @return UserInterface or null if user does not exist
     */
    public function findUserByConfirmationToken(token);

    /**
     * Returns a collection with all user instances.
     *
     * @return \Traversable
     */
    public function findUsers();

    /**
     * Returns the user's fully qualified class name.
     *
     * @return string
     */
    public function getClass();

    /**
     * Reloads a user.
     *
     * @param UserInterface user
     *
     * @return void
     */
    public function reloadUser(<UserInterface> user);

    /**
     * Updates a user.
     *
     * @param UserInterface user
     *
     * @return void
     */
    public function updateUser(<UserInterface> user);

    /**
     * Updates the canonical username and email fields for a user.
     *
     * @param UserInterface user
     *
     * @return void
     */
    public function updateCanonicalFields(<UserInterface> user);

    /**
     * Updates a user password if a plain password is set.
     *
     * @param UserInterface user
     *
     * @return void
     */
    public function updatePassword(<UserInterface> user);
}