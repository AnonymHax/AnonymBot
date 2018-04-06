#include "GameFightReadyMessage.h"

void GameFightReadyMessage::serialize(Writer *param1)
{
  this->serializeAs_GameFightReadyMessage(param1);
}

void GameFightReadyMessage::serializeAs_GameFightReadyMessage(Writer *param1)
{
  param1->writeBool(this->isReady);
}

void GameFightReadyMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GameFightReadyMessage(param1);
}

void GameFightReadyMessage::deserializeAs_GameFightReadyMessage(Reader *param1)
{
  this->isReady = param1->readBool();
}

GameFightReadyMessage::GameFightReadyMessage()
{
  m_type = MessageEnum::GAMEFIGHTREADYMESSAGE;
}

