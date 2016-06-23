
extern zend_class_entry *phady_route_router_ce;

ZEPHIR_INIT_CLASS(Phady_Route_Router);

PHP_METHOD(Phady_Route_Router, __construct);
PHP_METHOD(Phady_Route_Router, setConfig);
PHP_METHOD(Phady_Route_Router, getRouter);
PHP_METHOD(Phady_Route_Router, setDefaultRoute);
PHP_METHOD(Phady_Route_Router, setSystemRoutes);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phady_route_router_setconfig, 0, 0, 1)
	ZEND_ARG_INFO(0, config)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phady_route_router_setsystemroutes, 0, 0, 1)
	ZEND_ARG_INFO(0, rootDir)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phady_route_router_method_entry) {
	PHP_ME(Phady_Route_Router, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phady_Route_Router, setConfig, arginfo_phady_route_router_setconfig, ZEND_ACC_PUBLIC)
	PHP_ME(Phady_Route_Router, getRouter, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phady_Route_Router, setDefaultRoute, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phady_Route_Router, setSystemRoutes, arginfo_phady_route_router_setsystemroutes, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
