#include "GroupMonsterStaticInformationsWithAlternatives.h"

void GroupMonsterStaticInformationsWithAlternatives::serialize(Writer *param1)
{
  this->serializeAs_GroupMonsterStaticInformationsWithAlternatives(param1);
}

void GroupMonsterStaticInformationsWithAlternatives::serializeAs_GroupMonsterStaticInformationsWithAlternatives(Writer *param1)
{
  GroupMonsterStaticInformations::serializeAs_GroupMonsterStaticInformations(param1);
  param1->writeShort((short)this->alternatives.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->alternatives.size())
  {
    (this->alternatives[_loc2_]).serializeAs_AlternativeMonstersInGroupLightInformations(param1);
    _loc2_++;
  }
}

void GroupMonsterStaticInformationsWithAlternatives::deserialize(Reader *param1)
{
  this->deserializeAs_GroupMonsterStaticInformationsWithAlternatives(param1);
}

void GroupMonsterStaticInformationsWithAlternatives::deserializeAs_GroupMonsterStaticInformationsWithAlternatives(Reader *param1)
{
  AlternativeMonstersInGroupLightInformations _loc4_ ;
  GroupMonsterStaticInformations::deserialize(param1);
  uint _loc2_ = param1->readUShort();
  uint _loc3_ = 0;
  while(_loc3_ < _loc2_)
  {
    _loc4_ = AlternativeMonstersInGroupLightInformations();
    _loc4_.deserialize(param1);
    this->alternatives.append(_loc4_);
    _loc3_++;
  }
}

GroupMonsterStaticInformationsWithAlternatives::GroupMonsterStaticInformationsWithAlternatives()
{
  m_types<<ClassEnum::GROUPMONSTERSTATICINFORMATIONSWITHALTERNATIVES;
}

bool GroupMonsterStaticInformationsWithAlternatives::operator==(const GroupMonsterStaticInformationsWithAlternatives &compared)
{
  if(alternatives == compared.alternatives)
  return true;
  
  return false;
}

