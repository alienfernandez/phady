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
  * @class Phady\Security\Core\Authorization\Voter\AbstractVoter
  *
  * @author  Alien Fernández Fuentes <alienfernandez85@gmail.com>
  * @package Core
  * @copyright (c) 2015
  * @version 1.0.0
  */
abstract class AbstractVoter implements VoterInterface
{
    /**
     * {@inheritdoc}
     */
    public function supportsAttribute(attribute)
    {
        return in_array(attribute, this->getSupportedAttributes());
    }

    /**
     * {@inheritdoc}
     */
    public function supportsClass(supportsClass) -> boolean
    {

        var supportedClass;
        for supportedClass in this->getSupportedClasses() {
            if (supportedClass === supportsClass || is_subclass_of(supportsClass, supportedClass)) {
                return true;
            }
        }

        return false;
    }

    /**
     * Iteratively check all given attributes by calling isGranted
     *
     * This method terminates as soon as it is able to return ACCESS_GRANTED
     * If at least one attribute is supported, but access not granted, then ACCESS_DENIED is returned
     * Otherwise it will return ACCESS_ABSTAIN
     *
     * @param TokenInterface token      A TokenInterface instance
     * @param object         objectSecure     The objectSecure to secure
     * @param array          attributes An array of attributes associated with the method being invoked
     *
     * @return int either ACCESS_GRANTED, ACCESS_ABSTAIN, or ACCESS_DENIED
     */
    public function vote(<TokenInterface> token, objectSecure, array attributes)
    {
        var vote, attribute;
        if (!objectSecure || !this->supportsClass(get_class(objectSecure))) {
            return VoterInterface::ACCESS_ABSTAIN;
        }

        // abstain vote by default in case none of the attributes are supported
        let vote = VoterInterface::ACCESS_ABSTAIN;

        for attribute in attributes {
            if (!this->supportsAttribute(attribute)) {
                continue;
            }

            // as soon as at least one attribute is supported, default is to deny access
            let vote = VoterInterface::ACCESS_DENIED;

            if (this->isGranted(attribute, objectSecure, token->getUser())) {
                // grant access as soon as at least one voter returns a positive response
                return VoterInterface::ACCESS_GRANTED;
            }
        }

        return vote;
    }

    /**
     * Return an array of supported classes. This will be called by supportsClass
     *
     * @return array an array of supported classes, i.e. array('Acme\DemoBundle\Model\Product')
     */
    abstract protected function getSupportedClasses();

    /**
     * Return an array of supported attributes. This will be called by supportsAttribute
     *
     * @return array an array of supported attributes, i.e. array('CREATE', 'READ')
     */
    abstract protected function getSupportedAttributes();

    /**
     * Perform a single access check operation on a given attribute, object and (optionally) user
     * It is safe to assume that attribute and object's class pass supportsAttribute/supportsClass
     * user can be one of the following:
     *   a UserInterface object (fully authenticated user)
     *   a string               (anonymously authenticated user)
     *
     * @param string               attribute
     * @param object               objectSecure
     * @param UserInterface|string user
     *
     * @return bool
     */
    abstract protected function isGranted(attribute, objectSecure, user = null);
}
