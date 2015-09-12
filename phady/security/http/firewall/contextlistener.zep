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
use Phady\Security\Core\Authentication\Token\TokenInterface;
use Phady\Security\Core\Authentication\Token\AnonymousToken;
use Phady\Security\Core\User\UserInterface;
use Phady\Security\Core\Exception\UnsupportedUserException;
use Phady\Security\Core\User\UserProviderInterface;

/**
  * @class Phady\Security\Http\Firewall\ContextListener
  *
  * @author  Alien Fernández Fuentes <alienfernandez85@gmail.com>
  * @package Core
  * @copyright (c) 2015
  * @version 1.0.0
  */
class ContextListener extends \Phalcon\Di\Injectable implements ListenerInterface
{
    private tokenStorage;
    private contextKey;
    private sessionKey;
    private logger;
    private userProviders;
    private dispatcher;
    private registered;

    //TokenStorageInterface tokenStorage,
    public function __construct(contextKey, array userProviders)
    {
        var userProvider;
        if (empty(contextKey)) {
            throw new \InvalidArgumentException("contextKey must not be empty.");
        }
        for userProvider in userProviders {
            if (!(userProvider instanceof UserProviderInterface)) {
                throw new \InvalidArgumentException(sprintf("User provider %s must implement Phady//Security\\Core\\User\\UserProviderInterface", get_class(userProvider)));
            }
        }

        //this->tokenStorage = tokenStorage;
        let this->userProviders = userProviders;
        let this->contextKey = contextKey;
        let this->sessionKey = "_security_".contextKey;
        //this->logger = logger;
        //this->dispatcher = dispatcher;
    }

    /**
     * Reads the Security Token from the session.
     *
     */
    public function handle()
    {
        let this->tokenStorage = this->getDI()->get("security.token_storage");
        var request, session, token;
        let request = this->getDI()->get("request");
        let session = this->getDI()->get("session");

        //}

        let token = session->get(this->sessionKey);

        if (null === session || null === token) {
            this->tokenStorage->setToken(null);
            //this->getDI()->remove("security.token_storage");
            //this->getDI()->setShared("security.token_storage", this->tokenStorage);
            //session->remove(this->sessionKey);
            return;
        }

        let token = unserialize(token);

        /*if (null !== this->logger) {
            this->logger->debug("Read existing security token from the session.", array("key" => this->sessionKey));
        }*/

        if (token instanceof TokenInterface) {
            //let token = this->refreshUser(token);
        } elseif (null !== token) {
            /*if (null !== this->logger) {
                this->logger->warning("Expected a security token from the session, got something else.", array("key" => this->sessionKey, "received" => token));
            }*/

            let token = null;
        }

        this->tokenStorage->setToken(token);
        this->getDI()->remove("security.token_storage");
        this->getDI()->setShared("security.token_storage", this->tokenStorage);

    }

    /**
     * Writes the security token into the session.
     *
     */
    public function afterLoginSuccess(event, myComponent, token)
    {
        var session;
        let session = this->getDI()->get("session");

        //let token = this->tokenStorage->getToken();

        if ((null === token) || (token instanceof AnonymousToken)) {
            session->remove(this->sessionKey);
        } else {
            session->set(this->sessionKey, serialize(token));
            /*if (null !== this->logger) {
                this->logger->debug("Stored the security token in the session.", array("key" => this->sessionKey));
            }*/
        }
    }

    /**
     * Refreshes the user by reloading it from the user provider.
     *
     * @param TokenInterface token
     *
     * @return TokenInterface|null
     *
     * @throws \RuntimeException
     */
    protected function refreshUser(<TokenInterface> token)
    {
        var user, refreshedUser, provider, e;
        let user = token->getUser();
        if (!(user instanceof UserInterface)) {
            return token;
        }

        for provider in this->userProviders {
            try {
                let refreshedUser = provider->refreshUser(user);
                token->setUser(refreshedUser);

                /*
                if (null !== this->logger) {
                    this->logger->debug("User was reloaded from a user provider.", array("username" => refreshedUser->getUsername(), "provider" => get_class(provider)));
                }*/

                return token;
            } catch UnsupportedUserException, e {
                // let"s try the next user provider
            } catch UsernameNotFoundException, e {
                /*
                if (null !== this->logger) {
                    this->logger->warning("Username could not be found in the selected user provider.", array("username" => e->getUsername(), "provider" => get_class(provider)));
                }*/

                return;
            }
        }

        throw new \RuntimeException(sprintf("There is no user provider for user %s.", get_class(user)));
    }
}
