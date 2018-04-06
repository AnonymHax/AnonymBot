#ifndef ABSTRACTMODULE_H
#define ABSTRACTMODULE_H

#include "Public.h"
#include "DataHandler.h"

class AbstractModule : public QObject, public DataHandler
{
    Q_OBJECT

public:
    AbstractModule(ModuleType type, QMap<SocketIO*, BotData> *connectionsData);
    virtual ~AbstractModule();

    virtual void reset(SocketIO *sender) = 0;

    virtual bool processMessage(const MessageInfos &data, SocketIO *sender) = 0;

    ModuleType getType();

signals:
    void requestUpdate(SocketIO *sender);
    void scriptActionDone(SocketIO *sender);
    void scriptActionRepeat(SocketIO *sender);
    void scriptActionCancel(SocketIO *sender);
    void scriptActionFailure(SocketIO *sender);
    void requestResetData(SocketIO *sender);

private:
    ModuleType m_type;
};
#endif // ABSTRACTMODULE_H
