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

namespace Phady\Console;

/**
  * @class Phady\Console\Command - Console class for execute command in console
  *
  * @author  Alien Fernández Fuentes <alienfernandez85@gmail.com>
  * @package Console
  * @copyright (c) 2015
  * @version 1.0.0
  */
class Command
{
    const WINDOWS_PLATFORM = "Windows";
    const UNIX_PLATFORM = "Unix";

    /**
     * Run Application in background
     *
     * @param     string command
     * @param     int priority
     * @return     PID
     */
    public static function background(string! command, int priority = 0) {
        var pID;
        if (substr(php_uname(), 0, 7) == self::WINDOWS_PLATFORM) {
            pclose(popen("start /B " . command, "r"));
        }else{
            if (priority){
                let pID = shell_exec("nohup nice -n ". priority. "command > /dev/null & echo $!");
            }
            else{
                let pID = shell_exec("nohup ". command . " > /dev/null & echo $!");
            }
        }
        return pID;
    }

    /**
     * Check if the Application running !
     *
     * @param     string pID
     * @return     boolen
     */
    public static function isRunning(string pID) -> boolean {
        var processState;
        let processState = [];
        exec("ps ". pID, processState);
        return (count(processState) >= 2);
    }

    /**
     * Kill Application PID
     *
     * @param  string pID
     * @return boolen
     */
    public static function kill(string pID) -> boolean {
        if (self::isRunning(pID)) {
            exec("kill -KILL ". pID);
            return true;
        }
        return false;
    }
}
