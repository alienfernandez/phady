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

namespace Phady\Security\Factory;

use Phalcon\Di\Injectable;
use Phady\Security\Factory\SecurityFactoryInterface;

/**
  * @class Phady\Security\Factory\FormLoginFactory
  *
  * AbstractFactory is the base class for all classes inheriting from
  * AbstractAuthenticationListener.
  * @author  Alien Fernández Fuentes <alienfernandez85@gmail.com>
  * @package Core
  * @copyright (c) 2015
  * @version 1.0.0
  */
class FormLoginFactory extends AbstractFactory
{
    public function __construct()
    {
        this->addOption("username_parameter", "_username");
        this->addOption("password_parameter", "_password");
        this->addOption("csrf_parameter", "_csrf_token");
        this->addOption("intention", "authenticate");
        this->addOption("post_only", true);
    }

    public function getPosition()
    {
        return "form";
    }

    public function getKey()
    {
        return "form-login";
    }

    protected function getListenerId()
    {
        return "security.authentication.listener.form";
    }

    protected function createAuthProvider(id, config, userProviderId)
    {
        var provider, providerFunc, args;
        let provider = "security.authentication.provider.dao.".id;
        let args = ["id" : id, "config" : config, "userProviderId" : userProviderId, "container" : this->getDI()];
        let providerFunc = call_user_func_array(function(id, config, userProviderId, container) {
             var authProvider;
             let authProvider = new \Phady\Security\Core\Authentication\Provider\DaoAuthenticationProvider(
                    container->get(userProviderId), new \Phady\Security\Core\User\UserChecker(), id,
                    container->get("security.encoder_factory.generic")
              );
             return authProvider;
        }, args);
        this->getDI()->set(provider, providerFunc);
        return provider;
    }

    protected function createListener(id, config, userProvider)
    {
        var listenerId;
        let listenerId = parent::createListener(id, config, userProvider);
        /*
        container
            ->getDefinition(listenerId)
            ->addArgument(isset(config["csrf_provider"]) ? new Reference(config["csrf_provider"]) : null)
        ;*/

        return listenerId;
    }

    protected function createEntryPoint(id, config, defaultEntryPoint)
    {
        var entryPointId, entryPointFunc, args;
        let entryPointId = "security.authentication.form_entry_point.".id;
        let args = ["config" : config];
        let entryPointFunc = call_user_func_array(function(config) {
            var use_forward;
            let use_forward = (array_key_exists("use_forward", config) && isset(config["use_forward"])) ? config["use_forward"] : "";
             return new \Phady\Security\Http\EntryPoint\FormAuthenticationEntryPoint(config["login_path"], use_forward);
        }, args);
        this->getDI()->set(entryPointId, entryPointFunc);

        return entryPointId;
    }
}
