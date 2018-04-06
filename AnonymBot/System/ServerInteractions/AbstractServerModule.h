#ifndef ABSTRACTSERVERMODULE_H
#define ABSTRACTSERVERMODULE_H

#include "Public.h"
#include "ServerHandler.h"
#include "System/Tools/Singleton.h"

class AbstractServerModule
{
    friend class ServerHandler;

public:
    AbstractServerModule();
    virtual ~AbstractServerModule();

    virtual bool processMessage(const ServerMessageInfos &data) = 0;

protected:
    virtual void serverConnectionEstablished();
    virtual void serverConnectionFailed();
    virtual void serverDisconnected(bool anticipatedDisconnection);
};

#endif // ABSTRACTSERVERMODULE_H
