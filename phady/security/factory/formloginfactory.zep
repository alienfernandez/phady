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
  * @class Phady\Security\Factory\AbstractFactory
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
        var provider;
        let provider = "security.authentication.provider.dao.".id;
        /*this->container->set(provider, function (config) {
            var userProvider, container;
            let container = _SERVER["containerApp"];
            let userProvider = new \Phady\Security\Core\User\InMemoryUserProvider(config["users"]);
            return new \Phady\Security\Core\Authentication\Provider\DaoAuthenticationProvider(userProvider,
                        new \Phady\Security\Core\User\UserChecker(), "key",
                        _SERVER["security.encoder_factory.generic"]);
        });*/

        /*
        container
            ->setDefinition(provider, new DefinitionDecorator("security.authentication.provider.dao"))
            ->replaceArgument(0, new Reference(userProviderId))
            ->replaceArgument(2, id)
        ;*/

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

    protected function createEntryPoint(container, id, config, defaultEntryPoint)
    {
        /*
        entryPointId = "security.authentication.form_entry_point.".id;
        container
            ->setDefinition(entryPointId, new DefinitionDecorator("security.authentication.form_entry_point"))
            ->addArgument(new Reference("security.http_utils"))
            ->addArgument(config["login_path"])
            ->addArgument(config["use_forward"])
        ;

        return entryPointId;*/
    }
}
