
/* This file was generated automatically by Zephir do not modify it! */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <php.h>

#if PHP_VERSION_ID < 50500
#include <locale.h>
#endif

#include "php_ext.h"
#include "phady.h"

#include <ext/standard/info.h>

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/globals.h"
#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"



zend_class_entry *phady_cache_cacheinterface_ce;
zend_class_entry *phady_messaging_adapter_messaginginterface_ce;
zend_class_entry *phady_security_core_user_userinterface_ce;
zend_class_entry *phady_security_groups_groupinterface_ce;
zend_class_entry *phady_common_entities_modelbase_ce;
zend_class_entry *phady_core_kernel_ce;
zend_class_entry *phady_0__closure_ce;
zend_class_entry *phady_1__closure_ce;
zend_class_entry *phady_2__closure_ce;
zend_class_entry *phady_3__closure_ce;
zend_class_entry *phady_4__closure_ce;
zend_class_entry *phady_5__closure_ce;
zend_class_entry *phady_6__closure_ce;
zend_class_entry *phady_7__closure_ce;
zend_class_entry *phady_8__closure_ce;
zend_class_entry *phady_cache_cachehandler_ce;
zend_class_entry *phady_common_controllers_controllerbase_ce;
zend_class_entry *phady_config_yaml_ce;
zend_class_entry *phady_console_command_ce;
zend_class_entry *phady_core_kernelcli_ce;
zend_class_entry *phady_core_kernelmvc_ce;
zend_class_entry *phady_core_namespacehandler_ce;
zend_class_entry *phady_core_parameter_ce;
zend_class_entry *phady_db_databasehandler_ce;
zend_class_entry *phady_exception_ce;
zend_class_entry *phady_mail_mailreader_ce;
zend_class_entry *phady_messaging_adapter_rabbitmq_ce;
zend_class_entry *phady_messaging_messaging_ce;
zend_class_entry *phady_report_excel_template_excelmultitable_ce;
zend_class_entry *phady_route_router_ce;
zend_class_entry *phady_security_authentication_authhandler_ce;
zend_class_entry *phady_security_core_authorization_acl_ce;
zend_class_entry *phady_security_core_models_entities_actions_ce;
zend_class_entry *phady_security_core_models_entities_groups_ce;
zend_class_entry *phady_security_core_models_entities_modules_ce;
zend_class_entry *phady_security_core_models_entities_permissions_ce;
zend_class_entry *phady_security_core_models_entities_resources_ce;
zend_class_entry *phady_security_core_models_entities_roles_ce;
zend_class_entry *phady_security_core_models_entities_userrole_ce;
zend_class_entry *phady_security_core_models_entities_users_ce;
zend_class_entry *phady_security_core_models_exception_ce;
zend_class_entry *phady_security_core_models_repositories_users_ce;
zend_class_entry *phady_security_core_role_roles_ce;
zend_class_entry *phady_security_core_user_users_ce;
zend_class_entry *phady_security_exception_ce;
zend_class_entry *phady_security_groups_groupbase_ce;
zend_class_entry *phady_util_datetime_ce;
zend_class_entry *phady_util_file_ce;
zend_class_entry *phady_util_out_ce;
zend_class_entry *phady_util_random_ce;
zend_class_entry *phady_util_text_ce;
zend_class_entry *phady_util_tools_ce;
zend_class_entry *phady_util_uuid_ce;
zend_class_entry *phady_version_ce;

ZEND_DECLARE_MODULE_GLOBALS(phady)

PHP_INI_BEGIN()
	
PHP_INI_END()

static PHP_MINIT_FUNCTION(phady)
{
#if PHP_VERSION_ID < 50500
	char* old_lc_all = setlocale(LC_ALL, NULL);
	if (old_lc_all) {
		size_t len = strlen(old_lc_all);
		char *tmp  = calloc(len+1, 1);
		if (UNEXPECTED(!tmp)) {
			return FAILURE;
		}

		memcpy(tmp, old_lc_all, len);
		old_lc_all = tmp;
	}

	setlocale(LC_ALL, "C");
#endif
	REGISTER_INI_ENTRIES();
	ZEPHIR_INIT(Phady_Cache_CacheInterface);
	ZEPHIR_INIT(Phady_Messaging_Adapter_MessagingInterface);
	ZEPHIR_INIT(Phady_Security_Core_User_UserInterface);
	ZEPHIR_INIT(Phady_Security_Groups_GroupInterface);
	ZEPHIR_INIT(Phady_Common_Entities_ModelBase);
	ZEPHIR_INIT(Phady_Core_Kernel);
	ZEPHIR_INIT(Phady_Cache_CacheHandler);
	ZEPHIR_INIT(Phady_Common_Controllers_ControllerBase);
	ZEPHIR_INIT(Phady_Config_Yaml);
	ZEPHIR_INIT(Phady_Console_Command);
	ZEPHIR_INIT(Phady_Core_KernelCli);
	ZEPHIR_INIT(Phady_Core_KernelMvc);
	ZEPHIR_INIT(Phady_Core_NamespaceHandler);
	ZEPHIR_INIT(Phady_Core_Parameter);
	ZEPHIR_INIT(Phady_Db_DatabaseHandler);
	ZEPHIR_INIT(Phady_Exception);
	ZEPHIR_INIT(Phady_Mail_MailReader);
	ZEPHIR_INIT(Phady_Messaging_Adapter_RabbitMQ);
	ZEPHIR_INIT(Phady_Messaging_Messaging);
	ZEPHIR_INIT(Phady_Report_Excel_Template_ExcelMultiTable);
	ZEPHIR_INIT(Phady_Route_Router);
	ZEPHIR_INIT(Phady_Security_Authentication_AuthHandler);
	ZEPHIR_INIT(Phady_Security_Core_Authorization_Acl);
	ZEPHIR_INIT(Phady_Security_Core_Models_Entities_Actions);
	ZEPHIR_INIT(Phady_Security_Core_Models_Entities_Groups);
	ZEPHIR_INIT(Phady_Security_Core_Models_Entities_Modules);
	ZEPHIR_INIT(Phady_Security_Core_Models_Entities_Permissions);
	ZEPHIR_INIT(Phady_Security_Core_Models_Entities_Resources);
	ZEPHIR_INIT(Phady_Security_Core_Models_Entities_Roles);
	ZEPHIR_INIT(Phady_Security_Core_Models_Entities_UserRole);
	ZEPHIR_INIT(Phady_Security_Core_Models_Entities_Users);
	ZEPHIR_INIT(Phady_Security_Core_Models_Exception);
	ZEPHIR_INIT(Phady_Security_Core_Models_Repositories_Users);
	ZEPHIR_INIT(Phady_Security_Core_Role_Roles);
	ZEPHIR_INIT(Phady_Security_Core_User_Users);
	ZEPHIR_INIT(Phady_Security_Exception);
	ZEPHIR_INIT(Phady_Security_Groups_GroupBase);
	ZEPHIR_INIT(Phady_Util_DateTime);
	ZEPHIR_INIT(Phady_Util_File);
	ZEPHIR_INIT(Phady_Util_Out);
	ZEPHIR_INIT(Phady_Util_Random);
	ZEPHIR_INIT(Phady_Util_Text);
	ZEPHIR_INIT(Phady_Util_Tools);
	ZEPHIR_INIT(Phady_Util_Uuid);
	ZEPHIR_INIT(Phady_Version);
	ZEPHIR_INIT(phady_0__closure);
	ZEPHIR_INIT(phady_1__closure);
	ZEPHIR_INIT(phady_2__closure);
	ZEPHIR_INIT(phady_3__closure);
	ZEPHIR_INIT(phady_4__closure);
	ZEPHIR_INIT(phady_5__closure);
	ZEPHIR_INIT(phady_6__closure);
	ZEPHIR_INIT(phady_7__closure);
	ZEPHIR_INIT(phady_8__closure);

#if PHP_VERSION_ID < 50500
	setlocale(LC_ALL, old_lc_all);
	free(old_lc_all);
#endif
	return SUCCESS;
}

#ifndef ZEPHIR_RELEASE
static PHP_MSHUTDOWN_FUNCTION(phady)
{

	zephir_deinitialize_memory(TSRMLS_C);
	UNREGISTER_INI_ENTRIES();
	return SUCCESS;
}
#endif

/**
 * Initialize globals on each request or each thread started
 */
static void php_zephir_init_globals(zend_phady_globals *phady_globals TSRMLS_DC)
{
	phady_globals->initialized = 0;

	/* Memory options */
	phady_globals->active_memory = NULL;

	/* Virtual Symbol Tables */
	phady_globals->active_symbol_table = NULL;

	/* Cache Enabled */
	phady_globals->cache_enabled = 1;

	/* Recursive Lock */
	phady_globals->recursive_lock = 0;

	/* Static cache */
	memset(phady_globals->scache, '\0', sizeof(zephir_fcall_cache_entry*) * ZEPHIR_MAX_CACHE_SLOTS);


}

static PHP_RINIT_FUNCTION(phady)
{

	zend_phady_globals *phady_globals_ptr = ZEPHIR_VGLOBAL;

	php_zephir_init_globals(phady_globals_ptr TSRMLS_CC);
	//zephir_init_interned_strings(TSRMLS_C);

	zephir_initialize_memory(phady_globals_ptr TSRMLS_CC);


	return SUCCESS;
}

static PHP_RSHUTDOWN_FUNCTION(phady)
{

	

	zephir_deinitialize_memory(TSRMLS_C);
	return SUCCESS;
}

static PHP_MINFO_FUNCTION(phady)
{
	php_info_print_box_start(0);
	php_printf("%s", PHP_PHADY_DESCRIPTION);
	php_info_print_box_end();

	php_info_print_table_start();
	php_info_print_table_header(2, PHP_PHADY_NAME, "enabled");
	php_info_print_table_row(2, "Author", PHP_PHADY_AUTHOR);
	php_info_print_table_row(2, "Version", PHP_PHADY_VERSION);
	php_info_print_table_row(2, "Build Date", __DATE__ " " __TIME__ );
	php_info_print_table_row(2, "Powered by Zephir", "Version " PHP_PHADY_ZEPVERSION);
	php_info_print_table_end();

	DISPLAY_INI_ENTRIES();
}

static PHP_GINIT_FUNCTION(phady)
{
	php_zephir_init_globals(phady_globals TSRMLS_CC);
}

static PHP_GSHUTDOWN_FUNCTION(phady)
{

}


zend_function_entry php_phady_functions[] = {
ZEND_FE_END

};

zend_module_entry phady_module_entry = {
	STANDARD_MODULE_HEADER_EX,
	NULL,
	NULL,
	PHP_PHADY_EXTNAME,
	php_phady_functions,
	PHP_MINIT(phady),
#ifndef ZEPHIR_RELEASE
	PHP_MSHUTDOWN(phady),
#else
	NULL,
#endif
	PHP_RINIT(phady),
	PHP_RSHUTDOWN(phady),
	PHP_MINFO(phady),
	PHP_PHADY_VERSION,
	ZEND_MODULE_GLOBALS(phady),
	PHP_GINIT(phady),
	PHP_GSHUTDOWN(phady),
	NULL,
	STANDARD_MODULE_PROPERTIES_EX
};

#ifdef COMPILE_DL_PHADY
ZEND_GET_MODULE(phady)
#endif