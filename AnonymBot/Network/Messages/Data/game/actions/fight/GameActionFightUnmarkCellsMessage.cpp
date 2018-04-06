#include "GameActionFightUnmarkCellsMessage.h"

void GameActionFightUnmarkCellsMessage::serialize(Writer *param1)
{
  this->serializeAs_GameActionFightUnmarkCellsMessage(param1);
}

void GameActionFightUnmarkCellsMessage::serializeAs_GameActionFightUnmarkCellsMessage(Writer *param1)
{
  AbstractGameActionMessage::serializeAs_AbstractGameActionMessage(param1);
  param1->writeShort((short)this->markId);
}

void GameActionFightUnmarkCellsMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GameActionFightUnmarkCellsMessage(param1);
}

void GameActionFightUnmarkCellsMessage::deserializeAs_GameActionFightUnmarkCellsMessage(Reader *param1)
{
  AbstractGameActionMessage::deserialize(param1);
  this->markId = param1->readShort();
}

GameActionFightUnmarkCellsMessage::GameActionFightUnmarkCellsMessage()
{
  m_type = MessageEnum::GAMEACTIONFIGHTUNMARKCELLSMESSAGE;
}

