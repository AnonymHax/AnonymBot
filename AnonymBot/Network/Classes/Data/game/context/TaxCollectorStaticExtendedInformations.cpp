#include "TaxCollectorStaticExtendedInformations.h"

void TaxCollectorStaticExtendedInformations::serialize(Writer *param1)
{
  this->serializeAs_TaxCollectorStaticExtendedInformations(param1);
}

void TaxCollectorStaticExtendedInformations::serializeAs_TaxCollectorStaticExtendedInformations(Writer *param1)
{
  TaxCollectorStaticInformations::serializeAs_TaxCollectorStaticInformations(param1);
  this->allianceIdentity->serializeAs_AllianceInformations(param1);
}

void TaxCollectorStaticExtendedInformations::deserialize(Reader *param1)
{
  this->deserializeAs_TaxCollectorStaticExtendedInformations(param1);
}

void TaxCollectorStaticExtendedInformations::deserializeAs_TaxCollectorStaticExtendedInformations(Reader *param1)
{
  TaxCollectorStaticInformations::deserialize(param1);
  this->allianceIdentity = QSharedPointer<AllianceInformations>(new AllianceInformations() );
  this->allianceIdentity->deserialize(param1);
}

TaxCollectorStaticExtendedInformations::TaxCollectorStaticExtendedInformations()
{
  m_types<<ClassEnum::TAXCOLLECTORSTATICEXTENDEDINFORMATIONS;
}

bool TaxCollectorStaticExtendedInformations::operator==(const TaxCollectorStaticExtendedInformations &compared)
{
  if(allianceIdentity == compared.allianceIdentity)
  return true;
  
  return false;
}

