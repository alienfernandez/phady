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

use Phady\Security\Core\Role\Role;
use Phady\Security\Core\User\UserInterface;

/**
 * Phady\Security\Core\Authentication\Token\AbstractToken
 *
 * Interface
 */
abstract class AbstractToken implements TokenInterface
{

    protected user;
    protected roles = [];
    protected authenticated = false;
    protected attributes = [];
    /**
     * Constructor.
     *
     * @param RoleInterface[]|string[] roles An array of roles
     *
     * @throws \InvalidArgumentException
     */
    public function __construct(array roles = [])
    {
        var role;
        for role in roles  {
            if (is_string(role)) {
                let role = new Role(role);
            } elseif (!(role instanceof RoleInterface)) {
                throw new \InvalidArgumentException(sprintf("roles must be an array of strings, or RoleInterface instances, but got %s.", gettype(role)));
            }
            let this->roles[] = role;
        }
    }

    /**
     * {@inheritdoc}
     */
    public function getRoles()
    {
        return this->roles;
    }

    /**
     * {@inheritdoc}
     */
    public function getUsername()
    {
        if (this->user instanceof UserInterface) {
            return this->user->getUsername();
        }
        return (string) this->user;
    }

    /**
     * {@inheritdoc}
     */
    public function getUser()
    {
        return this->user;
    }

    /**
     * Sets the user in the token.
     *
     * The user can be a UserInterface instance, or an object implementing
     * a __toString method or the username as a regular string.
     *
     * @param string|object user The user
     *
     * @throws \InvalidArgumentException
     */
    public function setUser(user)
    {
        var changed;
        if (!((user instanceof UserInterface) || (is_object(user) && method_exists(user, "__toString")) || is_string(user))) {
            throw new \InvalidArgumentException("user must be an instanceof UserInterface, an object implementing a __toString method, or a primitive string.");
        }
        if (null === this->user) {
            let changed = false;
        } elseif (this->user instanceof UserInterface) {
            if (!(user instanceof UserInterface)) {
                let changed = true;
            } else {
                //let changed = this->hasUserChanged(user);
            }
        } elseif (user instanceof UserInterface) {
            let changed = true;
        } else {
            let changed = (string) this->user !== (string) user;
        }
        if (changed) {
            this->setAuthenticated(false);
        }
        let this->user = user;
    }

    /**
     * {@inheritdoc}
     */
    public function isAuthenticated()
    {
        return this->authenticated;
    }
    /**
     * {@inheritdoc}
     */
    public function setAuthenticated(authenticated)
    {
        let this->authenticated = (bool) authenticated;
    }

    /**
     * {@inheritdoc}
     */
    public function eraseCredentials()
    {
        if (this->getUser() instanceof UserInterface) {
            this->getUser()->eraseCredentials();
        }
    }

    /**
     * {@inheritdoc}
     */
    public function serialize()
    {
        return serialize(
            [
                is_object(this->user) ? clone this->user : this->user,
                this->authenticated,
                this->roles,
                this->attributes
            ]
        );
    }

    /**
     * {@inheritdoc}
     */
    public function unserialize(serialized)
    {
        var unserializedData;
        let unserializedData = unserialize(serialized);
        let this->user = unserializedData[0];
        let this->authenticated = unserializedData[1];
        let this->roles = unserializedData[2];
        let this->attributes = unserializedData[3];
         //list(this->user, this->authenticated, this->roles, this->attributes)
    }

    /**
     * Returns the token attributes.
     *
     * @return array The token attributes
     */
    public function getAttributes()
    {
        return this->attributes;
    }
    /**
     * Sets the token attributes.
     *
     * @param array attributes The token attributes
     */
    public function setAttributes(array attributes)
    {
        let this->attributes = attributes;
    }
    /**
     * Returns true if the attribute exists.
     *
     * @param string name The attribute name
     *
     * @return bool true if the attribute exists, false otherwise
     */
    public function hasAttribute(name)
    {
        return array_key_exists(name, this->attributes);
    }
    /**
     * Returns an attribute value.
     *
     * @param string name The attribute name
     *
     * @return mixed The attribute value
     *
     * @throws \InvalidArgumentException When attribute doesn"t exist for this token
     */
    public function getAttribute(name)
    {
        if (!array_key_exists(name, this->attributes)) {
            throw new \InvalidArgumentException(sprintf("This token has no %s attribute.", name));
        }
        return this->attributes[name];
    }

    /**
     * Sets an attribute.
     *
     * @param string name  The attribute name
     * @param mixed  value The attribute value
     */
    public function setAttribute(name, value)
    {
        let this->attributes[name] = value;
    }

    /**
     * {@inheritdoc}
     */
    public function __toString()
    {
        var role, roles, classStr;
        let classStr = get_class(this);
        let classStr = substr(classStr, strrpos(classStr, "\\") + 1);
        let roles = [];
        for role in this->roles {
            let roles[] = role->getRole();
        }
        return sprintf("%s(user=%s, authenticated=%s, roles=%s)", classStr, this->getUsername(), json_encode(this->authenticated), implode(", ", roles));
    }

    public function hasUserChanged(<UserInterface> user) -> boolean
    {
        if (!(this->user instanceof UserInterface)) {
            throw new \BadMethodCallException("Method hasUserChanged should be called when current user class is instance of UserInterface.");
        }
        /*
        if (this->user instanceof EquatableInterface) {
            return !(bool) this->user->isEqualTo(user);
        }*/
        if (this->user->getPassword() !== user->getPassword()) {
            return true;
        }
        if (this->user->getSalt() !== user->getSalt()) {
            return true;
        }
        if (this->user->getUsername() !== user->getUsername()) {
            return true;
        }
        /*
        if (this->user instanceof AdvancedUserInterface && user instanceof AdvancedUserInterface) {
            if (this->user->isAccountNonExpired() !== user->isAccountNonExpired()) {
                return true;
            }
            if (this->user->isAccountNonLocked() !== user->isAccountNonLocked()) {
                return true;
            }
            if (this->user->isCredentialsNonExpired() !== user->isCredentialsNonExpired()) {
                return true;
            }
            if (this->user->isEnabled() !== user->isEnabled()) {
                return true;
            }
        } elseif (this->user instanceof AdvancedUserInterface xor user instanceof AdvancedUserInterface) {
            return true;
        }*/
        return false;
    }
}