
extern zend_class_entry *phady_security_groups_groupinterface_ce;

ZEPHIR_INIT_CLASS(Phady_Security_Groups_GroupInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phady_security_groups_groupinterface_addrole, 0, 0, 1)
	ZEND_ARG_INFO(0, role)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phady_security_groups_groupinterface_hasrole, 0, 0, 1)
	ZEND_ARG_INFO(0, role)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phady_security_groups_groupinterface_removerole, 0, 0, 1)
	ZEND_ARG_INFO(0, role)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phady_security_groups_groupinterface_setname, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phady_security_groups_groupinterface_setroles, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, roles, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phady_security_groups_groupinterface_method_entry) {
	PHP_ABSTRACT_ME(Phady_Security_Groups_GroupInterface, addRole, arginfo_phady_security_groups_groupinterface_addrole)
	PHP_ABSTRACT_ME(Phady_Security_Groups_GroupInterface, getId, NULL)
	PHP_ABSTRACT_ME(Phady_Security_Groups_GroupInterface, getName, NULL)
	PHP_ABSTRACT_ME(Phady_Security_Groups_GroupInterface, hasRole, arginfo_phady_security_groups_groupinterface_hasrole)
	PHP_ABSTRACT_ME(Phady_Security_Groups_GroupInterface, getRoles, NULL)
	PHP_ABSTRACT_ME(Phady_Security_Groups_GroupInterface, removeRole, arginfo_phady_security_groups_groupinterface_removerole)
	PHP_ABSTRACT_ME(Phady_Security_Groups_GroupInterface, setName, arginfo_phady_security_groups_groupinterface_setname)
	PHP_ABSTRACT_ME(Phady_Security_Groups_GroupInterface, setRoles, arginfo_phady_security_groups_groupinterface_setroles)
	PHP_FE_END
};
