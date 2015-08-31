
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
  * @interface Phady\Cache\CacheInterface - Cache interface for all cache adapter
  *
  * @author  Alien Fernández Fuentes <alienfernandez85@gmail.com>
  * @package Cache
  * @copyright (c) 2015
  * @version 1.0.0
  */
ZEPHIR_INIT_CLASS(Phady_Cache_CacheInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phady\\Cache, CacheInterface, phady, cache_cacheinterface, phady_cache_cacheinterface_method_entry);

	return SUCCESS;

}

/**
 * @return CacheAdapter - Cache Adapter
 */
ZEPHIR_DOC_METHOD(Phady_Cache_CacheInterface, getAdapter);

