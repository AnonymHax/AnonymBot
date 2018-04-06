#include "FightCommonInformations.h"

void FightCommonInformations::serialize(Writer *param1)
{
  this->serializeAs_FightCommonInformations(param1);
}

void FightCommonInformations::serializeAs_FightCommonInformations(Writer *param1)
{
  param1->writeInt((int)this->fightId);
  param1->writeByte(this->fightType);
  param1->writeShort((short)this->fightTeams.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->fightTeams.size())
  {
    param1->writeShort((short)qSharedPointerCast<FightTeamInformations>(this->fightTeams[_loc2_])->getTypes().last());
    qSharedPointerCast<FightTeamInformations>(this->fightTeams[_loc2_])->serialize(param1);
    _loc2_++;
  }
  param1->writeShort((short)this->fightTeamsPositions.size());
  uint _loc3_ = 0;
  while(_loc3_ < this->fightTeamsPositions.size())
  {
    if(this->fightTeamsPositions[_loc3_] < 0 || this->fightTeamsPositions[_loc3_] > 559)
    {
      qDebug()<<"ERREUR - FightCommonInformations -"<<"Forbidden value (" << this->fightTeamsPositions[_loc3_] << ") on element 4 (starting at 1) of fightTeamsPositions.";
    }
    else
    {
      param1->writeVarShort((int)this->fightTeamsPositions[_loc3_]);
      _loc3_++;
      continue;
    }
  }
  param1->writeShort((short)this->fightTeamsOptions.size());
  uint _loc4_ = 0;
  while(_loc4_ < this->fightTeamsOptions.size())
  {
    (this->fightTeamsOptions[_loc4_]).serializeAs_FightOptionsInformations(param1);
    _loc4_++;
  }
}

void FightCommonInformations::deserialize(Reader *param1)
{
  this->deserializeAs_FightCommonInformations(param1);
}

void FightCommonInformations::deserializeAs_FightCommonInformations(Reader *param1)
{
  uint _loc8_ = 0;
  QSharedPointer<FightTeamInformations> _loc9_ ;
  uint _loc10_ = 0;
  FightOptionsInformations _loc11_ ;
  this->fightId = param1->readInt();
  this->fightType = param1->readByte();
  if(this->fightType < 0)
  {
    qDebug()<<"ERREUR - FightCommonInformations -"<<"Forbidden value (" << this->fightType << ") on element of FightCommonInformations.fightType.";
  }
  else
  {
    uint _loc2_ = param1->readUShort();
    uint _loc3_ = 0;
    while(_loc3_ < _loc2_)
    {
      _loc8_ = param1->readUShort();
      _loc9_ = qSharedPointerCast<FightTeamInformations>(ClassManagerSingleton::get()->getClass(_loc8_));
      _loc9_->deserialize(param1);
      this->fightTeams.append(_loc9_);
      _loc3_++;
    }
    uint _loc4_ = param1->readUShort();
    uint _loc5_ = 0;
    while(_loc5_ < _loc4_)
    {
      _loc10_ = param1->readVarUhShort();
      if(_loc10_ < 0 || _loc10_ > 559)
      {
        qDebug()<<"ERREUR - FightCommonInformations -"<<"Forbidden value (" << _loc10_ << ") on elements of fightTeamsPositions.";
      }
      else
      {
        this->fightTeamsPositions.append(_loc10_);
        _loc5_++;
        continue;
      }
    }
    uint _loc6_ = param1->readUShort();
    uint _loc7_ = 0;
    while(_loc7_ < _loc6_)
    {
      _loc11_ = FightOptionsInformations();
      _loc11_.deserialize(param1);
      this->fightTeamsOptions.append(_loc11_);
      _loc7_++;
    }
    return;
  }
}

FightCommonInformations::FightCommonInformations()
{
  m_types<<ClassEnum::FIGHTCOMMONINFORMATIONS;
}

bool FightCommonInformations::operator==(const FightCommonInformations &compared)
{
  if(fightId == compared.fightId)
  if(fightType == compared.fightType)
  if(fightTeams == compared.fightTeams)
  if(fightTeamsPositions == compared.fightTeamsPositions)
  if(fightTeamsOptions == compared.fightTeamsOptions)
  return true;
  
  return false;
}

