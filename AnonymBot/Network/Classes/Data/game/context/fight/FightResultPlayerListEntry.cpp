#include "FightResultPlayerListEntry.h"

void FightResultPlayerListEntry::serialize(Writer *param1)
{
  this->serializeAs_FightResultPlayerListEntry(param1);
}

void FightResultPlayerListEntry::serializeAs_FightResultPlayerListEntry(Writer *param1)
{
  FightResultFighterListEntry::serializeAs_FightResultFighterListEntry(param1);
  if(this->level < 1 || this->level > 206)
  {
    qDebug()<<"ERREUR - FightResultPlayerListEntry -"<<"Forbidden value (" << this->level << ") on element level.";
  }
  else
  {
    param1->writeByte(this->level);
    param1->writeShort((short)this->additional.size());
    uint _loc2_ = 0;
    while(_loc2_ < this->additional.size())
    {
      param1->writeShort((short)qSharedPointerCast<FightResultAdditionalData>(this->additional[_loc2_])->getTypes().last());
      qSharedPointerCast<FightResultAdditionalData>(this->additional[_loc2_])->serialize(param1);
      _loc2_++;
    }
    return;
  }
}

void FightResultPlayerListEntry::deserialize(Reader *param1)
{
  this->deserializeAs_FightResultPlayerListEntry(param1);
}

void FightResultPlayerListEntry::deserializeAs_FightResultPlayerListEntry(Reader *param1)
{
  uint _loc4_ = 0;
  QSharedPointer<FightResultAdditionalData> _loc5_ ;
  FightResultFighterListEntry::deserialize(param1);
  this->level = param1->readUByte();
  if(this->level < 1 || this->level > 206)
  {
    qDebug()<<"ERREUR - FightResultPlayerListEntry -"<<"Forbidden value (" << this->level << ") on element of FightResultPlayerListEntry.level.";
  }
  else
  {
    uint _loc2_ = param1->readUShort();
    uint _loc3_ = 0;
    while(_loc3_ < _loc2_)
    {
      _loc4_ = param1->readUShort();
      _loc5_ = qSharedPointerCast<FightResultAdditionalData>(ClassManagerSingleton::get()->getClass(_loc4_));
      _loc5_->deserialize(param1);
      this->additional.append(_loc5_);
      _loc3_++;
    }
    return;
  }
}

FightResultPlayerListEntry::FightResultPlayerListEntry()
{
  m_types<<ClassEnum::FIGHTRESULTPLAYERLISTENTRY;
}

bool FightResultPlayerListEntry::operator==(const FightResultPlayerListEntry &compared)
{
  if(level == compared.level)
  if(additional == compared.additional)
  return true;
  
  return false;
}

