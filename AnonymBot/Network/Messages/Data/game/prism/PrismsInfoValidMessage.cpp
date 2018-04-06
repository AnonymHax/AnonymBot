#include "PrismsInfoValidMessage.h"

void PrismsInfoValidMessage::serialize(Writer *param1)
{
  this->serializeAs_PrismsInfoValidMessage(param1);
}

void PrismsInfoValidMessage::serializeAs_PrismsInfoValidMessage(Writer *param1)
{
  param1->writeShort((short)this->fights.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->fights.size())
  {
    qSharedPointerCast<PrismFightersInformation>(this->fights[_loc2_])->serializeAs_PrismFightersInformation(param1);
    _loc2_++;
  }
}

void PrismsInfoValidMessage::deserialize(Reader *param1)
{
  this->deserializeAs_PrismsInfoValidMessage(param1);
}

void PrismsInfoValidMessage::deserializeAs_PrismsInfoValidMessage(Reader *param1)
{
  QSharedPointer<PrismFightersInformation> _loc4_ ;
  uint _loc2_ = param1->readUShort();
  uint _loc3_ = 0;
  while(_loc3_ < _loc2_)
  {
    _loc4_ = QSharedPointer<PrismFightersInformation>(new PrismFightersInformation() );
    _loc4_->deserialize(param1);
    this->fights.append(_loc4_);
    _loc3_++;
  }
}

PrismsInfoValidMessage::PrismsInfoValidMessage()
{
  m_type = MessageEnum::PRISMSINFOVALIDMESSAGE;
}

