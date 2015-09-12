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
use Phady\Security\Factory\FormLoginFactory;

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
    private authenticationProviders;
    private contextListeners = [];

    public function __construct()
    {
        var securityConfig;
        let this->container = this->getDI();
        let this->authenticationProviders = [];
        var position;
        for position in this->listenerPositions {
            let this->factories[position] = [];
        }

        let securityConfig = this->getDI()->get("parameters")->security;
        this->loadSecurityConfig(securityConfig);
    }

    public function loadSecurityConfig(array config)
    {

        if (array_key_exists("encoders", config) && config["encoders"]) {
            this->createEncoders(config["encoders"]);
        }
        //Add factories user providers "InMemoryFactory" y ""
        //this->addUserProviderFactory(new InMemoryFactory());
        this->addUserProviderFactory(new EntityFactory("entity", "phalcon.orm.security.user.provider"));

        this->addSecurityListenerFactory(new FormLoginFactory());

        this->createEntryPoint(config);
        this->createFirewalls(config);
        this->createAuthorization(config);
        this->createRoleHierarchy(config);

    }

    private function createEntryPoint(config)
    {
        var login_path;
        let login_path = "/login";
        // Channel listener
        var argsEntryPoint, entryPointFunc;
        let argsEntryPoint = ["login_path" : login_path];
        let entryPointFunc = call_user_func_array(function(login_path) {
             return new \Phady\Security\Http\EntryPoint\FormAuthenticationEntryPoint(login_path, false);
        }, argsEntryPoint);
        this->container->set("security.authentication.form_entry_point", entryPointFunc);
    }

    private function createEncoders(encoders)
    {
        var encoderMap, classEncoder, encoder, args, encFactoryFunc;
        let encoderMap = [];
        for classEncoder, encoder in encoders {
            let encoderMap[classEncoder] = this->createEncoder(encoder);
        }

        let args = ["encoderMap" : encoderMap];
        let encFactoryFunc = call_user_func_array(function(encoderMap) {
             return new \Phady\Security\Core\Encoder\EncoderFactory(encoderMap);
        }, args);
        this->container->set("security.encoder_factory.generic", encFactoryFunc);
    }

    private function createEncoder(array config)
    {
        var args, userFunc;
        // a custom encoder service
        /*
        if (isset(config["id"])) {
            return new Reference(config["id"]);
        }*/

        // bcrypt encoder
        if (array_key_exists("algorithm", config) && "bcrypt" === config["algorithm"]) {
            let args = ["config" : config];
            let userFunc = call_user_func_array(function(config) {
                 return new \Phady\Security\Core\Encoder\BCryptPasswordEncoder(config["cost"]);
            }, args);
            this->container->set("security.encoder.bcrypt.class", userFunc);
            return this->container->get("security.encoder.bcrypt.class");
        }

        // plaintext encoder
        //if ("plaintext" === config["algorithm"]) {
            this->container->set("security.encoder.plain.class", function () {
                return new \Phady\Security\Core\Encoder\PlaintextPasswordEncoder(false);
             });
            return this->container->get("security.encoder.plain.class");
        //}

    }


    private function createAuthorization(config)
    {
        var access, matcher, attributes, requires_channel, args, userFuncAccessMap;
        if (!config["access_control"]) {
            return;
        }

        for access in config["access_control"] {
            let matcher = this->createRequestMatcher(
                (array_key_exists("path", access)) ? access["path"] : "",
                (array_key_exists("host", access)) ? access["host"] : "",
                (array_key_exists("methods", access)) ? access["methods"] : "",
                (array_key_exists("ips", access)) ? access["ips"] : ""
            );

            let attributes = access["roles"];

            /*if (access["allow_if"]) {
                attributes[] = this->createExpression(container, access["allow_if"]);
            }*/
            let requires_channel = (array_key_exists("requires_channel", access)) ? access["requires_channel"] : null;

            let args = ["matcher" : matcher, "attributes" : attributes, "requires_channel" : requires_channel];
            let userFuncAccessMap = call_user_func_array(function(matcher, attributes, requires_channel) {
                 var access_Map;
                 let access_Map = new \Phady\Security\Http\AccessMap();
                 access_Map->add(matcher, attributes, requires_channel);
                 return access_Map;
            }, args);
            this->container->set("security.access_map", userFuncAccessMap);
        }
    }

    private function createRequestMatcher(path = null, host = null, methods = [], ip = null, array attributes = [])
    {
        var serialized, id, arguments;
        if (methods) {
            let methods = array_map("strtoupper", (array) methods);
        }

        let serialized = serialize([path, host, methods, ip, attributes]);
        let id = "security.request_matcher.".md5(serialized).sha1(serialized);

        if (isset(this->requestMatchers[id])) {
            return this->requestMatchers[id];
        }

        // only add arguments that are necessary
        /*while (count(arguments) > 0 && !end(arguments)) {
            array_pop(arguments);
        }*/

        var args, userFunc;
        let args = ["path" : path, "host" : host, "methods" : methods, "ip" : ip,
                    "attributes" : attributes, "schemes" : null];
        let userFunc = call_user_func_array(function(path, host, methods, ip, attributes, schemes) {
             return new \Phady\Http\RequestMatcher(path, host, methods, ip, attributes, schemes);
        }, args);
        this->container->set(id, userFunc);

        //"security.matcher.class"
        let this->requestMatchers[id] = this->container->get(id);
        return this->requestMatchers[id];
    }

    
    private function createFirewalls(config)
    {
        var providerIds, userProviderId, map, firewalls, userProviders;
        if (!isset(config["firewalls"])) {
            return;
        }

        let firewalls = config["firewalls"];
        let providerIds = this->createUserProviders(config);
        let userProviders = [];
        for userProviderId in providerIds {
            let userProviders[] = this->container->get(userProviderId);
        }

        // load firewall map
        let map = [];
        let this->authenticationProviders = [];
        var contextId, name, firewall, newFirewall, listeners, exceptionListener;
        for name, firewall in firewalls {
            //list(matcher, listeners, exceptionListener) = this->createFirewall(name, firewall, providerIds);
            let newFirewall = this->createFirewall(name, firewall, providerIds, userProviders);

            let contextId = "security.firewall.map.context.".name;
            let listeners = newFirewall[1];
            let exceptionListener = newFirewall[2];

            var args, userFunc;
            let args = ["listeners" : listeners, "exceptionListener" : exceptionListener];
            let userFunc = call_user_func_array(function(listeners, exceptionListener) {
                 return new \Phady\Security\FirewallContext(listeners, exceptionListener);
            }, args);
            this->container->set(contextId, userFunc);
            //let map[contextId] = matcher;
            let map[contextId] = newFirewall[0];
        }

        var firewallMapFunc, argsFM;
        let argsFM = ["container" : this->container, "map" : map];
        let firewallMapFunc = call_user_func_array(function(container, map) {
             return new \Phady\Security\FirewallMap(container, map);
        }, argsFM);
        this->container->set("security.firewall.map", firewallMapFunc);

        if (this->container->has("security.firewall")){
            //this->container->get("security.firewall")->setMap(this->container->get("security.firewall.map"));
        }
        //echo "<pre>"; print_r(this->container->get("security.firewall"));die();
        //map:Phady\Security\Firewall:private

        // add authentication providers to authentication manager
        var key, authProvider;
        array authenticationProvidersRef = [];
        for key, authProvider in this->authenticationProviders {
            let authenticationProvidersRef[key] = this->container->get(authProvider);
        }

        var authManagerFunc, argsManagerFunc;
        //Register component security.authentication.manager
        this->container->remove("security.authentication.manager");
        let argsManagerFunc = ["authenticationProvidersRef" : authenticationProvidersRef];
        let authManagerFunc = call_user_func_array(function(authenticationProvidersRef) {
             return new \Phady\Security\Core\Authentication\AuthenticationProviderManager(authenticationProvidersRef);
        }, argsManagerFunc);
        this->container->set("security.authentication.manager", authManagerFunc);
        //echo "<pre>"; print_r(this->container->get("security.authentication.manager"));die();

    }


    private function createFirewall(id, firewall, providerIds, userProviders)
    {
        var matcher, pattern, host, methods, listeners, defaultProvider, contextKey, configuredEntryPoint, createAuthListeners, exceptionListener;
        // Matcher
        let matcher = null;
        if (isset(firewall["request_matcher"])) {
            let matcher = firewall["request_matcher"];
        } elseif (isset(firewall["pattern"]) || isset(firewall["host"])) {
            let pattern = isset(firewall["pattern"]) ? firewall["pattern"] : null;
            let host = isset(firewall["host"]) ? firewall["host"] : null;
            let methods = isset(firewall["methods"]) ? firewall["methods"] : [];
            let matcher = this->createRequestMatcher(pattern, host, methods);
        }

        // Security disabled?
        if (array_key_exists("security", firewall) && false === firewall["security"]) {
            return [matcher, [], null];
        }

        // Provider id (take the first registered provider if none defined)
        if (isset(firewall["provider"])) {
            let defaultProvider = this->getUserProviderId(firewall["provider"]);
        } else {
            let defaultProvider = reset(providerIds);
        }

        // Register listeners
        let listeners = [];

        var argsChannel, channelFunc;
        let argsChannel = ["container" : this->container];
        let channelFunc = call_user_func_array(function(container) {
             return new \Phady\Security\Http\Firewall\ChannelListener(
                container->get("security.authentication.form_entry_point")
             );
        }, argsChannel);
        this->container->set("security.channel_listener", channelFunc);

        let listeners[] = "security.channel_listener";

        // Context serializer listener
        if (!array_key_exists("stateless", firewall) || false === firewall["stateless"]) {
            let contextKey = id;
            if (array_key_exists("context", firewall) && isset(firewall["context"])) {
                let contextKey = firewall["context"];
            }

            let listeners[] = this->createContextListener(contextKey, userProviders);
        }

        // Determine default entry point
        let configuredEntryPoint = isset(firewall["entry_point"]) ? firewall["entry_point"] : null;

        // Authentication listeners
        //list(authListeners, defaultEntryPoint) = this->createAuthenticationListeners(id, firewall, authenticationProviders, defaultProvider, configuredEntryPoint);
        let createAuthListeners = this->createAuthenticationListeners(id, firewall, defaultProvider, configuredEntryPoint);

        let listeners = array_merge(listeners, createAuthListeners[0]);

        //security.access.decision_manager
        var argsAccessMng, accessMngFunc;
        let argsAccessMng = ["container" : this->container];
        let accessMngFunc = call_user_func_array(function(container) {
             return new \Phady\Security\Core\Authorization\AccessDecisionManager(
               [container->get("security.access.simple_role_voter")]
             );
        }, argsAccessMng);
        this->container->set("security.access.decision_manager", accessMngFunc);

        // Access listener
        var args, userFunc;
        let args = ["container" : this->container];
        let userFunc = call_user_func_array(function(container) {
             return new \Phady\Security\Http\Firewall\AccessListener(
                container->get("security.token_storage"),
                container->get("security.access.decision_manager")
             );
        }, args);
        this->container->setShared("security.access_listener", userFunc);

        //security.access.role_hierarchy_voter
        let listeners[] = "security.access_listener";

        // Exception listener
        let exceptionListener = this->createExceptionListener(firewall, id, (configuredEntryPoint) ? configuredEntryPoint : createAuthListeners[1],
            (array_key_exists("stateless", firewall) && isset(firewall["stateless"])) ? firewall["stateless"] : "");

        return [matcher, listeners, exceptionListener];
    }

    private function createContextListener(contextKey, userProviders)
    {
        var listenerId;
        if (isset(this->contextListeners[contextKey])) {
            return this->contextListeners[contextKey];
        }

        let listenerId = "security.context_listener." . count(this->contextListeners);

        var args, userFunc;
        let args = ["contextKey" : contextKey, "userProviders" : userProviders];
        let userFunc = call_user_func_array(function(contextKey, userProviders) {
             return new \Phady\Security\Http\Firewall\ContextListener(contextKey, userProviders);
        }, args);
        this->container->setShared(listenerId, userFunc);
        let this->contextListeners[contextKey] = listenerId;
        return this->contextListeners[contextKey];
    }

    private function createExceptionListener(config, id, defaultEntryPoint, stateless)
    {
        var exceptionListenerId;
        let exceptionListenerId = "security.exception_listener.".id;
        var args, userFunc;
        let args = ["config" : config, "id" : id, "defaultEntryPoint" : defaultEntryPoint, "stateless" : stateless,
                    "container" : this->container];
        let userFunc = call_user_func_array(function(config, id, defaultEntryPoint, stateless, container) {
             return new \Phady\Security\Http\Firewall\ExceptionListener(
                container->get("security.token_storage"), null, id,
                null === defaultEntryPoint ? null : container->get(defaultEntryPoint),
                null,
                (array_key_exists("access_denied_handler", config) && isset(config["access_denied_handler"])) ? config["access_denied_url"] : null,
                stateless
             );
        }, args);
        this->container->set(exceptionListenerId, userFunc);


        if (this->container->has("dispatcher")) {
            if (this->container->get("dispatcher")->getEventsManager()) {
                 //this->container->get("dispatcher")->getEventsManager()->attach("dispatch:beforeException", this->container->get(exceptionListenerId));
            }
        }


        return exceptionListenerId;
    }

    // Parses user providers and returns an array of their ids
    private function createUserProviders(array config)
    {
        var providerIds, name, provider, id;
        let providerIds = [];
        for name, provider in config["providers"] {
            let id = this->createUserDaoProvider(name, provider);
            let providerIds[] = id;
        }
        return providerIds;
    }

    /**
     * Loads the web configuration.
     *
     * @param array            config    An array of configuration settings
     */
    private function createRoleHierarchy(config)
    {
        if (array_key_exists("role_hierarchy", config) && !isset(config["role_hierarchy"])) {
            this->container->remove("security.access.role_hierarchy_voter");
            return;
        }

        //container->setParameter("security.role_hierarchy.roles", config["role_hierarchy"]);
        this->container->remove("security.access.simple_role_voter");
    }

    private function createAuthenticationListeners(id, firewall, defaultProvider, defaultEntryPoint)
    {
        var listeners, hasListeners, position, factory, key, userProvider, provider, listenerId, createFactory;
        let listeners = [];
        let hasListeners = false;

        for position in this->listenerPositions {
            for factory in this->factories[position] {
                let key = str_replace("-", "_", factory->getKey());
                if (array_key_exists(key, firewall) && isset(firewall[key])) {
                    let userProvider = (array_key_exists("provider", firewall[key]) && isset(firewall[key]["provider"])) ? this->getUserProviderId(firewall[key]["provider"]) : defaultProvider;

                    //list(provider, listenerId, defaultEntryPoint) = factory->create(id, firewall[key], userProvider, defaultEntryPoint);
                    let createFactory = factory->create(id, firewall[key], userProvider, defaultEntryPoint);

                    let listeners[] = createFactory[1];
                    let this->authenticationProviders[] = createFactory[0];
                    let hasListeners = true;
                    let defaultEntryPoint = createFactory[2];
                }
            }
        }



        // Anonymous
        if (isset(firewall["anonymous"])) {
            //Auth listener
            let listenerId = "security.authentication.listener.anonymous.".id;
            var args, userFunc;
            let args = ["id" : firewall["anonymous"]["key"], "container" : this->container];
            let userFunc = call_user_func_array(function(id, container) {
                 return new \Phady\Security\Http\Firewall\AnonymousAuthenticationListener(
                    container->get("security.token_storage"), id
                 );
            }, args);
            this->container->set(listenerId, userFunc);

            let listeners[] = listenerId;

            //Auth provider
            var providerId, argsProvider, providerFunc;
            let providerId = "security.authentication.provider.anonymous.".id;
            let argsProvider = ["id" : firewall["anonymous"]["key"]];
            let providerFunc = call_user_func_array(function(id, container) {
                 return new \Phady\Security\Core\Authentication\Provider\AnonymousAuthenticationProvider(id);
            }, argsProvider);
            this->container->set(providerId, providerFunc);

            let this->authenticationProviders[] = providerId;
            let hasListeners = true;
        }

        if (!hasListeners) {
            throw new InvalidConfigurationException(sprintf("No authentication listener registered for firewall %s.", id));
        }

        return [listeners, defaultEntryPoint];
    }

    
    // Parses a <provider> tag and returns the id for the related user provider service
    private function createUserDaoProvider(name, provider)
    {
        var factory, key;
        let name = this->getUserProviderId(strtolower(name));

        // Doctrine Entity and In-memory DAO provider are managed by factories
        for factory in this->userProviderFactories {
            let key = str_replace("-", "_", factory->getKey());
            if (array_key_exists(key, provider) && !empty(provider[key])) {
                factory->create(name, provider[key]);
                return name;
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

        //throw new InvalidConfigurationException(sprintf("Unable to create definition for %s user provider", name));
        throw new \Exception(sprintf("Unable to create definition for %s user provider", name));
    }

    private function getUserProviderId(name)
    {
        return "security.user.provider.concrete.".name;
    }


    public function addUserProviderFactory(<UserProviderFactoryInterface> factory)
    {
        let this->userProviderFactories[] = factory;
    }

    public function addSecurityListenerFactory(factory)//SecurityFactoryInterface
    {
        let this->factories[factory->getPosition()][] = factory;
    }
}
