#include "InteractiveMapUpdateMessage.h"

void InteractiveMapUpdateMessage::serialize(Writer *param1)
{
  this->serializeAs_InteractiveMapUpdateMessage(param1);
}

void InteractiveMapUpdateMessage::serializeAs_InteractiveMapUpdateMessage(Writer *param1)
{
  param1->writeShort((short)this->interactiveElements.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->interactiveElements.size())
  {
    param1->writeShort((short)qSharedPointerCast<InteractiveElement>(this->interactiveElements[_loc2_])->getTypes().last());
    qSharedPointerCast<InteractiveElement>(this->interactiveElements[_loc2_])->serialize(param1);
    _loc2_++;
  }
}

void InteractiveMapUpdateMessage::deserialize(Reader *param1)
{
  this->deserializeAs_InteractiveMapUpdateMessage(param1);
}

void InteractiveMapUpdateMessage::deserializeAs_InteractiveMapUpdateMessage(Reader *param1)
{
  uint _loc4_ = 0;
  QSharedPointer<InteractiveElement> _loc5_ ;
  uint _loc2_ = param1->readUShort();
  uint _loc3_ = 0;
  while(_loc3_ < _loc2_)
  {
    _loc4_ = param1->readUShort();
    _loc5_ = qSharedPointerCast<InteractiveElement>(ClassManagerSingleton::get()->getClass(_loc4_));
    _loc5_->deserialize(param1);
    this->interactiveElements.append(_loc5_);
    _loc3_++;
  }
}

InteractiveMapUpdateMessage::InteractiveMapUpdateMessage()
{
  m_type = MessageEnum::INTERACTIVEMAPUPDATEMESSAGE;
}

