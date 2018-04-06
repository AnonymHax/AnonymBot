#include "GameContextMoveMultipleElementsMessage.h"

void GameContextMoveMultipleElementsMessage::serialize(Writer *param1)
{
  this->serializeAs_GameContextMoveMultipleElementsMessage(param1);
}

void GameContextMoveMultipleElementsMessage::serializeAs_GameContextMoveMultipleElementsMessage(Writer *param1)
{
  param1->writeShort((short)this->movements.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->movements.size())
  {
    (this->movements[_loc2_]).serializeAs_EntityMovementInformations(param1);
    _loc2_++;
  }
}

void GameContextMoveMultipleElementsMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GameContextMoveMultipleElementsMessage(param1);
}

void GameContextMoveMultipleElementsMessage::deserializeAs_GameContextMoveMultipleElementsMessage(Reader *param1)
{
  EntityMovementInformations _loc4_ ;
  uint _loc2_ = param1->readUShort();
  uint _loc3_ = 0;
  while(_loc3_ < _loc2_)
  {
    _loc4_ = EntityMovementInformations();
    _loc4_.deserialize(param1);
    this->movements.append(_loc4_);
    _loc3_++;
  }
}

GameContextMoveMultipleElementsMessage::GameContextMoveMultipleElementsMessage()
{
  m_type = MessageEnum::GAMECONTEXTMOVEMULTIPLEELEMENTSMESSAGE;
}

