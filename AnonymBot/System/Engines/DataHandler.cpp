#include "DataHandler.h"

bool operator==(const InventoryObject &left, const InventoryObject &right)
{
    if(left.GID == right.GID)
        if(left.UID == right.UID)
            if(left.quantity == right.quantity)
                if(left.position == right.position)
                    if(left.isEquipped == right.isEquipped)
                        if(left.regenLife == right.regenLife)
                   return true;

    return false;
}

bool operator<(const InventoryObject &left, const InventoryObject &right)
{
    if (left.regenLife < right.regenLife)
        return true;

    return false;
}

bool operator==(const RequestTradeObject &left, const RequestTradeObject &right)
{
    if(left.GID == right.GID)
        if(left.quantity == right.quantity)
            if(left.price == right.price)
                return true;

    return false;
}

bool operator==(const ConnectionInfos &left, const ConnectionInfos &right)
{
    if(left.serverId == right.serverId)
        if(left.login == right.login)
            if(left.password == right.password)
                if(left.character == right.character)
                    if(left.server == right.server)
                        return true;

    return false;
}

bool operator==(const RecipeInfos &left, const RecipeInfos &right)
{
    if (left.recipeId == right.recipeId)
        return true;

    return false;
}

bool operator==(const BankItem &left, const BankItem &right)
{
    if (left.itemId == right.itemId)
        return true;

    return false;
}

bool operator==(const PetFeedInfos &left, const PetFeedInfos &right)
{
    if (left.GID == right.GID)
        if (left.UID == right.UID)
            return true;

    return false;
}

bool operator<(const PetFeedInfos &left, const PetFeedInfos &right)
{
    if (left.GID < right.GID)
        return true;

    return false;
}

DataHandler::DataHandler():
    m_selfInit(true),
    m_botData(*(new QMap<SocketIO *, BotData>())),
    m_dataPointer(&m_botData)
{
}

DataHandler::DataHandler(QMap<SocketIO *, BotData> *connectionsData):
    m_selfInit(false),
    m_botData(*connectionsData)
{
}

DataHandler::~DataHandler()
{
    if(m_selfInit)
        delete m_dataPointer;
}

LogOutput &DataHandler::action(SocketIO *sender)
{
    return log(sender, CHANNELACTION);
}

LogOutput &DataHandler::info(SocketIO *sender)
{
    return log(sender, CHANNELINFO);
}

LogOutput &DataHandler::alert(SocketIO *sender)
{
    return log(sender, CHANNELALERT);
}

LogOutput &DataHandler::debug(SocketIO *sender)
{
    return log(sender, CHANNELDEBUG);
}

LogOutput &DataHandler::log(SocketIO *sender, Channel channel)
{
    m_botData[sender].generalData.logMessages.append(LogMessage());
    m_logOutput.setTarget(&m_botData[sender].generalData.logMessages.last(), channel);
    m_logOutput.initCall();
    return m_logOutput;
}
