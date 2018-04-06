#include "BasicNamedAllianceInformations.h"

void BasicNamedAllianceInformations::serialize(Writer *param1)
{
  this->serializeAs_BasicNamedAllianceInformations(param1);
}

void BasicNamedAllianceInformations::serializeAs_BasicNamedAllianceInformations(Writer *param1)
{
  BasicAllianceInformations::serializeAs_BasicAllianceInformations(param1);
  param1->writeUTF(this->allianceName);
}

void BasicNamedAllianceInformations::deserialize(Reader *param1)
{
  this->deserializeAs_BasicNamedAllianceInformations(param1);
}

void BasicNamedAllianceInformations::deserializeAs_BasicNamedAllianceInformations(Reader *param1)
{
  BasicAllianceInformations::deserialize(param1);
  this->allianceName = param1->readUTF();
}

BasicNamedAllianceInformations::BasicNamedAllianceInformations()
{
  m_types<<ClassEnum::BASICNAMEDALLIANCEINFORMATIONS;
}

bool BasicNamedAllianceInformations::operator==(const BasicNamedAllianceInformations &compared)
{
  if(allianceName == compared.allianceName)
  return true;
  
  return false;
}

