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

use Phady\Security\Http\Firewall\AbstractAuthenticationListener;
use Phady\Security\Core\Authentication\Token\UsernamePasswordToken;
use Phady\Security\Core\Authentication\Token\Storage\TokenStorageInterface;
use Phady\Security\Core\Authentication\AuthenticationManagerInterface;
use Phady\Security\Http\Authentication\AuthenticationSuccessHandlerInterface;
use Phady\Security\Http\Authentication\AuthenticationFailureHandlerInterface;
use Phalcon\Http\Request;
use Phady\Security\Core\Exception\InvalidCsrfTokenException;
use Phady\Security\Core\Security;

/**
  * @class Phady\Security\Http\Firewall\UsernamePasswordFormAuthenticationListener
  *
  * @author  Alien Fernández Fuentes <alienfernandez85@gmail.com>
  * @package Core
  * @copyright (c) 2015
  * @version 1.0.0
  */
class UsernamePasswordFormAuthenticationListener extends AbstractAuthenticationListener
{
    private csrfTokenManager;

    public function __construct(<TokenStorageInterface> tokenStorage, <AuthenticationManagerInterface> authenticationManager,
        providerKey, <AuthenticationSuccessHandlerInterface> successHandler, <AuthenticationFailureHandlerInterface> failureHandler,
         array options = [], csrfTokenManager = null)
    {
        /*
        if (csrfTokenManager instanceof CsrfProviderInterface) {
            csrfTokenManager = new CsrfProviderAdapter(csrfTokenManager);
        } elseif (null !== csrfTokenManager && !csrfTokenManager instanceof CsrfTokenManagerInterface) {
            throw new InvalidArgumentException("The CSRF token manager should be an instance of CsrfProviderInterface or CsrfTokenManagerInterface.");
        }*/

        parent::__construct(tokenStorage, authenticationManager, providerKey, successHandler, failureHandler, array_merge([
            "username_parameter" : "_username",
            "password_parameter" : "_password",
            "csrf_parameter" : "_csrf_token",
            "intention" : "authenticate",
            "post_only" : true
        ], options));

        let this->csrfTokenManager = csrfTokenManager;
    }

    /**
     * {@inheritdoc}
     */
    protected function requiresAuthentication(<Request> request)
    {
        //if (this->options["post_only"]) {// && !request->isPost()
        //    return false;
       // }

        return parent::requiresAuthentication(request);
    }

    /**
     * {@inheritdoc}
     */
    public function attemptAuthentication(<Request> request)
    {
        var username, password, di;
        let di = this->getDI();
        let this->authenticationManager = di->get("security.authentication.manager");
        if (!di->get("security")->checkToken()) {
             throw new InvalidCsrfTokenException("Invalid CSRF token.");
        }

        if (this->options["post_only"]) {
            let username = trim(request->getPost(this->options["username_parameter"], null, true));
            let password = request->getPost(this->options["password_parameter"], null, true);
        } else {
            let username = trim(request->getPost(this->options["username_parameter"], null, true));
            let password = request->getPost(this->options["password_parameter"], null, true);
        }

        return this->authenticationManager->authenticate(new UsernamePasswordToken(username, password, this->providerKey));
    }
}
