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

namespace Phady\Security\Http\Event;

use Phalcon\Events\Event;
use Phalcon\Http\Request;
use Phady\Security\Core\Authentication\Token\TokenInterface;

/**
  * @class Phady\Security\Http\Event\InteractiveLoginEvent
  *
  * @author  Alien Fernández Fuentes <alienfernandez85@gmail.com>
  * @package Core
  * @copyright (c) 2015
  * @version 1.0.0
  */
class InteractiveLoginEvent extends Event {
    
    private request;
    private authenticationToken;

    /**
     * Constructor.
     *
     * @param Request        request             A Request instance
     * @param TokenInterface authenticationToken A TokenInterface instance
     */
    public function __construct(<Request> request, <TokenInterface> authenticationToken)
    {
        let this->request = request;
        let this->authenticationToken = authenticationToken;
    }

    /**
     * Gets the request.
     *
     * @return Request A Request instance
     */
    public function getRequest()
    {
        return this->request;
    }

    /**
     * Gets the authentication token.
     *
     * @return TokenInterface A TokenInterface instance
     */
    public function getAuthenticationToken()
    {
        return this->authenticationToken;
    }
}
