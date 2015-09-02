
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
#include "kernel/operators.h"
#include "ext/phalcon/phalcon/cache/frontend/data.zep.h"
#include "ext/phalcon/phalcon/cache/backend/redis.zep.h"
#include "ext/phalcon/phalcon/cache/backend/memcache.zep.h"


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
	zval *arrCacheConfig = NULL, *cacheConfig, *adapter = NULL, *frontCache, *_0, *_2, *_3, *_4, *_5 = NULL, *_6, *_7, *_8, *_9, *_10, *_11;

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
	zephir_array_fetch_string(&_2, cacheConfig, SL("driver"), PH_NOISY | PH_READONLY, "phady/cache/cachehandler.zep", 57 TSRMLS_CC);
	do {
		if (ZEPHIR_IS_STRING(_2, "redis")) {
			ZEPHIR_INIT_VAR(arrCacheConfig);
			zephir_create_array(arrCacheConfig, 4, 0 TSRMLS_CC);
			zephir_array_fetch_string(&_3, cacheConfig, SL("redis"), PH_NOISY | PH_READONLY, "phady/cache/cachehandler.zep", 60 TSRMLS_CC);
			zephir_array_fetch_string(&_4, _3, SL("default"), PH_NOISY | PH_READONLY, "phady/cache/cachehandler.zep", 60 TSRMLS_CC);
			ZEPHIR_OBS_VAR(_5);
			zephir_array_fetch_string(&_5, _4, SL("host"), PH_NOISY, "phady/cache/cachehandler.zep", 60 TSRMLS_CC);
			zephir_array_update_string(&arrCacheConfig, SL("host"), &_5, PH_COPY | PH_SEPARATE);
			zephir_array_fetch_string(&_6, cacheConfig, SL("redis"), PH_NOISY | PH_READONLY, "phady/cache/cachehandler.zep", 61 TSRMLS_CC);
			zephir_array_fetch_string(&_7, _6, SL("default"), PH_NOISY | PH_READONLY, "phady/cache/cachehandler.zep", 61 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(_5);
			zephir_array_fetch_string(&_5, _7, SL("port"), PH_NOISY, "phady/cache/cachehandler.zep", 61 TSRMLS_CC);
			zephir_array_update_string(&arrCacheConfig, SL("port"), &_5, PH_COPY | PH_SEPARATE);
			zephir_array_fetch_string(&_8, cacheConfig, SL("redis"), PH_NOISY | PH_READONLY, "phady/cache/cachehandler.zep", 62 TSRMLS_CC);
			zephir_array_fetch_string(&_9, _8, SL("default"), PH_NOISY | PH_READONLY, "phady/cache/cachehandler.zep", 62 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(_5);
			zephir_array_fetch_string(&_5, _9, SL("persistent"), PH_NOISY, "phady/cache/cachehandler.zep", 62 TSRMLS_CC);
			zephir_array_update_string(&arrCacheConfig, SL("persistent"), &_5, PH_COPY | PH_SEPARATE);
			zephir_array_fetch_string(&_10, cacheConfig, SL("redis"), PH_NOISY | PH_READONLY, "phady/cache/cachehandler.zep", 63 TSRMLS_CC);
			zephir_array_fetch_string(&_11, _10, SL("default"), PH_NOISY | PH_READONLY, "phady/cache/cachehandler.zep", 63 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(_5);
			zephir_array_fetch_string(&_5, _11, SL("auth"), PH_NOISY, "phady/cache/cachehandler.zep", 64 TSRMLS_CC);
			zephir_array_update_string(&arrCacheConfig, SL("auth"), &_5, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_VAR(adapter);
			object_init_ex(adapter, phalcon_cache_backend_redis_ce);
			ZEPHIR_CALL_METHOD(NULL, adapter, "__construct", NULL, 0, arrCacheConfig);
			zephir_check_call_status();
			break;
		}
		if (ZEPHIR_IS_STRING(_2, "memcache")) {
			ZEPHIR_INIT_NVAR(arrCacheConfig);
			zephir_create_array(arrCacheConfig, 3, 0 TSRMLS_CC);
			zephir_array_fetch_string(&_3, cacheConfig, SL("memcache"), PH_NOISY | PH_READONLY, "phady/cache/cachehandler.zep", 69 TSRMLS_CC);
			zephir_array_fetch_string(&_4, _3, SL("default"), PH_NOISY | PH_READONLY, "phady/cache/cachehandler.zep", 69 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(_5);
			zephir_array_fetch_string(&_5, _4, SL("host"), PH_NOISY, "phady/cache/cachehandler.zep", 69 TSRMLS_CC);
			zephir_array_update_string(&arrCacheConfig, SL("host"), &_5, PH_COPY | PH_SEPARATE);
			zephir_array_fetch_string(&_6, cacheConfig, SL("memcache"), PH_NOISY | PH_READONLY, "phady/cache/cachehandler.zep", 70 TSRMLS_CC);
			zephir_array_fetch_string(&_7, _6, SL("default"), PH_NOISY | PH_READONLY, "phady/cache/cachehandler.zep", 70 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(_5);
			zephir_array_fetch_string(&_5, _7, SL("port"), PH_NOISY, "phady/cache/cachehandler.zep", 70 TSRMLS_CC);
			zephir_array_update_string(&arrCacheConfig, SL("port"), &_5, PH_COPY | PH_SEPARATE);
			zephir_array_fetch_string(&_8, cacheConfig, SL("memcache"), PH_NOISY | PH_READONLY, "phady/cache/cachehandler.zep", 71 TSRMLS_CC);
			zephir_array_fetch_string(&_9, _8, SL("default"), PH_NOISY | PH_READONLY, "phady/cache/cachehandler.zep", 71 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(_5);
			zephir_array_fetch_string(&_5, _9, SL("persistent"), PH_NOISY, "phady/cache/cachehandler.zep", 72 TSRMLS_CC);
			zephir_array_update_string(&arrCacheConfig, SL("persistent"), &_5, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_NVAR(adapter);
			object_init_ex(adapter, phalcon_cache_backend_memcache_ce);
			ZEPHIR_CALL_METHOD(NULL, adapter, "__construct", NULL, 0, arrCacheConfig);
			zephir_check_call_status();
			break;
		}
		ZEPHIR_INIT_NVAR(arrCacheConfig);
		zephir_create_array(arrCacheConfig, 4, 0 TSRMLS_CC);
		zephir_array_fetch_string(&_3, cacheConfig, SL("redis"), PH_NOISY | PH_READONLY, "phady/cache/cachehandler.zep", 77 TSRMLS_CC);
		zephir_array_fetch_string(&_4, _3, SL("default"), PH_NOISY | PH_READONLY, "phady/cache/cachehandler.zep", 77 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(_5);
		zephir_array_fetch_string(&_5, _4, SL("host"), PH_NOISY, "phady/cache/cachehandler.zep", 77 TSRMLS_CC);
		zephir_array_update_string(&arrCacheConfig, SL("host"), &_5, PH_COPY | PH_SEPARATE);
		zephir_array_fetch_string(&_6, cacheConfig, SL("redis"), PH_NOISY | PH_READONLY, "phady/cache/cachehandler.zep", 78 TSRMLS_CC);
		zephir_array_fetch_string(&_7, _6, SL("default"), PH_NOISY | PH_READONLY, "phady/cache/cachehandler.zep", 78 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(_5);
		zephir_array_fetch_string(&_5, _7, SL("port"), PH_NOISY, "phady/cache/cachehandler.zep", 78 TSRMLS_CC);
		zephir_array_update_string(&arrCacheConfig, SL("port"), &_5, PH_COPY | PH_SEPARATE);
		zephir_array_fetch_string(&_8, cacheConfig, SL("redis"), PH_NOISY | PH_READONLY, "phady/cache/cachehandler.zep", 79 TSRMLS_CC);
		zephir_array_fetch_string(&_9, _8, SL("default"), PH_NOISY | PH_READONLY, "phady/cache/cachehandler.zep", 79 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(_5);
		zephir_array_fetch_string(&_5, _9, SL("persistent"), PH_NOISY, "phady/cache/cachehandler.zep", 79 TSRMLS_CC);
		zephir_array_update_string(&arrCacheConfig, SL("persistent"), &_5, PH_COPY | PH_SEPARATE);
		zephir_array_fetch_string(&_10, cacheConfig, SL("redis"), PH_NOISY | PH_READONLY, "phady/cache/cachehandler.zep", 80 TSRMLS_CC);
		zephir_array_fetch_string(&_11, _10, SL("default"), PH_NOISY | PH_READONLY, "phady/cache/cachehandler.zep", 80 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(_5);
		zephir_array_fetch_string(&_5, _11, SL("auth"), PH_NOISY, "phady/cache/cachehandler.zep", 81 TSRMLS_CC);
		zephir_array_update_string(&arrCacheConfig, SL("auth"), &_5, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(adapter);
		object_init_ex(adapter, phalcon_cache_backend_redis_ce);
		ZEPHIR_CALL_METHOD(NULL, adapter, "__construct", NULL, 0, arrCacheConfig);
		zephir_check_call_status();
		break;
	} while(0);

	RETURN_CCTOR(adapter);

}

