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
use Phady\Security\Core\Authentication\Token\Storage\TokenStorageInterface;
use Phady\Security\Core\Authentication\AuthenticationManagerInterface;
use Phady\Security\Core\Authentication\Token\AnonymousToken;
use Phady\Security\Core\Exception\AuthenticationException;

/**
  * @class Phady\Security\Http\Firewall\AnonymousAuthenticationListener
  *
  * @author  Alien Fernández Fuentes <alienfernandez85@gmail.com>
  * @package Core
  * @copyright (c) 2015
  * @version 1.0.0
  */
class AnonymousAuthenticationListener implements ListenerInterface
{
    private tokenStorage;
    private key;
    private authenticationManager;
    private logger;

    public function __construct(<TokenStorageInterface> tokenStorage, key, <AuthenticationManagerInterface> authenticationManager = null)
    {
        let this->tokenStorage = tokenStorage;
        let this->key = key;
        let this->authenticationManager = authenticationManager;
        //this->logger = logger;
    }

    /**
     * Handles anonymous authentication.
     *
     * @param GetResponseEvent event A GetResponseEvent instance
     */
    public function handle()
    {
        var failed, token;
        if (null !== this->tokenStorage->getToken()) {
            return;
        }

        try {
            let token = new AnonymousToken(this->key, "anon.", []);
            if (null !== this->authenticationManager) {
                let token = this->authenticationManager->authenticate(token);
            }

            this->tokenStorage->setToken(token);

            /*
            if (null !== this->logger) {
                this->logger->info("Populated the TokenStorage with an anonymous Token.");
            }*/
        } catch AuthenticationException, failed {
            /*
            if (null !== this->logger) {
                this->logger->info("Anonymous authentication failed.", array("exception" => failed));
            }*/
        }
    }
}
