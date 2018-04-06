#include "CoreEngine.h"

CoreEngine::CoreEngine()
{
    QTime t;
    t.start();

    m_modules[ModuleType::MAP] = new MapModule(&m_botData);
    m_modules[ModuleType::STATS] = new StatsModule(&m_botData);
    m_modules[ModuleType::FLOOD] =  new FloodModule(&m_botData);
    m_modules[ModuleType::EXCHANGE] = new ExchangeModule(&m_botData);
    m_modules[ModuleType::CONNECTION] = new ConnectionModule(&m_botData);
    m_modules[ModuleType::INTERACTION] = new InteractionModule(&m_botData, static_cast<MapModule*>(m_modules[ModuleType::MAP]));
    m_modules[ModuleType::GROUP] = new GroupModule(&m_botData, static_cast<MapModule*>(m_modules[ModuleType::MAP]));
    m_modules[ModuleType::FIGHT] = new FightModule(&m_botData, static_cast<MapModule*>(m_modules[ModuleType::MAP]),
                                                static_cast<GroupModule*>(m_modules[ModuleType::GROUP]));
    m_modules[ModuleType::FARM] = new FarmModule(&m_botData,  static_cast<MapModule*>(m_modules[ModuleType::MAP]));
    m_modules[ModuleType::CRAFT] = new CraftModule(&m_botData, static_cast<MapModule*>(m_modules[ModuleType::MAP]));
    m_modules[ModuleType::SCRIPT] = new ScriptModule(&m_botData, static_cast<MapModule*>(m_modules[ModuleType::MAP]),
                                                static_cast<FightModule*>(m_modules[ModuleType::FIGHT]),
                                                static_cast<FarmModule*>(m_modules[ModuleType::FARM]),
                                                static_cast<CraftModule*>(m_modules[ModuleType::CRAFT]),
                                                static_cast<InteractionModule*>(m_modules[ModuleType::INTERACTION]),
                                                static_cast<GroupModule*>(m_modules[ModuleType::GROUP]),
                                                static_cast<StatsModule*>(m_modules[ModuleType::STATS]),
                                                static_cast<ConnectionModule*>(m_modules[ModuleType::CONNECTION]));

    qDebug()<<"CoreEngine - Initialisation - Temps écoulé:"<<t.elapsed()<<"ms";
}

CoreEngine::~CoreEngine()
{
    QMapIterator<ModuleType, AbstractModule*> module(m_modules);
    while (module.hasNext())
    {
        module.next();
        delete module.value();
    }
}

MapModule &CoreEngine::getMapModule()
{
    return *static_cast<MapModule*>(m_modules[ModuleType::MAP]);
}

FloodModule &CoreEngine::getFloodModule()
{
    return *static_cast<FloodModule*>(m_modules[ModuleType::FLOOD]);
}

FightModule &CoreEngine::getFightModule()
{
    return *static_cast<FightModule*>(m_modules[ModuleType::FIGHT]);
}

FarmModule &CoreEngine::getFarmModule()
{
    return *static_cast<FarmModule*>(m_modules[ModuleType::FARM]);
}

ConnectionModule &CoreEngine::getConnectionModule()
{
    return *static_cast<ConnectionModule*>(m_modules[ModuleType::CONNECTION]);
}

StatsModule &CoreEngine::getStatsModule()
{
    return *static_cast<StatsModule*>(m_modules[ModuleType::STATS]);
}

ExchangeModule &CoreEngine::getExchangeModule()
{
    return *static_cast<ExchangeModule*>(m_modules[ModuleType::EXCHANGE]);
}

GroupModule &CoreEngine::getGroupModule()
{
    return *static_cast<GroupModule*>(m_modules[ModuleType::GROUP]);
}

CraftModule &CoreEngine::getCraftModule()
{
    return *static_cast<CraftModule*>(m_modules[ModuleType::CRAFT]);
}

ScriptModule &CoreEngine::getScriptModule()
{
    return *static_cast<ScriptModule*>(m_modules[ModuleType::SCRIPT]);
}

InteractionModule &CoreEngine::getInteractionModule()
{
    return *static_cast<InteractionModule*>(m_modules[ModuleType::INTERACTION]);
}

const BotData &CoreEngine::getData(SocketIO *sender)
{
    return m_botData[sender];
}
