#include "AllianceInformations.h"

void AllianceInformations::serialize(Writer *param1)
{
  this->serializeAs_AllianceInformations(param1);
}

void AllianceInformations::serializeAs_AllianceInformations(Writer *param1)
{
  BasicNamedAllianceInformations::serializeAs_BasicNamedAllianceInformations(param1);
  this->allianceEmblem.serializeAs_GuildEmblem(param1);
}

void AllianceInformations::deserialize(Reader *param1)
{
  this->deserializeAs_AllianceInformations(param1);
}

void AllianceInformations::deserializeAs_AllianceInformations(Reader *param1)
{
  BasicNamedAllianceInformations::deserialize(param1);
  this->allianceEmblem = GuildEmblem();
  this->allianceEmblem.deserialize(param1);
}

AllianceInformations::AllianceInformations()
{
  m_types<<ClassEnum::ALLIANCEINFORMATIONS;
}

bool AllianceInformations::operator==(const AllianceInformations &compared)
{
  if(allianceEmblem == compared.allianceEmblem)
  return true;
  
  return false;
}

