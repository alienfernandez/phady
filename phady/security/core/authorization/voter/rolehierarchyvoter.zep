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

namespace Phady\Security\Core\Authorization\Voter;

use Phady\Security\Core\Authorization\Voter\VoterInterface;
use Phady\Security\Core\Authorization\Voter\RoleVoter;
use Phady\Security\Core\Authentication\Token\TokenInterface;
use Phady\Security\Core\Role\RoleHierarchyInterface;

/**
  * @class Phady\Security\Core\Authorization\Voter\AbstractVoter
  *
  * @author  Alien Fernández Fuentes <alienfernandez85@gmail.com>
  * @package Core
  * @copyright (c) 2015
  * @version 1.0.0
  */
class RoleHierarchyVoter extends RoleVoter
{
    private roleHierarchy;

    public function __construct(<RoleHierarchyInterface> roleHierarchy, prefix = "ROLE_")
    {
        let this->roleHierarchy = roleHierarchy;
        parent::__construct(prefix);
    }

    /**
     * {@inheritdoc}
     */
    protected function extractRoles(<TokenInterface> token)
    {
        return this->roleHierarchy->getReachableRoles(token->getRoles());
    }
}
