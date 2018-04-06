#ifndef CONNECTIONMODULE_H
#define CONNECTIONMODULE_H

#include "Public.h"
#include "AbstractModule.h"
#include "System/Tools/Security/RsaManager.h"
#include "System/Tools/IO/D2O/ParamsDecoder.h"
#include "System/ServerInteractions/RawDataModule.h"
#include "System/Tools/EntityLook/EntityLookParser.h"
#include "System/Tools/IO/D2O/GameDataTypeDeclarator.h"

enum class DofusVersion
{
    MAJOR = 2,
    MINOR = 39,
    PATCH = 0,
    RELEASE = 0,
    REVISION = 116979,
};

class ConnectionModule : public AbstractModule
{
    Q_OBJECT

public:
    ConnectionModule(QMap<SocketIO*, BotData> *connectionsData);

    virtual void reset(SocketIO *sender);

    virtual bool processMessage(const MessageInfos &data, SocketIO *sender);

    SocketIO *addConnection(const ConnectionInfos &connectionInfos);
    void removeConnection(SocketIO *sender);

    void reconnect(SocketIO *sender);

    void setReconnectionAuto(SocketIO *sender, bool active);

    void connect(SocketIO *sender);
    void disconnect(SocketIO *sender);

private slots:
    void hasConnected();
    void hasDisconnected();

    void processReconnection();
    void processAntiBotReply(SocketIO *sender, int requestIndex, QList<int> answerData);
    void processAntiBotFailure(SocketIO *sender, int requestIndex, FailureReasonsEnum reason);
    void processBotServerConnectionFailure(SocketIO *sender);

signals:
    void connectionAdded(SocketIO *sender);
    void botDisconnected(SocketIO *sender);

private:
    RawDataModule m_rawDataModule;
};

#endif // CONNECTIONMODULE_H
