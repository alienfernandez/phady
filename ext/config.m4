PHP_ARG_ENABLE(phady, whether to enable phady, [ --enable-phady   Enable Phady])

if test "$PHP_PHADY" = "yes"; then

	

	if ! test "x" = "x"; then
		PHP_EVAL_LIBLINE(, PHADY_SHARED_LIBADD)
	fi

	AC_DEFINE(HAVE_PHADY, 1, [Whether you have Phady])
	phady_sources="phady.c kernel/main.c kernel/memory.c kernel/exception.c kernel/hash.c kernel/debug.c kernel/backtrace.c kernel/object.c kernel/array.c kernel/extended/array.c kernel/string.c kernel/fcall.c kernel/extended/fcall.c kernel/require.c kernel/file.c kernel/operators.c kernel/math.c kernel/concat.c kernel/variables.c kernel/filter.c kernel/iterator.c kernel/time.c kernel/exit.c phady/common/entities/modelbase.zep.c
	phady/security/core/authentication/authenticationmanagerinterface.zep.c
	phady/security/core/exception/authenticationexception.zep.c
	phady/security/core/authentication/provider/authenticationproviderinterface.zep.c
	phady/security/core/user/userinterface.zep.c
	phady/security/core/user/userproviderinterface.zep.c
	phady/core/kernel.zep.c
	phady/security/core/authentication/token/tokeninterface.zep.c
	phady/security/core/role/roleinterface.zep.c
	phady/security/core/user/advanceduserinterface.zep.c
	phady/security/http/firewall/listenerinterface.zep.c
	phady/cache/cacheinterface.zep.c
	phady/messaging/adapter/messaginginterface.zep.c
	phady/security/core/authentication/loginmanagerinterface.zep.c
	phady/security/core/authentication/model/userinterface.zep.c
	phady/security/core/authentication/provider/userauthenticationprovider.zep.c
	phady/security/core/authentication/token/abstracttoken.zep.c
	phady/security/core/authentication/token/storage/tokenstorageinterface.zep.c
	phady/security/core/encoder/encoderfactoryinterface.zep.c
	phady/security/core/exception/authenticationserviceexception.zep.c
	phady/security/core/role/role.zep.c
	phady/security/core/user/usercheckerinterface.zep.c
	phady/security/http/authentication/authenticationfailurehandlerinterface.zep.c
	phady/security/http/authentication/authenticationsuccesshandlerinterface.zep.c
	phady/security/http/firewall/abstractauthenticationlistener.zep.c
	phady/cache/cachehandler.zep.c
	phady/common/controllers/controllerbase.zep.c
	phady/config/yaml.zep.c
	phady/console/command.zep.c
	phady/core/kernelcli.zep.c
	phady/core/kernelmvc.zep.c
	phady/core/namespacehandler.zep.c
	phady/core/parameter.zep.c
	phady/db/databasehandler.zep.c
	phady/exception.zep.c
	phady/mail/mailreader.zep.c
	phady/messaging/adapter/rabbitmq.zep.c
	phady/messaging/messaging.zep.c
	phady/report/excel/template/excelmultitable.zep.c
	phady/route/router.zep.c
	phady/security/core/authentication/authenticationprovidermanager.zep.c
	phady/security/core/authentication/authhandler.zep.c
	phady/security/core/authentication/eventlistener/authenticationlistener.zep.c
	phady/security/core/authentication/loginmanager.zep.c
	phady/security/core/authentication/model/user.zep.c
	phady/security/core/authentication/model/usermanagerinterface.zep.c
	phady/security/core/authentication/provider/daoauthenticationprovider.zep.c
	phady/security/core/authentication/provider/simpleauthenticationprovider.zep.c
	phady/security/core/authentication/provider/userprovider.zep.c
	phady/security/core/authentication/simpleauthenticatorinterface.zep.c
	phady/security/core/authentication/token/storage/tokenstorage.zep.c
	phady/security/core/authentication/token/usernamepasswordtoken.zep.c
	phady/security/core/authorization/acl.zep.c
	phady/security/core/encoder/encoderawareinterface.zep.c
	phady/security/core/encoder/encoderfactory.zep.c
	phady/security/core/exception/accessdeniedexception.zep.c
	phady/security/core/exception/badcredentialsexception.zep.c
	phady/security/core/exception/invalidcsrftokenexception.zep.c
	phady/security/core/exception/providernotfoundexception.zep.c
	phady/security/core/exception/unsupporteduserexception.zep.c
	phady/security/core/exception/usernamenotfoundexception.zep.c
	phady/security/core/models/entities/actions.zep.c
	phady/security/core/models/entities/groups.zep.c
	phady/security/core/models/entities/modules.zep.c
	phady/security/core/models/entities/permissions.zep.c
	phady/security/core/models/entities/resources.zep.c
	phady/security/core/models/entities/roles.zep.c
	phady/security/core/models/entities/userrole.zep.c
	phady/security/core/models/entities/users.zep.c
	phady/security/core/models/exception.zep.c
	phady/security/core/models/repositories/users.zep.c
	phady/security/core/role/rolehierarchyinterface.zep.c
	phady/security/core/role/roles.zep.c
	phady/security/core/role/switchuserrole.zep.c
	phady/security/core/security.zep.c
	phady/security/core/user/chainuserprovider.zep.c
	phady/security/core/user/equatableinterface.zep.c
	phady/security/core/user/inmemoryuserprovider.zep.c
	phady/security/core/user/user.zep.c
	phady/security/core/user/userchecker.zep.c
	phady/security/core/user/users.zep.c
	phady/security/eventlistener/securitylistener.zep.c
	phady/security/exception.zep.c
	phady/security/groups/groupbase.zep.c
	phady/security/groups/groupinterface.zep.c
	phady/security/http/authentication/defaultauthenticationfailurehandler.zep.c
	phady/security/http/authentication/defaultauthenticationsuccesshandler.zep.c
	phady/security/http/firewall/usernamepasswordformauthenticationlistener.zep.c
	phady/security/securityextension.zep.c
	phady/util/datetime.zep.c
	phady/util/file.zep.c
	phady/util/out.zep.c
	phady/util/random.zep.c
	phady/util/text.zep.c
	phady/util/tools.zep.c
	phady/util/uuid.zep.c
	phady/version.zep.c
	phady/0__closure.zep.c
	phady/1__closure.zep.c
	phady/2__closure.zep.c
	phady/3__closure.zep.c
	phady/4__closure.zep.c
	phady/5__closure.zep.c
	phady/6__closure.zep.c
	phady/7__closure.zep.c
	phady/8__closure.zep.c
	phady/9__closure.zep.c
	phady/10__closure.zep.c
	phady/11__closure.zep.c
	phady/12__closure.zep.c
	phady/13__closure.zep.c
	phady/14__closure.zep.c
	phady/15__closure.zep.c
	phady/16__closure.zep.c "
	PHP_NEW_EXTENSION(phady, $phady_sources, $ext_shared,, )
	PHP_SUBST(PHADY_SHARED_LIBADD)

	old_CPPFLAGS=$CPPFLAGS
	CPPFLAGS="$CPPFLAGS $INCLUDES"

	AC_CHECK_DECL(
		[HAVE_BUNDLED_PCRE],
		[
			AC_CHECK_HEADERS(
				[ext/pcre/php_pcre.h],
				[
					PHP_ADD_EXTENSION_DEP([phady], [pcre])
					AC_DEFINE([ZEPHIR_USE_PHP_PCRE], [1], [Whether PHP pcre extension is present at compile time])
				],
				,
				[[#include "main/php.h"]]
			)
		],
		,
		[[#include "php_config.h"]]
	)

	AC_CHECK_DECL(
		[HAVE_JSON],
		[
			AC_CHECK_HEADERS(
				[ext/json/php_json.h],
				[
					PHP_ADD_EXTENSION_DEP([phady], [json])
					AC_DEFINE([ZEPHIR_USE_PHP_JSON], [1], [Whether PHP json extension is present at compile time])
				],
				,
				[[#include "main/php.h"]]
			)
		],
		,
		[[#include "php_config.h"]]
	)

	CPPFLAGS=$old_CPPFLAGS

	PHP_INSTALL_HEADERS([ext/phady], [php_PHADY.h])

fi
