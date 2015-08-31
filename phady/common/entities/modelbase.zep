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

namespace Phady\Common\Entities;

use Phalcon\Mvc\Model as ModelMvc;

/**
 * Phady\Common\Entities\ModelBase
 *
 * Base Model
 */
abstract class ModelBase extends ModelMvc
{

    /**
     * Stores that attributes can be setter
     *
     * @var array
     */
    protected _set;

    /**
     * Stores that attributes can be getter
     *
     * @var array
     */
    protected _get;

    /**
     * Stores the attributes that relate to class with another with different cardinality (one to one , one to many , etc ) .
     * Preserves the core functionality of Phalcon .
     * @var type
     */
    protected _related;

    /**
     * Stores the date the record
     *
     * @var timestamp
     */
    protected create_at;

    /**
     * Stores the last modified date of registration
     *
     * @var timestamp
     */
    protected modify_at;

    /**
     * Stores the ID of the user who created the record
     *
     * @var uuid
     */
    protected create_user;

    /**
     *
     * Stores the identifier of the user who last modified the record.
     *
     * @var uuid
     */
    protected modify_user;

    /**
     *
     * Saves last IP address that made ​​a change and created the record.
     *
     * @var uuid
     */
    protected request_ip;

    /**
     * Performs procedures to initialize the class
     */
    public function onConstruct() {
        this->init();
    }

    /**
     * Inicializa la clase. Asigna los attributeutos que pueden ser obtenidos
     * y seteados.
     */
    protected function init() {
        let this->_set = ["create_at", "modify_at", "create_user", "modify_user", "request_ip"];
        let this->_get = ["create_at", "modify_at", "create_user", "modify_user", "request_ip"];
    }

    /**
     * Method magic to set starting attributeutos allowed .
     *
     * If a validation method executes .
     *
     * If there is a specific method for setting it uses it, otherwise it It sets directly
     *
     * @param string attribute
     * @param string value
     * @throws Exception
     */
    public function __set(string attribute, value) {
        var varName, validateMethod, setMethod, reflectionClass, reflectionProperty;
        if (isset(this->_related) && is_array(this->_related) && in_array(attribute, this->_related)) {
            return parent::__get(attribute);
        }

        if (in_array(attribute, this->_set)) {
            let varName = ucfirst(str_ireplace("_", "", attribute));
            let validateMethod = "validate" . varName;
            let setMethod = "set" . varName;
            if (method_exists(this, setMethod)) {
                this->{"setMethod"}(value);
            } else {
                let reflectionClass = new \ReflectionClass(this);
                let reflectionProperty = reflectionClass->getProperty(attribute);
                reflectionProperty->setAccessible(true);
                reflectionProperty->setValue(this, value);
                //print_r("set: " . setMethod);
                //let this->{"attribute"} = value;
            }
        }
    }


    /**
     *
     * Gets the value of an attribute. If there is a specific method for the attribute is used,
     * otherwise only available directly.
     *
     * @param string attribute
     * @return type
     */
    public function __get(attribute) {
        var methodName;
        if (isset(this->_related) && is_array(this->_related) && in_array(attribute, this->_related)) {
            return parent::__get(attribute);
        }

        if (in_array(attribute, this->_get)) {
            let methodName = "get" . ucfirst(str_ireplace("_", "", attribute));

            if (method_exists(this, methodName)) {
                return this->{"methodName"};
            } else {
                return this->{"attribute"};
            }
        }
    }
    
    
    /**
     * Método que se ejecuta antes de validar al crear un nuevo registro.
     *
     * Se almacena la fecha de creación.
     */
    public function beforeValidationOnCreate() {
        var request;
        //usrSession = this->getDI()->getSession()->get('auth');
        let request = this->getDI()->get("request");
        //if (isset(usrSession->UsuarioId) && strlen(this->create_user) == 0) {
        //    this->create_user = usrSession->UsuarioId;
        //} else {
            let this->create_user = 1;
        //}
        let this->create_at = date("Y-m-d H:i:s");
        let this->request_ip = request->getClientAddress(TRUE);
    }

    /**
     * Method that executes before update a record. It stores the date of update
     */
    public function beforeUpdate() {
        var request;
        //$usrSession = $this->getDI()->getSession()->get('auth');
        let request = this->getDI()->get("request");
        //if (isset($usrSession->UsuarioId)) {
            //$this->modify_user = $usrSession->UsuarioId;
        //} else {
            let this->modify_user = "alien";
        //}
        let this->modify_at = date("Y-m-d H:i:s");
        let this->request_ip = request->getClientAddress(TRUE);
    }
}
