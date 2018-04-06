#include "FightTeamMemberCharacterInformations.h"

void FightTeamMemberCharacterInformations::serialize(Writer *param1)
{
  this->serializeAs_FightTeamMemberCharacterInformations(param1);
}

void FightTeamMemberCharacterInformations::serializeAs_FightTeamMemberCharacterInformations(Writer *param1)
{
  FightTeamMemberInformations::serializeAs_FightTeamMemberInformations(param1);
  param1->writeUTF(this->name);
  if(this->level < 0 || this->level > 255)
  {
    qDebug()<<"ERREUR - FightTeamMemberCharacterInformations -"<<"Forbidden value (" << this->level << ") on element level.";
  }
  else
  {
    param1->writeByte(this->level);
    return;
  }
}

void FightTeamMemberCharacterInformations::deserialize(Reader *param1)
{
  this->deserializeAs_FightTeamMemberCharacterInformations(param1);
}

void FightTeamMemberCharacterInformations::deserializeAs_FightTeamMemberCharacterInformations(Reader *param1)
{
  FightTeamMemberInformations::deserialize(param1);
  this->name = param1->readUTF();
  this->level = param1->readUByte();
  if(this->level < 0 || this->level > 255)
  {
    qDebug()<<"ERREUR - FightTeamMemberCharacterInformations -"<<"Forbidden value (" << this->level << ") on element of FightTeamMemberCharacterInformations.level.";
  }
  else
  {
    return;
  }
}

FightTeamMemberCharacterInformations::FightTeamMemberCharacterInformations()
{
  m_types<<ClassEnum::FIGHTTEAMMEMBERCHARACTERINFORMATIONS;
}

bool FightTeamMemberCharacterInformations::operator==(const FightTeamMemberCharacterInformations &compared)
{
  if(name == compared.name)
  if(level == compared.level)
  return true;
  
  return false;
}

