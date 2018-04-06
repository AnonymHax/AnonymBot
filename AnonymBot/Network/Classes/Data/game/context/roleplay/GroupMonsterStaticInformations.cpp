#include "GroupMonsterStaticInformations.h"

void GroupMonsterStaticInformations::serialize(Writer *param1)
{
  this->serializeAs_GroupMonsterStaticInformations(param1);
}

void GroupMonsterStaticInformations::serializeAs_GroupMonsterStaticInformations(Writer *param1)
{
  this->mainCreatureLightInfos.serializeAs_MonsterInGroupLightInformations(param1);
  param1->writeShort((short)this->underlings.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->underlings.size())
  {
    qSharedPointerCast<MonsterInGroupInformations>(this->underlings[_loc2_])->serializeAs_MonsterInGroupInformations(param1);
    _loc2_++;
  }
}

void GroupMonsterStaticInformations::deserialize(Reader *param1)
{
  this->deserializeAs_GroupMonsterStaticInformations(param1);
}

void GroupMonsterStaticInformations::deserializeAs_GroupMonsterStaticInformations(Reader *param1)
{
  QSharedPointer<MonsterInGroupInformations> _loc4_ ;
  this->mainCreatureLightInfos = MonsterInGroupLightInformations();
  this->mainCreatureLightInfos.deserialize(param1);
  uint _loc2_ = param1->readUShort();
  uint _loc3_ = 0;
  while(_loc3_ < _loc2_)
  {
    _loc4_ = QSharedPointer<MonsterInGroupInformations>(new MonsterInGroupInformations() );
    _loc4_->deserialize(param1);
    this->underlings.append(_loc4_);
    _loc3_++;
  }
}

GroupMonsterStaticInformations::GroupMonsterStaticInformations()
{
  m_types<<ClassEnum::GROUPMONSTERSTATICINFORMATIONS;
}

bool GroupMonsterStaticInformations::operator==(const GroupMonsterStaticInformations &compared)
{
  if(mainCreatureLightInfos == compared.mainCreatureLightInfos)
  if(underlings == compared.underlings)
  return true;
  
  return false;
}

