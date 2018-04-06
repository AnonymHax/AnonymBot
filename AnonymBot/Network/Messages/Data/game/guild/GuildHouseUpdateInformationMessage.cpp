#include "GuildHouseUpdateInformationMessage.h"

void GuildHouseUpdateInformationMessage::serialize(Writer *param1)
{
  this->serializeAs_GuildHouseUpdateInformationMessage(param1);
}

void GuildHouseUpdateInformationMessage::serializeAs_GuildHouseUpdateInformationMessage(Writer *param1)
{
  this->housesInformations.serializeAs_HouseInformationsForGuild(param1);
}

void GuildHouseUpdateInformationMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GuildHouseUpdateInformationMessage(param1);
}

void GuildHouseUpdateInformationMessage::deserializeAs_GuildHouseUpdateInformationMessage(Reader *param1)
{
  this->housesInformations = HouseInformationsForGuild();
  this->housesInformations.deserialize(param1);
}

GuildHouseUpdateInformationMessage::GuildHouseUpdateInformationMessage()
{
  m_type = MessageEnum::GUILDHOUSEUPDATEINFORMATIONMESSAGE;
}

