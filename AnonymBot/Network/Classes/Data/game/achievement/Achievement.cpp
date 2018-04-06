#include "Achievement.h"

void Achievement::serialize(Writer *param1)
{
  this->serializeAs_Achievement(param1);
}

void Achievement::serializeAs_Achievement(Writer *param1)
{
  if(this->id < 0)
  {
    qDebug()<<"ERREUR - Achievement -"<<"Forbidden value (" << this->id << ") on element id.";
  }
  else
  {
    param1->writeVarShort((int)this->id);
    param1->writeShort((short)this->finishedObjective.size());
    uint _loc2_ = 0;
    while(_loc2_ < this->finishedObjective.size())
    {
      (this->finishedObjective[_loc2_]).serializeAs_AchievementObjective(param1);
      _loc2_++;
    }
    param1->writeShort((short)this->startedObjectives.size());
    uint _loc3_ = 0;
    while(_loc3_ < this->startedObjectives.size())
    {
      (this->startedObjectives[_loc3_]).serializeAs_AchievementStartedObjective(param1);
      _loc3_++;
    }
    return;
  }
}

void Achievement::deserialize(Reader *param1)
{
  this->deserializeAs_Achievement(param1);
}

void Achievement::deserializeAs_Achievement(Reader *param1)
{
  AchievementObjective _loc6_ ;
  AchievementStartedObjective _loc7_ ;
  this->id = param1->readVarUhShort();
  if(this->id < 0)
  {
    qDebug()<<"ERREUR - Achievement -"<<"Forbidden value (" << this->id << ") on element of Achievement.id.";
  }
  else
  {
    uint _loc2_ = param1->readUShort();
    uint _loc3_ = 0;
    while(_loc3_ < _loc2_)
    {
      _loc6_ = AchievementObjective();
      _loc6_.deserialize(param1);
      this->finishedObjective.append(_loc6_);
      _loc3_++;
    }
    uint _loc4_ = param1->readUShort();
    uint _loc5_ = 0;
    while(_loc5_ < _loc4_)
    {
      _loc7_ = AchievementStartedObjective();
      _loc7_.deserialize(param1);
      this->startedObjectives.append(_loc7_);
      _loc5_++;
    }
    return;
  }
}

Achievement::Achievement()
{
  m_types<<ClassEnum::ACHIEVEMENT;
}

bool Achievement::operator==(const Achievement &compared)
{
  if(id == compared.id)
  if(finishedObjective == compared.finishedObjective)
  if(startedObjectives == compared.startedObjectives)
  return true;
  
  return false;
}

