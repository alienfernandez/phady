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

use Phalcon\Events\Event;
use Phalcon\Di\Injectable;
use Phalcon\Http\Request;
use Phady\Security\Http\FirewallMapInterface;

/**
  * @class Phady\Security\FirewallMap
  *
  * @author  Alien Fernández Fuentes <alienfernandez85@gmail.com>
  * @package Core
  * @copyright (c) 2015
  * @version 1.0.0
  */
class FirewallMap extends Injectable implements FirewallMapInterface
{
    protected map;
    protected container;
    
    public function __construct(array map)
    {
        let this->container = this->getDI();
        let this->map = map;
    }

    public function getListeners(<Request> request)
    {
        var contextId, requestMatcher;
        for contextId, requestMatcher in this->map {
            if (null === requestMatcher || requestMatcher->matches(request)) {
                return this->container->get(contextId);
            }
        }

        return [[], null];
    }
}
