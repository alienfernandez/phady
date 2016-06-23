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

namespace Phady\Security\Core\Role;

use Phady\Security\Core\Role\RoleInterface;

/**
  * @class Phady\Security\Core\Role\Role
  *
  * @author  Alien Fernández Fuentes <alienfernandez85@gmail.com>
  * @package Core
  * @copyright (c) 2015
  * @version 1.0.0
  */
class Role implements RoleInterface
{

    private role;

    /**
     * Constructor.
     *
     * @param string role The role name
     */
    public function __construct(role)
    {
        let this->role = (string) role;
    }

    /**
     * {@inheritdoc}
     */
    public function getRole() -> string
    {
        return this->role;
    }

    /**
     * {@inheritdoc}
     */
    public function __toString() -> string
    {
        return (string) this->role;
    }
}
