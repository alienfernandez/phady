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

namespace Phady\Security\Core;

/**
  * @class Phady\Security\Core\AuthenticationEvents
  *
  * @author  Alien Fernández Fuentes <alienfernandez85@gmail.com>
  * @package Core
  * @copyright (c) 2015
  * @version 1.0.0
  */
final class AuthenticationEvents
{
    /**
     * The AUTHENTICATION_SUCCESS event occurs after a user is authenticated
     * by one provider.
     *
     * The event listener method receives a
     * Symfony\Component\Security\Core\Event\AuthenticationEvent instance.
     *
     * @var string
     */
    const AUTHENTICATION_SUCCESS = "security.authentication.success";

    /**
     * The AUTHENTICATION_FAILURE event occurs after a user cannot be
     * authenticated by any of the providers.
     *
     * The event listener method receives a
     * Symfony\Component\Security\Core\Event\AuthenticationFailureEvent
     * instance.
     *
     * @var string
     */
    const AUTHENTICATION_FAILURE = "security.authentication.failure";
}
