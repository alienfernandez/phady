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

namespace Phady\Security\Http\Authentication;

use Phady\Security\Http\Authentication\AuthenticationSuccessHandlerInterface;
use Phady\Security\Core\Authentication\Token\TokenInterface;
use Phalcon\Http\Request;

/**
  * @class Phady\Security\Http\Authentication\DefaultAuthenticationSuccessHandler
  *
  * @author  Alien Fernández Fuentes <alienfernandez85@gmail.com>
  * @package Core
  * @copyright (c) 2015
  * @version 1.0.0
  */
class DefaultAuthenticationSuccessHandler extends \Phalcon\Di\Injectable implements AuthenticationSuccessHandlerInterface {
    
    protected httpUtils;
    protected options;
    protected providerKey;
    protected defaultOptions = [
        "always_use_default_target_path" : false,
        "default_target_path" : "/",
        "login_path" : "/login",
        "target_path_parameter" : "_target_path",
        "use_referer" : false
    ];

    /**
     * Constructor.
     *
     * @param HttpUtils httpUtils
     * @param array     options   Options for processing a successful authentication attempt.
     */
    public function __construct(array options = [])
    {
        this->setOptions(options);
    }

    /**
     * {@inheritdoc}
     */
    public function onAuthenticationSuccess(<Request> request, <TokenInterface> token)
    {
        print_r(" Auth ok");
        die();
        return this->getDI()->get("response")->redirect(this->determineTargetUrl(request));
    }

    /**
     * Gets the options.
     *
     * @return array An array of options
     */
    public function getOptions()
    {
        return this->options;
    }

    /**
     * Sets the options.
     *
     * @param array options An array of options
     */
    public function setOptions(array options)
    {
        let this->options = array_merge(this->defaultOptions, options);
    }

    /**
     * Get the provider key.
     *
     * @return string
     */
    public function getProviderKey()
    {
        return this->providerKey;
    }

    /**
     * Set the provider key.
     *
     * @param string providerKey
     */
    public function setProviderKey(providerKey)
    {
        let this->providerKey = providerKey;
    }

    /**
     * Builds the target URL according to the defined options.
     *
     * @param Request request
     *
     * @return string
     */
    protected function determineTargetUrl(<Request> request)
    {
        if (this->options["always_use_default_target_path"]) {
            return this->options["default_target_path"];
        }

        /*
        let targetUrl = request->get(this->options["target_path_parameter"], null, true);
        if (targetUrl) {
            return targetUrl;
        }*/
        return this->options["default_target_path"];
    }
}
