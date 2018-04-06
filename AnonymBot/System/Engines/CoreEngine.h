#ifndef CoreEngine_H
#define CoreEngine_H

#include "System/Tools/IO/Reader.h"
#include "FloodModule.h"
#include "FightModule.h"
#include "FarmModule.h"
#include "MapModule.h"
#include "ConnectionModule.h"
#include "StatsModule.h"
#include "ExchangeModule.h"
#include "GroupModule.h"
#include "CraftModule.h"
#include "ScriptModule.h"
#include "InteractionModule.h"

class CoreEngine : public QObject, public DataHandler
{

    Q_OBJECT

public:
    CoreEngine();
    ~CoreEngine();

    MapModule &getMapModule();
    FarmModule &getFarmModule();
    CraftModule &getCraftModule();
    FightModule &getFightModule();
    FloodModule &getFloodModule();
    GroupModule &getGroupModule();
    StatsModule &getStatsModule();
    ScriptModule &getScriptModule();
    ExchangeModule &getExchangeModule();
    ConnectionModule &getConnectionModule();
    InteractionModule &getInteractionModule();

    const BotData &getData(SocketIO *sender);

signals:
    void informationsUpdated(SocketIO *sender);

protected:
    QMap<ModuleType, AbstractModule*> m_modules;

private:
    QMap<SocketIO*, ConnectionInfos> m_connectionsInfos;
};

#endif // CoreEngine_H
