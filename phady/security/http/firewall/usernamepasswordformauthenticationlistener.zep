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
        if (this->options["post_only"] && !request->isMethod("POST")) {
            return false;
        }

        return parent::requiresAuthentication(request);
    }

    /**
     * {@inheritdoc}
     */
    protected function attemptAuthentication(<Request> request)
    {
        var username, password;
        if (null !== this->csrfTokenManager) {
            //let csrfToken = request->get(this->options["csrf_parameter"], null, true);

            /*
            if (false === this->csrfTokenManager->isTokenValid(new CsrfToken(this->options["intention"], csrfToken))) {
                throw new InvalidCsrfTokenException("Invalid CSRF token.");
            }*/
        }

        if (this->options["post_only"]) {
            let username = trim(request->getPost(this->options["username_parameter"], null, true));
            let password = request->getPost(this->options["password_parameter"], null, true);
        } else {
            let username = trim(request->getPost(this->options["username_parameter"], null, true));
            let password = request->getPost(this->options["password_parameter"], null, true);
        }

        //request->getSession()->set(Security::LAST_USERNAME, username);

        return this->authenticationManager->authenticate(new UsernamePasswordToken(username, password, this->providerKey));
    }
}
