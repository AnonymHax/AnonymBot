#include "TaxCollectorGuildInformations.h"

void TaxCollectorGuildInformations::serialize(Writer *param1)
{
  this->serializeAs_TaxCollectorGuildInformations(param1);
}

void TaxCollectorGuildInformations::serializeAs_TaxCollectorGuildInformations(Writer *param1)
{
  TaxCollectorComplementaryInformations::serializeAs_TaxCollectorComplementaryInformations(param1);
  this->guild->serializeAs_BasicGuildInformations(param1);
}

void TaxCollectorGuildInformations::deserialize(Reader *param1)
{
  this->deserializeAs_TaxCollectorGuildInformations(param1);
}

void TaxCollectorGuildInformations::deserializeAs_TaxCollectorGuildInformations(Reader *param1)
{
  TaxCollectorComplementaryInformations::deserialize(param1);
  this->guild = QSharedPointer<BasicGuildInformations>(new BasicGuildInformations() );
  this->guild->deserialize(param1);
}

TaxCollectorGuildInformations::TaxCollectorGuildInformations()
{
  m_types<<ClassEnum::TAXCOLLECTORGUILDINFORMATIONS;
}

bool TaxCollectorGuildInformations::operator==(const TaxCollectorGuildInformations &compared)
{
  if(guild == compared.guild)
  return true;
  
  return false;
}

