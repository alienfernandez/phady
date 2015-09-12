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
use Phady\Security\Core\Authentication\Token\TokenInterface;

/**
  * @class Phady\Security\Core\Authorization\Voter\RoleVoter
  *
  * @author  Alien Fernández Fuentes <alienfernandez85@gmail.com>
  * @package Core
  * @copyright (c) 2015
  * @version 1.0.0
  */
class RoleVoter implements VoterInterface
{
    private prefix;

    /**
     * Constructor.
     *
     * @param string prefix The role prefix
     */
    public function __construct(prefix = "ROLE_")
    {
        let this->prefix = prefix;
    }

    /**
     * {@inheritdoc}
     */
    public function supportsAttribute(attribute)
    {
        return 0 === strpos(attribute, this->prefix);
    }

    /**
     * {@inheritdoc}
     */
    public function supportsClass(supportsClass)
    {
        return true;
    }

    /**
     * {@inheritdoc}
     */
    public function vote(<TokenInterface> token, objectSecure, array attributes)
    {
        var result, role, roles, attribute;
        let result = VoterInterface::ACCESS_ABSTAIN;
        let roles = this->extractRoles(token);
        for attribute in attributes {
            if (!this->supportsAttribute(attribute)) {
                continue;
            }

            let result = VoterInterface::ACCESS_DENIED;
            for role in roles {
                if (attribute === role->getRole()) {
                    return VoterInterface::ACCESS_GRANTED;
                }
            }
        }

        return result;
    }

    protected function extractRoles(<TokenInterface> token)
    {
        return token->getRoles();
    }
}
