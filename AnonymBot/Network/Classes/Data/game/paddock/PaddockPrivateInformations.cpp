#include "PaddockPrivateInformations.h"

void PaddockPrivateInformations::serialize(Writer *param1)
{
  this->serializeAs_PaddockPrivateInformations(param1);
}

void PaddockPrivateInformations::serializeAs_PaddockPrivateInformations(Writer *param1)
{
  PaddockAbandonnedInformations::serializeAs_PaddockAbandonnedInformations(param1);
  this->guildInfo->serializeAs_GuildInformations(param1);
}

void PaddockPrivateInformations::deserialize(Reader *param1)
{
  this->deserializeAs_PaddockPrivateInformations(param1);
}

void PaddockPrivateInformations::deserializeAs_PaddockPrivateInformations(Reader *param1)
{
  PaddockAbandonnedInformations::deserialize(param1);
  this->guildInfo = QSharedPointer<GuildInformations>(new GuildInformations() );
  this->guildInfo->deserialize(param1);
}

PaddockPrivateInformations::PaddockPrivateInformations()
{
  m_types<<ClassEnum::PADDOCKPRIVATEINFORMATIONS;
}

bool PaddockPrivateInformations::operator==(const PaddockPrivateInformations &compared)
{
  if(guildInfo == compared.guildInfo)
  return true;
  
  return false;
}

