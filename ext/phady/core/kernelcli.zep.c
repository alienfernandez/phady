
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


/**
  * @class Phady\Core\KernelCli -  Kernel cli
  *
  * @author  Alien Fernández Fuentes <alienfernandez85@gmail.com>
  * @package Core
  * @copyright (c) 2015
  * @version 1.0.0
  */
ZEPHIR_INIT_CLASS(Phady_Core_KernelCli) {

	ZEPHIR_REGISTER_CLASS_EX(Phady\\Core, KernelCli, phady, core_kernelcli, phady_core_kernel_ce, NULL, 0);

	return SUCCESS;

}

