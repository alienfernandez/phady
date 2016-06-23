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

namespace Phady\Route;

use Phalcon\Mvc\Router as RouterMVC;

/**
  * @class Phady\Route\Router -  Routing componente app
  *
  * @author  Alien Fernández Fuentes <alienfernandez85@gmail.com>
  * @package Core
  * @copyright (c) 2015
  * @version 1.0.0
  */
class Router
{

    private config;

    private router;

    private configRoutes;

    public function __construct() {
        //let this->config = config;
        let this->router = new RouterMVC();
    }

	/**
	 * Constructor.
	 *
	 * @param string config The config route
	 * @api
	 */
	public function setConfig(config) -> void {
		//print_r(config);die;
		let this->config = config;
	}

	/**
	 *
	 * @return router
	 */
	public function getRouter() {
		return this->router;
	}

	/**
	 * @name setDefaultRoute - Generate default route system
	 * @return void
	 */
	public function setDefaultRoute() -> void {
	    var configDefaultMod;
		let configDefaultMod = this->config["routing"]["modules"]["default"];
		//echo "<pre>";print_r(configDefaultMod["route"]["options"]["ns"]);die;
		this->router->removeExtraSlashes(true);
		this->router->setDefaultModule(configDefaultMod["name"]);
		this->router->setDefaultNamespace(configDefaultMod["namespace"]);

		this->router->add(configDefaultMod["route"]["path"], [
			"module" : configDefaultMod["route"]["options"]["module"],
			"namespace" : configDefaultMod["route"]["options"]["ns"],
			"controller" : configDefaultMod["route"]["options"]["controller"],
			"action" : configDefaultMod["route"]["options"]["action"]
		]);

		//Establecar pagina de error 404
		this->router->notFound([
			"namespace" : "App\\Common\\Controllers",
			"controller" : "error",
			"action" : "route404"
		]);
	}

	/**
	 * @name setSystemRoutes - Build system paths routing config file
	 * @param string rootDir - System root directory
	 * @return void
	 */
	public function setSystemRoutes(string rootDir) -> void {
	    let this->config = \Phady\Config\Yaml::parse(rootDir . "/config/config.yml");
	    var route, arrOptionsRoute, index, optRoute;
		//Change default route of application
		this->setDefaultRoute();

		//Read configuration file
		let this->configRoutes = yaml_parse_file(rootDir . "/config/routing.yml");
		//echo "<pre>";print_r(this->configRoutes);
		for route in this->configRoutes["routes"] {
			let arrOptionsRoute = [];
			for index, optRoute in route["options"] {
				let arrOptionsRoute[index] = optRoute;
			}
			this->router->add(route["path"], arrOptionsRoute);
		}
	}
}
