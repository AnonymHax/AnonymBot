#include "GuildHousesInformationMessage.h"

void GuildHousesInformationMessage::serialize(Writer *param1)
{
  this->serializeAs_GuildHousesInformationMessage(param1);
}

void GuildHousesInformationMessage::serializeAs_GuildHousesInformationMessage(Writer *param1)
{
  param1->writeShort((short)this->housesInformations.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->housesInformations.size())
  {
    (this->housesInformations[_loc2_]).serializeAs_HouseInformationsForGuild(param1);
    _loc2_++;
  }
}

void GuildHousesInformationMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GuildHousesInformationMessage(param1);
}

void GuildHousesInformationMessage::deserializeAs_GuildHousesInformationMessage(Reader *param1)
{
  HouseInformationsForGuild _loc4_ ;
  uint _loc2_ = param1->readUShort();
  uint _loc3_ = 0;
  while(_loc3_ < _loc2_)
  {
    _loc4_ = HouseInformationsForGuild();
    _loc4_.deserialize(param1);
    this->housesInformations.append(_loc4_);
    _loc3_++;
  }
}

GuildHousesInformationMessage::GuildHousesInformationMessage()
{
  m_type = MessageEnum::GUILDHOUSESINFORMATIONMESSAGE;
}

