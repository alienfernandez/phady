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

namespace Phady\Security\Bundle\Model;

use Phady\Security\Bundle\Model\Repository\UserRepository;
use Phady\Security\Core\Models\Entities\User;
use Phady\Util\Uuid;
use Phady\Util\Model as ModelUtil;
use Phady\Util\Text;

/**
  * @class Phady\Security\Bundle\Model\UserCore
  *
  * @author  Alien Fernández Fuentes <alienfernandez85@gmail.com>
  * @package Core
  * @copyright (c) 2015
  * @version 1.0.0
  */
class UserCore extends \Phalcon\DI\Injectable
{
    private encoder_factory;

    public function __construct(){
        let this->encoder_factory = this->getDI()->get("security.encoder_factory.generic");
    }

    /**
     * @name getUsers - Get user data
     * @param array arrData - Data to filters
     * @param boolean getTotal - Get the total with the filter applied
     * @return array
     */
    public function getUsers(array arrDataFilter, boolean getTotal = false) {
        var arrData, userRepository, arrUsers, arrTotalUsers;
        //let arrData = [];
        let userRepository = new UserRepository();
        let arrUsers = userRepository->getUsers(arrDataFilter);
        let arrData = ["data" : arrUsers];
        if (getTotal) {
            let arrTotalUsers = userRepository->getTotalUsers(arrData);
            let arrData["total"] = arrTotalUsers;
        }
        return arrData;
    }


    /**
     * @name persist - Persist user
     * @param array arrData Data to persist
     * @return bool
     */
    public function persist(array arrData) {
        var count, objectPersist, encoder, save;
        boolean persist = true;
        let count = User::count(["username = '" . arrData["username"] . "'"]);
        //Edit
        if (array_key_exists("id", arrData) && !empty(arrData["id"])) {

            let objectPersist = User::findFirst(["id = '" . arrData["id"] . "'"]);
            //Si se modifico la descripcion verificar si es unica la misma
            if (objectPersist->username != arrData["username"]) {
                let persist = (count == 0) ? true : false;
            }
        } else {
            //Add
            let persist = (count == 0) ? true : false;
            let objectPersist = new User();
            //let objectPersist->id = Uuid::v4();
            let arrData["usernameCanonical"] = strtolower(arrData["username"]);
            let arrData["emailCanonical"] = strtolower(arrData["email"]);
            unset(arrData["id"]);
        }

        if (persist) {
            unset(arrData["passwordConfirmation"]);
            let encoder = this->encoder_factory->getEncoder(objectPersist);
            //print_r(encoder);die();
            let arrData["password"] = encoder->encodePassword(arrData["password"], objectPersist->getSalt());

            //Assign data to object
            ModelUtil::asssignData(objectPersist, arrData);
            //echo "<pre>";print_r(objectPersist->toArray());die();
            let save = objectPersist->save();
            if (save == false) {
                //this->db->rollback();
                let objectPersist = [
                    "error_code" : "AppSeguridadMsgCore::MODEL_USUARIO_SAVE_CODE_ERROR",
                    "message" : "AppSeguridadMsgCore::MODEL_USUARIO_SAVE_MSG_ERROR"
                ];
            }
        } else {
            //Si no se pudo persistir porque se repite el usuario
            let objectPersist = [
                "error_code" : "AppSeguridadMsgCore::MODEL_EXIST_RECORD_USUARIO_CODE_ERROR",
                "message" : "AppSeguridadMsgCore::MODEL_EXIST_RECORD_USUARIO_MSG_ERROR .  [<strong>{arrData[username]}</strong>]"
            ];
        }

        return objectPersist;
    }
    
    
    /**
     * @name setEnabledStatusUser - Active or deactive user
     * @param userId User dato to active
     * @param integer status 0 | 1
     * @return bool
     */
     public function setEnabledStatusUser(userId, status = 1) {
        var user;
        let user = User::findFirst(["id = '" . userId . "'"]);
        let user->enabled = status;
        //user->FechaExpiracionToken = now->add(\DateInterval::createFromDateString("-8 day"))->format(this->parameters->datetime["default_format"]);
        return user->save();
     }


    /**
     * @name changePassword - Change password
     * @param array arrData Data to change password
     * @return bool
     */
    public function changePassword(array arrData) {
        var user, encoder, password;
        let user = User::findFirst(["id = '" . arrData["id"] . "'"]);
        //arrData["Actual"] = hash(this->securityConfig["security"]["encoding_format"], arrData["Actual"]);
        let encoder = this->encoder_factory->getEncoder(user);
        //print_r(encoder);die();
        let arrData["actual"] = encoder->encodePassword(arrData["actual"], user->getSalt());

        if (Text::equals(arrData["actual"], user->getPassword())) {
            if (Text::equals(arrData["new"], arrData["verify"])) {
                let password = encoder->encodePassword(arrData["new"], user->getSalt());
                user->setPassword(password);

                if (user->save()) {
                    /*
                    auth = this->auth->checkCredentials(array("NombreUsuario" : user->getNombreUsuario(), "Clave" : arrData["Nueva"]));
                    if (is_object(auth) && auth->UsuarioId) {
                        return = true;
                    } else {
                        return = auth;
                    }*/
                } else {
                    return [
                        "error_code" : "AppSeguridadMsgCore::MODEL_USUARIO_SAVE_MSG_ERROR",
                        "message" : "AppSeguridadMsgCore::MODEL_USUARIO_SAVE_CODE_ERROR"
                    ];
                }
            } else {
                return [
                    "error_code" : "AppSeguridadMsgCore::CONFIRMATION_KEY_CODE_ERROR",
                    "message" : "AppSeguridadMsgCore::CONFIRMATION_KEY_MSG_ERROR"
                ];
            }
        } else {
            return [
                "error_code" : "AppSeguridadMsgCore::CURRENT_KEY_CODE_ERROR",
                "message" : "AppSeguridadMsgCore::CURRENT_KEY_MSG_ERROR"
            ];
        }

        return;
    }


    /**
     * @name deleteUser - Delete user
     * @param  userId - User id to delete
     * @return bool
     */
    public function deleteUser(userId) {
        var user, deleted;
        let user = User::findFirst(["id = '" . userId . "'"]);

        if (user) {
            let deleted = user->delete();
            return deleted;
        }

        return FALSE;
    }


    /**
     * @name setLockedStatusUser - locked user
     * @param userId User dato to active
     * @param integer status 0 | 1
     * @return bool
     */
    public function setLockedStatusUser(userId, status = 1) {
        var user;
        let user = User::findFirst(["id = '" . userId . "'"]);
        let user->locked = status;
        return user->save();
    }
}

