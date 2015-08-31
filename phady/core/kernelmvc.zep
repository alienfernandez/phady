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

use Phalcon\Mvc\Application;

/**
  * @class Phady\Core\KernelMvc -  Kernel mvc
  *
  * @author  Alien Fernández Fuentes <alienfernandez85@gmail.com>
  * @package Core
  * @copyright (c) 2015
  * @version 1.0.0
  */
class KernelMvc extends \Phady\Core\Kernel
{
    /**
     * @var <Phalcon\Mvc\Application> application - Instance of app
     */
    protected application;

    /**
     * @param string environment - development environment [dev | prod | test]
     * @param string scope - Scope of execution [mvc | cli]
     * @param string debug - Whether to enable debugging or not
     * @param array modules - Array modules
     */
    public function __construct(string environment, bool debug = false, string scope, array! modules) {
        parent::__construct(environment, debug, scope, modules);
        let this->application = new Application();
        this->initializeModules();
        //print_r(this->modules);
        //change default container for app
        this->application->setDI(this->container);
    }
    /**
     * Initializes modules.
     *
     */
    protected function initializeModules() {
        var module;
        for module in this->modules {  //this->register()
            //echo '<pre>';print_r(module);die;
            this->application->registerModules(module, true);
        }
    }

    /**
     * @var <Phalcon\Mvc\Application> Get instance app
     */
    public function getApplication() {
        return this->application;
    }
}
