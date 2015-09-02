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

namespace Phady\Core;

use Phalcon\DI\FactoryDefault;
use Phalcon\DI\FactoryDefault\CLI as CliFactory;
use Phalcon\Loader;
use Phalcon\Db\Exception;
use Phalcon\Mvc\View;
use Phalcon\Mvc\View\Engine\Volt;
use Phalcon\Flash\Session;
use Phalcon\Http\Response\Cookies;
use Phalcon\Session\Adapter\Files;
use Phalcon\Config\Adapter\Yaml;

/**
  * @class Phady\Core\Kernel -  Kernel system class
  *
  * @author  Alien Fernández Fuentes <alienfernandez85@gmail.com>
  * @package Core
  * @copyright (c) 2015
  * @version 1.0.0
  */
abstract class Kernel
{

    /**
     * const ENVIRONMENT DEVELOPMENT
     */
    const ENVIRONMENT_DEV = "dev";

    /**
     * const ENVIRONMENT PRODUCTION
     */
    const ENVIRONMENT_PROD = "prod";

    /**
     * const ENVIRONMENT TEST
     */
    const ENVIRONMENT_TEST = "test";

    /**
     * const SCOPE CLI
     */
    const SCOPE_CLI = "cli";

    /**
     * const SCOPE MVC
     */
    const SCOPE_MVC = "mvc";

    /**
     * Const of version app
     */
    const VERSION = "1.0.0";
    const VERSION_ID = "10000";
    const MAJOR_VERSION = "1";
    const MINOR_VERSION = "0";
    const RELEASE_VERSION = "0";
    const EXTRA_VERSION = "";

    /**
     * @var array modules - Modules list
     */
    protected modules;

    /**
     * @var array ns - ns list
     */
    protected ns;

    /**
     * @var string rootDir - Root dir app
     */
    protected rootDir;

    /**
     * @var string environment - Environment execution app
     */
    protected environment;

    /**
     * Dependencies container
     * @var FactoryDefault
     */
    protected container;

    /**
     * @var string scope - Scope execution app (cli or mvc)
     */
    protected scope;

    /**
     * @var boolean debug - Is debug mode
     */
    protected debug;

    /**
     * @var boolean debug - Is booted app
     */
    protected booted;

    /**
     * @var array config - Array of file config app
     */
    protected config;

    /**
     * Instance of Command console
     * @var Phady\Console\Command
     */
    protected command;

    protected startTime;

    protected security;


    /**
     * Constructor.
     *
     * @param string environment - The environment
     * @param string scope - Scope of execution [mvc | cli]
     * @param boolean debug - Whether to enable debugging or not
     * @param array modules - Array modules app
     * @api
     */
    public function __construct(string! environment, boolean! debug = false, string! scope, array! modules) {
        this->validateExternalLibrary();
        let this->debug = debug;
        let this->scope = scope;
        let this->booted = false;
        let this->rootDir = this->getRootDir();
        let this->modules = modules;
        let this->ns = [];
        let this->command = new \Phady\Console\Command();
        //Read the configuration file
        this->readConfigFiles();
        this->setEnvironment(environment);

        if (this->debug) {
            let this->startTime = microtime(true);
        }
        //Boot app
        this->boot();
    }

    /**
     * Start the current kernel.
     *
     * @api
     */
    public function boot() {
        if (true == this->booted) {
            return false;
        }
        // init container
        this->initializeContainer();
        // init namespaces
        this->initializeNamespace();
        //init default service
        this->initializeDefaultService();
        let this->booted = true;
    }

    /**
     * Initializes the service container.
     *
     * The cached version of the service container is used when fresh, otherwise the
     * container is built.
     * @return FactoryDefault
     */
    protected function initializeContainer() -> void {
        if (this->scope == self::SCOPE_MVC) {
            let this->container = new FactoryDefault();
        } else {
            let this->container = new CliFactory();
        }
    }

    /**
     * Validate external libs exist
     *
     */
    protected function validateExternalLibrary() -> void {
        if (!extension_loaded("phalcon")) {
            throw new \Phady\Exception("Phalcon extension isn\'t installed, follow these instructions to install it: http://docs.phalconphp.com/en/latest/reference/install.html");
        }
    }

    /**
     * Read config files
     *
     */
    protected function readConfigFiles() -> void {
        var configFile, securityFile;
        let configFile = this->rootDir . "/config/config.yml";
        let securityFile = this->rootDir . "/config/security.yml";
        if (!extension_loaded("yaml")) {
            throw new \Phady\Exception("Yaml extension isn\'t installed.");
        }
        if (!file_exists(configFile)) {
            throw new \Phady\Exception("Config file isn\'t found.");
        }

        if (!file_exists(securityFile)) {
            throw new \Phady\Exception("Security file isn\'t found.");
        }

        let this->config = \Phady\Config\Yaml::parse(configFile);
        let this->security = \Phady\Config\Yaml::parse(securityFile);
    }

    /**
     * Initializes namespaces.
     *
     */
    protected function initializeNamespace() -> void {
        var nsCore, loader;
        let loader = new Loader();
        //Init modules
        //let this->modules = this->register();
        let nsCore = new \Phady\Core\NamespaceHandler(this->scope, this->rootDir, this->modules);
        loader->registerNamespaces(nsCore->getAllNamespaceApp());
        loader->register();
    }

    /**
     * Initializes default service.
     *
     */
    protected function initializeDefaultService() {
        var di, config;
        let di = this->container;
        let config = this->config;
        if (is_array(config)){

        }
        //TODO Cuando se de soporte closure para use cambiar estas vars
        //Si el ambito es de aplicacion web
        let _SERVER["rootDirOk"] = this->rootDir;
        let _SERVER["environment"] = this->environment;
        let _SERVER["configApp"] = this->config;
        let _SERVER["containerApp"] = this->container;

        if (this->scope == self::SCOPE_MVC) {
            this->container->set("router", function () {
                var routeCore;
                let routeCore = new \Phady\Route\Router();
                //routeCore->setConfig(config);
                routeCore->setSystemRoutes(_SERVER["rootDirOk"]);
                return routeCore->getRouter();
            });

            //Register the events manager service
            this->container->setShared("dispatcher", function () {
                var dispatcher, eventsManager;

                let eventsManager = new \Phalcon\Events\Manager();

                /**
                 * Check if the user is allowed to access certain action using the AuthenticationListener
                 */
                eventsManager->attach("dispatch:beforeDispatch", new \Phady\Security\Core\Authentication\EventListener\AuthenticationListener());
                let dispatcher = new \Phalcon\Mvc\Dispatcher();
                //echo "<pre>";print_r(dispatcher);
                eventsManager->fire("dispatch:beforeDispatch", dispatcher);
                //dispatcher->setEventsManager(eventsManager);
                return dispatcher;
            });
        }


        //Register component database service
        this->container->set("db", function () {
            var dbCore, exception;
            try {
                let dbCore = new \Phady\Db\DatabaseHandler(_SERVER["configApp"]);
                //Get Adapter DB
                return dbCore->getAdapter();
            } catch Exception, exception {
                 // handle exception
                 echo exception->getMessage();
                 exit();
             }
        });

        //Register component view service
        this->container->set("view", function () {
            var view;
            let view = new \Phalcon\Mvc\View();
            view->registerEngines([
                ".volt" : "volt"
            ]);
            return view;
        });

        //Register volt engines service
        this->container->set("volt", function (view, di) {
            var volt, voltOptions;
            let volt = new \Phalcon\Mvc\View\Engine\Volt(view, di);
            let voltOptions = [
                "compiledPath" : _SERVER["rootDirOk"] . "/cache/" . _SERVER["environment"] . "/volt/",
                "compiledSeparator" : "_"
            ];
            if (_SERVER["environment"] == "dev") {//self::ENVIRONMENT_DEV
                let voltOptions["compileAlways"] = true;
            }
            volt->setOptions(voltOptions);
            return volt;
        }, true);

        //Init flash service
        this->container->set("flash", function () {
            var flash;
            let flash = new \Phalcon\Flash\Session([
                "error" : "alert alert-danger",
                "success" : "alert alert-success",
                "notice" : "alert alert-info"
            ]);
            return flash;
        });

        //Init parameters data service
        this->container->set("parameters", function () {
            //return this->getCoreParameters();
            return true;
        });
        
        //Init parameters data service
        this->container->set("cache", function () {
            var cache;
            let cache = new \Phady\Cache\CacheHandler(_SERVER["configApp"]);
            return cache->getAdapter();
        });

        //Init cookies service
        this->container->set("cookies", function () {
            var cookies;
            let cookies = new \Phalcon\Http\Response\Cookies();
            cookies->useEncryption(false);
            return cookies;
        });

        /**
         * Init session service
         * Inicia la sesión la primera vez que algun componente solicita el servicio "session"
         */
        /*this->container->set("session", function () {
            var session;
            let session = new \Phalcon\Session\Adapter\Files();
            if (session_id() == "") {
                session->start();
            }
            return session;
        });*/

        //Register component login manager service
        this->container->set("loginManager", function () {
            var loginManager, userChecker;
            let userChecker = new \Phady\Security\Core\User\UserChecker();
            let loginManager = new \Phady\Security\Core\Authentication\LoginManager(null, userChecker, _SERVER["containerApp"]);
            return loginManager;
        });

    }

    /**
     * Returns the core parameters.
     *
     * @return array An array of core parameters
     */
    protected function getCoreParameters() {
        var modules, module, parameters, url, name, data, tools;
        let modules = [];
        for module in this->modules {
            for name, data in module {
                //print_r(data);die;
                let modules[name] = data["className"];
            }
        }
        let parameters = new \Phady\Core\Parameter();
        let tools = new \Phady\Util\Tools();
        if (this->scope == self::SCOPE_MVC) {
            parameters->setParameter("http_host", tools->getHttpHost());
            parameters->setParameter("request_protocol", tools->getRequestProtocol());
            let url = tools->getRequestProtocol() . "://" . tools->getHttpHost();
            parameters->setParameter("url", url);
        }
        parameters->setParameter("root_dir", this->rootDir);
        parameters->setParameter("environment", this->environment);
        parameters->setParameter("debug", this->debug);
        parameters->setParameter("cache_dir", this->getCacheDir());
        parameters->setParameter("log_dir", this->getLogDir());
        parameters->setParameter("modules", modules);
        parameters->setParameter("charset", this->getCharset());
        parameters->setParameter("catalog", this->config["framework"]["catalog"]);
        parameters->setParameter("datetime", this->config["framework"]["datetime"]);
        parameters->setParameter("mail", this->config["mail"]);
        parameters->setParameter("pdf", this->config["pdf"]);
        parameters->setParameter("files", this->config["files"]);
        //parameters->setParameter("security", this->security["security"]);
        parameters->setParameter("container", this->container);
        return parameters;
    }


    /**
     * {@inheritdoc}
     *
     * @api
     */
    public function getRootDir() -> string {
        var document_root, document_root_spl;
        if (null == this->rootDir) {
            let document_root = _SERVER["DOCUMENT_ROOT"];
            let document_root_spl = explode("web", document_root);
            if (count(document_root_spl) > 0){
                let this->rootDir = document_root_spl[0] . "app";
            }else {
                throw new \Phady\Exception("No found root directory.");
            }
            //let rObject = new \ReflectionObject(this);
            //let this->rootDir = str_replace("\\", "/", dirname(rObject->getFileName()));
        }

        return this->rootDir;
    }

    /**
     * Set evironment
     *
     * @api
     */
    public function setEnvironment(string! environment) -> void {
        if (environment == self::ENVIRONMENT_DEV) {
            error_reporting(E_ALL);
            ini_set("display_errors", 1);
            //define(PHALCON_INIT_LOADED, false);
        } elseif (environment == self::ENVIRONMENT_PROD) {
            ini_set("display_errors", 0);
        }
        let this->environment = environment;
    }

    /**
     * Is debug mode
     *
     * @api
     */
    public function isDebug() -> boolean {
        return this->debug;
    }

    /**
     * Get dependencies container
     *
     * @api
     */
    public function getContainer() {
        return this->container;
    }

    /**
     * Get command cli exec
     *
     * @api
     */
    public function getCommand() {
        return this->command;
    }

    /**
     * {@inheritdoc}
     *
     * @api
     */
    public function getStartTime() {
        return this->debug ? this->startTime : "-INF";
    }

    /**
     * {@inheritdoc}
     *
     * @api
     */
    public function getCacheDir() -> string {
        return this->rootDir . "/cache/" . this->environment;
    }

    /**
     * {@inheritdoc}
     *
     * @api
     */
    public function getLogDir() -> string {
        return this->rootDir . "/logs";
    }

    /**
     * {@inheritdoc}
     *
     * @api
     */
    public function getCharset() -> string {
        return "UTF-8";
    }

    /**
     * {@inheritdoc}
     *
     * @api
     */
    public function shutdown() {
        if (false == this->booted) {
            return false;
        }
        let this->booted = false;
        //this->container = null;
    }

    /**
     * {@inheritdoc}
     *
     * @api
     */
    public function getEnvironment() -> string {
        return this->environment;
    }

    /**
     * {@inheritdoc}
     *
     * @api
     */
    public function getModules() -> array {
        return this->modules;
    }

    public function serialize() {
        return serialize([this->environment, this->debug]);
    }

    public function unserialize(data) {
        //list(environment, debug) = unserialize(data);
        //this->__construct(environment, debug);
    }
}
