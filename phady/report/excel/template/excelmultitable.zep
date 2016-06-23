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

namespace Phady\Report\Excel\Template;

/**
  * @class Phady\Report\Excel\Template\ExcelMultiTable -  template excel multi table
  *
  * @author  Alien Fernández Fuentes <alienfernandez85@gmail.com>
  * @package Core
  * @copyright (c) 2015
  * @version 1.0.0
  */
class ExcelMultiTable
{

    const ROW_START_DEFAULT = 5;
    const COLUMN_START_DEFAULT = "B";
    const AUTO_SIZE = true;

    protected excel;
    protected style_table;
    protected style_header;
    protected style;
    protected title;
    protected start_row;
    protected start_col;
    protected title_sheet;
    protected sheet;
    protected config;
    protected headers = [];
    protected letters = [];

    /**
     * @param array config - The config template multi-table
     */
    public function __construct(array! config) {
        //Read config file
        let this->config = config;
    }

    /**
     * @return \PHPExcel
     */
    public function getExcelInstance()
    {
        return this->excel;
    }

    /**
     * @return string
     */
    public function getStartRow()
    {
        return self::ROW_START_DEFAULT;
    }

    /**
     * @return string
     */
    public function getColumnLetter()
    {
        var key, newLt, lt;
        let this->letters = range("A", "Z");
        for lt in range("A", "D") {
            for key, newLt in range("A", "Z") {
                let this->letters[] = lt . newLt;
            }
        }
    }

    /**
     * @return string
     */
    public function getStartColumn()
    {
        return self::COLUMN_START_DEFAULT;
    }

    /**
     * @return string
     */
    public function getEndColumn()
    {
        var countHeaders;
        let countHeaders = count(this->headers);
        return this->letters[countHeaders];
    }
}
