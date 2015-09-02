
/* This file was generated automatically by Zephir do not modify it! */

#ifndef ZEPHIR_CLASS_ENTRIES_H
#define ZEPHIR_CLASS_ENTRIES_H

#include "phady/common/entities/modelbase.zep.h"
#include "phady/security/core/authentication/authenticationmanagerinterface.zep.h"
#include "phady/security/core/exception/authenticationexception.zep.h"
#include "phady/security/core/user/userinterface.zep.h"
#include "phady/core/kernel.zep.h"
#include "phady/security/core/authentication/provider/authenticationproviderinterface.zep.h"
#include "phady/security/core/authentication/token/tokeninterface.zep.h"
#include "phady/security/core/role/roleinterface.zep.h"
#include "phady/security/core/user/advanceduserinterface.zep.h"
#include "phady/security/core/user/userproviderinterface.zep.h"
#include "phady/security/http/firewall/listenerinterface.zep.h"
#include "phady/cache/cacheinterface.zep.h"
#include "phady/messaging/adapter/messaginginterface.zep.h"
#include "phady/security/core/authentication/loginmanagerinterface.zep.h"
#include "phady/security/core/authentication/model/userinterface.zep.h"
#include "phady/security/core/authentication/provider/userauthenticationprovider.zep.h"
#include "phady/security/core/authentication/token/abstracttoken.zep.h"
#include "phady/security/core/authentication/token/storage/tokenstorageinterface.zep.h"
#include "phady/security/core/exception/authenticationserviceexception.zep.h"
#include "phady/security/core/role/role.zep.h"
#include "phady/security/core/user/usercheckerinterface.zep.h"
#include "phady/security/http/firewall/abstractauthenticationlistener.zep.h"
#include "phady/cache/cachehandler.zep.h"
#include "phady/common/controllers/controllerbase.zep.h"
#include "phady/config/yaml.zep.h"
#include "phady/console/command.zep.h"
#include "phady/core/kernelcli.zep.h"
#include "phady/core/kernelmvc.zep.h"
#include "phady/core/namespacehandler.zep.h"
#include "phady/core/parameter.zep.h"
#include "phady/db/databasehandler.zep.h"
#include "phady/exception.zep.h"
#include "phady/mail/mailreader.zep.h"
#include "phady/messaging/adapter/rabbitmq.zep.h"
#include "phady/messaging/messaging.zep.h"
#include "phady/report/excel/template/excelmultitable.zep.h"
#include "phady/route/router.zep.h"
#include "phady/security/core/authentication/authenticationprovidermanager.zep.h"
#include "phady/security/core/authentication/authhandler.zep.h"
#include "phady/security/core/authentication/eventlistener/authenticationlistener.zep.h"
#include "phady/security/core/authentication/loginmanager.zep.h"
#include "phady/security/core/authentication/model/user.zep.h"
#include "phady/security/core/authentication/model/usermanagerinterface.zep.h"
#include "phady/security/core/authentication/provider/daoauthenticationprovider.zep.h"
#include "phady/security/core/authentication/provider/userprovider.zep.h"
#include "phady/security/core/authentication/token/storage/tokenstorage.zep.h"
#include "phady/security/core/authentication/token/usernamepasswordtoken.zep.h"
#include "phady/security/core/authorization/acl.zep.h"
#include "phady/security/core/exception/accessdeniedexception.zep.h"
#include "phady/security/core/exception/badcredentialsexception.zep.h"
#include "phady/security/core/exception/invalidcsrftokenexception.zep.h"
#include "phady/security/core/exception/providernotfoundexception.zep.h"
#include "phady/security/core/exception/unsupporteduserexception.zep.h"
#include "phady/security/core/exception/usernamenotfoundexception.zep.h"
#include "phady/security/core/models/entities/actions.zep.h"
#include "phady/security/core/models/entities/groups.zep.h"
#include "phady/security/core/models/entities/modules.zep.h"
#include "phady/security/core/models/entities/permissions.zep.h"
#include "phady/security/core/models/entities/resources.zep.h"
#include "phady/security/core/models/entities/roles.zep.h"
#include "phady/security/core/models/entities/userrole.zep.h"
#include "phady/security/core/models/entities/users.zep.h"
#include "phady/security/core/models/exception.zep.h"
#include "phady/security/core/models/repositories/users.zep.h"
#include "phady/security/core/role/rolehierarchyinterface.zep.h"
#include "phady/security/core/role/roles.zep.h"
#include "phady/security/core/role/switchuserrole.zep.h"
#include "phady/security/core/security.zep.h"
#include "phady/security/core/user/inmemoryuserprovider.zep.h"
#include "phady/security/core/user/user.zep.h"
#include "phady/security/core/user/userchecker.zep.h"
#include "phady/security/core/user/users.zep.h"
#include "phady/security/exception.zep.h"
#include "phady/security/groups/groupbase.zep.h"
#include "phady/security/groups/groupinterface.zep.h"
#include "phady/security/http/authentication/authenticationfailurehandlerinterface.zep.h"
#include "phady/security/http/authentication/authenticationsuccesshandlerinterface.zep.h"
#include "phady/security/http/firewall/usernamepasswordformauthenticationlistener.zep.h"
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

#endif