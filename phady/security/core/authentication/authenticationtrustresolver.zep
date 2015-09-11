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

namespace Phady\Security\Core\Authentication;

use Phady\Security\Core\Authentication\AuthenticationTrustResolverInterface;
use Phady\Security\Core\Authentication\Token\TokenInterface;

/**
  * @class Phady\Security\Core\Authentication\AuthenticationTrustResolver
  *
  * @author  Alien Fernández Fuentes <alienfernandez85@gmail.com>
  * @package Core
  * @copyright (c) 2015
  * @version 1.0.0
  */
class AuthenticationTrustResolver implements AuthenticationTrustResolverInterface
{
    private anonymousClass;
    private rememberMeClass;

    /**
     * Constructor.
     *
     * @param string anonymousClass
     * @param string rememberMeClass
     */
    public function __construct(anonymousClass, rememberMeClass)
    {
        let this->anonymousClass = anonymousClass;
        let this->rememberMeClass = rememberMeClass;
    }

    /**
     * {@inheritdoc}
     */
    public function isAnonymous(<TokenInterface> token = null)
    {
        if (null === token) {
            return false;
        }

        return token instanceof this->anonymousClass;
    }

    /**
     * {@inheritdoc}
     */
    public function isRememberMe(<TokenInterface> token = null)
    {
        if (null === token) {
            return false;
        }

        return token instanceof this->rememberMeClass;
    }

    /**
     * {@inheritdoc}
     */
    public function isFullFledged(<TokenInterface> token = null)
    {
        if (null === token) {
            return false;
        }

        return !this->isAnonymous(token) && !this->isRememberMe(token);
    }
}
