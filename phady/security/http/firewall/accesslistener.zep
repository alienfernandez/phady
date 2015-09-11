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
use Phady\Security\Core\Authentication\Token\Storage\TokenStorageInterface;
use Phady\Security\Core\Authorization\AccessDecisionManagerInterface;
use Phady\Security\Core\Authentication\AuthenticationManagerInterface;
use Phady\Security\Core\Exception\AuthenticationCredentialsNotFoundException;
use Phady\Security\Core\Exception\AccessDeniedException;

/**
  * @class Phady\Security\Http\Firewall\ChannelListener
  *
  * @author  Alien Fernández Fuentes <alienfernandez85@gmail.com>
  * @package Core
  * @copyright (c) 2015
  * @version 1.0.0
  */
class AccessListener extends \Phalcon\Di\Injectable implements ListenerInterface
{
    private tokenStorage;
    private accessDecisionManager;
    private map;
    private authManager;

    //,<AccessMapInterface> map, <AuthenticationManagerInterface> authManager
    public function __construct(<TokenStorageInterface> tokenStorage, <AccessDecisionManagerInterface> accessDecisionManager)
    {
        let this->tokenStorage = tokenStorage;
        let this->accessDecisionManager = accessDecisionManager;
        //let this->map = map;
        //let this->authManager = authManager;
    }


    /**
     * Set tokenStorage
     *
     */
    public function setTokenStorage(<TokenStorageInterface> tokenStorage)
    {
        let this->tokenStorage = tokenStorage;
    }
    /**
     * Set accessDecisionManager
     *
     */
    public function setAccessDecisionManager(<AccessDecisionManagerInterface> accessDecisionManager)
    {
        let this->accessDecisionManager = accessDecisionManager;
    }

    /**
     * Set map
     *
     */
    public function setMap(<AccessMapInterface> map)
    {
        let this->map = map;
    }

    /**
     * Set map
     *
     */
    public function setAuthManager(<AuthenticationManagerInterface> authManager)
    {
        let this->authManager = authManager;
    }

    /**
     * Handles access authorization.
     *
     * @param GetResponseEvent event A GetResponseEvent instance
     *
     * @throws AccessDeniedException
     * @throws AuthenticationCredentialsNotFoundException
     */
    public function handle()
    {
        let this->map = this->getDI()->get("security.access_map");
        let this->authManager = this->getDI()->get("security.authentication.manager");

        var token, request, patterns, attributes;
        let token = this->tokenStorage->getToken();
        if (null === token) {
            throw new AuthenticationCredentialsNotFoundException("A Token was not found in the TokenStorage.");
        }

        let request = this->getDI()->get("request");

        //list(attributes) = this->map->getPatterns(request);
        let patterns = this->map->getPatterns(request);
        let attributes = patterns[0];

        if (null === attributes) {
            return;
        }

        if (!token->isAuthenticated()) {
            let token = this->authManager->authenticate(token);
            this->tokenStorage->setToken(token);
        }

        if (!this->accessDecisionManager->decide(token, attributes, request)) {
            throw new AccessDeniedException();
        }
    }
}
