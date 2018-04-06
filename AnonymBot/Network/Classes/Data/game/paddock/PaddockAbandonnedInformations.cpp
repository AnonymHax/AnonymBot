#include "PaddockAbandonnedInformations.h"

void PaddockAbandonnedInformations::serialize(Writer *param1)
{
  this->serializeAs_PaddockAbandonnedInformations(param1);
}

void PaddockAbandonnedInformations::serializeAs_PaddockAbandonnedInformations(Writer *param1)
{
  PaddockBuyableInformations::serializeAs_PaddockBuyableInformations(param1);
  param1->writeInt((int)this->guildId);
}

void PaddockAbandonnedInformations::deserialize(Reader *param1)
{
  this->deserializeAs_PaddockAbandonnedInformations(param1);
}

void PaddockAbandonnedInformations::deserializeAs_PaddockAbandonnedInformations(Reader *param1)
{
  PaddockBuyableInformations::deserialize(param1);
  this->guildId = param1->readInt();
}

PaddockAbandonnedInformations::PaddockAbandonnedInformations()
{
  m_types<<ClassEnum::PADDOCKABANDONNEDINFORMATIONS;
}

bool PaddockAbandonnedInformations::operator==(const PaddockAbandonnedInformations &compared)
{
  if(guildId == compared.guildId)
  return true;
  
  return false;
}

