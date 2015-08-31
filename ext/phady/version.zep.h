
extern zend_class_entry *phady_version_ce;

ZEPHIR_INIT_CLASS(Phady_Version);

PHP_METHOD(Phady_Version, _getVersion);
PHP_METHOD(Phady_Version, _getSpecial);
PHP_METHOD(Phady_Version, get);
PHP_METHOD(Phady_Version, getId);
PHP_METHOD(Phady_Version, getPart);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phady_version__getspecial, 0, 0, 1)
	ZEND_ARG_INFO(0, special)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phady_version_getpart, 0, 0, 1)
	ZEND_ARG_INFO(0, part)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phady_version_method_entry) {
	PHP_ME(Phady_Version, _getVersion, NULL, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_ME(Phady_Version, _getSpecial, arginfo_phady_version__getspecial, ZEND_ACC_PROTECTED|ZEND_ACC_FINAL|ZEND_ACC_STATIC)
	PHP_ME(Phady_Version, get, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phady_Version, getId, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phady_Version, getPart, arginfo_phady_version_getpart, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
