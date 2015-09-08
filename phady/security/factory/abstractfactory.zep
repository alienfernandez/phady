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
abstract class AbstractFactory extends Injectable implements SecurityFactoryInterface
{
   protected options = [
        "check_path" : "/login_check",
        "use_forward" : false,
        "require_previous_session" : true
    ];

    protected defaultSuccessHandlerOptions = [
        "always_use_default_target_path" : false,
        "default_target_path" : "/",
        "login_path" : "/login",
        "target_path_parameter" : "_target_path",
        "use_referer" : false
    ];

    protected defaultFailureHandlerOptions = [
        "failure_path" : null,
        "failure_forward" : false,
        "login_path" : "/login",
        "failure_path_parameter" : "_failure_path"
    ];

    public function create(id, config, userProviderId, defaultEntryPointId)
    {
        var authProviderId, listenerId, entryPointId;
        // authentication provider
        let authProviderId = this->createAuthProvider(id, config, userProviderId);

        // authentication listener
        let listenerId = this->createListener(id, config, userProviderId);

        // add remember-me aware tag if requested
        /*
        if (this->isRememberMeAware(config)) {
            container
                ->getDefinition(listenerId)
                ->addTag("security.remember_me_aware", ["id" : id, "provider" : userProviderId))
            ;
        }*/

        // create entry point if applicable (optional)
        let entryPointId = this->createEntryPoint(id, config, defaultEntryPointId);

        return [authProviderId, listenerId, entryPointId];
    }

    final public function addOption(name, defaultOption = null)
    {
        let this->options[name] = defaultOption;
    }

    /**
     * Subclasses must return the id of a service which implements the
     * AuthenticationProviderInterface.
     *
     * @param string           id             The unique id of the firewall
     * @param array            config         The options array for this listener
     * @param string           userProviderId The id of the user provider
     *
     * @return string never null, the id of the authentication provider
     */
    abstract protected function createAuthProvider(id, config, userProviderId);

    /**
     * Subclasses must return the id of the abstract listener template.
     *
     * Listener definitions should inherit from the AbstractAuthenticationListener
     * like this:
     *
     *    <service id="my.listener.id"
     *             class="My\Concrete\Classname"
     *             parent="security.authentication.listener.abstract"
     *             abstract="true" />
     *
     * In the above case, this method would return "my.listener.id".
     *
     * @return string
     */
    abstract protected function getListenerId();

    /**
     * Subclasses may create an entry point of their as they see fit. The
     * default implementation does not change the default entry point.
     *
     * @param ContainerBuilder container
     * @param string           id
     * @param array            config
     * @param string           defaultEntryPointId
     *
     * @return string the entry point id
     */
    protected function createEntryPoint(id, config, defaultEntryPointId)
    {
        return defaultEntryPointId;
    }

    /**
     * Subclasses may disable remember-me features for the listener, by
     * always returning false from this method.
     *
     * @param array config
     *
     * @return bool Whether a possibly configured RememberMeServices should be set for this listener
     */
    protected function isRememberMeAware(config)
    {
        return config["remember_me"];
    }

    protected function createListener(id, config, userProvider)
    {
        /*
        let listenerId = this->getListenerId();
        listener = new DefinitionDecorator(listenerId);
        listener->replaceArgument(4, id);
        listener->replaceArgument(5, new Reference(this->createAuthenticationSuccessHandler(container, id, config)));
        listener->replaceArgument(6, new Reference(this->createAuthenticationFailureHandler(container, id, config)));
        listener->replaceArgument(7, array_intersect_key(config, this->options));

        listenerId .= ".".id;
        container->setDefinition(listenerId, listener);

        return listenerId;*/
    }

    protected function createAuthenticationSuccessHandler(id, config)
    {
        /*
        successHandlerId = this->getSuccessHandlerId(id);
        options = array_intersect_key(config, this->defaultSuccessHandlerOptions);

        if (isset(config["success_handler"])) {
            successHandler = container->setDefinition(successHandlerId, new DefinitionDecorator("security.authentication.custom_success_handler"));
            successHandler->replaceArgument(0, new Reference(config["success_handler"]));
            successHandler->replaceArgument(1, options);
            successHandler->replaceArgument(2, id);
        } else {
            successHandler = container->setDefinition(successHandlerId, new DefinitionDecorator("security.authentication.success_handler"));
            successHandler->addMethodCall("setOptions", array(options));
            successHandler->addMethodCall("setProviderKey", array(id));
        }

        return successHandlerId;*/
    }

    protected function createAuthenticationFailureHandler(id, config)
    {
        /*
        id = this->getFailureHandlerId(id);
        options = array_intersect_key(config, this->defaultFailureHandlerOptions);

        if (isset(config["failure_handler"])) {
            failureHandler = container->setDefinition(id, new DefinitionDecorator("security.authentication.custom_failure_handler"));
            failureHandler->replaceArgument(0, new Reference(config["failure_handler"]));
            failureHandler->replaceArgument(1, options);
        } else {
            failureHandler = container->setDefinition(id, new DefinitionDecorator("security.authentication.failure_handler"));
            failureHandler->addMethodCall("setOptions", array(options));
        }

        return id;*/
    }

    protected function getSuccessHandlerId(id)
    {
        return "security.authentication.success_handler.".id.".".str_replace("-", "_", this->getKey());
    }

    protected function getFailureHandlerId(id)
    {
        return "security.authentication.failure_handler.".id.".".str_replace("-", "_", this->getKey());
    }
}
