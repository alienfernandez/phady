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

namespace Phady\Util;

/**
  * @class Phady\Util\Random - Util class for random string, int ...
  *
  * @author  Alien Fernández Fuentes <alienfernandez85@gmail.com>
  * @package Util
  * @copyright (c) 2015
  * @version 1.0.0
  */
class Random
{

    /**
     * Return a seed value for the srand() function
     *
     * @deprecated Since 1.3.0, as this is not required since PHP 4.2.0.
     *
     * @return The resulting seed value
     */
    public static function getSeed()
    {
        var factor, expMicrotime;
        let factor = 95717; // prime
        let expMicrotime = explode(" ", microtime());

        return (double)strrev((expMicrotime[0]) * factor / M_PI);
    }

    /**
     * Return a random integer between floor and ceil (inclusive).
     *
     * @param int floor The lower bound.
     * @param int ceil  The upper bound.
     *
     * @return The resulting random integer
     */
    public static function getInteger(int floor, int ceil) -> int
    {
        var diff, inc;
        let diff = ceil - floor;
        let inc = mt_rand(0, diff);
        return floor + inc;
    }

    /**
     * Return a random string of specified length.
     *
     * This function uses md5() to generate the string.
     *
     * @param int length The length of string to generate.
     *
     * @return The resulting random integer.
     */
    public static function getRandomString(int length) -> int
    {
        var res = "";
        while (strlen(res) < length) {
            let res .= md5(self::getInteger(0, 100000));
        }

        return substr(res, 0, length);
    }

    /**
     * Return a random string
     *
     * @param int minLen            The minimum string length.
     * @param int maxLen            The maximum string length.
     * @param boolean leadingCapital Whether or not the string should start with a capital letter (optional) (default=true).
     * @param boolean useUpper       Whether or not to also use uppercase letters (optional) (default=true).
     * @param boolean useLower       Whether or not to also use lowercase letters (optional) (default=true).
     * @param boolean useSpace       Whether or not to also use whitespace letters (optional) (default=true).
     * @param boolean useNumber      Whether or not to also use numeric characters (optional) (default=false).
     * @param boolean useSpecial     Whether or not to also use special characters (optional) (default=false).
     * @param boolean seed           Whether or not to seed the random number generator (unused since 1.3.0) (optional) (default=false) seeding not required for PHP>4.2.0.
     * @param array   dontuse        Array of characters not to use (optional) (default=null) eg dontuse=array("a", "b", "c");.
     *
     * @return The resulting random string.
     */
    public static function getString(int minLen, int maxLen, boolean leadingCapital = true, boolean useUpper = true,
            boolean useLower = true, boolean useSpace = false, boolean useNumber = false, boolean useSpecial = false,
            boolean seed = false, var dontuse = null)
    {
        var rnd = "", len, i, charExp;
        int clen;
        var chars = "";
        var upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        var lower = "abcdefghijklmnopqrstuvwxyz";
        var number = "0123456789";
        var special = "~@#%^*()_+-={}|][";

        if (useLower) {
            let chars .= lower;
        }
        if (useUpper) {
            let chars .= upper;
        }
        if (useNumber) {
            let chars .= number;
        }
        if (useSpecial) {
            let chars .= special;
        }

        if (useSpace) {
            for i in range(0, (strlen(chars) % 10)) {
            //for (i = 0; i < (strlen(chars) % 10); i++) {
                let chars .= " ";
            }
        }

        // omit the following characters
        if (!is_null(dontuse) && is_array(dontuse)) {
            let chars = str_replace(dontuse, "", chars);
        }

        let len = self::getInteger(minLen, maxLen);
        let clen = strlen(chars) - 1;
        let charExp = explode("", chars);
        for i in range(0, len) {
        //for (i = 0; i < len; i++) {
            let rnd .= charExp[self::getInteger(0, clen)];
        }

        if (leadingCapital) {
            let rnd = ucfirst(rnd);
        }

        return rnd;
    }
    
    /**
     * Return a random string suitable for use as a password or password-like code.
     *
     * The string should conform to the constraints of the current password requirements:
     * suitable for human use (readable and unambiguous), within the specified minimum and maximum lengths.
     *
     * @param integer minLength The minimum length of the string to return; optional; default = 5; constrained to 1 <= minLength <= 25.
     * @param integer maxLength The maximum length of the string to return; optional; default = minLength; constrained to minLength <= maxLength <= 25.
     *
     * @return string|bool A random string suitable for human-use as a password or password-like code; false on error.
     */
    public static function getStringForPassword(int minLength = 5, int maxLength = 0) -> string|boolean
    {
        if (!is_numeric(minLength) || ((int)minLength != minLength) || (minLength <= 0)) {
            return false;
        }
        let minLength = min(minLength, 25);

        if (maxLength == 0) {
            let maxLength = minLength;
        } elseif (!is_numeric(maxLength) || ((int)maxLength != maxLength) || (maxLength <= 0)) {
            return false;
        } elseif (maxLength <= minLength) {
            let maxLength = minLength;
        } else {
            let maxLength = min(maxLength, 25);
        }

        return self::getString(minLength, maxLength, false, false, true, false, true, false, false, ["0", "o", "O", "l", "1", "i", "I", "j", "!", "|"]);
    }
}
