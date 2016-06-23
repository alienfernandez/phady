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

namespace Phady\Security\Core\Authorization;

use Phady\Security\Core\Authentication\Token\TokenInterface;

/**
  * @class Phady\Security\Core\Authorization\AccessDecisionManagerInterface
  *
  * @author  Alien Fernández Fuentes <alienfernandez85@gmail.com>
  * @package Core
  * @copyright (c) 2015
  * @version 1.0.0
  */
interface AccessDecisionManagerInterface
{
    /**
     * Decides whether the access is possible or not.
     *
     * @param TokenInterface token      A TokenInterface instance
     * @param array          attributes An array of attributes associated with the method being invoked
     * @param object         object     The object to secure
     *
     * @return bool true if the access is granted, false otherwise
     */
    public function decide(<TokenInterface> token, array attributes, objectSecure = null);

    /**
     * Checks if the access decision manager supports the given attribute.
     *
     * @param string attribute An attribute
     *
     * @return bool true if this decision manager supports the attribute, false otherwise
     */
    public function supportsAttribute(attribute);

    /**
     * Checks if the access decision manager supports the given class.
     *
     * @param string supportsClass A class name
     *
     * @return true if this decision manager can process the class
     */
    public function supportsClass(supportsClass);
}
