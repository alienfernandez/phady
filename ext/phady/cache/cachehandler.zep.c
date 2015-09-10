
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "ext/phalcon/phalcon/cache/frontend/data.zep.h"


/**
  * @class Phady\Cache\CacheHandler -  Cache handlers for app
  *
  * @author  Alien Fernández Fuentes <alienfernandez85@gmail.com>
  * @package Core
  * @copyright (c) 2015
  * @version 1.0.0
  */
ZEPHIR_INIT_CLASS(Phady_Cache_CacheHandler) {

	ZEPHIR_REGISTER_CLASS(Phady\\Cache, CacheHandler, phady, cache_cachehandler, phady_cache_cachehandler_method_entry, ZEND_ACC_FINAL_CLASS);

	/**
	 * @var array config - Config cache
	 */
	zend_declare_property_null(phady_cache_cachehandler_ce, SL("config"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_class_constant_string(phady_cache_cachehandler_ce, SL("REDIS_CACHE"), "redis" TSRMLS_CC);

	zend_declare_class_constant_string(phady_cache_cachehandler_ce, SL("MEMCACHE_CACHE"), "memcache" TSRMLS_CC);

	zend_class_implements(phady_cache_cachehandler_ce TSRMLS_CC, 1, phady_cache_cacheinterface_ce);
	return SUCCESS;

}

/**
 * @param array config - Config db
 */
PHP_METHOD(Phady_Cache_CacheHandler, __construct) {

	zval *config_param = NULL;
	zval *config = NULL;

	zephir_fetch_params(0, 1, 0, &config_param);

	config = config_param;



	zephir_update_property_this(this_ptr, SL("config"), config TSRMLS_CC);

}

/**
 *
 * @return DBAdapter Data base adapter
 */
PHP_METHOD(Phady_Cache_CacheHandler, getAdapter) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_1;
	zval *cacheConfig, *frontCache, *_0;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
	zephir_array_fetch_string(&cacheConfig, _0, SL("cache"), PH_NOISY | PH_READONLY, "phady/cache/cachehandler.zep", 51 TSRMLS_CC);
	ZEPHIR_INIT_VAR(frontCache);
	object_init_ex(frontCache, phalcon_cache_frontend_data_ce);
	ZEPHIR_INIT_VAR(_1);
	zephir_create_array(_1, 1, 0 TSRMLS_CC);
	add_assoc_long_ex(_1, SS("lifetime"), 172800);
	ZEPHIR_CALL_METHOD(NULL, frontCache, "__construct", NULL, 0, _1);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

