
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
#include "kernel/string.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"


/**
  * @class Phady\Console\Command - Console class for execute command in console
  *
  * @author  Alien Fernández Fuentes <alienfernandez85@gmail.com>
  * @package Console
  * @copyright (c) 2015
  * @version 1.0.0
  */
ZEPHIR_INIT_CLASS(Phady_Console_Command) {

	ZEPHIR_REGISTER_CLASS(Phady\\Console, Command, phady, console_command, phady_console_command_method_entry, 0);

	zend_declare_class_constant_string(phady_console_command_ce, SL("WINDOWS_PLATFORM"), "Windows" TSRMLS_CC);

	zend_declare_class_constant_string(phady_console_command_ce, SL("UNIX_PLATFORM"), "Unix" TSRMLS_CC);

	return SUCCESS;

}

/**
 * Run Application in background
 *
 * @param     string command
 * @param     int priority
 * @return     PID
 */
PHP_METHOD(Phady_Console_Command, background) {

	zephir_fcall_cache_entry *_7 = NULL;
	int priority, ZEPHIR_LAST_CALL_STATUS;
	zval *command_param = NULL, *priority_param = NULL, *pID = NULL, *_0 = NULL, _1, _2, *_3, _5 = zval_used_for_init, *_6 = NULL;
	zval *command = NULL, *_4 = NULL, *_8;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &command_param, &priority_param);

	if (unlikely(Z_TYPE_P(command_param) != IS_STRING && Z_TYPE_P(command_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'command' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(command_param) == IS_STRING)) {
		zephir_get_strval(command, command_param);
	} else {
		ZEPHIR_INIT_VAR(command);
		ZVAL_EMPTY_STRING(command);
	}
	if (!priority_param) {
		priority = 0;
	} else {
		priority = zephir_get_intval(priority_param);
	}


	ZEPHIR_CALL_FUNCTION(&_0, "php_uname", NULL, 31);
	zephir_check_call_status();
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_LONG(&_1, 0);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_LONG(&_2, 7);
	ZEPHIR_INIT_VAR(_3);
	zephir_substr(_3, _0, 0 , 7 , 0);
	if (ZEPHIR_IS_STRING(_3, "Windows")) {
		ZEPHIR_INIT_VAR(_4);
		ZEPHIR_CONCAT_SV(_4, "start /B ", command);
		ZEPHIR_SINIT_VAR(_5);
		ZVAL_STRING(&_5, "r", 0);
		ZEPHIR_CALL_FUNCTION(&_6, "popen", NULL, 32, _4, &_5);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(NULL, "pclose", NULL, 33, _6);
		zephir_check_call_status();
	} else {
		if (priority) {
			ZEPHIR_SINIT_NVAR(_5);
			ZVAL_LONG(&_5, priority);
			ZEPHIR_INIT_LNVAR(_4);
			ZEPHIR_CONCAT_SVS(_4, "nohup nice -n ", &_5, "command > /dev/null & echo $!");
			ZEPHIR_CALL_FUNCTION(&pID, "shell_exec", &_7, 34, _4);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_VAR(_8);
			ZEPHIR_CONCAT_SVS(_8, "nohup ", command, " > /dev/null & echo $!");
			ZEPHIR_CALL_FUNCTION(&pID, "shell_exec", &_7, 34, _8);
			zephir_check_call_status();
		}
	}
	RETURN_CCTOR(pID);

}

/**
 * Check if the Application running !
 *
 * @param     string pID
 * @return     boolen
 */
PHP_METHOD(Phady_Console_Command, isRunning) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *pID_param = NULL, *processState;
	zval *pID = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &pID_param);

	zephir_get_strval(pID, pID_param);


	ZEPHIR_INIT_VAR(processState);
	array_init(processState);
	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_CONCAT_SV(_0, "ps ", pID);
	Z_SET_ISREF_P(processState);
	ZEPHIR_CALL_FUNCTION(NULL, "exec", NULL, 35, _0, processState);
	Z_UNSET_ISREF_P(processState);
	zephir_check_call_status();
	RETURN_MM_BOOL((zephir_fast_count_int(processState TSRMLS_CC) >= 2));

}

/**
 * Kill Application PID
 *
 * @param  string pID
 * @return boolen
 */
PHP_METHOD(Phady_Console_Command, kill) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *pID_param = NULL, *_0 = NULL;
	zval *pID = NULL, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &pID_param);

	zephir_get_strval(pID, pID_param);


	ZEPHIR_CALL_SELF(&_0, "isrunning", NULL, 0, pID);
	zephir_check_call_status();
	if (zephir_is_true(_0)) {
		ZEPHIR_INIT_VAR(_1);
		ZEPHIR_CONCAT_SV(_1, "kill -KILL ", pID);
		ZEPHIR_CALL_FUNCTION(NULL, "exec", NULL, 35, _1);
		zephir_check_call_status();
		RETURN_MM_BOOL(1);
	}
	RETURN_MM_BOOL(0);

}

