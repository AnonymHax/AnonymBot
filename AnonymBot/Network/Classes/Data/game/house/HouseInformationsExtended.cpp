#include "HouseInformationsExtended.h"

void HouseInformationsExtended::serialize(Writer *param1)
{
  this->serializeAs_HouseInformationsExtended(param1);
}

void HouseInformationsExtended::serializeAs_HouseInformationsExtended(Writer *param1)
{
  HouseInformations::serializeAs_HouseInformations(param1);
  this->guildInfo->serializeAs_GuildInformations(param1);
}

void HouseInformationsExtended::deserialize(Reader *param1)
{
  this->deserializeAs_HouseInformationsExtended(param1);
}

void HouseInformationsExtended::deserializeAs_HouseInformationsExtended(Reader *param1)
{
  HouseInformations::deserialize(param1);
  this->guildInfo = QSharedPointer<GuildInformations>(new GuildInformations() );
  this->guildInfo->deserialize(param1);
}

HouseInformationsExtended::HouseInformationsExtended()
{
  m_types<<ClassEnum::HOUSEINFORMATIONSEXTENDED;
}

bool HouseInformationsExtended::operator==(const HouseInformationsExtended &compared)
{
  if(guildInfo == compared.guildInfo)
  return true;
  
  return false;
}

