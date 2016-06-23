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

use Phady\Security\Core\Encoder\EncoderFactoryInterface;
use Phady\Security\Core\Encoder\EncoderAwareInterface;

/**
  * @class Phady\Security\Core\Encoder\EncoderFactory
  *
  * @author  Alien Fernández Fuentes <alienfernandez85@gmail.com>
  * @package Core
  * @copyright (c) 2015
  * @version 1.0.0
  */
abstract class BasePasswordEncoder implements PasswordEncoderInterface
{
    const MAX_PASSWORD_LENGTH = 4096;

    /**
     * Demerges a merge password and salt string.
     *
     * @param string mergedPasswordSalt The merged password and salt string
     *
     * @return array An array where the first element is the password and the second the salt
     */
    protected function demergePasswordAndSalt(mergedPasswordSalt)
    {
        var password, salt, saltBegins;
        if (empty(mergedPasswordSalt)) {
            return ["",""];
        }

        let password = mergedPasswordSalt;
        let salt = "";
        let saltBegins = strrpos(mergedPasswordSalt, "{");

        if (false !== saltBegins && saltBegins + 1 < strlen(mergedPasswordSalt)) {
            let salt = substr(mergedPasswordSalt, saltBegins + 1, -1);
            let password = substr(mergedPasswordSalt, 0, saltBegins);
        }

        return [password, salt];
    }

    /**
     * Merges a password and a salt.
     *
     * @param string password the password to be used
     * @param string salt     the salt to be used
     *
     * @return string a merged password and salt
     *
     * @throws \InvalidArgumentException
     */
    protected function mergePasswordAndSalt(password, salt)
    {
        if (empty(salt)) {
            return password;
        }

        if (false !== strrpos(salt, "{") || false !== strrpos(salt, "}")) {
            throw new \InvalidArgumentException("Cannot use { or } in salt.");
        }

        return password . "{" . salt . "}";
    }

    /**
     * Compares two passwords.
     *
     * This method implements a constant-time algorithm to compare passwords to
     * avoid (remote) timing attacks.
     *
     * @param string password1 The first password
     * @param string password2 The second password
     *
     * @return bool true if the two passwords are the same, false otherwise
     */
    protected function comparePasswords(password1, password2)
    {
        //return \Phady\Util\Text::equals(password1, password2);
        //print_r("password1: " . password1 . " | password2: " . password2 );
        //die("  .........passs......");
        return password1 === password2;
    }

    /**
     * Checks if the password is too long.
     *
     * @param string password The password to check
     *
     * @return bool true if the password is too long, false otherwise
     */
    protected function isPasswordTooLong(password)
    {
        return strlen(password) > self::MAX_PASSWORD_LENGTH;
    }
}
