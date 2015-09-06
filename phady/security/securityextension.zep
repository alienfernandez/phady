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

namespace Phady\Security;

use Phalcon\Events\Event;
use Phalcon\Di\Injectable;
use Phady\Security\Core\User\Factory\UserProviderFactoryInterface;
use Phady\Security\Core\User\Factory\InMemoryFactory;
use Phady\Security\Core\User\Factory\EntityFactory;

/**
  * @class Phady\Security\SecurityExtension
  *
  * @author  Alien Fernández Fuentes <alienfernandez85@gmail.com>
  * @package Core
  * @copyright (c) 2015
  * @version 1.0.0
  */
class SecurityExtension extends \Phalcon\Di\Injectable
{

    private requestMatchers = [];
    private listenerPositions = ["pre_auth", "form", "http", "remember_me"];
    private factories = [];
    private userProviderFactories = [];
    private container;

    public function __construct()
    {
        let this->container = this->getDI();
        var position;
        for position in this->listenerPositions {
            let this->factories[position] = [];
        }

        //TODO change _SERVER["securityConfigApp"]
        this->loadSecurityConfig(_SERVER["securityConfigApp"]["security"]);
    }

    public function loadSecurityConfig(array config)
    {

        if (array_key_exists("encoders", config) && config["encoders"]) {
            this->createEncoders(config["encoders"]);
        }
        //Add factories user providers "InMemoryFactory" y ""
        this->addUserProviderFactory(new InMemoryFactory());
        this->addUserProviderFactory(new EntityFactory("entity", "phalcon.orm.security.user.provider"));
        this->createFirewalls(config);
        //this->createAuthorization(config, container);
        //this->createRoleHierarchy(config, container);

    }

    private function createEncoders(encoders)
    {
        var encoderMap, classEncoder, encoder;
        let encoderMap = [];
        for classEncoder, encoder in encoders {
            let encoderMap[classEncoder] = this->createEncoder(encoder);
        }

        let _SERVER["security.encoder_factory.generic"] = new \Phady\Security\Core\Encoder\EncoderFactory(encoderMap);
        this->container->set("security.encoder_factory.generic", function (encoderMap) {
            print_r(encoderMap);
            return new \Phady\Security\Core\Encoder\EncoderFactory(encoderMap);
         });
    }

    private function createEncoder(array config)
    {
        // a custom encoder service
        /*
        if (isset(config["id"])) {
            return new Reference(config["id"]);
        }*/

        // plaintext encoder
        //if ("plaintext" === config["algorithm"]) {
            this->container->set("security.encoder.plain.class", function () {
                return new \Phady\Security\Core\Encoder\PlaintextPasswordEncoder(false);
             });
            return this->container->get("security.encoder.plain.class");
        //}

        // bcrypt encoder
        if ("bcrypt" === config["algorithm"]) {
            this->container->set("security.encoder.bcrypt.class", function (config) {
                return new \Phady\Security\Core\Encoder\BCryptPasswordEncoder(config["cost"]);
             });
            return this->container->get("security.encoder.bcrypt.class");
        }
    }
    
    private function createFirewalls(config)
    {
        var providerIds;
        /*if (!isset(config["firewalls"])) {
            return;
        }*/

        //let firewalls = config["firewalls"];
        let providerIds = this->createUserProviders(config);
        //return firewalls;
        /*
        // make the ContextListener aware of the configured user providers
        definition = container->getDefinition("security.context_listener");
        arguments = definition->getArguments();
        userProviders = [];
        foreach (providerIds as userProviderId) {
            userProviders[] = new Reference(userProviderId);
        }
        arguments[1] = userProviders;
        definition->setArguments(arguments);

        // load firewall map
        mapDef = container->getDefinition("security.firewall.map");
        map = authenticationProviders = [];
        foreach (firewalls as name => firewall) {
            list(matcher, listeners, exceptionListener) = this->createFirewall(container, name, firewall, authenticationProviders, providerIds);

            contextId = "security.firewall.map.context.".name;
            context = container->setDefinition(contextId, new DefinitionDecorator("security.firewall.context"));
            context
                ->replaceArgument(0, listeners)
                ->replaceArgument(1, exceptionListener)
            ;
            map[contextId] = matcher;
        }
        mapDef->replaceArgument(1, map);

        // add authentication providers to authentication manager
        authenticationProviders = array_map(function (id) {
            return new Reference(id);
        }, array_values(array_unique(authenticationProviders)));
        container
            ->getDefinition("security.authentication.manager")
            ->replaceArgument(0, authenticationProviders)
        ;*/
    }

    // Parses user providers and returns an array of their ids
    private function createUserProviders(array config)
    {
        var providerIds, providersList, name, provider, arrReturn, containerApp, registry;
        let providerIds = [];
        let providersList = [];
        for name, provider in config["providers"] {
            let arrReturn = this->createUserDaoProvider(name, provider);
            if (arrReturn){
                let providerIds[] = arrReturn["name"];
                let providersList[] = this->container->get(arrReturn["name"], [provider[arrReturn["key"]]]);
            }
        }
        //Register component security.authentication.manager
        //let this->container["security.authentication.manager"] = new \Phady\Security\Core\Authentication\AuthenticationProviderManager(providersList);
        //TODO delete _SERVER
        let _SERVER["security.authentication.manager"] = new \Phady\Security\Core\Authentication\AuthenticationProviderManager(providersList);
        //Register component login manager service
        this->container->set("security.authentication.listener.form", function () {
            var container, listenForm;
            let container = _SERVER["containerApp"];

            let listenForm = new \Phady\Security\Http\Firewall\UsernamePasswordFormAuthenticationListener(
                    container->get("security.token_storage"), _SERVER["security.authentication.manager"],
                    "key", container->get("security.authentication.success_handler"), container->get("security.authentication.failure_handler"),
                    [], null);
            return listenForm;
        });

        return providerIds;
    }
    
    // Parses a <provider> tag and returns the id for the related user provider service
    private function createUserDaoProvider(name, provider)
    {
        var factory, key;
        array arrReturn = [];
        let name = this->getUserProviderId(strtolower(name));

        // Doctrine Entity and In-memory DAO provider are managed by factories
        for factory in this->userProviderFactories {
            let key = str_replace("-", "_", factory->getKey());
            if (!empty(provider[key])) {
                factory->create(name, provider[key]);
                let arrReturn["name"] = name;
                let arrReturn["key"] = key;
                return arrReturn;
            }
        }

        // Chain provider
        /*
        if (isset(provider["chain"])) {
            let providers = [];
            for providerName in provider["chain"]["providers"] {
                var providerId;
                let providerId = this->getUserProviderId(strtolower(providerName));
                this->container->set(providerId, function (config) {
                    return new \Phady\Security\Core\User\ChainUserProvider();
                 });
                let providers[] = ;
            }

            this->container->set("security.user.provider.chain", function (config) {
                return new \Phady\Security\Core\User\ChainUserProvider();
             });
            return this->container->get("security.encoder.bcrypt.class");

            container
                ->setDefinition(name, new DefinitionDecorator("security.user.provider.chain"))
                ->addArgument(providers);

            return name;
        }*/

        throw new InvalidConfigurationException(sprintf("Unable to create definition for %s user provider", name));
    }

    private function getUserProviderId(name)
    {
        return "security.user.provider.concrete.".name;
    }


    public function addUserProviderFactory(<UserProviderFactoryInterface> factory)
    {
        let this->userProviderFactories[] = factory;
    }
}
