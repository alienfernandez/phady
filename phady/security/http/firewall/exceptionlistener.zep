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
use Phady\Security\Core\Authentication\AuthenticationManagerInterface;
use Phady\Security\Http\Authentication\AuthenticationSuccessHandlerInterface;
use Phady\Security\Http\Authentication\AuthenticationFailureHandlerInterface;
use Phalcon\Http\Response;
use Phalcon\Http\Request;
use Phady\Security\Core\Exception\AuthenticationException;
use Phady\Security\Core\Authentication\Token\UsernamePasswordToken;
use Phady\Security\Core\Authentication\Token\TokenInterface;
use Phady\Security\Core\Security;
use Phady\Security\Http\Event\InteractiveLoginEvent;
use Phady\Security\Http\SecurityEvents;


use Phady\Security\Core\Authentication\Token\Storage\TokenStorageInterface;
use Phady\Security\Core\Authentication\AuthenticationTrustResolverInterface;
use Phady\Security\Http\EntryPoint\AuthenticationEntryPointInterface;
use Phady\Security\Http\Authorization\AccessDeniedHandlerInterface;

/**
  * @class Phady\Security\Http\Firewall\ExceptionListener
  * ExceptionListener catches authentication exception and converts them to
  * Response instances.
  *
  * @author  Alien Fernández Fuentes <alienfernandez85@gmail.com>
  * @package Core
  * @copyright (c) 2015
  * @version 1.0.0
  */
class ExceptionListener extends \Phalcon\Di\Injectable
{

    private tokenStorage;
    private providerKey;
    private accessDeniedHandler;
    private authenticationEntryPoint;
    private authenticationTrustResolver;
    private errorPage;
    private logger;
    private httpUtils;
    private stateless;

    public function __construct(<TokenStorageInterface> tokenStorage, <AuthenticationTrustResolverInterface> trustResolver,
                        providerKey, <AuthenticationEntryPointInterface> authenticationEntryPoint = null, errorPage = null,
                        <AccessDeniedHandlerInterface> accessDeniedHandler = null, stateless = false)
    {
        let this->tokenStorage = tokenStorage;
        let this->accessDeniedHandler = accessDeniedHandler;
        let this->providerKey = providerKey;
        let this->authenticationEntryPoint = authenticationEntryPoint;
        let this->authenticationTrustResolver = trustResolver;
        let this->errorPage = errorPage;
        //this->logger = logger;
        let this->stateless = stateless;
    }

}
