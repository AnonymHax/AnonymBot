#include "FightLoot.h"

void FightLoot::serialize(Writer *param1)
{
  this->serializeAs_FightLoot(param1);
}

void FightLoot::serializeAs_FightLoot(Writer *param1)
{
  param1->writeShort((short)this->objects.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->objects.size())
  {
    if(this->objects[_loc2_] < 0)
    {
      qDebug()<<"ERREUR - FightLoot -"<<"Forbidden value (" << this->objects[_loc2_] << ") on element 1 (starting at 1) of objects.";
    }
    else
    {
      param1->writeVarShort((int)this->objects[_loc2_]);
      _loc2_++;
      continue;
    }
  }
  if(this->kamas < 0)
  {
    qDebug()<<"ERREUR - FightLoot -"<<"Forbidden value (" << this->kamas << ") on element kamas.";
  }
  else
  {
    param1->writeVarInt((int)this->kamas);
    return;
  }
}

void FightLoot::deserialize(Reader *param1)
{
  this->deserializeAs_FightLoot(param1);
}

void FightLoot::deserializeAs_FightLoot(Reader *param1)
{
  uint _loc4_ = 0;
  uint _loc2_ = param1->readUShort();
  uint _loc3_ = 0;
  while(_loc3_ < _loc2_)
  {
    _loc4_ = param1->readVarUhShort();
    if(_loc4_ < 0)
    {
      qDebug()<<"ERREUR - FightLoot -"<<"Forbidden value (" << _loc4_ << ") on elements of objects.";
    }
    else
    {
      this->objects.append(_loc4_);
      _loc3_++;
      continue;
    }
  }
  this->kamas = param1->readVarUhInt();
  if(this->kamas < 0)
  {
    qDebug()<<"ERREUR - FightLoot -"<<"Forbidden value (" << this->kamas << ") on element of FightLoot.kamas.";
  }
  else
  {
    return;
  }
}

FightLoot::FightLoot()
{
  m_types<<ClassEnum::FIGHTLOOT;
}

bool FightLoot::operator==(const FightLoot &compared)
{
  if(objects == compared.objects)
  if(kamas == compared.kamas)
  return true;
  
  return false;
}

