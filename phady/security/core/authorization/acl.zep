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

namespace Phady\Security\Core\Authorization;

//use Phalcon\Mvc\User\Component as ComponentPhalcon;

/**
  * @class Phady\Security\Core\Authorization\Acl -  Authorization handlers for app
  *
  * @author  Alien Fernández Fuentes <alienfernandez85@gmail.com>
  * @package Core
  * @copyright (c) 2015
  * @version 1.0.0
  */
class Acl extends \Phalcon\Mvc\User\Component
{

    /**
     * ACL Object
     *
     * @var \Phalcon\Acl\Adapter\Memory
     */
    private acl;

    /**
     *
     * Name of the module that is using this component.
     *
     * @var string
     */
    private moduleName;

    /**
     * Defines resources considered as "private". Are defined as
     * controller => actions que requiere autenticación
     *
     * @var array
     */
    private resources;

    /**
     * Accessible to everyone
     * @var array
     */
    protected publicResources;

    /**
     *
     * Prefix acl.
     *
     * @const string
     */
    const PREFIX_ACL_APP = "app-acl-";
   
    public function __construct() {
        //var router;
        let this->publicResources = [
            "index" : ["*"],
            "login" : ["*"],
            "portal" : ["*"],
            "directorio" : ["*"],
            "seguridad" : ["activar"]
        ];
        //let router = this->getDI()->get("request");
        //let this->moduleName = router->getModuleName();
        let this->moduleName = "common";
        this->loadResources();
    }

    /**
     * Check if a controller is private or not
     *
     * @param string controllerName
     * @return boolean
     */
    public function isPrivate(controllerName) {
        return isset(this->resources[controllerName]);
    }

    /**
     * It checks if the current role has access to a resource
     *
     * @param string rol
     * @param string controller
     * @param string action
     * @return boolean
     */
    public function isAllowed(rol, controller, action) {
        var value, roles;
        if (!is_array(rol)) {
            let roles = [rol];
        }else{
            let roles = rol;
        }

        for value in roles {
            if (this->getAcl()->isAllowed(value, controller, action) || controller == "error") {
                return TRUE;
            }
        }
        return FALSE;
    }
    
    /**
     * Obtener la lista ACL
     *
     * @return \Phalcon\Acl\Adapter\Memory
     */
    public function getAcl() {
        var acpName;
        // Verifica si la lista ACL ya ha sido creada
        if (is_object(this->acl)) {
            return this->acl;
        }
		//this->cleanCache();
	    let acpName = self::PREFIX_ACL_APP . this->moduleName;
        //Verificar que la cache no se encuentre en cache
        /*
        //this->cache->redis->onAllServer(strict = true)->set(acpName, '');
        if (!this->cache->redis->onOneRandomServer()->get(acpName)) {
            //Crear ACL
            this->acl = this->rebuild();
//            serializeData = this->serializer->serialize(this->acl, 'xml');
            //Guardar el menu en la cache
            this->cache->redis->onAllServer(strict = true)->set(acpName, serialize(this->acl));
        } else {
            //Obtener la acl de la cache
            //arrDataAcl = this->serializer->deserialize(this->cache->redis->onOneRandomServer()->get(acpName), '\Phalcon\Acl\Adapter\Memory', 'xml');
            if (this->cache->redis->onOneRandomServer()->get(acpName)) {
                this->acl = unserialize(this->cache->redis->onOneRandomServer()->get(acpName));
            } else {
                this->logger->addNotice('No se encontró el key en el servidor de cache. ');
                this->acl = new AclMemory();
            }
        }*/
        return this->acl;
    }

    /**
     * Carga los recursos y sus acciones desde la base de datos
     * para el modulo actual
     *
     * @return void
     */
    private function loadResources() {
        var result;
        let result = [];
        /*
        let modulos = \App\Seguridad\Models\Entities\Modulos::find("Nombre = '{this->moduleName}'");

        if (!modulos) {
            this->resources = result;
            return;
        }

        foreach (modulos as modulo) {
            foreach (modulo->getRecursos() as recurso) {
                acciones = [];
                foreach (recurso->getAcciones() as accion) {
                    acciones[] = accion->Nombre;
                }
                result[recurso->Nombre] = acciones;
            }
        }
        */
        let this->resources = result;
    }

}
