
extern zend_class_entry *phady_console_command_ce;

ZEPHIR_INIT_CLASS(Phady_Console_Command);

PHP_METHOD(Phady_Console_Command, background);
PHP_METHOD(Phady_Console_Command, isRunning);
PHP_METHOD(Phady_Console_Command, kill);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phady_console_command_background, 0, 0, 1)
	ZEND_ARG_INFO(0, command)
	ZEND_ARG_INFO(0, priority)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phady_console_command_isrunning, 0, 0, 1)
	ZEND_ARG_INFO(0, pID)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phady_console_command_kill, 0, 0, 1)
	ZEND_ARG_INFO(0, pID)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phady_console_command_method_entry) {
	PHP_ME(Phady_Console_Command, background, arginfo_phady_console_command_background, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phady_Console_Command, isRunning, arginfo_phady_console_command_isrunning, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phady_Console_Command, kill, arginfo_phady_console_command_kill, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
