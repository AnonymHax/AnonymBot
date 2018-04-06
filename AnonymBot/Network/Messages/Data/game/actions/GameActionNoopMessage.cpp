#include "GameActionNoopMessage.h"

void GameActionNoopMessage::serialize(Writer *param1)
{
}

void GameActionNoopMessage::serializeAs_GameActionNoopMessage(Writer *param1)
{
}

void GameActionNoopMessage::deserialize(Reader *param1)
{
}

void GameActionNoopMessage::deserializeAs_GameActionNoopMessage(Reader *param1)
{
}

GameActionNoopMessage::GameActionNoopMessage()
{
  m_type = MessageEnum::GAMEACTIONNOOPMESSAGE;
}

