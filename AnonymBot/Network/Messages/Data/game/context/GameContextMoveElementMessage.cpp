#include "GameContextMoveElementMessage.h"

void GameContextMoveElementMessage::serialize(Writer *param1)
{
  this->serializeAs_GameContextMoveElementMessage(param1);
}

void GameContextMoveElementMessage::serializeAs_GameContextMoveElementMessage(Writer *param1)
{
  this->movement.serializeAs_EntityMovementInformations(param1);
}

void GameContextMoveElementMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GameContextMoveElementMessage(param1);
}

void GameContextMoveElementMessage::deserializeAs_GameContextMoveElementMessage(Reader *param1)
{
  this->movement = EntityMovementInformations();
  this->movement.deserialize(param1);
}

GameContextMoveElementMessage::GameContextMoveElementMessage()
{
  m_type = MessageEnum::GAMECONTEXTMOVEELEMENTMESSAGE;
}

