#include "FightExternalInformations.h"

void FightExternalInformations::serialize(Writer *param1)
{
  this->serializeAs_FightExternalInformations(param1);
}

void FightExternalInformations::serializeAs_FightExternalInformations(Writer *param1)
{
  param1->writeInt((int)this->fightId);
  param1->writeByte(this->fightType);
  if(this->fightStart < 0)
  {
    qDebug()<<"ERREUR - FightExternalInformations -"<<"Forbidden value (" << this->fightStart << ") on element fightStart.";
  }
  else
  {
    param1->writeInt((int)this->fightStart);
    param1->writeBool(this->fightSpectatorLocked);
    uint _loc2_ = 0;
    while(_loc2_ < 2)
    {
      this->fightTeams[_loc2_].serializeAs_FightTeamLightInformations(param1);
      _loc2_++;
    }
    uint _loc3_ = 0;
    while(_loc3_ < 2)
    {
      this->fightTeamsOptions[_loc3_].serializeAs_FightOptionsInformations(param1);
      _loc3_++;
    }
    return;
  }
}

void FightExternalInformations::deserialize(Reader *param1)
{
  this->deserializeAs_FightExternalInformations(param1);
}

void FightExternalInformations::deserializeAs_FightExternalInformations(Reader *param1)
{
  this->fightId = param1->readInt();
  this->fightType = param1->readByte();
  if(this->fightType < 0)
  {
    qDebug()<<"ERREUR - FightExternalInformations -"<<"Forbidden value (" << this->fightType << ") on element of FightExternalInformations.fightType.";
  }
  else
  {
    this->fightStart = param1->readInt();
    if(this->fightStart < 0)
    {
      qDebug()<<"ERREUR - FightExternalInformations -"<<"Forbidden value (" << this->fightStart << ") on element of FightExternalInformations.fightStart.";
    }
    else
    {
      this->fightSpectatorLocked = param1->readBool();
      uint _loc2_ = 0;
      while(_loc2_ < 2)
      {
        this->fightTeams<<FightTeamLightInformations();
        this->fightTeams[_loc2_].deserialize(param1);
        _loc2_++;
      }
      uint _loc3_ = 0;
      while(_loc3_ < 2)
      {
        this->fightTeamsOptions<<FightOptionsInformations();
        this->fightTeamsOptions[_loc3_].deserialize(param1);
        _loc3_++;
      }
      return;
    }
  }
}

FightExternalInformations::FightExternalInformations()
{
  m_types<<ClassEnum::FIGHTEXTERNALINFORMATIONS;
}

bool FightExternalInformations::operator==(const FightExternalInformations &compared)
{
  if(fightId == compared.fightId)
  if(fightType == compared.fightType)
  if(fightStart == compared.fightStart)
  if(fightSpectatorLocked == compared.fightSpectatorLocked)
  if(fightTeams == compared.fightTeams)
  if(fightTeamsOptions == compared.fightTeamsOptions)
  return true;
  
  return false;
}

