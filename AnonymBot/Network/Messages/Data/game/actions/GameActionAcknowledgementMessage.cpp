#include "GameActionAcknowledgementMessage.h"

void GameActionAcknowledgementMessage::serialize(Writer *param1)
{
  this->serializeAs_GameActionAcknowledgementMessage(param1);
}

void GameActionAcknowledgementMessage::serializeAs_GameActionAcknowledgementMessage(Writer *param1)
{
  param1->writeBool(this->valid);
  param1->writeByte(this->actionId);
}

void GameActionAcknowledgementMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GameActionAcknowledgementMessage(param1);
}

void GameActionAcknowledgementMessage::deserializeAs_GameActionAcknowledgementMessage(Reader *param1)
{
  this->valid = param1->readBool();
  this->actionId = param1->readByte();
}

GameActionAcknowledgementMessage::GameActionAcknowledgementMessage()
{
  m_type = MessageEnum::GAMEACTIONACKNOWLEDGEMENTMESSAGE;
}

