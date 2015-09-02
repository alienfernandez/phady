
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
#include "kernel/object.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "ext/phalcon/phalcon/db/adapter/pdo/postgresql.zep.h"
#include "ext/phalcon/phalcon/db/adapter/pdo/mysql.zep.h"
#include "ext/phalcon/phalcon/db/adapter/pdo/sqlite.zep.h"
#include "ext/phalcon/phalcon/db/adapter/pdo/oracle.zep.h"


/**
  * @class Phady\Db\DatabaseHandler -  Database handlers for app
  *
  * @author  Alien Fernández Fuentes <alienfernandez85@gmail.com>
  * @package Core
  * @copyright (c) 2015
  * @version 1.0.0
  */
ZEPHIR_INIT_CLASS(Phady_Db_DatabaseHandler) {

	ZEPHIR_REGISTER_CLASS(Phady\\Db, DatabaseHandler, phady, db_databasehandler, phady_db_databasehandler_method_entry, ZEND_ACC_FINAL_CLASS);

	/**
	 * @var array config - Config database
	 */
	zend_declare_property_null(phady_db_databasehandler_ce, SL("config"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * @param array config - Config db
 */
PHP_METHOD(Phady_Db_DatabaseHandler, __construct) {

	zval *config_param = NULL;
	zval *config = NULL;

	zephir_fetch_params(0, 1, 0, &config_param);

	config = config_param;



	zephir_update_property_this(this_ptr, SL("config"), config TSRMLS_CC);

}

/**
 *
 * @return DBAdapter Adaptador de base de datos 
 */
PHP_METHOD(Phady_Db_DatabaseHandler, getAdapter) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *arrdbConfig, *dbConfig, *adapter = NULL, *_0, *_1, *_2 = NULL, *_3;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
	zephir_array_fetch_string(&_1, _0, SL("orm"), PH_NOISY | PH_READONLY, "phady/db/databasehandler.zep", 51 TSRMLS_CC);
	zephir_array_fetch_string(&dbConfig, _1, SL("database"), PH_NOISY | PH_READONLY, "phady/db/databasehandler.zep", 51 TSRMLS_CC);
	ZEPHIR_INIT_VAR(arrdbConfig);
	zephir_create_array(arrdbConfig, 4, 0 TSRMLS_CC);
	ZEPHIR_OBS_VAR(_2);
	zephir_array_fetch_string(&_2, dbConfig, SL("host"), PH_NOISY, "phady/db/databasehandler.zep", 54 TSRMLS_CC);
	zephir_array_update_string(&arrdbConfig, SL("host"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(_2);
	zephir_array_fetch_string(&_2, dbConfig, SL("username"), PH_NOISY, "phady/db/databasehandler.zep", 55 TSRMLS_CC);
	zephir_array_update_string(&arrdbConfig, SL("username"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(_2);
	zephir_array_fetch_string(&_2, dbConfig, SL("password"), PH_NOISY, "phady/db/databasehandler.zep", 56 TSRMLS_CC);
	zephir_array_update_string(&arrdbConfig, SL("password"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(_2);
	zephir_array_fetch_string(&_2, dbConfig, SL("dbname"), PH_NOISY, "phady/db/databasehandler.zep", 58 TSRMLS_CC);
	zephir_array_update_string(&arrdbConfig, SL("dbname"), &_2, PH_COPY | PH_SEPARATE);
	zephir_array_fetch_string(&_3, dbConfig, SL("driver"), PH_NOISY | PH_READONLY, "phady/db/databasehandler.zep", 61 TSRMLS_CC);
	do {
		if (ZEPHIR_IS_STRING(_3, "pgsql")) {
			ZEPHIR_INIT_VAR(adapter);
			object_init_ex(adapter, phalcon_db_adapter_pdo_postgresql_ce);
			if (zephir_has_constructor(adapter TSRMLS_CC)) {
				ZEPHIR_CALL_METHOD(NULL, adapter, "__construct", NULL, 0, arrdbConfig);
				zephir_check_call_status();
			}
			break;
		}
		if (ZEPHIR_IS_STRING(_3, "mysql")) {
			ZEPHIR_INIT_NVAR(adapter);
			object_init_ex(adapter, phalcon_db_adapter_pdo_mysql_ce);
			if (zephir_has_constructor(adapter TSRMLS_CC)) {
				ZEPHIR_CALL_METHOD(NULL, adapter, "__construct", NULL, 0, arrdbConfig);
				zephir_check_call_status();
			}
			break;
		}
		if (ZEPHIR_IS_STRING(_3, "sqlite")) {
			ZEPHIR_INIT_NVAR(adapter);
			object_init_ex(adapter, phalcon_db_adapter_pdo_sqlite_ce);
			if (zephir_has_constructor(adapter TSRMLS_CC)) {
				ZEPHIR_CALL_METHOD(NULL, adapter, "__construct", NULL, 0, arrdbConfig);
				zephir_check_call_status();
			}
			break;
		}
		if (ZEPHIR_IS_STRING(_3, "oracle")) {
			ZEPHIR_INIT_NVAR(adapter);
			object_init_ex(adapter, phalcon_db_adapter_pdo_oracle_ce);
			if (zephir_has_constructor(adapter TSRMLS_CC)) {
				ZEPHIR_CALL_METHOD(NULL, adapter, "__construct", NULL, 0, arrdbConfig);
				zephir_check_call_status();
			}
			break;
		}
		ZEPHIR_INIT_NVAR(adapter);
		object_init_ex(adapter, phalcon_db_adapter_pdo_postgresql_ce);
		if (zephir_has_constructor(adapter TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, adapter, "__construct", NULL, 0, arrdbConfig);
			zephir_check_call_status();
		}
		break;
	} while(0);

	RETURN_CCTOR(adapter);

}

