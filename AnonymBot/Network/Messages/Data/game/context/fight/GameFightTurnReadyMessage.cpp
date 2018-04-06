#include "GameFightTurnReadyMessage.h"

void GameFightTurnReadyMessage::serialize(Writer *param1)
{
  this->serializeAs_GameFightTurnReadyMessage(param1);
}

void GameFightTurnReadyMessage::serializeAs_GameFightTurnReadyMessage(Writer *param1)
{
  param1->writeBool(this->isReady);
}

void GameFightTurnReadyMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GameFightTurnReadyMessage(param1);
}

void GameFightTurnReadyMessage::deserializeAs_GameFightTurnReadyMessage(Reader *param1)
{
  this->isReady = param1->readBool();
}

GameFightTurnReadyMessage::GameFightTurnReadyMessage()
{
  m_type = MessageEnum::GAMEFIGHTTURNREADYMESSAGE;
}

