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

use Phalcon\Http\Request;
use Phady\Security\Http\Firewall\ExceptionListener;
use Phady\Security\Http\FirewallMapInterface;
use Phalcon\Events\Event;
use Phalcon\Mvc\Dispatcher;

/**
  * @class Phady\Security\Http\Firewall
  *
  * @author  Alien Fernández Fuentes <alienfernandez85@gmail.com>
  * @package Core
  * @copyright (c) 2015
  * @version 1.0.0
  */
class Firewall extends \Phalcon\Di\Injectable
{
    private map = [];
    private dispatcher;
    private exceptionListeners;
    

    /**
     * Constructor.
     *
     * @param FirewallMapInterface     map        A FirewallMapInterface instance
     * @param EventDispatcherInterface dispatcher An EventDispatcherInterface instance
     */
    public function __construct(<FirewallMapInterface> map)
    {
        let this->map = map;
        let this->dispatcher = this->getDI()->get("dispatcher");
        let this->exceptionListeners = new \SplObjectStorage();
    }

    /**
     * Handles security.
     *
     * @param GetResponseEvent event An GetResponseEvent instance
     */
    public function beforeDispatch(<Event> event, <Dispatcher> dispatcher)
    {
        /*
        if (!event->isMasterRequest()) {
            return;
        }*/
        var request, listeners, exceptionListener, listenersMap;
        let request = this->getDI()->get("request");
        // register listeners for this firewall
        //list(listeners, exceptionListener) = this->map->getListeners(request);
        let listenersMap = this->map->getListeners(request);
        /*if (null !== exceptionListener) {
            this->exceptionListeners[event->getRequest()] = listenersMap[1];
            exceptionListener->register(this->dispatcher);
        }*/

        // initiate the listener chain
        foreach (listenersMap[0] as listener) {
            listener->handle();
            /*
            if (event->hasResponse()) {
                break;
            }*/
        }
    }        
}
