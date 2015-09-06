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
  * @class Phady\Security\Core\Encoder\PlaintextPasswordEncoder
  *
  * @author  Alien Fernández Fuentes <alienfernandez85@gmail.com>
  * @package Core
  * @copyright (c) 2015
  * @version 1.0.0
  */
class PlaintextPasswordEncoder extends BasePasswordEncoder
{
    private ignorePasswordCase;

    /**
     * Constructor.
     *
     * @param bool ignorePasswordCase Compare password case-insensitive
     */
    public function __construct(boolean ignorePasswordCase = false)
    {
        let this->ignorePasswordCase = ignorePasswordCase;
    }

    /**
     * {@inheritdoc}
     */
    public function encodePassword(raw, salt)
    {
        if (this->isPasswordTooLong(raw)) {
            throw new BadCredentialsException("Invalid password.");
        }

        return this->mergePasswordAndSalt(raw, salt);
    }

    /**
     * {@inheritdoc}
     */
    public function isPasswordValid(encoded, raw, salt)
    {
        //print_r("encoded: " . encoded . " | raw: " . raw . " | salt: " . salt );
        //die("  .........passs......");
        var pass2;
        if (this->isPasswordTooLong(raw)) {
            return false;
        }
        return this->comparePasswords(encoded, raw);
        /*
        let pass2 = this->mergePasswordAndSalt(raw, salt);

        if (!this->ignorePasswordCase) {
            return this->comparePasswords(encoded, pass2);
        }*/

        //return this->comparePasswords(strtolower(encoded), strtolower(pass2));
    }
}
