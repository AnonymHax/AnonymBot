#include "FightTeamMemberInformations.h"

void FightTeamMemberInformations::serialize(Writer *param1)
{
  this->serializeAs_FightTeamMemberInformations(param1);
}

void FightTeamMemberInformations::serializeAs_FightTeamMemberInformations(Writer *param1)
{
  if(this->id < -9.007199254740992E15 || this->id > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - FightTeamMemberInformations -"<<"Forbidden value (" << this->id << ") on element id.";
  }
  else
  {
    param1->writeDouble(this->id);
    return;
  }
}

void FightTeamMemberInformations::deserialize(Reader *param1)
{
  this->deserializeAs_FightTeamMemberInformations(param1);
}

void FightTeamMemberInformations::deserializeAs_FightTeamMemberInformations(Reader *param1)
{
  this->id = param1->readDouble();
  if(this->id < -9.007199254740992E15 || this->id > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - FightTeamMemberInformations -"<<"Forbidden value (" << this->id << ") on element of FightTeamMemberInformations.id.";
  }
  else
  {
    return;
  }
}

FightTeamMemberInformations::FightTeamMemberInformations()
{
  m_types<<ClassEnum::FIGHTTEAMMEMBERINFORMATIONS;
}

bool FightTeamMemberInformations::operator==(const FightTeamMemberInformations &compared)
{
  if(id == compared.id)
  return true;
  
  return false;
}

