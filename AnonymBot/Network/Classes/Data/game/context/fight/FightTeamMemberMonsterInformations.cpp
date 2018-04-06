#include "FightTeamMemberMonsterInformations.h"

void FightTeamMemberMonsterInformations::serialize(Writer *param1)
{
  this->serializeAs_FightTeamMemberMonsterInformations(param1);
}

void FightTeamMemberMonsterInformations::serializeAs_FightTeamMemberMonsterInformations(Writer *param1)
{
  FightTeamMemberInformations::serializeAs_FightTeamMemberInformations(param1);
  param1->writeInt((int)this->monsterId);
  if(this->grade < 0)
  {
    qDebug()<<"ERREUR - FightTeamMemberMonsterInformations -"<<"Forbidden value (" << this->grade << ") on element grade.";
  }
  else
  {
    param1->writeByte(this->grade);
    return;
  }
}

void FightTeamMemberMonsterInformations::deserialize(Reader *param1)
{
  this->deserializeAs_FightTeamMemberMonsterInformations(param1);
}

void FightTeamMemberMonsterInformations::deserializeAs_FightTeamMemberMonsterInformations(Reader *param1)
{
  FightTeamMemberInformations::deserialize(param1);
  this->monsterId = param1->readInt();
  this->grade = param1->readByte();
  if(this->grade < 0)
  {
    qDebug()<<"ERREUR - FightTeamMemberMonsterInformations -"<<"Forbidden value (" << this->grade << ") on element of FightTeamMemberMonsterInformations.grade.";
  }
  else
  {
    return;
  }
}

FightTeamMemberMonsterInformations::FightTeamMemberMonsterInformations()
{
  m_types<<ClassEnum::FIGHTTEAMMEMBERMONSTERINFORMATIONS;
}

bool FightTeamMemberMonsterInformations::operator==(const FightTeamMemberMonsterInformations &compared)
{
  if(monsterId == compared.monsterId)
  if(grade == compared.grade)
  return true;
  
  return false;
}

