#include "PaddockPropertiesMessage.h"

void PaddockPropertiesMessage::serialize(Writer *param1)
{
  this->serializeAs_PaddockPropertiesMessage(param1);
}

void PaddockPropertiesMessage::serializeAs_PaddockPropertiesMessage(Writer *param1)
{
  param1->writeShort((short)this->properties->getTypes().last());
  this->properties->serialize(param1);
}

void PaddockPropertiesMessage::deserialize(Reader *param1)
{
  this->deserializeAs_PaddockPropertiesMessage(param1);
}

void PaddockPropertiesMessage::deserializeAs_PaddockPropertiesMessage(Reader *param1)
{
  uint _loc2_ = param1->readUShort();
  this->properties = qSharedPointerCast<PaddockInformations>(ClassManagerSingleton::get()->getClass(_loc2_));
  this->properties->deserialize(param1);
}

PaddockPropertiesMessage::PaddockPropertiesMessage()
{
  m_type = MessageEnum::PADDOCKPROPERTIESMESSAGE;
}

