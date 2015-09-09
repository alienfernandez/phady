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
  * @class Phady\Util\Tools - Util class tools for app, server vars, ini values, etc...
  *
  * @author  Alien Fernández Fuentes <alienfernandez85@gmail.com>
  * @package Util
  * @copyright (c) 2015
  * @version 1.0.0
  */
class Tools
{
    const REQUEST_PROTOCOL_HTTP = "http";
    const REQUEST_PROTOCOL_HTTPS = "https";

    /**
     * Get the server variable SERVER_NAME
     *
     * @return string server name
     */
    public static function getServerName() -> string
    {
        var server = "";
        if (isset(_SERVER["HTTP_X_FORWARDED_SERVER"]) && _SERVER["HTTP_X_FORWARDED_SERVER"]){
            let server = _SERVER["HTTP_X_FORWARDED_SERVER"];
        }else{
            let server = _SERVER["SERVER_NAME"];
        }
        return server;
    }

    /**
     * Get the server variable HTTP_HOST
     *
     * @return string host http name
     */
    public static function getHttpHost() -> string
    {
        var server = "";
        if (isset(_SERVER["HTTP_HOST"]) && _SERVER["HTTP_HOST"]){
            let server = _SERVER["HTTP_HOST"];
        }
        return server;
    }

    /**
     * Get the protocol used by the app - http|https
     *
     * @return string
     */
    public function getRequestProtocol() -> string {
        var isSecure = false;
        if (isset(_SERVER["HTTPS"]) && _SERVER["HTTPS"] == "on") {
            let isSecure = true;
        } elseif ((array_key_exists("HTTP_X_FORWARDED_PROTO", _SERVER) && !empty(_SERVER["HTTP_X_FORWARDED_PROTO"])) &&
                   (array_key_exists("HTTP_X_FORWARDED_PROTO", _SERVER) && _SERVER["HTTP_X_FORWARDED_PROTO"] == "https") ||
                    (array_key_exists("HTTP_X_FORWARDED_SSL", _SERVER) && !empty(_SERVER["HTTP_X_FORWARDED_SSL"]) &&
                    _SERVER["HTTP_X_FORWARDED_SSL"] == "on")) {
            let isSecure = true;
        }
        return isSecure ? self::REQUEST_PROTOCOL_HTTP : self::REQUEST_PROTOCOL_HTTPS;
    }

    /**
     * Get the server variable REMOTE_ADDR, or the first ip of HTTP_X_FORWARDED_FOR (when using proxy)
     *
     * @return string $remote_addr ip of client
     */
    public static function getRemoteAddr()
    {
        var ips, remoteAddr;
        // This condition is necessary when using CDN, don't remove it.
        if (isset(_SERVER["HTTP_X_FORWARDED_FOR"]) && _SERVER["HTTP_X_FORWARDED_FOR"] && (!isset(_SERVER["REMOTE_ADDR"])
            || preg_match("/^127\..*/i", trim(_SERVER["REMOTE_ADDR"])) || preg_match("/^172\.16.*/i", trim(_SERVER["REMOTE_ADDR"]))
            || preg_match("/^192\.168\.*/i", trim(_SERVER["REMOTE_ADDR"])) || preg_match("/^10\..*/i", trim(_SERVER["REMOTE_ADDR"]))))
        {
            if (strpos(_SERVER["HTTP_X_FORWARDED_FOR"], ","))
            {
                let ips = explode(",", _SERVER["HTTP_X_FORWARDED_FOR"]);
                let remoteAddr = ips[0];
            }
            else{
                let remoteAddr = _SERVER["HTTP_X_FORWARDED_FOR"];
            }
        }else{
            let remoteAddr = _SERVER["REMOTE_ADDR"];
        }
        return remoteAddr;
    }

    /**
     * Check if the current page use SSL connection on not
     *
     * @return bool uses SSL
     */
    public static function usingSecureMode() -> boolean
    {
        var secureMode;
        if (isset(_SERVER["HTTPS"])){
            let secureMode = (_SERVER["HTTPS"] == 1 || strtolower(_SERVER["HTTPS"]) == "on");
        }
        // _SERVER["SSL"] exists only in some specific configuration
        elseif (isset(_SERVER["SSL"])){
            let secureMode = (_SERVER["SSL"] == 1 || strtolower(_SERVER["SSL"]) == "on");
        }
        else{
            let secureMode = false;
        }
        return secureMode;
    }

    /**
     * getMemoryLimit allow to get the memory limit in octet
     *
     * @return int the memory limit value in octet
     */
    public static function getMemoryLimit()
    {
        var memory_limit, getOctect;
        let memory_limit = ini_get("memory_limit");
        print_r(memory_limit);
        let getOctect = self::getOctets(memory_limit);
        return getOctect;
    }

    /**
     * getOctet allow to gets the value of a configuration option in octet
     *
     * @return int the value of a configuration option in octet
     */
    public static function getOctets(var option)
    {
        var size;
        if (preg_match("/[0-9]+k/i", option)){
            let size = ((int)preg_replace("/m/i", "", option) * 1024);
        }
        elseif (preg_match("/[0-9]+m/i", option)){
            let size = 1024 * 1024 * (int)preg_replace("/m/i", "", option);
        }
        elseif (preg_match("/[0-9]+g/i", option)){
            let size = 1024 * 1024 * 1024 * (int)preg_replace("/g/i", "", option);
        }
        else{
            let size = option;
        }

        return size;
    }

    /**
     * getHostName Get host name
     *
     * @return string
     */
    public static function getHostName() -> string {
        var computerName, hostname;
        let computerName = getenv("COMPUTERNAME");
        let hostname = gethostname() . "|" . computerName;
        return hostname ? hostname : "Desconocido";
    }

    /**
     * getUserAgent Get user agent
     *
     * @return string
     */
    public static function getUserAgent() -> string {
        return isset(_SERVER["HTTP_USER_AGENT"]) ? _SERVER["HTTP_USER_AGENT"] : "Desconocido";
    }

}
