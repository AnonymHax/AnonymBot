#include "AlternativeMonstersInGroupLightInformations.h"

void AlternativeMonstersInGroupLightInformations::serialize(Writer *param1)
{
  this->serializeAs_AlternativeMonstersInGroupLightInformations(param1);
}

void AlternativeMonstersInGroupLightInformations::serializeAs_AlternativeMonstersInGroupLightInformations(Writer *param1)
{
  param1->writeInt((int)this->playerCount);
  param1->writeShort((short)this->monsters.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->monsters.size())
  {
    (this->monsters[_loc2_]).serializeAs_MonsterInGroupLightInformations(param1);
    _loc2_++;
  }
}

void AlternativeMonstersInGroupLightInformations::deserialize(Reader *param1)
{
  this->deserializeAs_AlternativeMonstersInGroupLightInformations(param1);
}

void AlternativeMonstersInGroupLightInformations::deserializeAs_AlternativeMonstersInGroupLightInformations(Reader *param1)
{
  MonsterInGroupLightInformations _loc4_ ;
  this->playerCount = param1->readInt();
  uint _loc2_ = param1->readUShort();
  uint _loc3_ = 0;
  while(_loc3_ < _loc2_)
  {
    _loc4_ = MonsterInGroupLightInformations();
    _loc4_.deserialize(param1);
    this->monsters.append(_loc4_);
    _loc3_++;
  }
}

AlternativeMonstersInGroupLightInformations::AlternativeMonstersInGroupLightInformations()
{
  m_types<<ClassEnum::ALTERNATIVEMONSTERSINGROUPLIGHTINFORMATIONS;
}

bool AlternativeMonstersInGroupLightInformations::operator==(const AlternativeMonstersInGroupLightInformations &compared)
{
  if(playerCount == compared.playerCount)
  if(monsters == compared.monsters)
  return true;
  
  return false;
}

