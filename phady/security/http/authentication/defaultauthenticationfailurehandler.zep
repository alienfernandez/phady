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

use Phady\Security\Http\Authentication\AuthenticationFailureHandlerInterface;
use Phady\Security\Core\Exception\AuthenticationException;
use Phalcon\Http\Request;

/**
  * @class Phady\Security\Http\Authentication\DefaultAuthenticationFailureHandler
  *
  * @author  Alien Fernández Fuentes <alienfernandez85@gmail.com>
  * @package Core
  * @copyright (c) 2015
  * @version 1.0.0
  */
class DefaultAuthenticationFailureHandler implements AuthenticationFailureHandlerInterface {
    
   protected httpKernel;
   protected httpUtils;
   protected logger;
   protected options;
   protected defaultOptions = [
       "failure_path" : null,
       "failure_forward" : false,
       "login_path" : "/login",
       "failure_path_parameter" : "_failure_path"
   ];

   /**
    * Constructor.
    *
    * @param HttpKernelInterface httpKernel
    * @param HttpUtils           httpUtils
    * @param array               options    Options for processing a failed authentication attempt.
    * @param LoggerInterface     logger     Optional logger
    */
   public function __construct(array options = [])
   {
       this->setOptions(options);
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
    * {@inheritdoc}
    */
   public function onAuthenticationFailure(<Request> request, <AuthenticationException> exception)
   {
        var failureUrl;
        let failureUrl = request->get(this->options["failure_path_parameter"], null, true);
       if (failureUrl) {
           let this->options["failure_path"] = failureUrl;
       }

       if (null === this->options["failure_path"]) {
           let this->options["failure_path"] = this->options["login_path"];
       }

       if (this->options["failure_forward"]) {
           //if (null !== this->logger) {
               //this->logger->debug("Authentication failure, forward triggered.", ["failure_path" : this->options["failure_path"]]);
           //}

           //subRequest = this->httpUtils->createRequest(request, this->options["failure_path"]);
           //subRequest->attributes->set(Security::AUTHENTICATION_ERROR, exception);

           //return this->httpKernel->handle(subRequest, HttpKernelInterface::SUB_REQUEST);
       }

       if (null !== this->logger) {
           //this->logger->debug("Authentication failure, redirect triggered.", ["failure_path" : this->options["failure_path"]]);
       }

       //request->getSession()->set(Security::AUTHENTICATION_ERROR, exception);

       return false;
       //this->httpUtils->createRedirectResponse(request, this->options["failure_path"]);
   }
}
