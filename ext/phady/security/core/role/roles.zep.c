
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "ext/phalcon/phalcon/mvc/user/component.zep.h"


/**
  * @class Phady\Security\Core\Role\Roles -  Core roles for app
  *
  * @author  Alien Fernández Fuentes <alienfernandez85@gmail.com>
  * @package Core
  * @copyright (c) 2015
  * @version 1.0.0
  */
ZEPHIR_INIT_CLASS(Phady_Security_Core_Role_Roles) {

	ZEPHIR_REGISTER_CLASS_EX(Phady\\Security\\Core\\Role, Roles, phady, security_core_role_roles, phalcon_mvc_user_component_ce, NULL, 0);

	return SUCCESS;

}

