#include "GameMapNoMovementMessage.h"

void GameMapNoMovementMessage::serialize(Writer *param1)
{
  this->serializeAs_GameMapNoMovementMessage(param1);
}

void GameMapNoMovementMessage::serializeAs_GameMapNoMovementMessage(Writer *param1)
{
  param1->writeShort((short)this->cellX);
  param1->writeShort((short)this->cellY);
}

void GameMapNoMovementMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GameMapNoMovementMessage(param1);
}

void GameMapNoMovementMessage::deserializeAs_GameMapNoMovementMessage(Reader *param1)
{
  this->cellX = param1->readShort();
  this->cellY = param1->readShort();
}

GameMapNoMovementMessage::GameMapNoMovementMessage()
{
  m_type = MessageEnum::GAMEMAPNOMOVEMENTMESSAGE;
}

