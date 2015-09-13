
/* This file was generated automatically by Zephir do not modify it! */

#ifndef ZEPHIR_CLASS_ENTRIES_H
#define ZEPHIR_CLASS_ENTRIES_H

#include "phady/security/core/exception/authenticationexception.zep.h"
#include "phady/common/entities/modelbase.zep.h"
#include "phady/security/http/firewall/listenerinterface.zep.h"
#include "phady/security/core/authentication/authenticationmanagerinterface.zep.h"
#include "phady/security/core/user/userinterface.zep.h"
#include "phady/security/core/authentication/provider/authenticationproviderinterface.zep.h"
#include "phady/security/core/authentication/token/tokeninterface.zep.h"
#include "phady/security/core/authorization/voter/voterinterface.zep.h"
#include "phady/security/core/encoder/passwordencoderinterface.zep.h"
#include "phady/security/core/exception/accountstatusexception.zep.h"
#include "phady/security/core/user/userproviderinterface.zep.h"
#include "phady/security/core/authentication/token/abstracttoken.zep.h"
#include "phady/security/core/encoder/basepasswordencoder.zep.h"
#include "phady/security/core/user/advanceduserinterface.zep.h"
#include "phady/core/kernel.zep.h"
#include "phady/security/core/role/roleinterface.zep.h"
#include "phady/security/core/user/factory/userproviderfactoryinterface.zep.h"
#include "phady/security/factory/securityfactoryinterface.zep.h"
#include "phady/security/http/firewallmapinterface.zep.h"
#include "phady/cache/cacheinterface.zep.h"
#include "phady/http/requestmatcherinterface.zep.h"
#include "phady/messaging/adapter/messaginginterface.zep.h"
#include "phady/security/core/authentication/authenticationtrustresolverinterface.zep.h"
#include "phady/security/core/authentication/loginmanagerinterface.zep.h"
#include "phady/security/core/authentication/model/userinterface.zep.h"
#include "phady/security/core/authentication/provider/userauthenticationprovider.zep.h"
#include "phady/security/core/authentication/token/storage/tokenstorageinterface.zep.h"
#include "phady/security/core/authorization/accessdecisionmanagerinterface.zep.h"
#include "phady/security/core/authorization/authorizationcheckerinterface.zep.h"
#include "phady/security/core/authorization/voter/rolevoter.zep.h"
#include "phady/security/core/encoder/encoderfactoryinterface.zep.h"
#include "phady/security/core/exception/authenticationserviceexception.zep.h"
#include "phady/security/core/role/role.zep.h"
#include "phady/security/core/user/usercheckerinterface.zep.h"
#include "phady/security/factory/abstractfactory.zep.h"
#include "phady/security/http/accessmapinterface.zep.h"
#include "phady/security/http/authentication/authenticationfailurehandlerinterface.zep.h"
#include "phady/security/http/authentication/authenticationsuccesshandlerinterface.zep.h"
#include "phady/security/http/authorization/accessdeniedhandlerinterface.zep.h"
#include "phady/security/http/entrypoint/authenticationentrypointinterface.zep.h"
#include "phady/security/http/firewall/abstractauthenticationlistener.zep.h"
#include "phady/security/http/logout/logouthandlerinterface.zep.h"
#include "phady/security/http/logout/logoutsuccesshandlerinterface.zep.h"
#include "phady/cache/cachehandler.zep.h"
#include "phady/common/controllers/accessdeniedcontroller.zep.h"
#include "phady/common/controllers/controllerbase.zep.h"
#include "phady/config/yaml.zep.h"
#include "phady/console/command.zep.h"
#include "phady/core/kernelcli.zep.h"
#include "phady/core/kernelmvc.zep.h"
#include "phady/core/namespacehandler.zep.h"
#include "phady/core/parameter.zep.h"
#include "phady/db/databasehandler.zep.h"
#include "phady/exception.zep.h"
#include "phady/http/iputils.zep.h"
#include "phady/http/requestmatcher.zep.h"
#include "phady/mail/mailreader.zep.h"
#include "phady/messaging/adapter/rabbitmq.zep.h"
#include "phady/messaging/messaging.zep.h"
#include "phady/report/excel/template/excelmultitable.zep.h"
#include "phady/route/router.zep.h"
#include "phady/security/core/authentication/authenticationprovidermanager.zep.h"
#include "phady/security/core/authentication/authenticationtrustresolver.zep.h"
#include "phady/security/core/authentication/authhandler.zep.h"
#include "phady/security/core/authentication/eventlistener/authenticationlistener.zep.h"
#include "phady/security/core/authentication/loginmanager.zep.h"
#include "phady/security/core/authentication/model/user.zep.h"
#include "phady/security/core/authentication/model/usermanagerinterface.zep.h"
#include "phady/security/core/authentication/provider/anonymousauthenticationprovider.zep.h"
#include "phady/security/core/authentication/provider/daoauthenticationprovider.zep.h"
#include "phady/security/core/authentication/provider/entityuserprovider.zep.h"
#include "phady/security/core/authentication/provider/simpleauthenticationprovider.zep.h"
#include "phady/security/core/authentication/provider/userprovider.zep.h"
#include "phady/security/core/authentication/simpleauthenticatorinterface.zep.h"
#include "phady/security/core/authentication/token/anonymoustoken.zep.h"
#include "phady/security/core/authentication/token/remembermetoken.zep.h"
#include "phady/security/core/authentication/token/storage/tokenstorage.zep.h"
#include "phady/security/core/authentication/token/usernamepasswordtoken.zep.h"
#include "phady/security/core/authenticationevents.zep.h"
#include "phady/security/core/authorization/accessdecisionmanager.zep.h"
#include "phady/security/core/authorization/acl.zep.h"
#include "phady/security/core/authorization/authorizationchecker.zep.h"
#include "phady/security/core/authorization/voter/abstractvoter.zep.h"
#include "phady/security/core/authorization/voter/authenticatedvoter.zep.h"
#include "phady/security/core/authorization/voter/rolehierarchyvoter.zep.h"
#include "phady/security/core/encoder/bcryptpasswordencoder.zep.h"
#include "phady/security/core/encoder/encoderawareinterface.zep.h"
#include "phady/security/core/encoder/encoderfactory.zep.h"
#include "phady/security/core/encoder/messagedigestpasswordencoder.zep.h"
#include "phady/security/core/encoder/plaintextpasswordencoder.zep.h"
#include "phady/security/core/exception/accessdeniedexception.zep.h"
#include "phady/security/core/exception/accountexpiredexception.zep.h"
#include "phady/security/core/exception/authenticationcredentialsnotfoundexception.zep.h"
#include "phady/security/core/exception/badcredentialsexception.zep.h"
#include "phady/security/core/exception/credentialsexpiredexception.zep.h"
#include "phady/security/core/exception/disabledexception.zep.h"
#include "phady/security/core/exception/insufficientauthenticationexception.zep.h"
#include "phady/security/core/exception/invalidcsrftokenexception.zep.h"
#include "phady/security/core/exception/lockedexception.zep.h"
#include "phady/security/core/exception/providernotfoundexception.zep.h"
#include "phady/security/core/exception/unsupporteduserexception.zep.h"
#include "phady/security/core/exception/usernamenotfoundexception.zep.h"
#include "phady/security/core/models/entities/actions.zep.h"
#include "phady/security/core/models/entities/groups.zep.h"
#include "phady/security/core/models/entities/modules.zep.h"
#include "phady/security/core/models/entities/permissions.zep.h"
#include "phady/security/core/models/entities/resources.zep.h"
#include "phady/security/core/models/entities/roles.zep.h"
#include "phady/security/core/models/entities/user.zep.h"
#include "phady/security/core/models/entities/userrole.zep.h"
#include "phady/security/core/models/entities/users.zep.h"
#include "phady/security/core/models/exception.zep.h"
#include "phady/security/core/models/repositories/users.zep.h"
#include "phady/security/core/role/rolehierarchyinterface.zep.h"
#include "phady/security/core/role/roles.zep.h"
#include "phady/security/core/role/switchuserrole.zep.h"
#include "phady/security/core/security.zep.h"
#include "phady/security/core/user/chainuserprovider.zep.h"
#include "phady/security/core/user/equatableinterface.zep.h"
#include "phady/security/core/user/factory/entityfactory.zep.h"
#include "phady/security/core/user/factory/inmemoryfactory.zep.h"
#include "phady/security/core/user/inmemoryuserprovider.zep.h"
#include "phady/security/core/user/user.zep.h"
#include "phady/security/core/user/userchecker.zep.h"
#include "phady/security/core/user/users.zep.h"
#include "phady/security/eventlistener/securitylistener.zep.h"
#include "phady/security/exception.zep.h"
#include "phady/security/factory/formloginfactory.zep.h"
#include "phady/security/firewall.zep.h"
#include "phady/security/firewallcontext.zep.h"
#include "phady/security/firewallmap.zep.h"
#include "phady/security/http/accessmap.zep.h"
#include "phady/security/http/authentication/defaultauthenticationfailurehandler.zep.h"
#include "phady/security/http/authentication/defaultauthenticationsuccesshandler.zep.h"
#include "phady/security/http/authorization/accessdeniedlistener.zep.h"
#include "phady/security/http/entrypoint/formauthenticationentrypoint.zep.h"
#include "phady/security/http/event/interactiveloginevent.zep.h"
#include "phady/security/http/firewall/accesslistener.zep.h"
#include "phady/security/http/firewall/anonymousauthenticationlistener.zep.h"
#include "phady/security/http/firewall/channellistener.zep.h"
#include "phady/security/http/firewall/contextlistener.zep.h"
#include "phady/security/http/firewall/exceptionlistener.zep.h"
#include "phady/security/http/firewall/logoutlistener.zep.h"
#include "phady/security/http/firewall/usernamepasswordformauthenticationlistener.zep.h"
#include "phady/security/http/firewallmap.zep.h"
#include "phady/security/http/logout/defaultlogoutsuccesshandler.zep.h"
#include "phady/security/http/logout/sessionlogouthandler.zep.h"
#include "phady/security/http/securityevents.zep.h"
#include "phady/security/phadyuserextension.zep.h"
#include "phady/security/securityextension.zep.h"
#include "phady/util/datetime.zep.h"
#include "phady/util/file.zep.h"
#include "phady/util/out.zep.h"
#include "phady/util/random.zep.h"
#include "phady/util/text.zep.h"
#include "phady/util/tools.zep.h"
#include "phady/util/uuid.zep.h"
#include "phady/version.zep.h"
#include "phady/0__closure.zep.h"
#include "phady/1__closure.zep.h"
#include "phady/2__closure.zep.h"
#include "phady/3__closure.zep.h"
#include "phady/4__closure.zep.h"
#include "phady/5__closure.zep.h"
#include "phady/6__closure.zep.h"
#include "phady/7__closure.zep.h"
#include "phady/8__closure.zep.h"
#include "phady/9__closure.zep.h"
#include "phady/10__closure.zep.h"
#include "phady/11__closure.zep.h"
#include "phady/12__closure.zep.h"
#include "phady/13__closure.zep.h"
#include "phady/14__closure.zep.h"
#include "phady/15__closure.zep.h"
#include "phady/16__closure.zep.h"
#include "phady/17__closure.zep.h"
#include "phady/18__closure.zep.h"
#include "phady/19__closure.zep.h"
#include "phady/20__closure.zep.h"
#include "phady/21__closure.zep.h"
#include "phady/22__closure.zep.h"
#include "phady/23__closure.zep.h"
#include "phady/24__closure.zep.h"
#include "phady/25__closure.zep.h"
#include "phady/26__closure.zep.h"
#include "phady/27__closure.zep.h"
#include "phady/28__closure.zep.h"
#include "phady/29__closure.zep.h"
#include "phady/30__closure.zep.h"
#include "phady/31__closure.zep.h"
#include "phady/32__closure.zep.h"
#include "phady/33__closure.zep.h"
#include "phady/34__closure.zep.h"
#include "phady/35__closure.zep.h"
#include "phady/36__closure.zep.h"
#include "phady/37__closure.zep.h"
#include "phady/38__closure.zep.h"

#endif