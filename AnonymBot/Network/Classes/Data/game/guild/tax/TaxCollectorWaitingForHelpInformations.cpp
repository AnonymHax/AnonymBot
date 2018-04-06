#include "TaxCollectorWaitingForHelpInformations.h"

void TaxCollectorWaitingForHelpInformations::serialize(Writer *param1)
{
  this->serializeAs_TaxCollectorWaitingForHelpInformations(param1);
}

void TaxCollectorWaitingForHelpInformations::serializeAs_TaxCollectorWaitingForHelpInformations(Writer *param1)
{
  TaxCollectorComplementaryInformations::serializeAs_TaxCollectorComplementaryInformations(param1);
  this->waitingForHelpInfo.serializeAs_ProtectedEntityWaitingForHelpInfo(param1);
}

void TaxCollectorWaitingForHelpInformations::deserialize(Reader *param1)
{
  this->deserializeAs_TaxCollectorWaitingForHelpInformations(param1);
}

void TaxCollectorWaitingForHelpInformations::deserializeAs_TaxCollectorWaitingForHelpInformations(Reader *param1)
{
  TaxCollectorComplementaryInformations::deserialize(param1);
  this->waitingForHelpInfo = ProtectedEntityWaitingForHelpInfo();
  this->waitingForHelpInfo.deserialize(param1);
}

TaxCollectorWaitingForHelpInformations::TaxCollectorWaitingForHelpInformations()
{
  m_types<<ClassEnum::TAXCOLLECTORWAITINGFORHELPINFORMATIONS;
}

bool TaxCollectorWaitingForHelpInformations::operator==(const TaxCollectorWaitingForHelpInformations &compared)
{
  if(waitingForHelpInfo == compared.waitingForHelpInfo)
  return true;
  
  return false;
}

