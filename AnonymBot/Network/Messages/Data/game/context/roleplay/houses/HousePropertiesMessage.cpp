#include "HousePropertiesMessage.h"

void HousePropertiesMessage::serialize(Writer *param1)
{
  this->serializeAs_HousePropertiesMessage(param1);
}

void HousePropertiesMessage::serializeAs_HousePropertiesMessage(Writer *param1)
{
  param1->writeShort((short)this->properties->getTypes().last());
  this->properties->serialize(param1);
}

void HousePropertiesMessage::deserialize(Reader *param1)
{
  this->deserializeAs_HousePropertiesMessage(param1);
}

void HousePropertiesMessage::deserializeAs_HousePropertiesMessage(Reader *param1)
{
  uint _loc2_ = param1->readUShort();
  this->properties = qSharedPointerCast<HouseInformations>(ClassManagerSingleton::get()->getClass(_loc2_));
  this->properties->deserialize(param1);
}

HousePropertiesMessage::HousePropertiesMessage()
{
  m_type = MessageEnum::HOUSEPROPERTIESMESSAGE;
}

