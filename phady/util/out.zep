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
  * @class Phady\Util\Out - Util class for print
  *
  * @author  Alien Fernández Fuentes <alienfernandez85@gmail.com>
  * @package Util
  * @copyright (c) 2015
  * @version 1.0.0
  */
class Out
{

    /**
     * Display a variable"s contents using nice HTML formatting and will
     * properly display the value of booleans as true or false
     *
     * @see var_dump_plain()
     *
     * @param  mixed var The variable to dump
     * @return string
     */
    public static function dump(var varToDump, returnDump = false, expandLevel = 1)
    {
        /*var hasArray, toggScript, imgScript, jsCode, html;
        toggScript = 'var colToggle = function(toggID) {var img = document.getElementById(toggID);if (document.getElementById(toggID + "-collapsable").style.display == "none") {document.getElementById(toggID + "-collapsable").style.display = "inline";setImg(toggID, 0);var previousSibling = document.getElementById(toggID + "-collapsable").previousSibling;while (previousSibling != null && (previousSibling.nodeType != 1 || previousSibling.tagName.toLowerCase() != "br")) {previousSibling = previousSibling.previousSibling;}} else {document.getElementById(toggID + "-collapsable").style.display = "none";setImg(toggID, 1);var previousSibling = document.getElementById(toggID + "-collapsable").previousSibling; while (previousSibling != null && (previousSibling.nodeType != 1 || previousSibling.tagName.toLowerCase() != "br")) {previousSibling = previousSibling.previousSibling;}}};';
        imgScript = 'var setImg = function(objID,imgID,addStyle) {var imgStore = ["data:image/png;base64,' . self::icon_collapse . '", "data:image/png;base64,' . self::icon_expand . '"];if (objID) {document.getElementById(objID).setAttribute("src", imgStore[imgID]);if (addStyle){document.getElementById(objID).setAttribute("style", "position:relative;left:-5px;top:-1px;cursor:pointer;");}}};';
        jsCode = preg_replace('/ +/', ' ', '<script>' . toggScript . imgScript . '</script>');
        html = '<pre style="margin-bottom: 18px;' .
            'background: #f7f7f9;' .
            'border: 1px solid #e1e1e8;' .
            'padding: 8px;' .
            'border-radius: 4px;' .
            '-moz-border-radius: 4px;' .
            '-webkit-border radius: 4px;' .
            'display: block;' .
            'font-size: 12.05px;' .
            'white-space: pre-wrap;' .
            'word-wrap: break-word;' .
            'color: #333;' .
            'font-family: Menlo,Monaco,Consolas,\'Courier New\',monospace;">';
        done  = array();
        html .= self::var_dump_plain(var, intval(expandLevel), 0, done);
        html .= '</pre>';

        if (self::hasArray) {
            html = jsCode . html;
        }

        if (!return) {
            echo html;
        }*/
        return self::var_dump_plain(varToDump, intval(expandLevel), 0, []);
        //return html;
    }

    /**
     * Display a variable"s contents using nice HTML formatting (Without
     * the <pre> tag) and will properly display the values of variables
     * like booleans and resources. Supports collapsable arrays and objects
     * as well.
     *
     * @param  mixed var The variable to dump
     * @return string
     */
    public static function var_dump_plain(var varToDump, int expLevel, int depth = 0, array done = [])
    {
        /*var html, setImg, setStyle, uuid, prev, indent, longest_key, hasArray, key, value, line, val, varArray,
            varToDumpLen, varToDumpCount;
        let html = "";
        if (expLevel > 0) {
            let expLevel--;
            let setImg = 0;
            let setStyle = "display:inline;";
        } elseif (expLevel == 0) {
            let setImg = 1;
            let setStyle="display:none;";
        } elseif (expLevel < 0) {
            let setImg = 0;
            let setStyle = "display:inline;";
        }

        if (is_bool(varToDump)) {
            let html .= "<span style=color:#588bff;>bool</span><span style=color:#999;>(</span><strong>" . ((varToDump) ? "true" : "false") . "</strong><span style=color:#999;>)</span>";
        } elseif (is_int(varToDump)) {
            let html .= "<span style=color:#588bff;>int</span><span style=color:#999;>(</span><strong>" . varToDump . "</strong><span style=color:#999;>)</span>";
        } elseif (is_float(varToDump)) {
            let html .= "<span style=color:#588bff;>float</span><span style=color:#999;>(</span><strong>" . varToDump . "</strong><span style=color:#999;>)</span>";
        } elseif (is_string(varToDump)) {
            let varToDumpLen = strlen(varToDump);
            let html .= "<span style=color:#588bff;>string</span><span style=color:#999;>(</span>" . varToDumpLen . "<span style=color:#999;>)</span> <strong>" . self::htmlentities(varToDump) . "</strong>";
        } elseif (is_null(varToDump)) {
            let html .= "<strong>NULL</strong>";
        } elseif (is_resource(varToDump)) {
            let html .= "<span style=color:#588bff;>resource</span>(" . get_resource_type(varToDump) . ") <strong>" . varToDump . "</strong>";
        } elseif (is_array(varToDump)) {
            // Check for recursion
            if (depth > 0) {
                for prev in done {
                    if (prev === varToDump) {
                        let varToDumpCount = count(varToDump);
                        let html .= "<span style=color:#588bff;>array</span>(" . varToDumpCount . ") *RECURSION DETECTED*";
                        return html;
                    }
                }

                // Keep track of varToDumpiables we have already processed to detect recursion
                //let done[] = &varToDump;
                let done[] = varToDump;
            }

            let hasArray = true;
            let uuid = "include-php-" . uniqid() . mt_rand(1, 1000000);
            let varToDumpCount = count(varToDump);
            let html .= (!empty(varToDump) ? " <img id=" . uuid . " src=data:image/gif;base64,R0lGODlhAQABAAD/ACwAAAAAAQABAAACADs%3D onclick=javascript:colToggle(this.id); /><script>setImg(" . uuid . ",". setImg .",1);</script>" : "") . "<span style=color:#588bff;>array</span>(" . varToDumpCount . ")";
            if (!empty(varToDump)) {
                let html .= " <span id=" . uuid . "-collapsable style=".setStyle."><br />[<br />";

                let indent = 4;
                let longest_key = 0;

                for key, value in varToDump {
                    if (is_string(key)) {
                        let longest_key = max(longest_key, strlen(key) + 2);
                    } else {
                        let longest_key = max(longest_key, strlen(key));
                    }
                }

                for key, value in varToDump {
                    if (is_numeric(key)) {
                        let html .= str_repeat(" ", indent) . str_pad(key, longest_key, " ");
                    } else {
                        let html .= str_repeat(" ", indent) . str_pad("'" . self::htmlentities(key) . "'", longest_key, " ");
                    }

                    let html .= " => ";

                    let value = explode("<br />", self::var_dump_plain(value, expLevel, depth + 1, done));

                    for line, val in value {
                        if (line != 0) {
                            let value[line] = str_repeat(" ", indent * 2) . val;
                        }
                    }

                    let html .= implode("<br />", value) . "<br />";
                }

                let html .= "]</span>";
            }
        } elseif (is_object(varToDump)) {
            // Check for recursion
            for prev in done {
                if (prev === varToDump) {
                    let html .= "<span style=color:#588bff;>object</span>(" . get_class(varToDump) . ") *RECURSION DETECTED*";
                    return html;
                }
            }

            // Keep track of variables we have already processed to detect recursion
            let done[] = &varToDump;

            let hasArray=true;
            let uuid = "include-php-" . uniqid() . mt_rand(1, 1000000);

            let html .= " <img id=" . uuid . " src=data:image/gif;base64,R0lGODlhAQABAAD/ACwAAAAAAQABAAACADs%3D onclick=javascript:colToggle(this.id); /><script>setImg(" . uuid . ",". setImg .",1);</script><span style=color:#588bff;>object</span>(" . get_class(varToDump) . ") <span id=" . uuid . "-collapsable style=". setStyle ."><br />[<br />";

            let varArray = (array) varToDump;

            let indent = 4;
            let longest_key = 0;

            for key, value in varArray {
                if (substr(key, 0, 2) == "\0*") {
                    unset(varArray[key]);
                    let key = "protected:" . substr(key, 3);
                    let varArray[key] = value;
                } elseif (substr(key, 0, 1) == "\0") {
                    unset(varArray[key]);
                    let key = "private:" . substr(key, 1, strpos(substr(key, 1), "\0")) . ":" . substr(key, strpos(substr(key, 1), "\0") + 2);
                    let varArray[key] = value;
                }

                if (is_string(key)) {
                    let longest_key = max(longest_key, strlen(key) + 2);
                } else {
                    let longest_key = max(longest_key, strlen(key));
                }
            }

            for key, value in varArray {
                if (is_numeric(key)) {
                    let html .= str_repeat(" ", indent) . str_pad(key, longest_key, " ");
                } else {
                    let html .= str_repeat(" ", indent) . str_pad("'" . self::htmlentities(key) . "'", longest_key, " ");
                }

                let html .= " => ";

                let value = explode("<br />", self::var_dump_plain(value, expLevel, depth + 1, done));

                for line, val in value {
                    if (line != 0) {
                        let value[line] = str_repeat(" ", indent * 2) . val;
                    }
                }

                let html .= implode("<br />", value) . "<br />";
            }

            let html .= "]</span>";
        }

        return html;*/
    }

    /**
     * Convert entities, while preserving already-encoded entities.
     *
     * @param  string string The text to be converted
     * @return string
     */
    public static function htmlentities(string text, boolean preserve_encoded_entities = false)
    {
        var translation_table;
        if (preserve_encoded_entities) {
            // @codeCoverageIgnoreStart
            if (defined("HHVM_VERSION")) {
                let translation_table = get_html_translation_table(HTML_ENTITIES, ENT_QUOTES);
            } else {
                let translation_table = get_html_translation_table(HTML_ENTITIES, ENT_QUOTES, self::mbInternalEncoding());
            }
            // @codeCoverageIgnoreEnd

            let translation_table[chr(38)] = '&';
            return preg_replace("/&(?![A-Za-z]{0,4}\w{2,3};|#[0-9]{2,3};)/", "&amp;", strtr(text, translation_table));
        }

        return htmlentities(text, ENT_QUOTES, self::mbInternalEncoding());
    }
    
    /**
     * Wrapper to prevent errors if the user doesn't have the mbstring
     * extension installed.
     *
     * @param  string encoding
     * @return string
     */
    protected static function mbInternalEncoding(encoding = null)
    {
        if (function_exists("mb_internal_encoding")) {
            return encoding ? mb_internal_encoding(encoding) : mb_internal_encoding();
        }

        // @codeCoverageIgnoreStart
        return "UTF-8";
        // @codeCoverageIgnoreEnd
    }
}
