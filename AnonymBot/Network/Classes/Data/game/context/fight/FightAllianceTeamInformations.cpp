#include "FightAllianceTeamInformations.h"

void FightAllianceTeamInformations::serialize(Writer *param1)
{
  this->serializeAs_FightAllianceTeamInformations(param1);
}

void FightAllianceTeamInformations::serializeAs_FightAllianceTeamInformations(Writer *param1)
{
  FightTeamInformations::serializeAs_FightTeamInformations(param1);
  param1->writeByte(this->relation);
}

void FightAllianceTeamInformations::deserialize(Reader *param1)
{
  this->deserializeAs_FightAllianceTeamInformations(param1);
}

void FightAllianceTeamInformations::deserializeAs_FightAllianceTeamInformations(Reader *param1)
{
  FightTeamInformations::deserialize(param1);
  this->relation = param1->readByte();
  if(this->relation < 0)
  {
    qDebug()<<"ERREUR - FightAllianceTeamInformations -"<<"Forbidden value (" << this->relation << ") on element of FightAllianceTeamInformations.relation.";
  }
  else
  {
    return;
  }
}

FightAllianceTeamInformations::FightAllianceTeamInformations()
{
  m_types<<ClassEnum::FIGHTALLIANCETEAMINFORMATIONS;
}

bool FightAllianceTeamInformations::operator==(const FightAllianceTeamInformations &compared)
{
  if(relation == compared.relation)
  return true;
  
  return false;
}

