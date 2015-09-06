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

namespace Phady\Security\Http\EntryPoint;

use Phalcon\Http\Request;
use Phady\Security\Http\EntryPoint\AuthenticationEntryPointInterface;
use Phady\Security\Core\Exception\AuthenticationException;

/**
  * @class Phady\Security\Http\EntryPoint\FormAuthenticationEntryPoint
  *
  * @author  Alien Fernández Fuentes <alienfernandez85@gmail.com>
  * @package Core
  * @copyright (c) 2015
  * @version 1.0.0
  */
class FormAuthenticationEntryPoint  extends \Phalcon\Di\Injectable implements AuthenticationEntryPointInterface
{
    private loginPath;
    private useForward;

    /**
     * Constructor.
     *
     * @param string              loginPath  The path to the login form
     * @param bool                useForward Whether to forward or redirect to the login form
     */
    public function __construct(loginPath, useForward = false)
    {
        let this->loginPath = loginPath;
        let this->useForward = (bool) useForward;
    }

    /**
     * {@inheritdoc}
     */
    public function start(<Request> request, <AuthenticationException> authException = null)
    {
        /*
        if (this->useForward) {
            subRequest = this->httpUtils->createRequest(request, this->loginPath);

            response = this->httpKernel->handle(subRequest, HttpKernelInterface::SUB_REQUEST);
            if (200 === response->getStatusCode()) {
                response->headers->set('X-Status-Code', 401);
            }

            return response;
        }*/

        return this->getDI()->get("response")->redirect(this->loginPath);
    }
}
