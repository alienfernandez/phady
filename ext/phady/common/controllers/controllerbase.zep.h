
extern zend_class_entry *phady_common_controllers_controllerbase_ce;

ZEPHIR_INIT_CLASS(Phady_Common_Controllers_ControllerBase);

PHP_METHOD(Phady_Common_Controllers_ControllerBase, initialize);
PHP_METHOD(Phady_Common_Controllers_ControllerBase, beforeExecuteRoute);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phady_common_controllers_controllerbase_beforeexecuteroute, 0, 0, 1)
	ZEND_ARG_INFO(0, dispatcher)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phady_common_controllers_controllerbase_method_entry) {
	PHP_ME(Phady_Common_Controllers_ControllerBase, initialize, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phady_Common_Controllers_ControllerBase, beforeExecuteRoute, arginfo_phady_common_controllers_controllerbase_beforeexecuteroute, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
