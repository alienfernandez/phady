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
  * @class Phady\Util\Text - Util class for text manipulation
  *
  * @author  Alien Fernández Fuentes <alienfernandez85@gmail.com>
  * @package Util
  * @copyright (c) 2015
  * @version 1.0.0
  */
class Text
{
    const BACKGROUND_COLOR_DEFAULT = "#D82EE8";
  	const COLOR_DEFAULT = "#FFFFFF";
  	const BREAK_DEFAULT = ".";
  	const PAD_DEFAULT = "...";

	/**
	 * @name highlight - Highlight text to display as html
	 *
	 * @param string text Text highlight
	 * @param string query Sub searched string
	 * @param boolean first Whether to search only by First Letter
	 * @param string background_color Background color of the highlighted
	 * @param string color Font color of the highlighted
	 * @return string
	 */
    public static function highlight(string! text, string! query, boolean first, string background_color = self::BACKGROUND_COLOR_DEFAULT, string color = self::COLOR_DEFAULT) -> string{
        var posResultQuery, subStrQuery, strQuery;
        //long length;
        //int i, paddingSize = 0, ord;
        //let length = strlen(text);
        if (text && query) {
            let posResultQuery = strpos(text->lower(), query->lower());
            if (first == false) {
                if (posResultQuery != null) {
                    let subStrQuery = substr(text, posResultQuery, query->length());
                    let strQuery = preg_replace("/" . query . "/i",
                            "<span style=background:" . background_color . ";color:" . color . ";border:1px dotted;margin-right:0px><strong>".subStrQuery."</strong></span>", text);
                    } else {
                        let strQuery = "";
                    }
            }else {
                let subStrQuery = substr(text, 0, 1);
                if (posResultQuery == 0) {
                    let strQuery = preg_replace("/" . query . "/i",
                        "<span style=background:" . background_color . ";color:" . color . ";border:1px dotted;margin-right:0px><strong>".subStrQuery."</strong></span>", text, 1);
                } else {
                    let strQuery = text;
                }
            }
            //let last = substr(text, length - 1, 1);
            //let pos = strpos(text->lower(), query->lower());
        } else {
            let strQuery = text;
        }
        return strQuery;
    }

    /**
     * @name truncate - Truncate a string
     *
     * @param string text - String truncated
     * @param int limit - limit to truncate
     * @param string str_break - string to break
     * @param string pad - filling the end of the string
     * @return string
     */
    public static function truncate(string! text, int! limit, string str_break = self::BREAK_DEFAULT, string pad = self::PAD_DEFAULT) -> string {
        var breakpoint, trcText;
        let trcText = text;
        if (limit <= text->length()){
            if (str_break){
                 let breakpoint = strpos(text, str_break, limit);
                 if (breakpoint != false) {
                     if (breakpoint < (text->length() - 1)) {
                         let trcText = substr(text, 0, breakpoint) . pad;
                     }
                 }
            }else{
                let trcText = substr(text, 0, limit) . pad;
            }
        }
        return trcText;
    }

    /**
     * @name findAndReplaceUrlTags - Search mail and url and replace the complete url
     *
     * @param array text String to replace
     * @return string
     */
    public static function findAndReplaceUrlTags(string! text) -> string
    {
        var sanitate;
        let sanitate = trim(text);
        let sanitate = preg_replace("(((f|ht){1}tp://)[-a-zA-Z0-9@:%_+.~#?&//=]+)", "<a href=0>0</a>", sanitate);
        let sanitate = preg_replace("(((f|ht){1}tps://)[-a-zA-Z0-9@:%_+.~#?&//=]+)", "<a href=0> 0</a>", sanitate);
        let sanitate = preg_replace("/w{3}.[a-zA-Z0-9_-]*.[a-z]*.[a-z]*/", " 1<a href=http://0>0</a>", sanitate);
        let sanitate = preg_replace("([_.0-9a-z-]+@([0-9a-z][0-9a-z-]+.).[a-z]{2,3})", "<a href=mailto: 0> 0</a>", sanitate);
        return sanitate;
    }

    /**
    * Transform a snake_case string into a camelCase string.
    *
    * @param string snake the string to convert
    * @return string
    */
    public static function snakeToCamel( string snake ) -> string {
        var pieces, count, str, i, p;
        //print_r(snake);
        let pieces = explode( "_", snake );
        let count = count( pieces );
        if ( 1 == count ) {
          return snake;
        }
        let str = pieces[0];
        for i in range(1, count - 1) {
            let p = pieces[i];
            let str = str . mb_strtoupper( substr(p, 0, 1) ) . mb_substr( p, 1 );
        }
        return str;
    }


    /**
    * Transform a camelCase string into a snake_case string.
    *
    * @param string camel the string to convert
    * @return string
    */
    public static function camelToSnake( string camel ) -> string {
        return mb_strtolower( preg_replace( "/([A-Z])/u", "_1", camel ) );
    }
    
	/**
    * Transform a text to uppercase.
    *
    * @deprecated	Use {@link mb_strtoupper} instead.
    *
    * @param text the text to transform.
    * @param encoding the character encoding to use. default is {@link mb_internal_encoding()}.
    * @return	the text in uppercase.
    */
    public static function toUpper( string text, var encoding = null ) {
        var enc;
        let enc = is_string( encoding ) ? encoding : mb_internal_encoding();
        return mb_strtoupper( text, enc );
    }
    
    /**
    * Transform a text to lowercase.
    *
    * @deprecated	Use {@link mb_strtolower} instead.
    *
    * @param text the text to transform.
    * @param encoding the character encoding to use. default is {@link mb_internal_encoding()}.
    * @return	the text in lowercase.
    */
    public static function toLower( string text, var encoding = null ) {
        var enc;
        let enc = is_string( encoding ) ? encoding : mb_internal_encoding();
        return mb_strtolower( text, enc );
    }

    /**
    * Transform all the letters to lowercase and just the first letter of each word to uppercase.
    *
    * This method can be replaced by {@code mb_convert_case( "your text here", MB_CASE_TITLE )} when
    * the {@code exceptions} parameter is not given.
    *
    * How to use it:
    * #( "john von neumann", array( " von " ) ) ==> "John von Neumann"
    * #( "JOHN VON NEUMANN", array( " von " ) ) ==> "John von Neumann"
    * #( "maria da silva e castro", array( " da ", " e " ) ) ==> "Maria da Silva e Castro"
    *
    * @see {@link commonNameExceptions}.
    *
    * @param text text to transform.
    * @param exceptions array of words to ignore exceptions.
    * @param encoding the character encoding to use. default is {@link mb_internal_encoding()}.
    * @return	the transformed text.
    */
    public static function upperCaseFirst( string text, array exceptions = [], var encoding = null ) {
        var enc, newText, e;
        let enc = is_string( encoding ) ? encoding : mb_internal_encoding();
        let newText = mb_convert_case( text, MB_CASE_TITLE, enc );
        if ( count( exceptions ) < 1 ) {
            return newText;
        }
        for e in exceptions {
            let newText = str_replace(mb_convert_case( e, MB_CASE_TITLE, enc),
            mb_convert_case( e, MB_CASE_LOWER, enc ), newText );
        }
        return newText;
    }
    
    /**
     * Count the instances of needle in the given string
     *
     * Why is this function here? PHP has a builtin substr_count()
     * to do the same.
     *
     * @param string haystack The string to search.
     * @param string needle   The needle to search for and count.
     *
     * @return integer The numer of instances of needle in string
     */
    public static function countInstances(string haystack, string needle) -> int
    {
        return mb_substr_count(haystack, needle);
    }


    /**
     * Translate html input newlines to <br /> sequences.
     *
     * This function is necessary as inputted strings will contain
     * "\n\r" instead of just "\n".
     *
     * @param string text The string to operate on.
     *
     * @return string The converted string.
     */
    public static function nl2html(string text) -> string
    {
        var str;
        let str = str_replace("\n", "<br />", text);
        let str = str_replace("\r", "", str);

        return str;
    }

    /**
     * Tokenize a string according to the given parameters.
     *
     * This function just wraps explode to provide a more java-similar syntax.
     *
     * @param string  text    The string to tokenize.
     * @param string  delimeter The delimeter to use.
     * @param int max       The maximal number of tokens to generate (optional) (default=999999).
     *
     * @return array The token array.
     */
    public static function tokenize(string text, string delimeter, int max = 999999)
    {
        return explode(delimeter, text, max);
    }
    
    /**
     * Case-Insensitive version of strpos (standard only available in PHP 5)
     *
     * @param string  haystack The string to search.
     * @param string  needle   The string to search for.
     * @param int offset   The search start offset position (optional) (default=0).
     *
     * @return array The token array.
     */
    public static function stripos(string haystack, string needle, int offset = 0)
    {
        return mb_strpos(mb_strtoupper(haystack), mb_strtoupper(needle), offset);
    }
    
    /**
     * Returns the left x chars of a string.
     *
     * If the string is longer than x, the whole string is returned.
     *
     * @param string  text The string to operate on.
     * @param int left   The number of chars to return.
     *
     * @return string A part of the supplied string.
     */
    public static function left(string text, int left = 0) -> string
    {
        var len;
        let len = mb_strlen(text);
        if (len > left) {
            let text = mb_substr(text, 0, left);
        }

        return text;
    }

    /**
     * Returns the right x chars of a string.
     *
     * If the string is longer than x, the whole string is returned.
     *
     * @param string  text The string to operate on.
     * @param integer right  The number of chars to return.
     *
     * @return string A part of the supplied string.
     */
    public static function right(string text, int right = 0) -> string
    {
        var len;
        let len = mb_strlen(text);
        if (len > right) {
            let text = mb_substr(text, len - right, right);
        }

        return text;
    }
}
