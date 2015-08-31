
extern zend_class_entry *phady_util_text_ce;

ZEPHIR_INIT_CLASS(Phady_Util_Text);

PHP_METHOD(Phady_Util_Text, highlight);
PHP_METHOD(Phady_Util_Text, truncate);
PHP_METHOD(Phady_Util_Text, findAndReplaceUrlTags);
PHP_METHOD(Phady_Util_Text, snakeToCamel);
PHP_METHOD(Phady_Util_Text, camelToSnake);
PHP_METHOD(Phady_Util_Text, toUpper);
PHP_METHOD(Phady_Util_Text, toLower);
PHP_METHOD(Phady_Util_Text, upperCaseFirst);
PHP_METHOD(Phady_Util_Text, countInstances);
PHP_METHOD(Phady_Util_Text, nl2html);
PHP_METHOD(Phady_Util_Text, tokenize);
PHP_METHOD(Phady_Util_Text, stripos);
PHP_METHOD(Phady_Util_Text, left);
PHP_METHOD(Phady_Util_Text, right);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phady_util_text_highlight, 0, 0, 3)
	ZEND_ARG_INFO(0, text)
	ZEND_ARG_INFO(0, query)
	ZEND_ARG_INFO(0, first)
	ZEND_ARG_INFO(0, background_color)
	ZEND_ARG_INFO(0, color)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phady_util_text_truncate, 0, 0, 2)
	ZEND_ARG_INFO(0, text)
	ZEND_ARG_INFO(0, limit)
	ZEND_ARG_INFO(0, str_break)
	ZEND_ARG_INFO(0, pad)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phady_util_text_findandreplaceurltags, 0, 0, 1)
	ZEND_ARG_INFO(0, text)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phady_util_text_snaketocamel, 0, 0, 1)
	ZEND_ARG_INFO(0, snake)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phady_util_text_cameltosnake, 0, 0, 1)
	ZEND_ARG_INFO(0, camel)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phady_util_text_toupper, 0, 0, 1)
	ZEND_ARG_INFO(0, text)
	ZEND_ARG_INFO(0, encoding)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phady_util_text_tolower, 0, 0, 1)
	ZEND_ARG_INFO(0, text)
	ZEND_ARG_INFO(0, encoding)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phady_util_text_uppercasefirst, 0, 0, 1)
	ZEND_ARG_INFO(0, text)
	ZEND_ARG_ARRAY_INFO(0, exceptions, 1)
	ZEND_ARG_INFO(0, encoding)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phady_util_text_countinstances, 0, 0, 2)
	ZEND_ARG_INFO(0, haystack)
	ZEND_ARG_INFO(0, needle)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phady_util_text_nl2html, 0, 0, 1)
	ZEND_ARG_INFO(0, text)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phady_util_text_tokenize, 0, 0, 2)
	ZEND_ARG_INFO(0, text)
	ZEND_ARG_INFO(0, delimeter)
	ZEND_ARG_INFO(0, max)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phady_util_text_stripos, 0, 0, 2)
	ZEND_ARG_INFO(0, haystack)
	ZEND_ARG_INFO(0, needle)
	ZEND_ARG_INFO(0, offset)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phady_util_text_left, 0, 0, 1)
	ZEND_ARG_INFO(0, text)
	ZEND_ARG_INFO(0, left)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phady_util_text_right, 0, 0, 1)
	ZEND_ARG_INFO(0, text)
	ZEND_ARG_INFO(0, right)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phady_util_text_method_entry) {
	PHP_ME(Phady_Util_Text, highlight, arginfo_phady_util_text_highlight, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phady_Util_Text, truncate, arginfo_phady_util_text_truncate, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phady_Util_Text, findAndReplaceUrlTags, arginfo_phady_util_text_findandreplaceurltags, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phady_Util_Text, snakeToCamel, arginfo_phady_util_text_snaketocamel, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phady_Util_Text, camelToSnake, arginfo_phady_util_text_cameltosnake, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phady_Util_Text, toUpper, arginfo_phady_util_text_toupper, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phady_Util_Text, toLower, arginfo_phady_util_text_tolower, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phady_Util_Text, upperCaseFirst, arginfo_phady_util_text_uppercasefirst, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phady_Util_Text, countInstances, arginfo_phady_util_text_countinstances, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phady_Util_Text, nl2html, arginfo_phady_util_text_nl2html, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phady_Util_Text, tokenize, arginfo_phady_util_text_tokenize, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phady_Util_Text, stripos, arginfo_phady_util_text_stripos, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phady_Util_Text, left, arginfo_phady_util_text_left, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phady_Util_Text, right, arginfo_phady_util_text_right, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
