#ifndef SERVERMESSAGEENUM_H
#define SERVERMESSAGEENUM_H

#include <QByteArray>
#include <QString>
#include <QList>

struct PathContainerData
{
    QStringList tags;
    QByteArray content;
    QString author;
    QString name;
    uint UID;
};

enum class FailureReasonsEnum
{
    WRONGCREDENTIALS = 0,
    NOTPREMIUM = 1,
    BANNED = 2,
    UNKNOWN = 3,
    MULTIPLECONNECTION = 4
};

enum class AccountTypeEnum
{
    TRIAL, PREMIUM
};

enum class ServerMessageEnum
{
    RAWRESOLVEREQUESTMESSAGE = 0,
    RAWRESOLVEFAILUREMESSAGE = 1,
    RAWRESOLVEMESSAGE = 2,
    CONNECTIONREQUESTMESSAGE = 3,
    CONNECTIONSUCCESSMESSAGE = 4,
    CONNECTIONFAILUREMESSAGE = 5,
    CLIENTUPDATEMESSAGE = 6,
    FORCEDISCONNECTIONMESSAGE = 7,
    SERVERUPDATEMESSAGE = 8,
    PATHDATAREQUESTMESSAGE = 9,
    PATHDATAMESSAGE = 10
};

#endif // SERVERMESSAGEENUM_H
