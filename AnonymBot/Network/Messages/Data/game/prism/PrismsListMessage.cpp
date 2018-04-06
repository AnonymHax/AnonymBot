#include "PrismsListMessage.h"

void PrismsListMessage::serialize(Writer *param1)
{
  this->serializeAs_PrismsListMessage(param1);
}

void PrismsListMessage::serializeAs_PrismsListMessage(Writer *param1)
{
  param1->writeShort((short)this->prisms.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->prisms.size())
  {
    param1->writeShort((short)qSharedPointerCast<PrismSubareaEmptyInfo>(this->prisms[_loc2_])->getTypes().last());
    qSharedPointerCast<PrismSubareaEmptyInfo>(this->prisms[_loc2_])->serialize(param1);
    _loc2_++;
  }
}

void PrismsListMessage::deserialize(Reader *param1)
{
  this->deserializeAs_PrismsListMessage(param1);
}

void PrismsListMessage::deserializeAs_PrismsListMessage(Reader *param1)
{
  uint _loc4_ = 0;
  QSharedPointer<PrismSubareaEmptyInfo> _loc5_ ;
  uint _loc2_ = param1->readUShort();
  uint _loc3_ = 0;
  while(_loc3_ < _loc2_)
  {
    _loc4_ = param1->readUShort();
    _loc5_ = qSharedPointerCast<PrismSubareaEmptyInfo>(ClassManagerSingleton::get()->getClass(_loc4_));
    _loc5_->deserialize(param1);
    this->prisms.append(_loc5_);
    _loc3_++;
  }
}

PrismsListMessage::PrismsListMessage()
{
  m_type = MessageEnum::PRISMSLISTMESSAGE;
}

