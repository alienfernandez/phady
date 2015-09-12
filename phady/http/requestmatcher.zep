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
use Phady\Http\RequestMatcherInterface;

/**
  * @class Phady\Http\RequestMatcher
  *
  * @author  Alien Fernández Fuentes <alienfernandez85@gmail.com>
  * @package Core
  * @copyright (c) 2015
  * @version 1.0.0
  */
class RequestMatcher implements RequestMatcherInterface
{
    /**
     * @var string
     */
    private path;

    /**
     * @var string
     */
    private host;

    /**
     * @var array
     */
    private methods = [];

    /**
     * @var string
     */
    private ips = [];

    /**
     * @var array
     */
    private attributes = [];

    /**
     * @var string[]
     */
    private schemes = [];

    /**
     * @param string|null          path
     * @param string|null          host
     * @param string|string[]|null methods
     * @param string|string[]|null ips
     * @param array                attributes
     * @param string|string[]|null schemes
     */
    public function __construct(path = null, host = null, methods = null, ips = null, array attributes = [], schemes = null)
    {
        this->matchPath(path);
        this->matchHost(host);
        this->matchMethod(methods);
        this->matchIps(ips);
        this->matchScheme(schemes);

        var k, v;
        for k, v in attributes {
            this->matchAttribute(k, v);
        }
    }

    /**
     * Adds a check for the HTTP scheme.
     *
     * @param string|string[]|null scheme An HTTP scheme or an array of HTTP schemes
     */
    public function matchScheme(scheme)
    {
        let this->schemes = array_map("strtolower", (array) scheme);
    }

    /**
     * Adds a check for the URL host name.
     *
     * @param string regexp A Regexp
     */
    public function matchHost(regexp)
    {
        let this->host = regexp;
    }

    /**
     * Adds a check for the URL path info.
     *
     * @param string regexp A Regexp
     */
    public function matchPath(regexp)
    {
        let this->path = regexp;
    }

    /**
     * Adds a check for the client IP.
     *
     * @param string ip A specific IP address or a range specified using IP/netmask like 192.168.1.0/24
     */
    public function matchIp(ip)
    {
        this->matchIps(ip);
    }

    /**
     * Adds a check for the client IP.
     *
     * @param string|string[] ips A specific IP address or a range specified using IP/netmask like 192.168.1.0/24
     */
    public function matchIps(ips)
    {
        let this->ips = (array) ips;
    }

    /**
     * Adds a check for the HTTP method.
     *
     * @param string|string[] method An HTTP method or an array of HTTP methods
     */
    public function matchMethod(method)
    {
        let this->methods = array_map("strtoupper", (array) method);
    }

    /**
     * Adds a check for request attribute.
     *
     * @param string key    The request attribute name
     * @param string regexp A Regexp
     */
    public function matchAttribute(key, regexp)
    {
        let this->attributes[key] = regexp;
    }

    /**
     * {@inheritdoc}
     *
     * @api
     */
    public function matches(<Request> request)
    {
        //(http/https)
        if (this->schemes && !in_array(request->getScheme(), this->schemes)) {
            return false;
        }

        //Method which request has been made
        if (this->methods && !in_array(request->getMethod(), this->methods)) {
            return false;
        }

        var key, pattern;
        for key, pattern in this->attributes {
            if (!preg_match("{".pattern."}", request->get(key))) {
                return false;
            }
        }

        if (null !== this->path && !preg_match("{".this->path."}", rawurldecode(request->getURI()))) {
            return false;
        }

        if (null !== this->host && !preg_match("{".this->host."}i", request->getHttpHost())) {
            return false;
        }

        //print_r(" :client addres: " . request->getClientAddress());
        //print_r(this->ips);
        //die();

        if (IpUtils::checkIp(request->getClientAddress(), this->ips)) {
            return true;
        }

        // Note to future implementors: add additional checks above the
        // foreach above or else your check might not be run!
        return count(this->ips) === 0;
    }
}
