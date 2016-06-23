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

/**
  * @class Phady\Core\Parameter -  Parameter for app
  *
  * @author  Alien Fernández Fuentes <alienfernandez85@gmail.com>
  * @package Core
  * @copyright (c) 2015
  * @version 1.0.0
  */
class Parameter
{

    /**
     * @var string Directorio raiz del proyecto /app
     */
    public root_dir;

    /**
     * @var string Direcccion completa del proyecto
     */
    public http_host;

    /**
     * @var string Direcccion completa del proyecto con el protocolo
     */
    public url;

    /**
     * @var string Protocolo usado en el sistema http|https
     */
    public request_protocol;

    /**
     * @var string Entorno del proyecto
     */
    public environment;

    /**
     * @var boolean Si esa en modo debug
     */
    public debug;

    /**
     * @var string Directorio de cache
     */
    public cache_dir;

    /**
     * @var string Directorio de log
     */
    public log_dir;

    /**
     * @var array Array de modulos
     */
    public modules;

    /**
     * @var string Juego de caracteres
     */
    public charset;

    /**
     * @var array Array de config de catalogos
     */
    public catalog;

    /**
     * @var array Array de config de fecha
     */
    public datetime;

    /**
     * @var array Array de config de correos
     */
    public mail;

    /**
     * @var array Array de config de pdf
     */
    public pdf;

    /**
     * @var array Array de config de archivos
     */
    public files;

    /**
     * @var array Array de config de seguridad
     */
    public security;

    /**
     * @var DI Contenedor de dependencias
     */
    public container;

    /**
     * @param string param Parametro a modificar
     * @param mixed value Valor del parametro
     */
    public function setParameter(string param, var value) {
        //print_r(property_exists(this, param));die;
        if (property_exists(this, param)) {
            let this->{param} = value;
        }
    }
}
