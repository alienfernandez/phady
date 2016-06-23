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

use Phady\Security\Http\AccessMapInterface;
use Phady\Http\RequestMatcherInterface;
use Phalcon\Http\Request;

/**
  * @class Phady\Security\Http\AccessMap
  *
  * @author  Alien Fernández Fuentes <alienfernandez85@gmail.com>
  * @package Core
  * @copyright (c) 2015
  * @version 1.0.0
  */
class AccessMap implements AccessMapInterface
{
    private map = [];

    /**
     * Constructor.
     *
     * @param RequestMatcherInterface requestMatcher A RequestMatcherInterface instance
     * @param array                   attributes     An array of attributes to pass to the access decision manager (like roles)
     * @param string|null             channel        The channel to enforce (http, https, or null)
     */
    public function add(<RequestMatcherInterface> requestMatcher, array attributes = [], channel = null)
    {
        let this->map[] = [requestMatcher, attributes, channel];
    }

    /**
     * {@inheritdoc}
     */
    public function getPatterns(<Request> request)
    {
        var elements;

        for elements in this->map {
            if (null === elements[0] || elements[0]->matches(request)) {
                return [elements[1], elements[2]];
            }
        }

        return [null, null];
    }
}
