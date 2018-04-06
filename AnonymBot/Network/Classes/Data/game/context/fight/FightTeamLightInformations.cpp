#include "FightTeamLightInformations.h"

void FightTeamLightInformations::serialize(Writer *param1)
{
  this->serializeAs_FightTeamLightInformations(param1);
}

void FightTeamLightInformations::serializeAs_FightTeamLightInformations(Writer *param1)
{
  AbstractFightTeamInformations::serializeAs_AbstractFightTeamInformations(param1);
  uint _loc2_ = 0;
  _loc2_ = BooleanByteWrapper::setFlag(_loc2_, 0, this->hasFriend);
  _loc2_ = BooleanByteWrapper::setFlag(_loc2_, 1, this->hasGuildMember);
  _loc2_ = BooleanByteWrapper::setFlag(_loc2_, 2, this->hasAllianceMember);
  _loc2_ = BooleanByteWrapper::setFlag(_loc2_, 3, this->hasGroupMember);
  _loc2_ = BooleanByteWrapper::setFlag(_loc2_, 4, this->hasMyTaxCollector);
  param1->writeByte(_loc2_);
  if(this->teamMembersCount < 0)
  {
    qDebug()<<"ERREUR - FightTeamLightInformations -"<<"Forbidden value (" << this->teamMembersCount << ") on element teamMembersCount.";
  }
  else
  {
    param1->writeByte(this->teamMembersCount);
    if(this->meanLevel < 0)
    {
      qDebug()<<"ERREUR - FightTeamLightInformations -"<<"Forbidden value (" << this->meanLevel << ") on element meanLevel.";
    }
    else
    {
      param1->writeVarInt((int)this->meanLevel);
      return;
    }
  }
}

void FightTeamLightInformations::deserialize(Reader *param1)
{
  this->deserializeAs_FightTeamLightInformations(param1);
}

void FightTeamLightInformations::deserializeAs_FightTeamLightInformations(Reader *param1)
{
  AbstractFightTeamInformations::deserialize(param1);
  uint _loc2_ = param1->readByte();
  this->hasFriend = BooleanByteWrapper::getFlag(_loc2_, 0);
  this->hasGuildMember = BooleanByteWrapper::getFlag(_loc2_, 1);
  this->hasAllianceMember = BooleanByteWrapper::getFlag(_loc2_, 2);
  this->hasGroupMember = BooleanByteWrapper::getFlag(_loc2_, 3);
  this->hasMyTaxCollector = BooleanByteWrapper::getFlag(_loc2_, 4);
  this->teamMembersCount = param1->readByte();
  if(this->teamMembersCount < 0)
  {
    qDebug()<<"ERREUR - FightTeamLightInformations -"<<"Forbidden value (" << this->teamMembersCount << ") on element of FightTeamLightInformations.teamMembersCount.";
  }
  else
  {
    this->meanLevel = param1->readVarUhInt();
    if(this->meanLevel < 0)
    {
      qDebug()<<"ERREUR - FightTeamLightInformations -"<<"Forbidden value (" << this->meanLevel << ") on element of FightTeamLightInformations.meanLevel.";
    }
    else
    {
      return;
    }
  }
}

FightTeamLightInformations::FightTeamLightInformations()
{
  m_types<<ClassEnum::FIGHTTEAMLIGHTINFORMATIONS;
}

bool FightTeamLightInformations::operator==(const FightTeamLightInformations &compared)
{
  if(teamMembersCount == compared.teamMembersCount)
  if(meanLevel == compared.meanLevel)
  if(hasFriend == compared.hasFriend)
  if(hasGuildMember == compared.hasGuildMember)
  if(hasAllianceMember == compared.hasAllianceMember)
  if(hasGroupMember == compared.hasGroupMember)
  if(hasMyTaxCollector == compared.hasMyTaxCollector)
  return true;
  
  return false;
}

