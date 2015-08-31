
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"


/**
 * Phady\Security\Groups\GroupBase
 *
 * Base Group for Phady\Security\Groups
 */
ZEPHIR_INIT_CLASS(Phady_Security_Groups_GroupBase) {

	ZEPHIR_REGISTER_CLASS(Phady\\Security\\Groups, GroupBase, phady, security_groups_groupbase, NULL, 0);

	return SUCCESS;

}

