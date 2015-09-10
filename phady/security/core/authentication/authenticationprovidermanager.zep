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

//use Phady\Security\Core\Authentication\AuthenticationManagerInterface;
use Phady\Security\Core\Authentication\Token\TokenInterface;
use Phady\Security\Core\Authentication\Provider\AuthenticationProviderInterface;
use Phady\Security\Core\Exception\AuthenticationException;
use Phady\Security\Core\Exception\ProviderNotFoundException;

/**
  * @class Phady\Security\Core\Authentication\AuthenticationProviderManager
  *
  * @author  Alien Fernández Fuentes <alienfernandez85@gmail.com>
  * @package Core
  * @copyright (c) 2015
  * @version 1.0.0
  */
class AuthenticationProviderManager implements AuthenticationManagerInterface
{
    private providers;
    private eraseCredentials;
    private eventDispatcher;

    /**
     * Constructor.
     *
     * @param AuthenticationProviderInterface[] providers        An array of AuthenticationProviderInterface instances
     * @param bool                              eraseCredentials Whether to erase credentials after authentication or not
     *
     * @throws \InvalidArgumentException
     */
    public function __construct(providers, eraseCredentials = true)
    {
        this->setProviders(providers);
        let this->eraseCredentials = (bool) eraseCredentials;
    }

    /**
     * {@inheritdoc}
     */
    public function setProviders(providers)
    {
        var provider;
        if (!providers) {
            throw new \InvalidArgumentException("You must at least add one authentication provider.");
        }
        for provider in providers {
            if (!(provider instanceof AuthenticationProviderInterface)) {
                throw new \InvalidArgumentException(sprintf("Provider %s must implement the AuthenticationProviderInterface.", get_class(provider)));
            }
        }
        let this->providers = providers;
    }

    /**
     * {@inheritdoc}
     */
    public function authenticate(<TokenInterface> token)
    {
        var e, lastException, result, provider;
        let lastException = null;
        let result = null;
        //echo "<pre>"; print_r(this->providers);
        //die("end provider...");
        for provider in this->providers {
            if (!provider->supports(token)) {
                continue;
            }
            try {

                let result = provider->authenticate(token);

                if (null !== result) {
                    break;
                }
            }
            catch AuthenticationException, e {
                let lastException = e;
            }
        }
        if (null !== result) {
            if (true === this->eraseCredentials) {
                result->eraseCredentials();
            }
            if (null !== this->eventDispatcher) {
                //this->eventDispatcher->dispatch(AuthenticationEvents::AUTHENTICATION_SUCCESS, new AuthenticationEvent(result));
            }
            return result;
        }
        if (null === lastException) {
            let lastException = new ProviderNotFoundException(sprintf("No Authentication Provider found for token of class %s.", get_class(token)));
        }
        if (null !== this->eventDispatcher) {
            //this->eventDispatcher->dispatch(AuthenticationEvents::AUTHENTICATION_FAILURE, new AuthenticationFailureEvent(token, lastException));
        }
        lastException->setToken(token);
        throw lastException;
    }
}
