
extern zend_class_entry *phady_cache_cachehandler_ce;

ZEPHIR_INIT_CLASS(Phady_Cache_CacheHandler);

PHP_METHOD(Phady_Cache_CacheHandler, __construct);
PHP_METHOD(Phady_Cache_CacheHandler, getAdapter);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phady_cache_cachehandler___construct, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, config, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phady_cache_cachehandler_method_entry) {
	PHP_ME(Phady_Cache_CacheHandler, __construct, arginfo_phady_cache_cachehandler___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phady_Cache_CacheHandler, getAdapter, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
