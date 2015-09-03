
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
#include "kernel/array.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/concat.h"
#include "kernel/fcall.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/string.h"
#include "kernel/exit.h"
#include "kernel/hash.h"


/**
  * @class Phady\Mail\MailReader - This class is used to read and analyze IMAP mailboxes with features such as :
  * - Used to access plain text, html , headers and attachments of messages
  * - Read Message by date of receipt by the sender address messages .
  *
  * @author  Alien Fernández Fuentes <alienfernandez85@gmail.com>
  * @package Mail
  * @copyright (c) 2015
  * @version 1.0.0
  */
ZEPHIR_INIT_CLASS(Phady_Mail_MailReader) {

	ZEPHIR_REGISTER_CLASS(Phady\\Mail, MailReader, phady, mail_mailreader, phady_mail_mailreader_method_entry, 0);

	/**
	 * Mail server to connect
	 *
	 * @var string
	 */
	zend_declare_property_string(phady_mail_mailreader_ce, SL("mailserver"), "", ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * User mail server ej. xyz.abc@mail.com
	 *
	 * @var string
	 */
	zend_declare_property_string(phady_mail_mailreader_ce, SL("username"), "", ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * User Password mail server
	 *
	 * @var string
	 */
	zend_declare_property_null(phady_mail_mailreader_ce, SL("password"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * Port connection to the mail server
	 *
	 * @var integer
	 */
	zend_declare_property_null(phady_mail_mailreader_ce, SL("port"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * Mailbox user input
	 *
	 * @var string
	 */
	zend_declare_property_string(phady_mail_mailreader_ce, SL("mailbox"), "", ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * Conexion al servidor de correo
	 *
	 * @var resource IMAP stream as a connection
	 */
	zend_declare_property_null(phady_mail_mailreader_ce, SL("connection"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * Contains items from header information
	 *
	 * @var Object
	 */
	zend_declare_property_null(phady_mail_mailreader_ce, SL("headers"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * Associative array containing the attachment name as a key and the corresponding binary file as value.
	 *
	 * @var Array
	 */
	zend_declare_property_null(phady_mail_mailreader_ce, SL("attachments"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * This variable contains the HTML part of a message .
	 *
	 * @var String
	 */
	zend_declare_property_string(phady_mail_mailreader_ce, SL("htmlBody"), "", ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * Contains the plain text part of a message.
	 *
	 * @var String
	 */
	zend_declare_property_string(phady_mail_mailreader_ce, SL("plainBody"), "", ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * Associative array containing attachments, HTMLBody , plainBody as their keys.
	 * 
	 * @var Array
	 */
	zend_declare_property_null(phady_mail_mailreader_ce, SL("result"), ZEND_ACC_PRIVATE TSRMLS_CC);

	phady_mail_mailreader_ce->create_object = zephir_init_properties_Phady_Mail_MailReader;
	/**
	 * Constant Connection Port mail server ssl
	 *
	 * @var integer
	 */
	zend_declare_class_constant_long(phady_mail_mailreader_ce, SL("IMAP_PORT_SSL"), 993 TSRMLS_CC);

	/**
	 * Use constant ssl
	 *
	 * @var bool
	 */
	zend_declare_class_constant_bool(phady_mail_mailreader_ce, SL("USE_SSL"), 1 TSRMLS_CC);

	/**
	 * Constant Use ssl certificate no
	 *
	 * @var bool
	 */
	zend_declare_class_constant_bool(phady_mail_mailreader_ce, SL("USE_NOVALIDATE_CERT_SSL"), 0 TSRMLS_CC);

	/**
	 * Constant Try connecting the mail server three times
	 *
	 * @var bool
	 */
	zend_declare_class_constant_long(phady_mail_mailreader_ce, SL("TRY_TO_CONNECT"), 3 TSRMLS_CC);

	/**
	 * Option unread message
	 *
	 * @var bool
	 */
	zend_declare_class_constant_long(phady_mail_mailreader_ce, SL("UNREAD"), 4 TSRMLS_CC);

	/**
	 * Constant type of mail server
	 *
	 * @var string
	 */
	zend_declare_class_constant_string(phady_mail_mailreader_ce, SL("DEFAULT_SERVER_TYPE"), "imap" TSRMLS_CC);

	return SUCCESS;

}

/**
 * Constructor de la clase MailReader
 *
 * @param String username
 * @param String password
 * @param String mailserver
 * @param Array options - Array de opciones
 *                  ["serverType"] - Type access server messages stored on an Internet server ej. "imap" o "pop".
 *                  ["useSSL"] - If you are using secure communication with the server.
 *                  ["useNoValidateCertSSL"] - If the server does not have a valid certificate.
 *                  ["port"] - Port for communication with server.
 */
PHP_METHOD(Phady_Mail_MailReader, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool _3;
	zval *username_param = NULL, *password_param = NULL, *mailserver_param = NULL, *options = NULL, *serverType = NULL, *useSSL = NULL, *useNoValidateCertSSL = NULL, *port = NULL, *strConnect = NULL, _0, _1, _2, *_4, _5, *_6;
	zval *username = NULL, *password = NULL, *mailserver = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 2, &username_param, &password_param, &mailserver_param, &options);

	if (unlikely(Z_TYPE_P(username_param) != IS_STRING && Z_TYPE_P(username_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'username' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(username_param) == IS_STRING)) {
		zephir_get_strval(username, username_param);
	} else {
		ZEPHIR_INIT_VAR(username);
		ZVAL_EMPTY_STRING(username);
	}
	if (unlikely(Z_TYPE_P(password_param) != IS_STRING && Z_TYPE_P(password_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'password' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(password_param) == IS_STRING)) {
		zephir_get_strval(password, password_param);
	} else {
		ZEPHIR_INIT_VAR(password);
		ZVAL_EMPTY_STRING(password);
	}
	if (!mailserver_param) {
		ZEPHIR_INIT_VAR(mailserver);
		ZVAL_STRING(mailserver, "imap.gmail.com", 1);
	} else {
	if (unlikely(Z_TYPE_P(mailserver_param) != IS_STRING && Z_TYPE_P(mailserver_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'mailserver' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(mailserver_param) == IS_STRING)) {
		zephir_get_strval(mailserver, mailserver_param);
	} else {
		ZEPHIR_INIT_VAR(mailserver);
		ZVAL_EMPTY_STRING(mailserver);
	}
	}
	if (!options) {
		ZEPHIR_INIT_VAR(options);
		array_init(options);
	}


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "serverType", 0);
	if (zephir_array_key_exists(options, &_0 TSRMLS_CC)) {
		ZEPHIR_OBS_VAR(serverType);
		zephir_array_fetch_string(&serverType, options, SL("serverType"), PH_NOISY, "phady/mail/mailreader.zep", 161 TSRMLS_CC);
	} else {
		ZEPHIR_INIT_NVAR(serverType);
		ZVAL_STRING(serverType, "imap", 1);
	}
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "useSSL", 0);
	if (zephir_array_key_exists(options, &_1 TSRMLS_CC)) {
		ZEPHIR_OBS_VAR(useSSL);
		zephir_array_fetch_string(&useSSL, options, SL("useSSL"), PH_NOISY, "phady/mail/mailreader.zep", 162 TSRMLS_CC);
	} else {
		ZEPHIR_INIT_NVAR(useSSL);
		ZVAL_BOOL(useSSL, 1);
	}
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_STRING(&_2, "useNoValidateCertSSL", 0);
	_3 = zephir_array_key_exists(options, &_2 TSRMLS_CC);
	if (_3) {
		ZEPHIR_OBS_VAR(_4);
		zephir_array_fetch_string(&_4, options, SL("useNoValidateCertSSL"), PH_NOISY, "phady/mail/mailreader.zep", 163 TSRMLS_CC);
		_3 = !(ZEPHIR_IS_EMPTY(_4));
	}
	if (_3) {
		ZEPHIR_OBS_VAR(useNoValidateCertSSL);
		zephir_array_fetch_string(&useNoValidateCertSSL, options, SL("useNoValidateCertSSL"), PH_NOISY, "phady/mail/mailreader.zep", 163 TSRMLS_CC);
	} else {
		ZEPHIR_INIT_NVAR(useNoValidateCertSSL);
		ZVAL_BOOL(useNoValidateCertSSL, 0);
	}
	ZEPHIR_SINIT_VAR(_5);
	ZVAL_STRING(&_5, "port", 0);
	if (zephir_array_key_exists(options, &_5 TSRMLS_CC)) {
		ZEPHIR_OBS_VAR(port);
		zephir_array_fetch_string(&port, options, SL("port"), PH_NOISY, "phady/mail/mailreader.zep", 164 TSRMLS_CC);
	} else {
		ZEPHIR_INIT_NVAR(port);
		ZVAL_LONG(port, 993);
	}
	if (ZEPHIR_IS_STRING(serverType, "imap")) {
		ZEPHIR_INIT_VAR(strConnect);
		if (zephir_is_true(useSSL)) {
			ZEPHIR_INIT_ZVAL_NREF(_6);
			ZVAL_LONG(_6, 993);
			zephir_update_property_this(this_ptr, SL("port"), _6 TSRMLS_CC);
			_6 = zephir_fetch_nproperty_this(this_ptr, SL("port"), PH_NOISY_CC);
			ZEPHIR_CONCAT_SVSVS(strConnect, "{", mailserver, ":", _6, "/imap/ssl");
			if (zephir_is_true(useNoValidateCertSSL)) {
				zephir_concat_self_str(&strConnect, SL("/novalidate-cert}") TSRMLS_CC);
			} else {
				zephir_concat_self_str(&strConnect, SL("}") TSRMLS_CC);
			}
		} else {
			ZEPHIR_INIT_ZVAL_NREF(_6);
			ZVAL_LONG(_6, 143);
			zephir_update_property_this(this_ptr, SL("port"), _6 TSRMLS_CC);
			_6 = zephir_fetch_nproperty_this(this_ptr, SL("port"), PH_NOISY_CC);
			ZEPHIR_CONCAT_SVSVS(strConnect, "{", mailserver, ":", _6, "/novalidate-cert}");
		}
	} else {
		ZEPHIR_INIT_NVAR(strConnect);
		ZEPHIR_CONCAT_SVSVS(strConnect, "{", mailserver, ":", port, "/pop3/novalidate-cert}");
		zephir_update_property_this(this_ptr, SL("port"), port TSRMLS_CC);
	}
	zephir_update_property_this(this_ptr, SL("mailbox"), strConnect TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("mailserver"), mailserver TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("username"), username TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("password"), password TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setconnection", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Function to connect to the specified email server .
 *
 * @return IMAP stream as a connection
 */
PHP_METHOD(Phady_Mail_MailReader, setConnection) {

	zephir_fcall_cache_entry *_13 = NULL, *_16 = NULL;
	int _8, _9, ZEPHIR_LAST_CALL_STATUS;
	zend_bool _7;
	zval *key = NULL, *exception = NULL, *_0, *_1, *_2, _3, *_4, *_5, *_6, *_10, *_11, *_12 = NULL, *_14 = NULL, *_15 = NULL;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("connection"), PH_NOISY_CC);
	if (!zephir_is_true(_0)) {
		ZEPHIR_INIT_VAR(_1);
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("mailbox"), PH_NOISY_CC);
		zephir_fast_trim(_1, _2, NULL , ZEPHIR_TRIM_BOTH TSRMLS_CC);
		ZEPHIR_SINIT_VAR(_3);
		ZVAL_LONG(&_3, -1);
		ZEPHIR_INIT_VAR(_4);
		zephir_substr(_4, _1, -1 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
		if (ZEPHIR_IS_STRING(_4, "}")) {
			_5 = zephir_fetch_nproperty_this(this_ptr, SL("mailbox"), PH_NOISY_CC);
			ZEPHIR_INIT_VAR(_6);
			ZEPHIR_CONCAT_VS(_6, _5, "INBOX");
			zephir_update_property_this(this_ptr, SL("mailbox"), _6 TSRMLS_CC);
		}

		/* try_start_1: */

			_9 = 3;
			_8 = 1;
			_7 = 0;
			if (_8 <= _9) {
				while (1) {
					if (_7) {
						_8++;
						if (!(_8 <= _9)) {
							break;
						}
					} else {
						_7 = 1;
					}
					ZEPHIR_INIT_NVAR(key);
					ZVAL_LONG(key, _8);
					if ((zephir_function_exists_ex(SS("imap_open") TSRMLS_CC) == SUCCESS)) {
						_5 = zephir_fetch_nproperty_this(this_ptr, SL("mailbox"), PH_NOISY_CC);
						_10 = zephir_fetch_nproperty_this(this_ptr, SL("username"), PH_NOISY_CC);
						_11 = zephir_fetch_nproperty_this(this_ptr, SL("password"), PH_NOISY_CC);
						ZEPHIR_CALL_FUNCTION(&_12, "imap_open", &_13, 34, _5, _10, _11);
						zephir_check_call_status_or_jump(try_end_1);
						zephir_update_property_this(this_ptr, SL("connection"), _12 TSRMLS_CC);
					} else {
						ZEPHIR_INIT_NVAR(_14);
						object_init_ex(_14, zend_exception_get_default(TSRMLS_C));
						ZEPHIR_INIT_NVAR(_15);
						ZVAL_STRING(_15, "imap_open function is not available install the extension php5_imap", ZEPHIR_TEMP_PARAM_COPY);
						ZEPHIR_CALL_METHOD(NULL, _14, "__construct", &_16, 26, _15);
						zephir_check_temp_parameter(_15);
						zephir_check_call_status_or_jump(try_end_1);
						zephir_throw_exception_debug(_14, "phady/mail/mailreader.zep", 213 TSRMLS_CC);
						goto try_end_1;

					}
					_10 = zephir_fetch_nproperty_this(this_ptr, SL("connection"), PH_NOISY_CC);
					if (zephir_is_true(_10)) {
						RETURN_MM_MEMBER(this_ptr, "connection");
					}
				}
			}
			ZEPHIR_INIT_NVAR(_14);
			object_init_ex(_14, zend_exception_get_default(TSRMLS_C));
			ZEPHIR_INIT_NVAR(_15);
			ZVAL_STRING(_15, "You can't connect the mail server", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(NULL, _14, "__construct", &_16, 26, _15);
			zephir_check_temp_parameter(_15);
			zephir_check_call_status_or_jump(try_end_1);
			zephir_throw_exception_debug(_14, "phady/mail/mailreader.zep", 220 TSRMLS_CC);
			goto try_end_1;


		try_end_1:

		if (EG(exception)) {
			ZEPHIR_CPY_WRT(exception, EG(exception));
			if (zephir_instance_of_ev(exception, zend_exception_get_default(TSRMLS_C) TSRMLS_CC)) {
				zend_clear_exception(TSRMLS_C);
				ZEPHIR_CALL_METHOD(&_12, exception, "getmessage", NULL, 0);
				zephir_check_call_status();
				zend_print_zval(_12, 0);
				zephir_exit_empty();
				ZEPHIR_MM_RESTORE();
			}
		}
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Function to read messages and filter user
 *
 * @param Integer userInput
 * @param Integer filterType
 * @param Boolean flag
 */
PHP_METHOD(Phady_Mail_MailReader, readMessageByFilter) {

	zephir_fcall_cache_entry *_6 = NULL, *_14 = NULL, *_15 = NULL, *_16 = NULL;
	zend_bool flag, filter, _1, _8;
	zval *userInput_param = NULL, *filterType_param = NULL, *flag_param = NULL, *i = NULL, *countMsg = NULL, *_0, *_3 = NULL, *_4, *_5 = NULL, *_7 = NULL, *_9, *_10 = NULL, *_11 = NULL, _12 = zval_used_for_init, *_13 = NULL;
	int userInput, filterType, ZEPHIR_LAST_CALL_STATUS, _2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &userInput_param, &filterType_param, &flag_param);

	userInput = zephir_get_intval(userInput_param);
	filterType = zephir_get_intval(filterType_param);
	flag = zephir_get_boolval(flag_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("connection"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&countMsg, "imap_num_msg", NULL, 35, _0);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(_3, countMsg);
	_2 = 1;
	_1 = 0;
	if (ZEPHIR_GE_LONG(_3, _2)) {
		while (1) {
			if (_1) {
				_2++;
				if (!(ZEPHIR_GE_LONG(_3, _2))) {
					break;
				}
			} else {
				_1 = 1;
			}
			ZEPHIR_INIT_NVAR(i);
			ZVAL_LONG(i, _2);
			_4 = zephir_fetch_nproperty_this(this_ptr, SL("connection"), PH_NOISY_CC);
			ZEPHIR_CALL_FUNCTION(&_5, "imap_headerinfo", &_6, 36, _4, i);
			zephir_check_call_status();
			zephir_update_property_this(this_ptr, SL("headers"), _5 TSRMLS_CC);
			if (filterType == 0) {
				ZEPHIR_OBS_NVAR(_7);
				zephir_read_property_this(&_7, this_ptr, SL("headers"), PH_NOISY_CC);
				_8 = zephir_is_true(_7);
				if (_8) {
					_9 = zephir_fetch_nproperty_this(this_ptr, SL("headers"), PH_NOISY_CC);
					ZEPHIR_OBS_NVAR(_10);
					zephir_read_property(&_10, _9, SL("Msgno"), PH_NOISY_CC);
					ZEPHIR_INIT_NVAR(_11);
					ZEPHIR_SINIT_NVAR(_12);
					ZVAL_LONG(&_12, userInput);
					zephir_fast_trim(_11, &_12, NULL , ZEPHIR_TRIM_BOTH TSRMLS_CC);
					_8 = ZEPHIR_IS_EQUAL(_10, _11);
				}
				filter = _8;
			} else if (filterType == 1) {
				ZEPHIR_OBS_NVAR(_7);
				zephir_read_property_this(&_7, this_ptr, SL("headers"), PH_NOISY_CC);
				_8 = zephir_is_true(_7);
				if (_8) {
					_9 = zephir_fetch_nproperty_this(this_ptr, SL("headers"), PH_NOISY_CC);
					ZEPHIR_OBS_NVAR(_10);
					zephir_read_property(&_10, _9, SL("date"), PH_NOISY_CC);
					ZEPHIR_CALL_METHOD(&_13, this_ptr, "getrecdate", &_14, 37, _10);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(_11);
					ZEPHIR_SINIT_NVAR(_12);
					ZVAL_LONG(&_12, userInput);
					zephir_fast_trim(_11, &_12, NULL , ZEPHIR_TRIM_BOTH TSRMLS_CC);
					_8 = ZEPHIR_IS_EQUAL(_13, _11);
				}
				filter = _8;
			} else if (filterType == 2) {
				ZEPHIR_OBS_NVAR(_7);
				zephir_read_property_this(&_7, this_ptr, SL("headers"), PH_NOISY_CC);
				_8 = zephir_is_true(_7);
				if (_8) {
					_9 = zephir_fetch_nproperty_this(this_ptr, SL("headers"), PH_NOISY_CC);
					ZEPHIR_OBS_NVAR(_10);
					zephir_read_property(&_10, _9, SL("Subject"), PH_NOISY_CC);
					ZEPHIR_INIT_NVAR(_11);
					ZEPHIR_SINIT_NVAR(_12);
					ZVAL_LONG(&_12, userInput);
					zephir_fast_trim(_11, &_12, NULL , ZEPHIR_TRIM_BOTH TSRMLS_CC);
					_8 = ZEPHIR_IS_EQUAL(_10, _11);
				}
				filter = _8;
			} else if (filterType == 3) {
				ZEPHIR_OBS_NVAR(_7);
				zephir_read_property_this(&_7, this_ptr, SL("headers"), PH_NOISY_CC);
				_8 = zephir_is_true(_7);
				if (_8) {
					_9 = zephir_fetch_nproperty_this(this_ptr, SL("headers"), PH_NOISY_CC);
					ZEPHIR_OBS_NVAR(_10);
					zephir_read_property(&_10, _9, SL("fromaddress"), PH_NOISY_CC);
					ZEPHIR_INIT_NVAR(_11);
					ZEPHIR_SINIT_NVAR(_12);
					ZVAL_LONG(&_12, userInput);
					zephir_fast_trim(_11, &_12, NULL , ZEPHIR_TRIM_BOTH TSRMLS_CC);
					ZEPHIR_CALL_METHOD(&_13, this_ptr, "containsfromaddress", &_15, 38, _10, _11);
					zephir_check_call_status();
					_8 = zephir_is_true(_13);
				}
				filter = _8;
			} else if (filterType == 4) {
				ZEPHIR_OBS_NVAR(_7);
				zephir_read_property_this(&_7, this_ptr, SL("headers"), PH_NOISY_CC);
				_8 = zephir_is_true(_7);
				if (_8) {
					_8 = 1;
				}
				filter = _8;
			}
			if (filter) {
				if (flag) {
					_9 = zephir_fetch_nproperty_this(this_ptr, SL("headers"), PH_NOISY_CC);
					ZEPHIR_OBS_NVAR(_7);
					zephir_read_property(&_7, _9, SL("Unseen"), PH_NOISY_CC);
					if (ZEPHIR_IS_STRING(_7, "U")) {
						ZEPHIR_CALL_METHOD(NULL, this_ptr, "parsemessage", &_16, 0, i);
						zephir_check_call_status();
					}
				} else {
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "parsemessage", &_16, 0, i);
					zephir_check_call_status();
				}
			}
		}
	}
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("connection"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(NULL, "imap_close", NULL, 39, _4);
	zephir_check_call_status();
	RETURN_MM_MEMBER(this_ptr, "result");

}

/**
 * Date Posted format dd-mm-aaaa
 *
 * @param String date format Thu, 20 Aug 2009 15:55:52 +0530
 * @return String date format 08-20-2009
 */
PHP_METHOD(Phady_Mail_MailReader, getRecDate) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *date_param = NULL, *timestamp = NULL, _0, _1, *_2, _3;
	zval *date = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &date_param);

	zephir_get_strval(date, date_param);


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, 5);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_LONG(&_1, 20);
	ZEPHIR_INIT_VAR(_2);
	zephir_substr(_2, date, 5 , 20 , 0);
	zephir_get_strval(date, _2);
	ZEPHIR_CALL_FUNCTION(&timestamp, "strtotime", NULL, 40, date);
	zephir_check_call_status();
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_STRING(&_3, "m-d-Y", 0);
	ZEPHIR_RETURN_CALL_FUNCTION("date", NULL, 4, &_3, timestamp);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * This function is used to check the email id in particular present
 * The address of the header information . Returns true if present , otherwise false.
 *
 * @param String fromAddresses
 * @param String userInput
 * @return bool
 */
PHP_METHOD(Phady_Mail_MailReader, containsFromAddress) {

	zval *fromAddresses_param = NULL, *userInput_param = NULL, *_0;
	zval *fromAddresses = NULL, *userInput = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &fromAddresses_param, &userInput_param);

	if (unlikely(Z_TYPE_P(fromAddresses_param) != IS_STRING && Z_TYPE_P(fromAddresses_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'fromAddresses' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(fromAddresses_param) == IS_STRING)) {
		zephir_get_strval(fromAddresses, fromAddresses_param);
	} else {
		ZEPHIR_INIT_VAR(fromAddresses);
		ZVAL_EMPTY_STRING(fromAddresses);
	}
	if (unlikely(Z_TYPE_P(userInput_param) != IS_STRING && Z_TYPE_P(userInput_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'userInput' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(userInput_param) == IS_STRING)) {
		zephir_get_strval(userInput, userInput_param);
	} else {
		ZEPHIR_INIT_VAR(userInput);
		ZVAL_EMPTY_STRING(userInput);
	}


	ZEPHIR_INIT_VAR(_0);
	zephir_fast_strpos(_0, fromAddresses, userInput, 0 );
	if (!ZEPHIR_IS_FALSE(_0)) {
		RETURN_MM_BOOL(1);
	}
	RETURN_MM_BOOL(0);

}

/**
 * Function to get the message
 *
 * @param Integer messageId
 */
PHP_METHOD(Phady_Mail_MailReader, getMessage) {

	HashTable *_5;
	HashPosition _4;
	zval *messageId_param = NULL, *structure = NULL, *arrParts = NULL, *_0, _1, *_2 = NULL, *_3 = NULL, *partMsg = NULL, *key = NULL, **_6;
	int messageId, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &messageId_param);

	messageId = zephir_get_intval(messageId_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("connection"), PH_NOISY_CC);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_LONG(&_1, messageId);
	ZEPHIR_CALL_FUNCTION(&structure, "imap_fetchstructure", NULL, 41, _0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(arrParts);
	array_init(arrParts);
	ZEPHIR_OBS_NVAR(arrParts);
	zephir_read_property(&arrParts, structure, SL("parts"), PH_NOISY_CC);
	if (ZEPHIR_IS_EMPTY(arrParts)) {
		ZEPHIR_INIT_VAR(_2);
		ZVAL_LONG(_2, messageId);
		ZEPHIR_INIT_VAR(_3);
		ZVAL_LONG(_3, 0);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "getmessagepart", NULL, 0, _2, structure, _3);
		zephir_check_call_status();
	} else if (Z_TYPE_P(arrParts) == IS_ARRAY) {
		zephir_is_iterable(arrParts, &_5, &_4, 0, 0, "phady/mail/mailreader.zep", 323);
		for (
		  ; zephir_hash_get_current_data_ex(_5, (void**) &_6, &_4) == SUCCESS
		  ; zephir_hash_move_forward_ex(_5, &_4)
		) {
			ZEPHIR_GET_HMKEY(key, _5, _4);
			ZEPHIR_GET_HVALUE(partMsg, _6);
			ZEPHIR_INIT_NVAR(_2);
			ZVAL_LONG(_2, messageId);
			ZEPHIR_INIT_NVAR(_3);
			ZVAL_LONG(_3, (zephir_get_numberval(key) + 1));
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "getmessagepart", NULL, 0, _2, partMsg, _3);
			zephir_check_call_status();
		}
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Function to parse the message parts
 *
 * @param Integer messageId
 * @param Object partObj
 * @param Integer partno
 */
PHP_METHOD(Phady_Mail_MailReader, getMessagePart) {

	HashTable *_17, *_25, *_38;
	HashPosition _16, _24, _37;
	zval *_15 = NULL, *_23 = NULL, *_36 = NULL;
	zend_bool _6, _9, _12, _22, _28, _29, _30, _32, _34;
	zephir_fcall_cache_entry *_5 = NULL, *_41 = NULL;
	zval *messageId_param = NULL, *partObj, *partno_param = NULL, *data = NULL, *params, *x = NULL, *y = NULL, *filename = NULL, *partno2 = NULL, *part2 = NULL, *partNoAll = NULL, *part2Length = NULL, *_0, _1 = zval_used_for_init, _2 = zval_used_for_init, *_3, *_4 = NULL, *_7, *_8 = NULL, *_10, *_11 = NULL, *_13, *_14 = NULL, **_18, *_19 = NULL, *_20 = NULL, *_21 = NULL, **_26, *_27 = NULL, _31 = zval_used_for_init, *_33, *_35, **_39, _40 = zval_used_for_init;
	int messageId, partno, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &messageId_param, &partObj, &partno_param);

	messageId = zephir_get_intval(messageId_param);
	partno = zephir_get_intval(partno_param);


	if (partno) {
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("connection"), PH_NOISY_CC);
		ZEPHIR_SINIT_VAR(_1);
		ZVAL_LONG(&_1, messageId);
		ZEPHIR_SINIT_VAR(_2);
		ZVAL_LONG(&_2, partno);
		ZEPHIR_CALL_FUNCTION(&data, "imap_fetchbody", NULL, 42, _0, &_1, &_2);
		zephir_check_call_status();
	} else {
		_3 = zephir_fetch_nproperty_this(this_ptr, SL("connection"), PH_NOISY_CC);
		ZEPHIR_SINIT_NVAR(_1);
		ZVAL_LONG(&_1, messageId);
		ZEPHIR_CALL_FUNCTION(&data, "imap_body", NULL, 43, _3, &_1);
		zephir_check_call_status();
	}
	ZEPHIR_SINIT_NVAR(_1);
	ZVAL_STRING(&_1, "encoding", 0);
	ZEPHIR_CALL_FUNCTION(&_4, "property_exists", &_5, 33, partObj, &_1);
	zephir_check_call_status();
	_6 = zephir_is_true(_4);
	if (_6) {
		ZEPHIR_OBS_VAR(_7);
		zephir_read_property(&_7, partObj, SL("encoding"), PH_NOISY_CC);
		_6 = ZEPHIR_IS_LONG(_7, 4);
	}
	ZEPHIR_SINIT_NVAR(_1);
	ZVAL_STRING(&_1, "encoding", 0);
	ZEPHIR_CALL_FUNCTION(&_8, "property_exists", &_5, 33, partObj, &_1);
	zephir_check_call_status();
	_9 = zephir_is_true(_8);
	if (_9) {
		ZEPHIR_OBS_VAR(_10);
		zephir_read_property(&_10, partObj, SL("encoding"), PH_NOISY_CC);
		_9 = ZEPHIR_IS_LONG(_10, 3);
	}
	if (_6) {
		ZEPHIR_CALL_FUNCTION(&_11, "quoted_printable_decode", NULL, 44, data);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(data, _11);
	} else if (_9) {
		ZEPHIR_CALL_FUNCTION(&_11, "base64_decode", NULL, 45, data);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(data, _11);
	}
	ZEPHIR_INIT_VAR(params);
	array_init(params);
	ZEPHIR_SINIT_NVAR(_1);
	ZVAL_STRING(&_1, "parameters", 0);
	ZEPHIR_CALL_FUNCTION(&_11, "property_exists", &_5, 33, partObj, &_1);
	zephir_check_call_status();
	_12 = zephir_is_true(_11);
	if (_12) {
		ZEPHIR_OBS_VAR(_13);
		zephir_read_property(&_13, partObj, SL("parameters"), PH_NOISY_CC);
		_12 = zephir_is_true(_13);
	}
	if (_12) {
		ZEPHIR_OBS_VAR(_14);
		zephir_read_property(&_14, partObj, SL("parameters"), PH_NOISY_CC);
		zephir_get_arrval(_15, _14);
		zephir_is_iterable(_15, &_17, &_16, 0, 0, "phady/mail/mailreader.zep", 352);
		for (
		  ; zephir_hash_get_current_data_ex(_17, (void**) &_18, &_16) == SUCCESS
		  ; zephir_hash_move_forward_ex(_17, &_16)
		) {
			ZEPHIR_GET_HVALUE(x, _18);
			ZEPHIR_OBS_NVAR(_19);
			zephir_read_property(&_19, x, SL("value"), PH_NOISY_CC);
			ZEPHIR_INIT_NVAR(_20);
			ZEPHIR_OBS_NVAR(_21);
			zephir_read_property(&_21, x, SL("attribute"), PH_NOISY_CC);
			zephir_fast_strtolower(_20, _21);
			zephir_array_update_zval(&params, _20, &_19, PH_COPY | PH_SEPARATE);
		}
	}
	ZEPHIR_SINIT_NVAR(_1);
	ZVAL_STRING(&_1, "dparameters", 0);
	ZEPHIR_CALL_FUNCTION(&_11, "property_exists", &_5, 33, partObj, &_1);
	zephir_check_call_status();
	_22 = zephir_is_true(_11);
	if (_22) {
		ZEPHIR_OBS_NVAR(_14);
		zephir_read_property(&_14, partObj, SL("dparameters"), PH_NOISY_CC);
		_22 = !(ZEPHIR_IS_EMPTY(_14));
	}
	if (_22) {
		ZEPHIR_OBS_NVAR(_19);
		zephir_read_property(&_19, partObj, SL("dparameters"), PH_NOISY_CC);
		zephir_get_arrval(_23, _19);
		zephir_is_iterable(_23, &_25, &_24, 0, 0, "phady/mail/mailreader.zep", 357);
		for (
		  ; zephir_hash_get_current_data_ex(_25, (void**) &_26, &_24) == SUCCESS
		  ; zephir_hash_move_forward_ex(_25, &_24)
		) {
			ZEPHIR_GET_HVALUE(y, _26);
			ZEPHIR_OBS_NVAR(_21);
			zephir_read_property(&_21, y, SL("value"), PH_NOISY_CC);
			ZEPHIR_INIT_NVAR(_20);
			ZEPHIR_OBS_NVAR(_27);
			zephir_read_property(&_27, y, SL("attribute"), PH_NOISY_CC);
			zephir_fast_strtolower(_20, _27);
			zephir_array_update_zval(&params, _20, &_21, PH_COPY | PH_SEPARATE);
		}
	}
	ZEPHIR_SINIT_NVAR(_1);
	ZVAL_STRING(&_1, "filename", 0);
	_28 = zephir_array_key_exists(params, &_1 TSRMLS_CC);
	if (!(_28)) {
		ZEPHIR_SINIT_NVAR(_2);
		ZVAL_STRING(&_2, "name", 0);
		_28 = zephir_array_key_exists(params, &_2 TSRMLS_CC);
	}
	_29 = _28;
	if (_29) {
		ZEPHIR_OBS_NVAR(_14);
		zephir_array_fetch_string(&_14, params, SL("filename"), PH_NOISY, "phady/mail/mailreader.zep", 360 TSRMLS_CC);
		_30 = zephir_is_true(_14);
		if (!(_30)) {
			ZEPHIR_OBS_NVAR(_19);
			zephir_array_fetch_string(&_19, params, SL("name"), PH_NOISY, "phady/mail/mailreader.zep", 360 TSRMLS_CC);
			_30 = zephir_is_true(_19);
		}
		_29 = _30;
	}
	if (_29) {
		ZEPHIR_SINIT_VAR(_31);
		ZVAL_STRING(&_31, "filename", 0);
		_32 = zephir_array_key_exists(params, &_31 TSRMLS_CC);
		if (_32) {
			zephir_array_fetch_string(&_33, params, SL("filename"), PH_NOISY | PH_READONLY, "phady/mail/mailreader.zep", 362 TSRMLS_CC);
			_32 = zephir_is_true(_33);
		}
		if (_32) {
			ZEPHIR_OBS_VAR(filename);
			zephir_array_fetch_string(&filename, params, SL("filename"), PH_NOISY, "phady/mail/mailreader.zep", 362 TSRMLS_CC);
		} else {
			ZEPHIR_OBS_NVAR(filename);
			zephir_array_fetch_string(&filename, params, SL("name"), PH_NOISY, "phady/mail/mailreader.zep", 362 TSRMLS_CC);
		}
		zephir_update_property_array(this_ptr, SL("attachments"), filename, data TSRMLS_CC);
	}
	ZEPHIR_OBS_NVAR(_14);
	zephir_read_property(&_14, partObj, SL("type"), PH_NOISY_CC);
	_32 = ZEPHIR_IS_LONG(_14, 0);
	if (_32) {
		_32 = zephir_is_true(data);
	}
	ZEPHIR_OBS_NVAR(_21);
	zephir_read_property(&_21, partObj, SL("type"), PH_NOISY_CC);
	_34 = ZEPHIR_IS_LONG(_21, 2);
	if (_34) {
		_34 = zephir_is_true(data);
	}
	if (_32) {
		ZEPHIR_INIT_NVAR(_20);
		ZEPHIR_OBS_NVAR(_27);
		zephir_read_property(&_27, partObj, SL("subtype"), PH_NOISY_CC);
		zephir_fast_strtolower(_20, _27);
		if (ZEPHIR_IS_STRING(_20, "plain")) {
			ZEPHIR_INIT_VAR(_35);
			zephir_fast_trim(_35, data, NULL , ZEPHIR_TRIM_BOTH TSRMLS_CC);
			zephir_update_property_this(this_ptr, SL("plainBody"), _35 TSRMLS_CC);
		}
	} else if (_34) {
		ZEPHIR_INIT_NVAR(_20);
		zephir_fast_trim(_20, data, NULL , ZEPHIR_TRIM_BOTH TSRMLS_CC);
		zephir_update_property_this(this_ptr, SL("plainBody"), _20 TSRMLS_CC);
	}
	ZEPHIR_SINIT_NVAR(_31);
	ZVAL_STRING(&_31, "parts", 0);
	ZEPHIR_CALL_FUNCTION(&_11, "property_exists", &_5, 33, partObj, &_31);
	zephir_check_call_status();
	_32 = zephir_is_true(_11);
	if (_32) {
		ZEPHIR_OBS_NVAR(_14);
		zephir_read_property(&_14, partObj, SL("parts"), PH_NOISY_CC);
		_32 = !(ZEPHIR_IS_EMPTY(_14));
	}
	if (_32) {
		ZEPHIR_OBS_NVAR(_19);
		zephir_read_property(&_19, partObj, SL("parts"), PH_NOISY_CC);
		zephir_get_arrval(_36, _19);
		zephir_is_iterable(_36, &_38, &_37, 0, 0, "phady/mail/mailreader.zep", 390);
		for (
		  ; zephir_hash_get_current_data_ex(_38, (void**) &_39, &_37) == SUCCESS
		  ; zephir_hash_move_forward_ex(_38, &_37)
		) {
			ZEPHIR_GET_HMKEY(partno2, _38, _37);
			ZEPHIR_GET_HVALUE(part2, _39);
			ZEPHIR_SINIT_NVAR(_31);
			ZVAL_LONG(&_31, (zephir_get_numberval(partno2) + 1));
			ZEPHIR_INIT_NVAR(part2Length);
			ZVAL_LONG(part2Length, zephir_fast_strlen_ev(&_31));
			ZEPHIR_INIT_NVAR(partNoAll);
			ZVAL_LONG(partNoAll, ((partno * zephir_get_numberval(part2Length)) + ((zephir_get_numberval(partno2) + 1))));
			ZEPHIR_SINIT_NVAR(_40);
			ZVAL_LONG(&_40, messageId);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "getmessagepart", &_41, 46, &_40, part2, partNoAll);
			zephir_check_call_status();
		}
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Function to parse the message
 *
 * @param Integer messageId
 */
PHP_METHOD(Phady_Mail_MailReader, parseMessage) {

	zval *messageId_param = NULL, *_0;
	int messageId, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &messageId_param);

	messageId = zephir_get_intval(messageId_param);


	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, messageId);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "getmessage", NULL, 0, _0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "makeresult", NULL, 47);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Prepare message as array
 *
 */
PHP_METHOD(Phady_Mail_MailReader, makeResult) {

	zval *msg, *_0, *_1, *_2, *_3;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(msg);
	array_init(msg);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("plainBody"), PH_NOISY_CC);
	zephir_array_update_string(&msg, SL("Mensaje"), &_0, PH_COPY | PH_SEPARATE);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("headers"), PH_NOISY_CC);
	zephir_array_update_string(&msg, SL("headers"), &_1, PH_COPY | PH_SEPARATE);
	zephir_update_property_array_append(this_ptr, SL("result"), msg TSRMLS_CC);
	ZEPHIR_INIT_VAR(_2);
	array_init(_2);
	zephir_update_property_this(this_ptr, SL("attachments"), _2 TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_3);
	ZVAL_STRING(_3, "", 1);
	zephir_update_property_this(this_ptr, SL("plainBody"), _3 TSRMLS_CC);
	zephir_unset_property(this_ptr, "headers" TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Function to parse the messages that have not yet been read .
 *
 */
PHP_METHOD(Phady_Mail_MailReader, getUnreadMessages) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0, *_1, *_2;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, 0);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, 4);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_BOOL(_2, 1);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "readmessagebyfilter", NULL, 0, _0, _1, _2);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

static zend_object_value zephir_init_properties_Phady_Mail_MailReader(zend_class_entry *class_type TSRMLS_DC) {

		zval *_0, *_1 = NULL, *_2;

		ZEPHIR_MM_GROW();
	
	{
		zval *this_ptr = NULL;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("result"), PH_NOISY_CC);
		if (Z_TYPE_P(_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(_1);
			array_init(_1);
			zephir_update_property_this(this_ptr, SL("result"), _1 TSRMLS_CC);
		}
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("attachments"), PH_NOISY_CC);
		if (Z_TYPE_P(_2) == IS_NULL) {
			ZEPHIR_INIT_NVAR(_1);
			array_init(_1);
			zephir_update_property_this(this_ptr, SL("attachments"), _1 TSRMLS_CC);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJVAL_P(this_ptr);
	}

}

