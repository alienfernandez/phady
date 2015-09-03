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

namespace Phady\Security\Core\Authentication;

use Phady\Security\Core\Authentication\LoginManagerInterface;
use Phady\Security\Core\User\UserCheckerInterface;
use Phalcon\Session\Adapter\Files as SessionAdapter;
use Phalcon\Di\InjectionAwareInterface;
use Phady\Security\Core\Authentication\Token\Storage\TokenStorageInterface;
use Phady\Security\Core\Authentication\Model\UserInterface;
use Phalcon\Http\Response;
use Phady\Security\Core\Authentication\Token\UsernamePasswordToken;

/**
  * @class Phady\Security\Core\Authentication\LoginManager
  *
  * @author  Alien Fernández Fuentes <alienfernandez85@gmail.com>
  * @package Core
  * @copyright (c) 2015
  * @version 1.0.0
  */
class LoginManager implements LoginManagerInterface
{
    /**
     * @var SecurityContextInterface|TokenStorageInterface
     */
    private tokenStorage;
    private userChecker;
    private container;

    public function __construct(tokenStorage, <UserCheckerInterface> userChecker,
                                <InjectionAwareInterface> container)
    {
        if (!(tokenStorage instanceof TokenStorageInterface)) {
            throw new \InvalidArgumentException("Argument 1 should be an instance of Phady\\Security\\Core\\Authentication\\Token\\Storage\\TokenStorageInterface");
        }
        let this->tokenStorage = tokenStorage;
        let this->userChecker = userChecker;
        let this->container = container;
    }

    final public function loginUser(firewallName, <UserInterface> user, <Response> response = null)
    {
        var token;
        this->userChecker->checkPostAuth(user);
        let token = this->createToken(firewallName, user);
        if (this->container->getDI()->has("request")) {
            //this->sessionStrategy->onAuthentication(this->container->get("request"), token);
            if (null !== response) {
                /*
                rememberMeServices = null;
                if (this->container->has("security.authentication.rememberme.services.persistent.".firewallName)) {
                    rememberMeServices = this->container->get("security.authentication.rememberme.services.persistent.".firewallName);
                } elseif (this->container->has("security.authentication.rememberme.services.simplehash.".firewallName)) {
                    rememberMeServices = this->container->get("security.authentication.rememberme.services.simplehash.".firewallName);
                }
                if (rememberMeServices instanceof RememberMeServicesInterface) {
                    rememberMeServices->loginSuccess(this->container->get("request"), response, token);
                }*/
            }
        }
        this->tokenStorage->setToken(token);
    }

    protected function createToken(firewall, <UserInterface> user)
    {
        return new UsernamePasswordToken(user, null, firewall, user->getRoles());
    }
}
