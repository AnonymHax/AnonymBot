#include "AlliancePrismInformation.h"

void AlliancePrismInformation::serialize(Writer *param1)
{
  this->serializeAs_AlliancePrismInformation(param1);
}

void AlliancePrismInformation::serializeAs_AlliancePrismInformation(Writer *param1)
{
  PrismInformation::serializeAs_PrismInformation(param1);
  this->alliance->serializeAs_AllianceInformations(param1);
}

void AlliancePrismInformation::deserialize(Reader *param1)
{
  this->deserializeAs_AlliancePrismInformation(param1);
}

void AlliancePrismInformation::deserializeAs_AlliancePrismInformation(Reader *param1)
{
  PrismInformation::deserialize(param1);
  this->alliance = QSharedPointer<AllianceInformations>(new AllianceInformations() );
  this->alliance->deserialize(param1);
}

AlliancePrismInformation::AlliancePrismInformation()
{
  m_types<<ClassEnum::ALLIANCEPRISMINFORMATION;
}

bool AlliancePrismInformation::operator==(const AlliancePrismInformation &compared)
{
  if(alliance == compared.alliance)
  return true;
  
  return false;
}

