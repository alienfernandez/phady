/*
+------------------------------------------------------------------------+
| Phady Framework                                                        |
+------------------------------------------------------------------------+
| Copyright (c) 2015                                                     |
+------------------------------------------------------------------------+
| Phady Framework is a complement of Phalcon Framework                   |
|                                                                        |
+------------------------------------------------------------------------+
| Authors: Alien fernandez Fuentes <alienfernandez85@gmail.com>          |
+------------------------------------------------------------------------+
*/

namespace Phady\Cache;

use Phalcon\Cache\Frontend\Data as CacheData;
use Phalcon\Cache\Backend\Redis;
use Phalcon\Cache\Backend\Memcache;
/**
  * @class Phady\Cache\CacheHandler -  Cache handlers for app
  *
  * @author  Alien Fernández Fuentes <alienfernandez85@gmail.com>
  * @package Core
  * @copyright (c) 2015
  * @version 1.0.0
  */
final class CacheHandler implements \Phady\Cache\CacheInterface
{
	const REDIS_CACHE = "redis";
	const MEMCACHE_CACHE = "memcache";
	
    /**
     * @var array config - Config cache
     */
    protected config;

    /**
     * @param array config - Config db
     */
    public function __construct(array! config) {
        //Read config file
        let this->config = config;
    }

    /**
     *
     * @return DBAdapter Data base adapter
     */
    public function getAdapter() {
        var arrCacheConfig, cacheConfig, adapter, frontCache, cacheDefault;
        let cacheConfig = this->config["cache"];

        //print_r(arrCacheConfig);die;
        let frontCache = new CacheData([
            "lifetime" : 172800
        ]);
        /*
        if (array_key_exists(self::REDIS_CACHE, cacheConfig) && cacheConfig[self::REDIS_CACHE]) {
            let cacheDefault = cacheConfig[self::REDIS_CACHE]["default"];
            let arrCacheConfig = [
                "host" : array_key_exists("host", cacheDefault) ? cacheDefault["host"] : "",
                "port" : array_key_exists("port", cacheDefault) ? cacheDefault["port"] : "",
                "persistent" : array_key_exists("persistent", cacheDefault) ? cacheDefault["persistent"] : "",
                "auth" : array_key_exists("persistent", cacheDefault) ? cacheDefault["auth"] : ""
            ];
            let adapter = new Redis(arrCacheConfig);
        }
        if (array_key_exists(self::MEMCACHE_CACHE, cacheConfig) && cacheConfig[self::MEMCACHE_CACHE]) {
            let cacheDefault = cacheConfig[self::MEMCACHE_CACHE]["default"];
            let arrCacheConfig = [
                "host" : array_key_exists("host", cacheDefault) ? cacheDefault["host"] : "",
                "port" : array_key_exists("port", cacheDefault) ? cacheDefault["port"] : "",
                "persistent" : array_key_exists("persistent", cacheDefault) ? cacheDefault["persistent"] : ""
            ];
            let adapter = new Memcache(arrCacheConfig);
        }
        return adapter;*/
    }
}
