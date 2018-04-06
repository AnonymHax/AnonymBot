#ifndef BOTSTATSMODULE_H
#define BOTSTATSMODULE_H

#include "Public.h"
#include "AbstractServerModule.h"
#include "Network/ServerMessages/ClientUpdateMessage.h"
#include "Network/ServerMessages/ServerUpdateMessage.h"

class BotStatsModule : public QObject, public AbstractServerModule
{
    Q_OBJECT
public:
    BotStatsModule();

    virtual bool processMessage(const ServerMessageInfos &data);

    void addActiveBot();
    void removeActiveBot();
    void getPathContainerData(uint UId);

signals:
    void serverNbActiveBots(uint number);

private:
    uint m_nbActiveBots;
};

#endif // BOTSTATSMODULE_H
