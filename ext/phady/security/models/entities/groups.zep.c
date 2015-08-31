
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


/**
 * Phady\Security\Models\Entities\Groups
 *
 * Model for Users
 */
ZEPHIR_INIT_CLASS(Phady_Security_Models_Entities_Groups) {

	ZEPHIR_REGISTER_CLASS_EX(Phady\\Security\\Models\\Entities, Groups, phady, security_models_entities_groups, phady_common_entities_modelbase_ce, NULL, 0);

	return SUCCESS;

}

