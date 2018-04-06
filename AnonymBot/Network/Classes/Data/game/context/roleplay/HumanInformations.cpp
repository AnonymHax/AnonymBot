#include "HumanInformations.h"

void HumanInformations::serialize(Writer *param1)
{
  this->serializeAs_HumanInformations(param1);
}

void HumanInformations::serializeAs_HumanInformations(Writer *param1)
{
  this->restrictions.serializeAs_ActorRestrictionsInformations(param1);
  param1->writeBool(this->sex);
  param1->writeShort((short)this->options.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->options.size())
  {
    param1->writeShort((short)qSharedPointerCast<HumanOption>(this->options[_loc2_])->getTypes().last());
    qSharedPointerCast<HumanOption>(this->options[_loc2_])->serialize(param1);
    _loc2_++;
  }
}

void HumanInformations::deserialize(Reader *param1)
{
  this->deserializeAs_HumanInformations(param1);
}

void HumanInformations::deserializeAs_HumanInformations(Reader *param1)
{
  uint _loc4_ = 0;
  QSharedPointer<HumanOption> _loc5_ ;
  this->restrictions = ActorRestrictionsInformations();
  this->restrictions.deserialize(param1);
  this->sex = param1->readBool();
  uint _loc2_ = param1->readUShort();
  uint _loc3_ = 0;
  while(_loc3_ < _loc2_)
  {
    _loc4_ = param1->readUShort();
    _loc5_ = qSharedPointerCast<HumanOption>(ClassManagerSingleton::get()->getClass(_loc4_));
    _loc5_->deserialize(param1);
    this->options.append(_loc5_);
    _loc3_++;
  }
}

HumanInformations::HumanInformations()
{
  m_types<<ClassEnum::HUMANINFORMATIONS;
}

bool HumanInformations::operator==(const HumanInformations &compared)
{
  if(restrictions == compared.restrictions)
  if(sex == compared.sex)
  if(options == compared.options)
  return true;
  
  return false;
}

