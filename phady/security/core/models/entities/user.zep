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

namespace Phady\Security\Core\Models\Entities;

use Phady\Security\Core\User\UserInterface;


/**
 * Phady\Security\Core\Models\Entities\User
 *
 * Model for Users
 */
class User extends \Phady\Common\Entities\ModelBase implements UserInterface
{
    protected id;

    /**
     * @var string
     */
    protected username;

    /**
     * @var string
     */
    protected usernameCanonical;

    /**
     * @var string
     */
    protected email;

    /**
     * @var string
     */
    protected emailCanonical;

    /**
     * @var boolean
     */
    protected enabled;

    /**
     * The salt to use for hashing
     *
     * @var string
     */
    protected salt;

    /**
     * Encrypted password. Must be persisted.
     *
     * @var string
     */
    protected password;

    /**
     * Plain password. Used for model validation. Must not be persisted.
     *
     * @var string
     */
    protected plainPassword;

    /**
     * @var \DateTime
     */
    protected lastLogin;

    /**
     * Random string sent to the user email address in order to verify it
     *
     * @var string
     */
    protected confirmationToken;

    /**
     * @var \DateTime
     */
    protected passwordRequestedAt;

    /**
     * @var boolean
     */
    protected locked;

    /**
     * @var boolean
     */
    protected expired;

    /**
     * @var \DateTime
     */
    protected expiresAt;

    /**
     * @var array
     */
    protected roles;

    /**
     * @var boolean
     */
    protected credentialsExpired;

    /**
     * @var \DateTime
     */
    protected credentialsExpireAt;

	public function initialize() {

	}

	/**
	 * Physics returns the table name in the database engine
	 *
	 * @return string
	 */
	public function getSource() {
		return "phd_security_users";
	}

	/**
	 * Initializes the class. It assigns the attributes that can be obtained and modified.
	 */
	protected function init() {
        let this->salt = base_convert(sha1(uniqid(mt_rand(), true)), 16, 36);
        let this->enabled = false;
        let this->locked = false;
        let this->expired = false;
        let this->roles = [];
        let this->credentialsExpired = false;
		parent::init();
		array_push(this->_set, "id", "username", "usernameCanonical", "email", "emailCanonical", "enabled",
		 		"salt", "confirmationToken", "password", "passwordRequestedAt", "locked", "lastLogin", "expired", "expiresAt");
        array_push(this->_get, "id", "username", "usernameCanonical", "email", "usernameCanonical", "enabled",
        		 		"salt", "confirmationToken", "password", "passwordRequestedAt", "locked", "lastLogin", "expired", "expiresAt");
	}

    public function addRole(role)
    {
        let role = strtoupper(role);
        if (role === "ROLE_DEFAULT") {
            return this;
        }

        if (!in_array(role, this->roles, true)) {
            let this->roles[] = role;
        }

        return this;
    }

    /**
     * Serializes the user.
     *
     * The serialized data have to contain the fields used by the equals method and the username.
     *
     * @return string
     */
    public function serialize()
    {
        return serialize([
            this->password,
            this->salt,
            this->usernameCanonical,
            this->username,
            this->expired,
            this->locked,
            this->credentialsExpired,
            this->enabled,
            this->id
        ]);
    }

    /**
     * Unserializes the user.
     *
     * @param string serialized
     */
    public function unserialize(serialized)
    {
        /*data = unserialize(serialized);
        // add a few extra elements in the array to ensure that we have enough keys when unserializing
        // older data which does not include all properties.
        data = array_merge(data, array_fill(0, 2, null));

        list(
            this->password,
            this->salt,
            this->usernameCanonical,
            this->username,
            this->expired,
            this->locked,
            this->credentialsExpired,
            this->enabled,
            this->id
        ) = data;*/
    }

    /**
     * Removes sensitive data from the user.
     */
    public function eraseCredentials()
    {
        let this->plainPassword = null;
    }

    /**
     * Returns the user unique id.
     *
     * @return mixed
     */
    public function getId()
    {
        return this->id;
    }

    public function getUsername()
    {
        return this->username;
    }

    public function getUsernameCanonical()
    {
        return this->usernameCanonical;
    }

    public function getSalt()
    {
        return this->salt;
    }

    public function getEmail()
    {
        return this->email;
    }

    public function getEmailCanonical()
    {
        return this->emailCanonical;
    }

    /**
     * Gets the encrypted password.
     *
     * @return string
     */
    public function getPassword()
    {
        return this->password;
    }

    public function getPlainPassword()
    {
        return this->plainPassword;
    }

    /**
     * Gets the last login time.
     *
     * @return \DateTime
     */
    public function getLastLogin()
    {
        return this->lastLogin;
    }

    public function getConfirmationToken()
    {
        return this->confirmationToken;
    }

    /**
     * Returns the user roles
     *
     * @return array The roles
     */
    public function getRoles()
    {
        var roles;
        let roles = (!is_array(this->roles)) ? [] : this->roles;

        // we need to make sure to have at least one role
        let roles[] = "ROLE_DEFAULT";

        return array_unique(roles);
    }

    /**
     * Never use this to check if this user has access to anything!
     *
     * Use the SecurityContext, or an implementation of AccessDecisionManager
     * instead, e.g.
     *
     *         securityContext->isGranted('ROLE_USER');
     *
     * @param string role
     *
     * @return boolean
     */
    public function hasRole(role)
    {
        return in_array(strtoupper(role), this->getRoles(), true);
    }

    public function isAccountNonExpired()
    {
        if (true === this->expired) {
            return false;
        }

        if (null !== this->expiresAt && this->expiresAt->getTimestamp() < time()) {
            return false;
        }

        return true;
    }

    public function isAccountNonLocked()
    {
        return !this->locked;
    }

    public function isCredentialsNonExpired()
    {
        if (true === this->credentialsExpired) {
            return false;
        }

        if (null !== this->credentialsExpireAt && this->credentialsExpireAt->getTimestamp() < time()) {
            return false;
        }

        return true;
    }

    public function isCredentialsExpired()
    {
        return !this->isCredentialsNonExpired();
    }

    public function isEnabled()
    {
        return this->enabled;
    }

    public function isExpired()
    {
        return !this->isAccountNonExpired();
    }

    public function isLocked()
    {
        return !this->isAccountNonLocked();
    }

    public function isSuperAdmin()
    {
        return this->hasRole("ROLE_SUPER_ADMIN");
    }

    public function isUser(<UserInterface> user = null)
    {
        return null !== user && this->getId() === user->getId();
    }

    public function removeRole(role)
    {
        var key;
        let key = array_search(strtoupper(role), this->roles, true);
        if (false !== key) {
            unset(this->roles[key]);
            let this->roles = array_values(this->roles);
        }

        return this;
    }

    public function setUsername(username)
    {
        let this->username = username;

        return this;
    }

    public function setUsernameCanonical(usernameCanonical)
    {
        let this->usernameCanonical = usernameCanonical;

        return this;
    }

    /**
     * @param \DateTime date
     *
     * @return User
     */
    public function setCredentialsExpireAt(<\DateTime> date)
    {
        let this->credentialsExpireAt = date;

        return this;
    }

    /**
     * @param boolean boolean
     *
     * @return User
     */
    public function setCredentialsExpired(boolean credentialExpired)
    {
        let this->credentialsExpired = credentialExpired;

        return this;
    }

    public function setEmail(email)
    {
        let this->email = email;

        return this;
    }

    public function setEmailCanonical(emailCanonical)
    {
        let this->emailCanonical = emailCanonical;

        return this;
    }

    public function setEnabled(boolean enabled)
    {
        let this->enabled = enabled;

        return this;
    }

    /**
     * Sets this user to expired.
     *
     * @param Boolean boolean
     *
     * @return User
     */
    public function setExpired(boolean expired)
    {
        let this->expired = expired;

        return this;
    }

    /**
     * @param \DateTime date
     *
     * @return User
     */
    public function setExpiresAt(<\DateTime> date)
    {
        let this->expiresAt = date;

        return this;
    }

    public function setPassword(password)
    {
        let this->password = password;

        return this;
    }

    public function setSuperAdmin(isSuperAdmin)
    {
        if (true === isSuperAdmin) {
            this->addRole("ROLE_SUPER_ADMIN");
        } else {
            this->removeRole("ROLE_SUPER_ADMIN");
        }

        return this;
    }

    public function setPlainPassword(password)
    {
        let this->plainPassword = password;

        return this;
    }

    public function setLastLogin(<\DateTime> time)
    {
        let this->lastLogin = time;

        return this;
    }

    public function setLocked(boolean locked)
    {
        let this->locked = locked;

        return this;
    }

    public function setConfirmationToken(confirmationToken)
    {
        let this->confirmationToken = confirmationToken;

        return this;
    }

    public function setPasswordRequestedAt(<\DateTime> date = null)
    {
        let this->passwordRequestedAt = date;

        return this;
    }

    /**
     * Gets the timestamp that the user requested a password reset.
     *
     * @return null|\DateTime
     */
    public function getPasswordRequestedAt()
    {
        return this->passwordRequestedAt;
    }

    public function isPasswordRequestNonExpired(ttl)
    {
        return ((this->getPasswordRequestedAt() instanceof \DateTime) &&
                this->getPasswordRequestedAt()->getTimestamp() + ttl > time());
    }

    public function setRoles(array roles)
    {
        var role;
        let this->roles = [];

        for role in roles {
            this->addRole(role);
        }

        return this;
    }

    public function __toString()
    {
        return (string) this->getUsername();
    }
}
