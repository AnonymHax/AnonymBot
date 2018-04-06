#include "IgnoredListMessage.h"

void IgnoredListMessage::serialize(Writer *param1)
{
  this->serializeAs_IgnoredListMessage(param1);
}

void IgnoredListMessage::serializeAs_IgnoredListMessage(Writer *param1)
{
  param1->writeShort((short)this->ignoredList.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->ignoredList.size())
  {
    param1->writeShort((short)qSharedPointerCast<IgnoredInformations>(this->ignoredList[_loc2_])->getTypes().last());
    qSharedPointerCast<IgnoredInformations>(this->ignoredList[_loc2_])->serialize(param1);
    _loc2_++;
  }
}

void IgnoredListMessage::deserialize(Reader *param1)
{
  this->deserializeAs_IgnoredListMessage(param1);
}

void IgnoredListMessage::deserializeAs_IgnoredListMessage(Reader *param1)
{
  uint _loc4_ = 0;
  QSharedPointer<IgnoredInformations> _loc5_ ;
  uint _loc2_ = param1->readUShort();
  uint _loc3_ = 0;
  while(_loc3_ < _loc2_)
  {
    _loc4_ = param1->readUShort();
    _loc5_ = qSharedPointerCast<IgnoredInformations>(ClassManagerSingleton::get()->getClass(_loc4_));
    _loc5_->deserialize(param1);
    this->ignoredList.append(_loc5_);
    _loc3_++;
  }
}

IgnoredListMessage::IgnoredListMessage()
{
  m_type = MessageEnum::IGNOREDLISTMESSAGE;
}

