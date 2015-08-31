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

namespace Phady\Security\Authentication;

/**
  * @class Phady\Security\Authentication\AuthHandler -  Authentication handlers for app
  *
  * @author  Alien Fernández Fuentes <alienfernandez85@gmail.com>
  * @package Core
  * @copyright (c) 2015
  * @version 1.0.0
  */
final class AuthHandler
{

    /**
     * @var array securityConfig - Config security
     */
    protected securityConfig;

    /**
     * @param array config - Config db
     */
    public function __construct(array! configSecurity) {
        //Read config file security
        let this->securityConfig = configSecurity;
    }

    /**
     * @name checkCredentials - Verifies user credentials
     * @param array credentials - Array Credentials
     *              [username] - User name
     * @return boolean
     */
    public function checkCredentials(array! credentials) {
        var arrErrors, password, userData, checkStatus, auth;
        let arrErrors = [];
        //Clean the credentials of the session
        //this->session->set("auth", new \stdClass());
        //Check if the user exists (for UserName or by mail)
        /**let userData = this->userRepo->getDataMailUsers(array(
            "authentication" => credentials["username"],
            "principal" => 1
        ));*/
        let userData = [];
        let password = hash(this->securityConfig["security"]["encoding_format"], credentials["password"]);
        // Check user status
        let checkStatus = this->checkUserFlags(userData);
        if (checkStatus && is_array(checkStatus) && array_key_exists("error_code", checkStatus)) {
            let arrErrors = array_merge(arrErrors, checkStatus);
            //this->logger->addNotice("Error de inicio de sesión " . checkStatus["error_msg"]);
        }elseif (strcmp(password, userData["Clave"]) !== 0) {
             // Check the key
             //this->registerUserThrottling(userData["UsuarioId"]);
             let arrErrors["error_code"] = "INCORRECT_CREDENTIALS";
             //this->logger->addNotice("Error de inicio de sesión [INCORRECT_CREDENTIALS]");
        } elseif (!userData || !array_key_exists("user_id", userData)) {
              //this->registerUserThrottling();
              let arrErrors["error_code"] = "INCORRECT_CREDENTIALS";
              //this->logger->addNotice("Error de inicio de sesión [INCORRECT_CREDENTIALS]");
        }
        //Si no hay errores en la autenticacion
        if (arrErrors || array_key_exists("error_code", arrErrors)) {
            let auth = arrErrors;
        }else {
            let auth = true;
        }

        return auth;
    }
    
    /**
     * Check user status
     *
     * @param array user
     */
    public function checkUserFlags(array user) {
        var arrStatus = [];
        if (user["status_code"] == "INACTIVE" || user["status_code"] == "LOCKED") {
           if (user["status_code"] == "INACTIVE") {
                let arrStatus["error_code"] = "INACTIVE_USER_CODE";
            }
            if (user["status_code"] == "LOCKED") {
                let arrStatus["error_code"] = "LOCKED_USER_CODE";
            }
        }
        return arrStatus;
    }

    /**
     * Obtener los datos que se van a modificar en la session
     *
     * @param array userData
     * @return \stdClass
     */
    public function getDataSession(array! userData, user) {
        var tmpRoles, vRol, auth;
        let tmpRoles = [];
        for vRol in user->getRoles() {
            let tmpRoles[] = vRol->RolId;
        }
        let auth = new \stdClass();
        let auth->user_id = userData["user_id"];
        let auth->contact_id = userData["contact_id"];
        let auth->username = userData["username"];
        let auth->name = userData["name"];
        let auth->email = userData["email"];
        let auth->roles = tmpRoles;
        return auth;
    }
}
