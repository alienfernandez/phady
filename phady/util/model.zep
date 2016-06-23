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

namespace Phady\Util;

/**
  * @class Phady\Util\Model - Util class for model
  *
  * @author  Alien Fernández Fuentes <alienfernandez85@gmail.com>
  * @package Util
  * @copyright (c) 2015
  * @version 1.0.0
  */
class Model
{

    /**
     * Assign data to object model
     */
    public static function asssignData(objectAssign, array arrData)
    {
        var key, value;
        for key, value in arrData {
            //Verifify exist property in model
            if (property_exists(objectAssign, key)) {
                let objectAssign->{key} = value;
            }
        }
    }
}
