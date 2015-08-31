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

/**
  * @interface Phady\Cache\CacheInterface - Cache interface for all cache adapter
  *
  * @author  Alien Fernández Fuentes <alienfernandez85@gmail.com>
  * @package Cache
  * @copyright (c) 2015
  * @version 1.0.0
  */
interface CacheInterface
{

    /**
     * @return CacheAdapter - Cache Adapter
     */
	public function getAdapter();

}
