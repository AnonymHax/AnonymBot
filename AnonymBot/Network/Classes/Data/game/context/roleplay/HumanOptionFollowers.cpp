#include "HumanOptionFollowers.h"

void HumanOptionFollowers::serialize(Writer *param1)
{
  this->serializeAs_HumanOptionFollowers(param1);
}

void HumanOptionFollowers::serializeAs_HumanOptionFollowers(Writer *param1)
{
  HumanOption::serializeAs_HumanOption(param1);
  param1->writeShort((short)this->followingCharactersLook.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->followingCharactersLook.size())
  {
    qSharedPointerCast<IndexedEntityLook>(this->followingCharactersLook[_loc2_])->serializeAs_IndexedEntityLook(param1);
    _loc2_++;
  }
}

void HumanOptionFollowers::deserialize(Reader *param1)
{
  this->deserializeAs_HumanOptionFollowers(param1);
}

void HumanOptionFollowers::deserializeAs_HumanOptionFollowers(Reader *param1)
{
  QSharedPointer<IndexedEntityLook> _loc4_ ;
  HumanOption::deserialize(param1);
  uint _loc2_ = param1->readUShort();
  uint _loc3_ = 0;
  while(_loc3_ < _loc2_)
  {
    _loc4_ = QSharedPointer<IndexedEntityLook>(new IndexedEntityLook() );
    _loc4_->deserialize(param1);
    this->followingCharactersLook.append(_loc4_);
    _loc3_++;
  }
}

HumanOptionFollowers::HumanOptionFollowers()
{
  m_types<<ClassEnum::HUMANOPTIONFOLLOWERS;
}

bool HumanOptionFollowers::operator==(const HumanOptionFollowers &compared)
{
  if(followingCharactersLook == compared.followingCharactersLook)
  return true;
  
  return false;
}

