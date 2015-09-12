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

namespace Phady\Security\Http\Authorization;

use Phalcon\Http\Request;
use Phalcon\Http\Response;
use Phady\Security\Core\Exception\AuthenticationException;
use Phady\Security\Core\Exception\AccessDeniedException;
use Phady\Security\Http\Authorization\AccessDeniedHandlerInterface;
use Phady\Security\Core\Authorization\AuthorizationChecker;

/**
  * @class Phady\Security\Http\Authorization\AccessDeniedListener
  *
  * @author  Alien Fernández Fuentes <alienfernandez85@gmail.com>
  * @package Core
  * @copyright (c) 2015
  * @version 1.0.0
  */
class AccessDeniedListener implements AccessDeniedHandlerInterface
{

    protected authorizationChecker;

    public function __construct(<AuthorizationChecker> authorizationChecker)
    {
        let this->authorizationChecker = authorizationChecker;
    }

    /**
     * Handles an access denied failure.
     *
     * @param Request               request
     * @param AccessDeniedException accessDeniedException
     *
     * @return Response may return null
     */
    public function handle(<Request> request, <AccessDeniedException> accessDeniedException)
    {
        //if(!is_null($this->security->getTokenStorage()->getToken()->getUser()->getRoles())
        var roles;
        let roles = "ROLE_USER";

        if (this->authorizationChecker->getTokenStorage()->getToken()){
            let roles = this->authorizationChecker->getTokenStorage()->getToken()->getUser()->getRoles();
        }

        if (this->authorizationChecker->isGranted(roles)) {
            echo "<pre>";print_r("roles: ");
            print_r(roles);die();

            echo "<pre>";print_r("isGranted: ");
            print_r(this->authorizationChecker->isGranted(roles));die();
            return new Response();
        }else {
            return -1;
        }
    }
}
