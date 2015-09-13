
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"


/**
  * @class Phady\Util\File - Util class for file manipulation
  *
  * @author  Alien Fernández Fuentes <alienfernandez85@gmail.com>
  * @package Util
  * @copyright (c) 2015
  * @version 1.0.0
  */
ZEPHIR_INIT_CLASS(Phady_Util_File) {

	ZEPHIR_REGISTER_CLASS(Phady\\Util, File, phady, util_file, phady_util_file_method_entry, 0);

	zend_declare_class_constant_string(phady_util_file_ce, SL("CONTENT_DISPOSITION_DEFAULT"), "attachment" TSRMLS_CC);

	zend_declare_class_constant_string(phady_util_file_ce, SL("CONTENT_DISPOSITION_INLINE"), "inline" TSRMLS_CC);

	zend_declare_class_constant_string(phady_util_file_ce, SL("FILE_TYPE_PDF"), "pdf" TSRMLS_CC);

	zend_declare_class_constant_string(phady_util_file_ce, SL("FILE_TYPE_EXCEL"), "xls" TSRMLS_CC);

	zend_declare_class_constant_string(phady_util_file_ce, SL("FILE_TYPE_EXCELX"), "xlsx" TSRMLS_CC);

	zend_declare_class_constant_string(phady_util_file_ce, SL("FILE_TYPE_CSV"), "csv" TSRMLS_CC);

	return SUCCESS;

}

/**
 * @name downloadFile - Forcing file download
 * @param string $name File name
 * @param string $path File path
 * @param string $type File Type (pdf|xls|...)
 * @param string $contentDisposition Download form (attachment|inline)
 * @return file | -1
 */
PHP_METHOD(Phady_Util_File, downloadFile) {

	zephir_fcall_cache_entry *_3 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *path_param = NULL, *type_param = NULL, *contentDisposition_param = NULL, statusDownload, *_0 = NULL, *_1 = NULL, *_2, _4 = zval_used_for_init, *_6 = NULL, *_7;
	zval *name = NULL, *path = NULL, *type = NULL, *contentDisposition = NULL, *_5;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &name_param, &path_param, &type_param, &contentDisposition_param);

	if (unlikely(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(name, name_param);
	} else {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	}
	if (unlikely(Z_TYPE_P(path_param) != IS_STRING && Z_TYPE_P(path_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'path' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(path_param) == IS_STRING)) {
		zephir_get_strval(path, path_param);
	} else {
		ZEPHIR_INIT_VAR(path);
		ZVAL_EMPTY_STRING(path);
	}
	if (unlikely(Z_TYPE_P(type_param) != IS_STRING && Z_TYPE_P(type_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'type' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(type_param) == IS_STRING)) {
		zephir_get_strval(type, type_param);
	} else {
		ZEPHIR_INIT_VAR(type);
		ZVAL_EMPTY_STRING(type);
	}
	if (!contentDisposition_param) {
		ZEPHIR_INIT_VAR(contentDisposition);
		ZVAL_STRING(contentDisposition, "attachment", 1);
	} else {
		zephir_get_strval(contentDisposition, contentDisposition_param);
	}


	ZEPHIR_CALL_FUNCTION(&_0, "is_file", NULL, 137, path);
	zephir_check_call_status();
	ZEPHIR_SINIT_VAR(statusDownload);
	if (zephir_is_true(_0)) {
		ZEPHIR_CALL_SELF(&_1, "getcontenttype", NULL, 0, type);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_2);
		ZEPHIR_CONCAT_SV(_2, "Content-type: ", _1);
		ZEPHIR_CALL_FUNCTION(NULL, "header", &_3, 138, _2);
		zephir_check_call_status();
		if (ZEPHIR_IS_STRING(contentDisposition, "attachment")) {
			ZEPHIR_SINIT_VAR(_4);
			ZVAL_STRING(&_4, "Content-Type: application/force-download", 0);
			ZEPHIR_CALL_FUNCTION(NULL, "header", &_3, 138, &_4);
			zephir_check_call_status();
			ZEPHIR_SINIT_NVAR(_4);
			ZVAL_STRING(&_4, "Content-Type: application/download", 0);
			ZEPHIR_CALL_FUNCTION(NULL, "header", &_3, 138, &_4);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_VAR(_5);
		ZEPHIR_CONCAT_SVSV(_5, "Content-Disposition: ", contentDisposition, "; filename=", name);
		ZEPHIR_CALL_FUNCTION(NULL, "header", &_3, 138, _5);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_4);
		ZVAL_STRING(&_4, "Content-Transfer-Encoding: binary", 0);
		ZEPHIR_CALL_FUNCTION(NULL, "header", &_3, 138, &_4);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_6, "filesize", NULL, 139, path);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_7);
		ZEPHIR_CONCAT_SV(_7, "Content-Length: ", _6);
		ZEPHIR_CALL_FUNCTION(NULL, "header", &_3, 138, _7);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_4);
		ZVAL_STRING(&_4, "Accept-Ranges: bytes", 0);
		ZEPHIR_CALL_FUNCTION(NULL, "header", &_3, 138, &_4);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(NULL, "readfile", NULL, 140, path);
		zephir_check_call_status();
		ZVAL_BOOL(&statusDownload, 1);
	} else {
		ZVAL_LONG(&statusDownload, -1);
	}
	RETURN_LCTOR(statusDownload);

}

/**
 * @name getContentType - Get the content type of a file
 * @param string $type File Type (pdf|xls|...)
 * @return string
 */
PHP_METHOD(Phady_Util_File, getContentType) {

	zval *type_param = NULL, *strType = NULL;
	zval *type = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &type_param);

	if (unlikely(Z_TYPE_P(type_param) != IS_STRING && Z_TYPE_P(type_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'type' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(type_param) == IS_STRING)) {
		zephir_get_strval(type, type_param);
	} else {
		ZEPHIR_INIT_VAR(type);
		ZVAL_EMPTY_STRING(type);
	}


	ZEPHIR_INIT_VAR(strType);
	ZVAL_STRING(strType, "", 1);
	do {
		if (ZEPHIR_IS_STRING(type, "pdf")) {
			ZEPHIR_INIT_NVAR(strType);
			ZVAL_STRING(strType, "application/pdf", 1);
			break;
		}
		if (ZEPHIR_IS_STRING(type, "xls")) {
			ZEPHIR_INIT_NVAR(strType);
			ZVAL_STRING(strType, "application/vnd.openxmlformats-officedocument.spreadsheetml.sheet", 1);
			break;
		}
		if (ZEPHIR_IS_STRING(type, "xlsx")) {
			ZEPHIR_INIT_NVAR(strType);
			ZVAL_STRING(strType, "application/vnd.openxmlformats-officedocument.spreadsheetml.sheet", 1);
			break;
		}
		if (ZEPHIR_IS_STRING(type, "csv")) {
			ZEPHIR_INIT_NVAR(strType);
			ZVAL_STRING(strType, "application/csv", 1);
			break;
		}
		ZEPHIR_INIT_NVAR(strType);
		ZVAL_STRING(strType, "application/octet-stream", 1);
	} while(0);

	RETURN_CCTOR(strType);

}

