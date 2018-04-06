#include "FightTeamInformations.h"

void FightTeamInformations::serialize(Writer *param1)
{
  this->serializeAs_FightTeamInformations(param1);
}

void FightTeamInformations::serializeAs_FightTeamInformations(Writer *param1)
{
  AbstractFightTeamInformations::serializeAs_AbstractFightTeamInformations(param1);
  param1->writeShort((short)this->teamMembers.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->teamMembers.size())
  {
    param1->writeShort((short)qSharedPointerCast<FightTeamMemberInformations>(this->teamMembers[_loc2_])->getTypes().last());
    qSharedPointerCast<FightTeamMemberInformations>(this->teamMembers[_loc2_])->serialize(param1);
    _loc2_++;
  }
}

void FightTeamInformations::deserialize(Reader *param1)
{
  this->deserializeAs_FightTeamInformations(param1);
}

void FightTeamInformations::deserializeAs_FightTeamInformations(Reader *param1)
{
  uint _loc4_ = 0;
  QSharedPointer<FightTeamMemberInformations> _loc5_ ;
  AbstractFightTeamInformations::deserialize(param1);
  uint _loc2_ = param1->readUShort();
  uint _loc3_ = 0;
  while(_loc3_ < _loc2_)
  {
    _loc4_ = param1->readUShort();
    _loc5_ = qSharedPointerCast<FightTeamMemberInformations>(ClassManagerSingleton::get()->getClass(_loc4_));
    _loc5_->deserialize(param1);
    this->teamMembers.append(_loc5_);
    _loc3_++;
  }
}

FightTeamInformations::FightTeamInformations()
{
  m_types<<ClassEnum::FIGHTTEAMINFORMATIONS;
}

bool FightTeamInformations::operator==(const FightTeamInformations &compared)
{
  if(teamMembers == compared.teamMembers)
  return true;
  
  return false;
}

