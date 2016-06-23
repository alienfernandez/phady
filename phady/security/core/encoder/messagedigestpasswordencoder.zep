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

namespace Phady\Security\Core\Encoder;

use Phady\Security\Core\Encoder\BasePasswordEncoder;
use Phady\Security\Core\Exception\BadCredentialsException;

/**
  * @class Phady\Security\Core\Encoder\MessageDigestPasswordEncoder
  *
  * @author  Alien Fernández Fuentes <alienfernandez85@gmail.com>
  * @package Core
  * @copyright (c) 2015
  * @version 1.0.0
  */
class MessageDigestPasswordEncoder extends BasePasswordEncoder
{
    private algorithm;
    private encodeHashAsBase64;
    private iterations;

    /**
     * Constructor.
     *
     * @param string algorithm          The digest algorithm to use
     * @param bool   encodeHashAsBase64 Whether to base64 encode the password hash
     * @param int    iterations         The number of iterations to use to stretch the password hash
     */
    public function __construct(algorithm = "sha512", encodeHashAsBase64 = true, iterations = 5000)
    {
        let this->algorithm = algorithm;
        let this->encodeHashAsBase64 = encodeHashAsBase64;
        let this->iterations = iterations;
    }

    /**
     * {@inheritdoc}
     */
    public function encodePassword(raw, salt)
    {
        var salted, digest;
        if (this->isPasswordTooLong(raw)) {
            throw new BadCredentialsException("Invalid password.");
        }

        if (!in_array(this->algorithm, hash_algos(), true)) {
            throw new \LogicException(sprintf("The algorithm %s is not supported.", this->algorithm));
        }

        let salted = this->mergePasswordAndSalt(raw, salt);
        let digest = hash(this->algorithm, salted, true);

        // "stretch" hash
        var i;
        for i in range(1, this->iterations) {
            let digest = hash(this->algorithm, digest.salted, true);
        }

        return this->encodeHashAsBase64 ? base64_encode(digest) : bin2hex(digest);
    }

    /**
     * {@inheritdoc}
     */
    public function isPasswordValid(encoded, raw, salt)
    {
        return !this->isPasswordTooLong(raw) && this->comparePasswords(encoded, this->encodePassword(raw, salt));
    }
}
