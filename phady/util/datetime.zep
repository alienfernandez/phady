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
  * @class Phady\Util\DateTime - Util class for date and time manipulation
  *
  * @author  Alien Fernández Fuentes <alienfernandez85@gmail.com>
  * @package Util
  * @copyright (c) 2015
  * @version 1.0.0
  */
class DateTime
{
    const FORMAT_DAYWEEK_DAY_MONTH_YEAR = "%A, %d de %B del %Y";
    const FORMAT_DAY_MONTH_YEAR = "%d de %B del %Y";
    const FORMAT_DAYWEEK_DAY_MONTH_YEAR_TIME = "%A, %d de %B del %Y a las %H:%I";
    const DEFAULT_LANGUAGE_DATE = "es_ES";

    const DATEFORMAT_FIXED = "%Y-%m-%d %H:%M:%S";
    const DATEONLYFORMAT_FIXED = "%Y-%m-%d";

    /**
     * @name getDateByLanguage - Get a date given language
     * @param array time date
     * @param array language Language return date
     * @param array format Format return date
     * @return string
     */
    public static function getDateByLanguage(string! time, string! language = self::DEFAULT_LANGUAGE_DATE, format = self::FORMAT_DAYWEEK_DAY_MONTH_YEAR) -> string
    {
        var date;
        setlocale(LC_ALL, language);
        let date = new \DateTime(time);
        return utf8_encode(ucfirst(strftime(format, date->getTimestamp())));
    }

    /**
     * @name getDateMoment - Get the date as a string in days , months ...
     * @param string datetime date example. 2014-09-28 12:22:44
     * @param boolean showTime Whether to display the time
     * @return string
     */
    public static function getDateMoment (string datetime, boolean showTime = false) -> string
     {
        var datetimeSpt, dateCreate, date, dateInterval, days, dayStr;
        let datetimeSpt = explode(" ", datetime);
        let dateCreate = new \DateTime(datetime);
        let date = new \DateTime("now");
        let dateInterval = date->diff(dateCreate);
        let days = dateInterval->days;
        //print_r(dateInterval);die;
        let dayStr = "";
        if (days == 0) {
            if (dateInterval->h > 0) {
                let dayStr = "Hace " . dateInterval->h . " horas";
            } elseif (dateInterval->i > 0) {
                let dayStr = "Hace " . dateInterval->i . " minutos";
            } elseif (dateInterval->s > 0) {
                let dayStr = "Hace unos segundos";
            }

        } elseif (days == 1) {
            let dayStr = "Ayer a las " . datetimeSpt[1];
        } else {
            let dayStr = "Hace " . days . " días";
            if ( showTime ){
                let dayStr = dayStr. " a las ". datetimeSpt[1];
            }
        }
        return utf8_decode(dayStr);
    }

    /**
     * Return a the number of days in the given month/year.
     *
     * @param integer month The (human) month number to check.
     * @param integer year  The year number to check.
     *
     * @return integer The number of days in the given month/year
     */
    public static function getDaysInMonth(int month, int year) -> int
    {
        var days, d;
        if (month < 1 || month > 12) {
            return 0;
        }
        let days = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31];
        let d = days[month - 1];
        if (month == 2) {
            // Check for leap year, no 4000 rule
            if (year % 4 == 0) {
                if (year % 100 == 0) {
                    if (year % 400 == 0) {
                        let d = 29;
                    }
                } else {
                    let d = 29;
                }
            }
        }
        return d;
    }

    /**
     * Return an array of weekdays for the given month.
     *
     * @param integer month The (human) month number to check.
     * @param integer year  The year number to check.
     *
     * @return integer The number of days in the given month/year.
     */
    public static function getWeekdaysInMonth(int month, int year)
    {
        var nDays, weekdays, i, time, tDate;
        let nDays = self::getDaysInMonth(month, year);
        let weekdays = [nDays];
        for i in range(1, nDays) {
            let time = mktime(12, 0, 0, month, i, year);
            let tDate = getdate(time);
            let weekdays[i] = tDate["wday"];
        }
        return weekdays;
    }

    /**
     * Return the translated name of a specific timezone if exists.
     *
     * @param integer tz Timezone identifier.
     *
     * @return string Timezone translation (hour value).
     */
    public static function getTimezoneText(tz=null)
    {
        var timezones;
        if (!is_numeric(tz)) {
            return false;
        }

        let timezones = self::getTimezones();
        if (isset(timezones[tz])) {
            return timezones[tz];
        }

        // string freeze: cant return "Unknown timezone"
        return ("Unknown timezone");
    }
    /**
     * Return the translated list of timezones.
     *
     * @return array Timezones values and gettext strings.
     */
    public static function getTimezones()
    {
        return ["-12" : ("(GMT -12:00 hours) Baker Island"),
                "-11" : ("(GMT -11:00 hours) Midway Island, Samoa"),
                "-10" : ("(GMT -10:00 hours) Hawaii"),
                "-9.5" : ("(GMT -9:30 hours) French Polynesia"),
                "-9" : ("(GMT -9:00 hours) Alaska"),
                "-8" : ("(GMT -8:00 hours) Pacific Time (US & Canada)"),
                "-7" : ("(GMT -7:00 hours) Mountain Time (US & Canada)"),
                "-6" : ("(GMT -6:00 hours) Central Time (US & Canada), Mexico City"),
                "-5" : ("(GMT -5:00 hours) Eastern Time (US & Canada), Bogota, Lima, Quito"),
                "-4" : ("(GMT -4:00 hours) Atlantic Time (Canada), Caracas, La Paz"),
                "-3.5" : ("(GMT -3:30 hours) Newfoundland"),
                "-3" : ("(GMT -3:00 hours) Brazil, Buenos Aires, Georgetown"),
                "-2" : ("(GMT -2:00 hours) Mid-Atlantic"),
                "-1" : ("(GMT -1:00 hours) Azores, Cape Verde Islands"),
                "0" : ("(GMT) Western Europe Time, London, Lisbon, Casablanca, Monrovia"),
                "1" : ("(GMT +1:00 hours) CET (Central Europe Time), Brussels, Copenhagen, Madrid, Paris"),
                "2" : ("(GMT +2:00 hours) EET (Eastern Europe Time), Kaliningrad, South Africa"),
                "3" : ("(GMT +3:00 hours) Baghdad, Kuwait, Riyadh, Moscow, St. Petersburg"),
                "3.5" : ("(GMT +3:30 hours) Tehran"),
                "4" : ("(GMT +4:00 hours) Abu Dhabi, Muscat, Baku, Tbilisi"),
                "4.5" : ("(GMT +4:30 hours) Kabul"),
                "5" : ("(GMT +5:00 hours) Ekaterinburg, Islamabad, Karachi, Tashkent"),
                "5.5" : ("(GMT +5:30 hours) Bombay, Calcutta, Madras, New Delhi"),
                "5.75" : ("(GMT +5:45 hours) Kathmandu"),
                "6" : ("(GMT +6:00 hours) Almaty, Dhaka, Colombo"),
                "6.5" : ("(GMT +6:30 hours) Cocos Islands, Myanmar"),
                "7" : ("(GMT +7:00 hours) Bangkok, Hanoi, Jakarta"),
                "8" : ("(GMT +8:00 hours) Beijing, Perth, Singapore, Hong Kong, Chongqing, Urumqi, Taipei"),
                "9" : ("(GMT +9:00 hours) Tokyo, Seoul, Osaka, Sapporo, Yakutsk"),
                "9.5" : ("(GMT +9:30 hours) Adelaide, Darwin"),
                "10" : ("(GMT +10:00 hours) EAST (East Australian Standard)"),
                "10.5" : ("(GMT +10:30 hours) Lord Howe Island (NSW, Australia)"),
                "11" : ("(GMT +11:00 hours) Magadan, Solomon Islands, New Caledonia"),
                "11.5" : ("(GMT +11:30 hours) Norfolk Island"),
                "12" : ("(GMT +12:00 hours) Auckland, Wellington, Fiji, Kamchatka, Marshall Island"),
                "12.75" : ("(GMT +12:45 hours) Chatham Islands"),
                "13" : ("(GMT +13:00 hours Tonga, Kiribati (Phoenix Islands)"),
                "14" : ("(GMT +14:00 hours) Kiribati (Line Islands)")
            ];
    }
}
