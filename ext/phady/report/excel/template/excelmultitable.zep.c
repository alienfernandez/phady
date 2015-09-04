
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/hash.h"
#include "kernel/concat.h"
#include "kernel/array.h"
#include "kernel/operators.h"


/**
  * @class Phady\Report\Excel\Template\ExcelMultiTable -  template excel multi table
  *
  * @author  Alien Fernández Fuentes <alienfernandez85@gmail.com>
  * @package Core
  * @copyright (c) 2015
  * @version 1.0.0
  */
ZEPHIR_INIT_CLASS(Phady_Report_Excel_Template_ExcelMultiTable) {

	ZEPHIR_REGISTER_CLASS(Phady\\Report\\Excel\\Template, ExcelMultiTable, phady, report_excel_template_excelmultitable, phady_report_excel_template_excelmultitable_method_entry, 0);

	zend_declare_property_null(phady_report_excel_template_excelmultitable_ce, SL("excel"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phady_report_excel_template_excelmultitable_ce, SL("style_table"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phady_report_excel_template_excelmultitable_ce, SL("style_header"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phady_report_excel_template_excelmultitable_ce, SL("style"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phady_report_excel_template_excelmultitable_ce, SL("title"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phady_report_excel_template_excelmultitable_ce, SL("start_row"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phady_report_excel_template_excelmultitable_ce, SL("start_col"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phady_report_excel_template_excelmultitable_ce, SL("title_sheet"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phady_report_excel_template_excelmultitable_ce, SL("sheet"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phady_report_excel_template_excelmultitable_ce, SL("config"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phady_report_excel_template_excelmultitable_ce, SL("headers"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phady_report_excel_template_excelmultitable_ce, SL("letters"), ZEND_ACC_PROTECTED TSRMLS_CC);

	phady_report_excel_template_excelmultitable_ce->create_object = zephir_init_properties_Phady_Report_Excel_Template_ExcelMultiTable;
	zend_declare_class_constant_long(phady_report_excel_template_excelmultitable_ce, SL("ROW_START_DEFAULT"), 5 TSRMLS_CC);

	zend_declare_class_constant_string(phady_report_excel_template_excelmultitable_ce, SL("COLUMN_START_DEFAULT"), "B" TSRMLS_CC);

	zend_declare_class_constant_bool(phady_report_excel_template_excelmultitable_ce, SL("AUTO_SIZE"), 1 TSRMLS_CC);

	return SUCCESS;

}

/**
 * @param array config - The config template multi-table
 */
PHP_METHOD(Phady_Report_Excel_Template_ExcelMultiTable, __construct) {

	zval *config_param = NULL;
	zval *config = NULL;

	zephir_fetch_params(0, 1, 0, &config_param);

	config = config_param;



	zephir_update_property_this(this_ptr, SL("config"), config TSRMLS_CC);

}

/**
 * @return \PHPExcel
 */
PHP_METHOD(Phady_Report_Excel_Template_ExcelMultiTable, getExcelInstance) {


	RETURN_MEMBER(this_ptr, "excel");

}

/**
 * @return string
 */
PHP_METHOD(Phady_Report_Excel_Template_ExcelMultiTable, getStartRow) {


	RETURN_LONG(5);

}

/**
 * @return string
 */
PHP_METHOD(Phady_Report_Excel_Template_ExcelMultiTable, getColumnLetter) {

	HashTable *_6, *_10;
	HashPosition _5, _9;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_3 = NULL;
	zval *key = NULL, *newLt = NULL, *lt = NULL, _0 = zval_used_for_init, _1 = zval_used_for_init, *_2 = NULL, *_4 = NULL, **_7, *_8 = NULL, **_11, *_12 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "A", 0);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "Z", 0);
	ZEPHIR_CALL_FUNCTION(&_2, "range", &_3, 45, &_0, &_1);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("letters"), _2 TSRMLS_CC);
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_STRING(&_0, "A", 0);
	ZEPHIR_SINIT_NVAR(_1);
	ZVAL_STRING(&_1, "D", 0);
	ZEPHIR_CALL_FUNCTION(&_4, "range", &_3, 45, &_0, &_1);
	zephir_check_call_status();
	zephir_is_iterable(_4, &_6, &_5, 0, 0, "phady/report/excel/template/excelmultitable.zep", 80);
	for (
	  ; zephir_hash_get_current_data_ex(_6, (void**) &_7, &_5) == SUCCESS
	  ; zephir_hash_move_forward_ex(_6, &_5)
	) {
		ZEPHIR_GET_HVALUE(lt, _7);
		ZEPHIR_SINIT_NVAR(_0);
		ZVAL_STRING(&_0, "A", 0);
		ZEPHIR_SINIT_NVAR(_1);
		ZVAL_STRING(&_1, "Z", 0);
		ZEPHIR_CALL_FUNCTION(&_8, "range", &_3, 45, &_0, &_1);
		zephir_check_call_status();
		zephir_is_iterable(_8, &_10, &_9, 0, 0, "phady/report/excel/template/excelmultitable.zep", 79);
		for (
		  ; zephir_hash_get_current_data_ex(_10, (void**) &_11, &_9) == SUCCESS
		  ; zephir_hash_move_forward_ex(_10, &_9)
		) {
			ZEPHIR_GET_HMKEY(key, _10, _9);
			ZEPHIR_GET_HVALUE(newLt, _11);
			ZEPHIR_INIT_LNVAR(_12);
			ZEPHIR_CONCAT_VV(_12, lt, newLt);
			zephir_update_property_array_append(this_ptr, SL("letters"), _12 TSRMLS_CC);
		}
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * @return string
 */
PHP_METHOD(Phady_Report_Excel_Template_ExcelMultiTable, getStartColumn) {


	RETURN_STRING("B", 1);

}

/**
 * @return string
 */
PHP_METHOD(Phady_Report_Excel_Template_ExcelMultiTable, getEndColumn) {

	zval *countHeaders, *_0, *_1, *_2;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("headers"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(countHeaders);
	ZVAL_LONG(countHeaders, zephir_fast_count_int(_0 TSRMLS_CC));
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("letters"), PH_NOISY_CC);
	zephir_array_fetch(&_2, _1, countHeaders, PH_NOISY | PH_READONLY, "phady/report/excel/template/excelmultitable.zep", 97 TSRMLS_CC);
	RETURN_CTOR(_2);

}

static zend_object_value zephir_init_properties_Phady_Report_Excel_Template_ExcelMultiTable(zend_class_entry *class_type TSRMLS_DC) {

		zval *_0, *_1 = NULL, *_2;

		ZEPHIR_MM_GROW();
	
	{
		zval *this_ptr = NULL;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("letters"), PH_NOISY_CC);
		if (Z_TYPE_P(_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(_1);
			array_init(_1);
			zephir_update_property_this(this_ptr, SL("letters"), _1 TSRMLS_CC);
		}
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("headers"), PH_NOISY_CC);
		if (Z_TYPE_P(_2) == IS_NULL) {
			ZEPHIR_INIT_NVAR(_1);
			array_init(_1);
			zephir_update_property_this(this_ptr, SL("headers"), _1 TSRMLS_CC);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJVAL_P(this_ptr);
	}

}

