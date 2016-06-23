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

namespace Phady\Security\Http;

/**
  * @class Phady\Security\Http\SecurityEvents
  *
  * @author  Alien Fernández Fuentes <alienfernandez85@gmail.com>
  * @package Core
  * @copyright (c) 2015
  * @version 1.0.0
  */
final class SecurityEvents
{
    /**
     * The INTERACTIVE_LOGIN event occurs after a user is logged in
     * interactively for authentication based on http, cookies or X509.
     *
     * The event listener method receives a
     * Symfony\Component\Security\Http\Event\InteractiveLoginEvent instance.
     *
     * @Event
     *
     * @var string
     */
    const INTERACTIVE_LOGIN = "security.interactive_login";

    /**
     * The SWITCH_USER event occurs before switch to another user and
     * before exit from an already switched user.
     *
     * The event listener method receives a
     * Symfony\Component\Security\Http\Event\SwitchUserEvent instance.
     *
     * @Event
     *
     * @var string
     */
    const SWITCH_USER = "security.switch_user";
}
