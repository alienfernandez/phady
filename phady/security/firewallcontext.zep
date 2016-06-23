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

namespace Phady\Security;

use Phady\Security\Http\Firewall\ExceptionListener;

/**
  * @class Phady\Security\FirewallContext
  *
  * @author  Alien Fernández Fuentes <alienfernandez85@gmail.com>
  * @package Core
  * @copyright (c) 2015
  * @version 1.0.0
  */
class FirewallContext
{
    private listeners;
    private exceptionListener;

    public function __construct(array listeners, <ExceptionListener> exceptionListener = null)
    {
        let this->listeners = listeners;
        let this->exceptionListener = exceptionListener;
    }

    public function getContext()
    {
        return [this->listeners, this->exceptionListener];
    }
}

