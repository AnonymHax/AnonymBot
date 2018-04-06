#include "HavenBagFurnituresMessage.h"

void HavenBagFurnituresMessage::serialize(Writer *param1)
{
  this->serializeAs_HavenBagFurnituresMessage(param1);
}

void HavenBagFurnituresMessage::serializeAs_HavenBagFurnituresMessage(Writer *param1)
{
  param1->writeShort((short)this->furnituresInfos.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->furnituresInfos.size())
  {
    (this->furnituresInfos[_loc2_]).serializeAs_HavenBagFurnitureInformation(param1);
    _loc2_++;
  }
}

void HavenBagFurnituresMessage::deserialize(Reader *param1)
{
  this->deserializeAs_HavenBagFurnituresMessage(param1);
}

void HavenBagFurnituresMessage::deserializeAs_HavenBagFurnituresMessage(Reader *param1)
{
  HavenBagFurnitureInformation _loc4_ ;
  uint _loc2_ = param1->readUShort();
  uint _loc3_ = 0;
  while(_loc3_ < _loc2_)
  {
    _loc4_ = HavenBagFurnitureInformation();
    _loc4_.deserialize(param1);
    this->furnituresInfos.append(_loc4_);
    _loc3_++;
  }
}

HavenBagFurnituresMessage::HavenBagFurnituresMessage()
{
  m_type = MessageEnum::HAVENBAGFURNITURESMESSAGE;
}

