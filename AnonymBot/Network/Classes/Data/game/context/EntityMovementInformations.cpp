#include "EntityMovementInformations.h"

void EntityMovementInformations::serialize(Writer *param1)
{
  this->serializeAs_EntityMovementInformations(param1);
}

void EntityMovementInformations::serializeAs_EntityMovementInformations(Writer *param1)
{
  param1->writeInt((int)this->id);
  param1->writeShort((short)this->steps.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->steps.size())
  {
    param1->writeByte(this->steps[_loc2_]);
    _loc2_++;
  }
}

void EntityMovementInformations::deserialize(Reader *param1)
{
  this->deserializeAs_EntityMovementInformations(param1);
}

void EntityMovementInformations::deserializeAs_EntityMovementInformations(Reader *param1)
{
  auto _loc4_ = 0;
  this->id = param1->readInt();
  uint _loc2_ = param1->readUShort();
  uint _loc3_ = 0;
  while(_loc3_ < _loc2_)
  {
    _loc4_ = param1->readByte();
    this->steps.append(_loc4_);
    _loc3_++;
  }
}

EntityMovementInformations::EntityMovementInformations()
{
  m_types<<ClassEnum::ENTITYMOVEMENTINFORMATIONS;
}

bool EntityMovementInformations::operator==(const EntityMovementInformations &compared)
{
  if(id == compared.id)
  if(steps == compared.steps)
  return true;
  
  return false;
}

