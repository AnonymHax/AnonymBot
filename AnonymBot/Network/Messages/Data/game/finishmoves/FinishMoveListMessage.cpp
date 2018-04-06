#include "FinishMoveListMessage.h"

void FinishMoveListMessage::serialize(Writer *param1)
{
  this->serializeAs_FinishMoveListMessage(param1);
}

void FinishMoveListMessage::serializeAs_FinishMoveListMessage(Writer *param1)
{
  param1->writeShort((short)this->finishMoves.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->finishMoves.size())
  {
    (this->finishMoves[_loc2_]).serializeAs_FinishMoveInformations(param1);
    _loc2_++;
  }
}

void FinishMoveListMessage::deserialize(Reader *param1)
{
  this->deserializeAs_FinishMoveListMessage(param1);
}

void FinishMoveListMessage::deserializeAs_FinishMoveListMessage(Reader *param1)
{
  FinishMoveInformations _loc4_ ;
  uint _loc2_ = param1->readUShort();
  uint _loc3_ = 0;
  while(_loc3_ < _loc2_)
  {
    _loc4_ = FinishMoveInformations();
    _loc4_.deserialize(param1);
    this->finishMoves.append(_loc4_);
    _loc3_++;
  }
}

FinishMoveListMessage::FinishMoveListMessage()
{
  m_type = MessageEnum::FINISHMOVELISTMESSAGE;
}

