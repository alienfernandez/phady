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

use Phady\Http\RequestMatcherInterface;
use Phalcon\Http\Request;
use Phady\Security\Http\Firewall\ExceptionListener;

/**
  * @class Phady\Security\Http\FirewallMap
  *
  * @author  Alien Fernández Fuentes <alienfernandez85@gmail.com>
  * @package Core
  * @copyright (c) 2015
  * @version 1.0.0
  */
class FirewallMap implements FirewallMapInterface
{
    private map = [];

    /**
     * @param RequestMatcherInterface requestMatcher
     * @param array                   listeners
     * @param ExceptionListener       exceptionListener
     */
    public function add(<RequestMatcherInterface> requestMatcher = null, array listeners = [], <ExceptionListener> exceptionListener = null)
    {
        let this->map[] = [requestMatcher, listeners, exceptionListener];
    }

    /**
     * {@inheritdoc}
     */
    public function getListeners(<Request> request)
    {
        var elements;
        for elements in this->map {
            if (null === elements[0] || elements[0]->matches(request)) {
                return [elements[1], elements[2]];
            }
        }

        return [[], null];
    }
}
