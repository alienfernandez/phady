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
use Phady\Security\Core\Authentication\AuthenticationTrustResolverInterface;

/**
  * @class Phady\Security\Core\Authorization\Voter\AbstractVoter
  *
  * @author  Alien Fernández Fuentes <alienfernandez85@gmail.com>
  * @package Core
  * @copyright (c) 2015
  * @version 1.0.0
  */
class AuthenticatedVoter implements VoterInterface
{
    const IS_AUTHENTICATED_FULLY = "IS_AUTHENTICATED_FULLY";
    const IS_AUTHENTICATED_REMEMBERED = "IS_AUTHENTICATED_REMEMBERED";
    const IS_AUTHENTICATED_ANONYMOUSLY = "IS_AUTHENTICATED_ANONYMOUSLY";

    private authenticationTrustResolver;

    /**
     * Constructor.
     *
     * @param AuthenticationTrustResolverInterface authenticationTrustResolver
     */
    public function __construct(<AuthenticationTrustResolverInterface> authenticationTrustResolver)
    {
        let this->authenticationTrustResolver = authenticationTrustResolver;
    }

    /**
     * {@inheritdoc}
     */
    public function supportsAttribute(attribute)
    {
        return null !== attribute && (self::IS_AUTHENTICATED_FULLY === attribute || self::IS_AUTHENTICATED_REMEMBERED === attribute ||
                    self::IS_AUTHENTICATED_ANONYMOUSLY === attribute);
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
        var attribute, result;
        let result = VoterInterface::ACCESS_ABSTAIN;
        for attribute in attributes {
            if (!this->supportsAttribute(attribute)) {
                continue;
            }

            let result = VoterInterface::ACCESS_DENIED;

            if (self::IS_AUTHENTICATED_FULLY === attribute
                && this->authenticationTrustResolver->isFullFledged(token)) {
                return VoterInterface::ACCESS_GRANTED;
            }

            if (self::IS_AUTHENTICATED_REMEMBERED === attribute
                && (this->authenticationTrustResolver->isRememberMe(token)
                    || this->authenticationTrustResolver->isFullFledged(token))) {
                return VoterInterface::ACCESS_GRANTED;
            }

            if (self::IS_AUTHENTICATED_ANONYMOUSLY === attribute
                && (this->authenticationTrustResolver->isAnonymous(token)
                    || this->authenticationTrustResolver->isRememberMe(token)
                    || this->authenticationTrustResolver->isFullFledged(token))) {
                return VoterInterface::ACCESS_GRANTED;
            }
        }

        return result;
    }
}
