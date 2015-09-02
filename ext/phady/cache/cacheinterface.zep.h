
extern zend_class_entry *phady_cache_cacheinterface_ce;

ZEPHIR_INIT_CLASS(Phady_Cache_CacheInterface);

ZEPHIR_INIT_FUNCS(phady_cache_cacheinterface_method_entry) {
	PHP_ABSTRACT_ME(Phady_Cache_CacheInterface, getAdapter, NULL)
	PHP_FE_END
};
