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
        var arrCacheConfig, cacheConfig, adapter, frontCache;
        let cacheConfig = this->config["cache"];

        //print_r(arrCacheConfig);die;
        let frontCache = new CacheData([
            "lifetime" : 172800
        ]);
        switch cacheConfig["driver"] {
            case self::REDIS_CACHE :
                let arrCacheConfig = [
                    "host" : cacheConfig[self::REDIS_CACHE]["default"]["host"],
                    "port" : cacheConfig[self::REDIS_CACHE]["default"]["port"],
                    "persistent" : cacheConfig[self::REDIS_CACHE]["default"]["persistent"],
                    "auth" : cacheConfig[self::REDIS_CACHE]["default"]["auth"]
                ];
                let adapter = new Redis(arrCacheConfig);
                break;
            case self::MEMCACHE_CACHE :
                let arrCacheConfig = [
                    "host" : cacheConfig[self::MEMCACHE_CACHE]["default"]["host"],
                    "port" : cacheConfig[self::MEMCACHE_CACHE]["default"]["port"],
                    "persistent" : cacheConfig[self::MEMCACHE_CACHE]["default"]["persistent"]
                ];
                let adapter = new Memcache(arrCacheConfig);
                break;
            default :
                let arrCacheConfig = [
                    "host" : cacheConfig[self::REDIS_CACHE]["default"]["host"],
                    "port" : cacheConfig[self::REDIS_CACHE]["default"]["port"],
                    "persistent" : cacheConfig[self::REDIS_CACHE]["default"]["persistent"],
                    "auth" : cacheConfig[self::REDIS_CACHE]["default"]["auth"]
                ];
                let adapter = new Redis(arrCacheConfig);
                break;
        }
        return adapter;
    }
}
