
extern zend_class_entry *phady_util_random_ce;

ZEPHIR_INIT_CLASS(Phady_Util_Random);

PHP_METHOD(Phady_Util_Random, getSeed);
PHP_METHOD(Phady_Util_Random, getInteger);
PHP_METHOD(Phady_Util_Random, getRandomString);
PHP_METHOD(Phady_Util_Random, getString);
PHP_METHOD(Phady_Util_Random, getStringForPassword);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phady_util_random_getinteger, 0, 0, 2)
	ZEND_ARG_INFO(0, floor)
	ZEND_ARG_INFO(0, ceil)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phady_util_random_getrandomstring, 0, 0, 1)
	ZEND_ARG_INFO(0, length)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phady_util_random_getstring, 0, 0, 2)
	ZEND_ARG_INFO(0, minLen)
	ZEND_ARG_INFO(0, maxLen)
	ZEND_ARG_INFO(0, leadingCapital)
	ZEND_ARG_INFO(0, useUpper)
	ZEND_ARG_INFO(0, useLower)
	ZEND_ARG_INFO(0, useSpace)
	ZEND_ARG_INFO(0, useNumber)
	ZEND_ARG_INFO(0, useSpecial)
	ZEND_ARG_INFO(0, seed)
	ZEND_ARG_INFO(0, dontuse)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phady_util_random_getstringforpassword, 0, 0, 0)
	ZEND_ARG_INFO(0, minLength)
	ZEND_ARG_INFO(0, maxLength)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phady_util_random_method_entry) {
	PHP_ME(Phady_Util_Random, getSeed, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phady_Util_Random, getInteger, arginfo_phady_util_random_getinteger, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phady_Util_Random, getRandomString, arginfo_phady_util_random_getrandomstring, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phady_Util_Random, getString, arginfo_phady_util_random_getstring, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phady_Util_Random, getStringForPassword, arginfo_phady_util_random_getstringforpassword, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
