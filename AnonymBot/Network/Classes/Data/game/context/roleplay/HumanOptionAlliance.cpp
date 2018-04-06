#include "HumanOptionAlliance.h"

void HumanOptionAlliance::serialize(Writer *param1)
{
  this->serializeAs_HumanOptionAlliance(param1);
}

void HumanOptionAlliance::serializeAs_HumanOptionAlliance(Writer *param1)
{
  HumanOption::serializeAs_HumanOption(param1);
  this->allianceInformations->serializeAs_AllianceInformations(param1);
  param1->writeByte(this->aggressable);
}

void HumanOptionAlliance::deserialize(Reader *param1)
{
  this->deserializeAs_HumanOptionAlliance(param1);
}

void HumanOptionAlliance::deserializeAs_HumanOptionAlliance(Reader *param1)
{
  HumanOption::deserialize(param1);
  this->allianceInformations = QSharedPointer<AllianceInformations>(new AllianceInformations() );
  this->allianceInformations->deserialize(param1);
  this->aggressable = param1->readByte();
  if(this->aggressable < 0)
  {
    qDebug()<<"ERREUR - HumanOptionAlliance -"<<"Forbidden value (" << this->aggressable << ") on element of HumanOptionAlliance.aggressable.";
  }
  else
  {
    return;
  }
}

HumanOptionAlliance::HumanOptionAlliance()
{
  m_types<<ClassEnum::HUMANOPTIONALLIANCE;
}

bool HumanOptionAlliance::operator==(const HumanOptionAlliance &compared)
{
  if(allianceInformations == compared.allianceInformations)
  if(aggressable == compared.aggressable)
  return true;
  
  return false;
}

