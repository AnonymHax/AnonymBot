#include "FightTeamMemberCompanionInformations.h"

void FightTeamMemberCompanionInformations::serialize(Writer *param1)
{
  this->serializeAs_FightTeamMemberCompanionInformations(param1);
}

void FightTeamMemberCompanionInformations::serializeAs_FightTeamMemberCompanionInformations(Writer *param1)
{
  FightTeamMemberInformations::serializeAs_FightTeamMemberInformations(param1);
  if(this->companionId < 0)
  {
    qDebug()<<"ERREUR - FightTeamMemberCompanionInformations -"<<"Forbidden value (" << this->companionId << ") on element companionId.";
  }
  else
  {
    param1->writeByte(this->companionId);
    if(this->level < 1 || this->level > 200)
    {
      qDebug()<<"ERREUR - FightTeamMemberCompanionInformations -"<<"Forbidden value (" << this->level << ") on element level.";
    }
    else
    {
      param1->writeByte(this->level);
      if(this->masterId < -9.007199254740992E15 || this->masterId > 9.007199254740992E15)
      {
        qDebug()<<"ERREUR - FightTeamMemberCompanionInformations -"<<"Forbidden value (" << this->masterId << ") on element masterId.";
      }
      else
      {
        param1->writeDouble(this->masterId);
        return;
      }
    }
  }
}

void FightTeamMemberCompanionInformations::deserialize(Reader *param1)
{
  this->deserializeAs_FightTeamMemberCompanionInformations(param1);
}

void FightTeamMemberCompanionInformations::deserializeAs_FightTeamMemberCompanionInformations(Reader *param1)
{
  FightTeamMemberInformations::deserialize(param1);
  this->companionId = param1->readByte();
  if(this->companionId < 0)
  {
    qDebug()<<"ERREUR - FightTeamMemberCompanionInformations -"<<"Forbidden value (" << this->companionId << ") on element of FightTeamMemberCompanionInformations.companionId.";
  }
  else
  {
    this->level = param1->readUByte();
    if(this->level < 1 || this->level > 200)
    {
      qDebug()<<"ERREUR - FightTeamMemberCompanionInformations -"<<"Forbidden value (" << this->level << ") on element of FightTeamMemberCompanionInformations.level.";
    }
    else
    {
      this->masterId = param1->readDouble();
      if(this->masterId < -9.007199254740992E15 || this->masterId > 9.007199254740992E15)
      {
        qDebug()<<"ERREUR - FightTeamMemberCompanionInformations -"<<"Forbidden value (" << this->masterId << ") on element of FightTeamMemberCompanionInformations.masterId.";
      }
      else
      {
        return;
      }
    }
  }
}

FightTeamMemberCompanionInformations::FightTeamMemberCompanionInformations()
{
  m_types<<ClassEnum::FIGHTTEAMMEMBERCOMPANIONINFORMATIONS;
}

bool FightTeamMemberCompanionInformations::operator==(const FightTeamMemberCompanionInformations &compared)
{
  if(companionId == compared.companionId)
  if(level == compared.level)
  if(masterId == compared.masterId)
  return true;
  
  return false;
}

