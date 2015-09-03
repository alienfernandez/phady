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

namespace Phady\Security\Core\User;

use Phady\Security\Core\User\UserProviderInterface;
use Phady\Security\Core\User\UserInterface;
use Phady\Security\Core\User\User as UserCore;
use Phady\Security\Core\Exception\UsernameNotFoundException;
use Phady\Security\Core\Exception\UnsupportedUserException;

/**
  * @class Phady\Security\Core\User\InMemoryUserProvider
  *
  * @author  Alien Fernández Fuentes <alienfernandez85@gmail.com>
  * @package Core
  * @copyright (c) 2015
  * @version 1.0.0
  */
class ChainUserProvider implements UserProviderInterface
{
   private providers;

   public function __construct(array providers)
   {
       let this->providers = providers;
   }

   /**
    * @return array
    */
   public function getProviders()
   {
       return this->providers;
   }

   /**
    * {@inheritdoc}
    */
   public function loadUserByUsername(username)
   {
        var provider, e, ex;
        for provider in this->providers {
           try {
               return provider->loadUserByUsername(username);
           } catch \Phady\Security\Core\Exception\UsernameNotFoundException, e {
               // try next one
           }
       }

       let ex = new UsernameNotFoundException(sprintf("There is no user with name %s.", username));
       ex->setUsername(username);
       throw ex;
   }

   /**
    * {@inheritdoc}
    */
   public function refreshUser(<UserInterface> user)
   {
       var supportedUserFound, provider, e, ex;
       let supportedUserFound = false;

        for provider in this->providers {
           try {
               return provider->refreshUser(user);
           } catch UnsupportedUserException, e {
               // try next one
           } catch UsernameNotFoundException, e {
               let supportedUserFound = true;
               // try next one
           }
       }

       if (supportedUserFound) {
           let e = new UsernameNotFoundException(sprintf("There is no user with name %s.", user->getUsername()));
           e->setUsername(user->getUsername());
           throw e;
       } else {
           throw new UnsupportedUserException(sprintf("The account %s is not supported.", get_class(user)));
       }
   }

   /**
    * {@inheritdoc}
    */
   public function supportsClass(supportsClass)
   {
        var provider;
        for provider in this->providers {
           if (provider->supportsClass(supportsClass)) {
               return true;
           }
       }

       return false;
   }
}