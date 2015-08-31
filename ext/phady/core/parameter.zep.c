
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
#include "kernel/object.h"


/**
  * @class Phady\Core\Parameter -  Parameter for app
  *
  * @author  Alien Fernández Fuentes <alienfernandez85@gmail.com>
  * @package Core
  * @copyright (c) 2015
  * @version 1.0.0
  */
ZEPHIR_INIT_CLASS(Phady_Core_Parameter) {

	ZEPHIR_REGISTER_CLASS(Phady\\Core, Parameter, phady, core_parameter, phady_core_parameter_method_entry, 0);

	/**
	 * @var string Directorio raiz del proyecto /app
	 */
	zend_declare_property_null(phady_core_parameter_ce, SL("root_dir"), ZEND_ACC_PUBLIC TSRMLS_CC);

	/**
	 * @var string Direcccion completa del proyecto
	 */
	zend_declare_property_null(phady_core_parameter_ce, SL("http_host"), ZEND_ACC_PUBLIC TSRMLS_CC);

	/**
	 * @var string Direcccion completa del proyecto con el protocolo
	 */
	zend_declare_property_null(phady_core_parameter_ce, SL("url"), ZEND_ACC_PUBLIC TSRMLS_CC);

	/**
	 * @var string Protocolo usado en el sistema http|https
	 */
	zend_declare_property_null(phady_core_parameter_ce, SL("request_protocol"), ZEND_ACC_PUBLIC TSRMLS_CC);

	/**
	 * @var string Entorno del proyecto
	 */
	zend_declare_property_null(phady_core_parameter_ce, SL("environment"), ZEND_ACC_PUBLIC TSRMLS_CC);

	/**
	 * @var boolean Si esa en modo debug
	 */
	zend_declare_property_null(phady_core_parameter_ce, SL("debug"), ZEND_ACC_PUBLIC TSRMLS_CC);

	/**
	 * @var string Directorio de cache
	 */
	zend_declare_property_null(phady_core_parameter_ce, SL("cache_dir"), ZEND_ACC_PUBLIC TSRMLS_CC);

	/**
	 * @var string Directorio de log
	 */
	zend_declare_property_null(phady_core_parameter_ce, SL("log_dir"), ZEND_ACC_PUBLIC TSRMLS_CC);

	/**
	 * @var array Array de modulos
	 */
	zend_declare_property_null(phady_core_parameter_ce, SL("modules"), ZEND_ACC_PUBLIC TSRMLS_CC);

	/**
	 * @var string Juego de caracteres
	 */
	zend_declare_property_null(phady_core_parameter_ce, SL("charset"), ZEND_ACC_PUBLIC TSRMLS_CC);

	/**
	 * @var array Array de config de catalogos
	 */
	zend_declare_property_null(phady_core_parameter_ce, SL("catalog"), ZEND_ACC_PUBLIC TSRMLS_CC);

	/**
	 * @var array Array de config de fecha
	 */
	zend_declare_property_null(phady_core_parameter_ce, SL("datetime"), ZEND_ACC_PUBLIC TSRMLS_CC);

	/**
	 * @var array Array de config de correos
	 */
	zend_declare_property_null(phady_core_parameter_ce, SL("mail"), ZEND_ACC_PUBLIC TSRMLS_CC);

	/**
	 * @var array Array de config de pdf
	 */
	zend_declare_property_null(phady_core_parameter_ce, SL("pdf"), ZEND_ACC_PUBLIC TSRMLS_CC);

	/**
	 * @var array Array de config de archivos
	 */
	zend_declare_property_null(phady_core_parameter_ce, SL("files"), ZEND_ACC_PUBLIC TSRMLS_CC);

	/**
	 * @var array Array de config de seguridad
	 */
	zend_declare_property_null(phady_core_parameter_ce, SL("security"), ZEND_ACC_PUBLIC TSRMLS_CC);

	/**
	 * @var DI Contenedor de dependencias
	 */
	zend_declare_property_null(phady_core_parameter_ce, SL("container"), ZEND_ACC_PUBLIC TSRMLS_CC);

	return SUCCESS;

}

/**
 * @param string param Parametro a modificar
 * @param mixed value Valor del parametro
 */
PHP_METHOD(Phady_Core_Parameter, setParameter) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *param_param = NULL, *value, *_0 = NULL;
	zval *param = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &param_param, &value);

	zephir_get_strval(param, param_param);


	ZEPHIR_CALL_FUNCTION(&_0, "property_exists", NULL, 23, this_ptr, param);
	zephir_check_call_status();
	if (zephir_is_true(_0)) {
		zephir_update_property_zval_zval(this_ptr, param, value TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

