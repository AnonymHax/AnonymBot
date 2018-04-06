#ifndef PROCESSENGINE_H
#define PROCESSENGINE_H

#include "Public.h"
#include "CoreEngine.h"
#include "System/Tools/Pathfinding/Pathfinding.h"
#include "System/Tools/IO/D2O/ParamsDecoder.h"

class ProcessEngine : public CoreEngine
{
    Q_OBJECT

public:
    ProcessEngine();

    bool processMessage(const MessageInfos &data, SocketIO *sender);

private slots:
    void resetModules(SocketIO *sender);
    void processUpdateRequest(SocketIO *sender);
    void connectToSocket(SocketIO* sender);

    void processData(QList<MessageInfos> messages);
};

#endif // PROCESSENGINE_H
