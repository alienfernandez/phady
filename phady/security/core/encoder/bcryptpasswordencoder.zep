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
  * @class Phady\Security\Core\Encoder\BCryptPasswordEncoder
  *
  * @author  Alien Fernández Fuentes <alienfernandez85@gmail.com>
  * @package Core
  * @copyright (c) 2015
  * @version 1.0.0
  */
class BCryptPasswordEncoder extends BasePasswordEncoder
{
    /**
     * @var string
     */
    private cost;

    /**
     * Constructor.
     *
     * @param int cost The algorithmic cost that should be used
     *
     * @throws \RuntimeException         When no BCrypt encoder is available
     * @throws \InvalidArgumentException if cost is out of range
     */
    public function __construct(cost)
    {
        if (!function_exists("password_hash")) {
            throw new \RuntimeException("To use the BCrypt encoder, you need to upgrade to PHP 5.5 or install the ircmaxell/password-compat via Composer.");
        }

        let cost = (int) cost;
        if (cost < 4 || cost > 31) {
            throw new \InvalidArgumentException("Cost must be in the range of 4-31.");
        }

        let this->cost = cost;
    }

    /**
     * Encodes the raw password.
     *
     * It doesn"t work with PHP versions lower than 5.3.7, since
     * the password compat library uses CRYPT_BLOWFISH hash type with
     * the "2y" salt prefix (which is not available in the early PHP versions).
     *
     * @see https://github.com/ircmaxell/password_compat/issues/10#issuecomment-11203833
     *
     * It is almost best to **not** pass a salt and let PHP generate one for you.
     *
     * @param string raw  The password to encode
     * @param string salt The salt
     *
     * @return string The encoded password
     *
     * @throws BadCredentialsException when the given password is too long
     *
     * @link http://lxr.php.net/xref/PHP_5_5/ext/standard/password.c#111
     */
    public function encodePassword(raw, salt)
    {
        var options;
        if (this->isPasswordTooLong(raw)) {
            throw new BadCredentialsException("Invalid password.");
        }

        let options = ["cost" : this->cost];

        if (salt) {
            let options["salt"] = salt;
        }

        return password_hash(raw, PASSWORD_BCRYPT, options);
    }

    /**
     * {@inheritdoc}
     */
    public function isPasswordValid(encoded, raw, salt)
    {
        return !this->isPasswordTooLong(raw) && password_verify(raw, encoded);
    }
}
