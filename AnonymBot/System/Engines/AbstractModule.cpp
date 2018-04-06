#include "AbstractModule.h"

AbstractModule::AbstractModule(ModuleType type, QMap<SocketIO *, BotData> *connectionsData) :
    DataHandler(connectionsData),
    m_type(type)
{
}

AbstractModule::~AbstractModule()
{
}

ModuleType AbstractModule::getType()
{
    return m_type;
}
