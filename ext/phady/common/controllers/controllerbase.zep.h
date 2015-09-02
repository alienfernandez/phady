
extern zend_class_entry *phady_common_controllers_controllerbase_ce;

ZEPHIR_INIT_CLASS(Phady_Common_Controllers_ControllerBase);

PHP_METHOD(Phady_Common_Controllers_ControllerBase, initialize);

ZEPHIR_INIT_FUNCS(phady_common_controllers_controllerbase_method_entry) {
	PHP_ME(Phady_Common_Controllers_ControllerBase, initialize, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
