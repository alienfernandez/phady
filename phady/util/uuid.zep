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
  * @class Phady\Util\Uuid - Util class for generate uuid
  *
  * @author  Alien Fernández Fuentes <alienfernandez85@gmail.com>
  * @package Util
  * @copyright (c) 2015
  * @version 1.0.0
  */
class Uuid
{

    /**
     * Generates version 1: MAC address
     */
    public static function v1()
    {
        /*var context, uuid;
        if (!function_exists("uuid_create")) {
            return false;
        }

        let context = null;
        let uuid = null;
        uuid_create(context);
        uuid_make(context, UUID_MAKE_V1);
        uuid_export(context, UUID_FMT_STR, uuid);
        return trim(uuid);*/
    }

	/**
     *
     * Generate v4 UUID
     *
     * Version 4 UUIDs are pseudo-random.
     */
    public static function v4() -> string
    {
        return sprintf("%04x%04x-%04x-%04x-%04x-%04x%04x%04x",
            // 32 bits for "time_low"
            mt_rand(0, 0xffff), mt_rand(0, 0xffff),
            // 16 bits for "time_mid"
            mt_rand(0, 0xffff),
            // 16 bits for "time_hi_and_version",
            // four most significant bits holds version number 4
            mt_rand(0, 0x0fff) | 0x4000,
            // 16 bits, 8 bits for "clk_seq_hi_res",
            // 8 bits for "clk_seq_low",
            // two most significant bits holds zero and one for variant DCE1.1
            mt_rand(0, 0x3fff) | 0x8000,
            // 48 bits for "node"
            mt_rand(0, 0xffff), mt_rand(0, 0xffff), mt_rand(0, 0xffff)
        );
    }

    /**
     * Generate v5 UUID
     *
     * Version 5 UUIDs are named based. They require a namespace (another
     * valid UUID) and a value (the name). Given the same namespace and
     * name, the output is always the same.
     *
     * @param uuid $namespace
     * @param string $name
     */
    public static function v5(string ns, string name)
    {
        /*
        var nhex, nstr, hash;
        if (!self::is_valid(ns)) {
            return false;
        }

        // Get hexadecimal components of namespace
        let nhex = str_replace(["-","{","}"], "", ns);

        // Binary Value
        let nstr = "";

        // Convert Namespace UUID to bits
        for (i = 0; i < strlen(nhex); i += 2) {
            let nstr .= chr(hexdec(nhex[i] . nhex[i + 1]));
        }

        // Calculate hash value
        let hash = sha1(nstr . name);

        return sprintf("%08s-%04s-%04x-%04x-%12s",
            // 32 bits for "time_low"
            substr(hash, 0, 8),
            // 16 bits for "time_mid"
            substr(hash, 8, 4),
            // 16 bits for "time_hi_and_version",
            // four most significant bits holds version number 5
            (hexdec(substr(hash, 12, 4)) & 0x0fff) | 0x5000,
            // 16 bits, 8 bits for "clk_seq_hi_res",
            // 8 bits for "clk_seq_low",
            // two most significant bits holds zero and one for variant DCE1.1
            (hexdec(substr(hash, 16, 4)) & 0x3fff) | 0x8000,
            // 48 bits for "node"
            substr(hash, 20, 12)
        );*/
    }

    public static function is_valid(uuid)
    {
        return preg_match("/^\{?[0-9a-f]{8}\-?[0-9a-f]{4}\-?[0-9a-f]{4}\-?" .
            "[0-9a-f]{4}\-?[0-9a-f]{12}\}?$/i", $uuid) === 1;
    }
}
