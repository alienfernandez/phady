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
  * @class Phady\Util\File - Util class for file manipulation
  *
  * @author  Alien Fernández Fuentes <alienfernandez85@gmail.com>
  * @package Util
  * @copyright (c) 2015
  * @version 1.0.0
  */
class File
{
    const CONTENT_DISPOSITION_DEFAULT = "attachment";
    const CONTENT_DISPOSITION_INLINE = "inline";
    const FILE_TYPE_PDF = "pdf";
    const FILE_TYPE_EXCEL = "xls";
    const FILE_TYPE_EXCELX = "xlsx";
    const FILE_TYPE_CSV = "csv";

    /**
     * @name downloadFile - Forcing file download
     * @param string $name File name
     * @param string $path File path
     * @param string $type File Type (pdf|xls|...)
     * @param string $contentDisposition Download form (attachment|inline)
     * @return file | -1
     */
    public static function downloadFile (string! name, string! path, string! type, string contentDisposition = self::CONTENT_DISPOSITION_DEFAULT)
    {
        var statusDownload;
        //View or download the File
        if (is_file(path)) {
            header("Content-type: " . self::getContentType(type));
            if (contentDisposition == self::CONTENT_DISPOSITION_DEFAULT) {
                // force download
                header("Content-Type: application/force-download");
                header("Content-Type: application/download");
            }
            header("Content-Disposition: " . contentDisposition . "; filename=" . name);
            header("Content-Transfer-Encoding: binary");
            header("Content-Length: " . filesize(path));
            header("Accept-Ranges: bytes");
            readfile(path);
            let statusDownload = true;
        } else {
            let statusDownload = -1;
        }
        return statusDownload;
    }

    /**
     * @name getContentType - Get the content type of a file
     * @param string $type File Type (pdf|xls|...)
     * @return string
     */
    public static function getContentType (string! type) -> string
    {
        var strType;
        let strType = "";
        switch (type) {
            case self::FILE_TYPE_PDF:
                let strType = "application/pdf";
                break;
            case self::FILE_TYPE_EXCEL:
                let strType = "application/vnd.openxmlformats-officedocument.spreadsheetml.sheet";
                break;
            case self::FILE_TYPE_EXCELX:
                let strType = "application/vnd.openxmlformats-officedocument.spreadsheetml.sheet";
                break;
            case self::FILE_TYPE_CSV:
                let strType = "application/csv";
                break;
            default:
                let strType = "application/octet-stream";
        }
        return strType;
    }

}
