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

namespace Phady\Security\Http\Firewall;

use Phady\Security\Http\Firewall\ListenerInterface;
use Phalcon\Http\Request;
use Phady\Security\Http\AccessMapInterface;
use Phady\Security\Http\EntryPoint\AuthenticationEntryPointInterface;

/**
  * @class Phady\Security\Http\Firewall\ChannelListener
  *
  * @author  Alien Fernández Fuentes <alienfernandez85@gmail.com>
  * @package Core
  * @copyright (c) 2015
  * @version 1.0.0
  */
class ChannelListener extends \Phalcon\Di\Injectable implements ListenerInterface
{
    private map;
    private authenticationEntryPoint;
    private logger;

    /*public function __construct(<AccessMapInterface> map, <AuthenticationEntryPointInterface> authenticationEntryPoint)
    {
        let this->map = map;
        let this->authenticationEntryPoint = authenticationEntryPoint;
        //let this->logger = logger;
    }*/


    /**
     * Set map
     *
     */
    public function setMap(<AccessMapInterface> map)
    {
        let this->map = map;
    }

    /**
     * Set authenticationEntryPoint
     *
     */
    public function setAuthenticationEntryPoint( <AuthenticationEntryPointInterface> authenticationEntryPoint)
    {
        let this->authenticationEntryPoint = authenticationEntryPoint;
    }

    /**
     * Handles channel management.
     *
     */
    public function handle()
    {
        let this->map = this->getDI()->get("security.access_map");
        var request, patterns, channel, response;
        let request = this->getDI()->get("request");

        echo "<pre>";print_r(this->map->getPatterns(request));die();
        //list(, channel) = this->map->getPatterns(request);
        let patterns = this->map->getPatterns(request);
        let channel = patterns[1];
        if ("https" === channel && !request->isSecureRequest()) {
            /*
            if (null !== this->logger) {
                this->logger->info("Redirecting to HTTPS.");
            }*/

            let response = this->authenticationEntryPoint->start(request);
            return;
        }

        if ("http" === channel && request->isSecureRequest()) {
            /*
            if (null !== this->logger) {
                this->logger->info("Redirecting to HTTP.");
            }*/

            let response = this->authenticationEntryPoint->start(request);
        }
    }
}
