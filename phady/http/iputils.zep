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

namespace Phady\Http;

use Phalcon\Http\Request;

/**
  * @class Phady\Http\IpUtils
  *
  * @author  Alien Fernández Fuentes <alienfernandez85@gmail.com>
  * @package Core
  * @copyright (c) 2015
  * @version 1.0.0
  */
class IpUtils
{
    /**
     * This class should not be instantiated.
     */
    private function __construct()
    {
    }

    /**
     * Checks if an IPv4 or IPv6 address is contained in the list of given IPs or subnets.
     *
     * @param string       requestIp IP to check
     * @param string|array ips       List of IPs or subnets (can be a string if only a single one)
     *
     * @return bool Whether the IP is valid
     */
    public static function checkIp(requestIp, ips)
    {
        var ip, method;
        if (!is_array(ips)) {
            let ips = [ips];
        }

        let method = substr_count(requestIp, ":") > 1 ? "checkIp6" : "checkIp4";

        for ip in ips {
            if (method == "checkIp4") {
                if (self::checkIp4(requestIp, ip)) {
                    return true;
                }
            } else {
                if (self::checkIp6(requestIp, ip)) {
                    return true;
                }
            }

        }

        return false;
    }

    /**
     * Compares two IPv4 addresses.
     * In case a subnet is given, it checks if it contains the request IP.
     *
     * @param string requestIp IPv4 address to check
     * @param string ip        IPv4 address or subnet in CIDR notation
     *
     * @return bool Whether the IP is valid
     */
    public static function checkIp4(requestIp, ip)
    {
        var ipSplit, address, netmask;
        if (false !== strpos(ip, "/")) {
            if ("0.0.0.0/0" === ip) {
                return true;
            }

            let ipSplit = explode("/", ip, 2);
            let address = ipSplit[0];
            let netmask = ipSplit[1];
            //list(address, netmask) = explode("/", ip, 2);

            if (netmask < 1 || netmask > 32) {
                return false;
            }
        } else {
            let address = ip;
            let netmask = 32;
        }

        return 0 === substr_compare(sprintf("%032b", ip2long(requestIp)), sprintf("%032b", ip2long(address)), 0, netmask);
    }

    /**
     * Compares two IPv6 addresses.
     * In case a subnet is given, it checks if it contains the request IP.
     *
     * @author David Soria Parra <dsp at php dot net>
     *
     * @see https://github.com/dsp/v6tools
     *
     * @param string requestIp IPv6 address to check
     * @param string ip        IPv6 address or subnet in CIDR notation
     *
     * @return bool Whether the IP is valid
     *
     * @throws \RuntimeException When IPV6 support is not enabled
     */
    public static function checkIp6(requestIp, ip)
    {
        /*
        var ipSplit, address, netmask, bytesAddr, length, mask;
        if (!((extension_loaded("sockets") && defined("AF_INET6")) || @inet_pton("::1"))) {
            throw new \RuntimeException("Unable to check Ipv6. Check that PHP was not compiled with option 'disable-ipv6'.");
        }

        if (false !== strpos(ip, "/")) {
            //list(address, netmask) = explode("/", ip, 2);

            let ipSplit = explode("/", ip, 2);
            let address = ipSplit[0];
            let netmask = ipSplit[1];

            if (netmask < 1 || netmask > 128) {
                return false;
            }
        } else {
            address = ip;
            netmask = 128;
        }

        let bytesAddr = unpack("n*", inet_pton(address));
        let bytesTest = unpack("n*", inet_pton(requestIp));

        let length = ceil(netmask / 16);
        for i in range(1, length)  {
            let left = netmask - 16 * (i - 1);
            let left = (left <= 16) ? left : 16;
            let mask = ~(0xffff >> left) & 0xffff;
            if ((bytesAddr[i] & mask) != (bytesTest[i] & mask)) {
                return false;
            }
        }*/

        return true;
    }
}
