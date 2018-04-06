#include "BotStatsModule.h"

BotStatsModule::BotStatsModule():
    m_nbActiveBots(0)
{
}

bool BotStatsModule::processMessage(const ServerMessageInfos &data)
{
    bool messageFound = true;
    Reader reader(data.messageData);

    switch (data.messageType)
    {
    default :
        messageFound = false;
        break;

    case ServerMessageEnum::SERVERUPDATEMESSAGE:
    {
        ServerUpdateMessage message;
        message.deserialize(&reader);

        ClientUpdateMessage answer;
        answer.nbActiveBots = m_nbActiveBots;
        ServerHandlerSingleton::get()->send(answer);

        emit serverNbActiveBots(message.nbActiveBots);
    }
        break;

    }

    return messageFound;
}

void BotStatsModule::addActiveBot()
{
    m_nbActiveBots++;
}

void BotStatsModule::removeActiveBot()
{
    m_nbActiveBots--;
}
