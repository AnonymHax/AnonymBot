#include "EntityLook.h"

void EntityLook::serialize(Writer *param1)
{
  this->serializeAs_EntityLook(param1);
}

void EntityLook::serializeAs_EntityLook(Writer *param1)
{
  if(this->bonesId < 0)
  {
    qDebug()<<"ERREUR - EntityLook -"<<"Forbidden value (" << this->bonesId << ") on element bonesId.";
  }
  else
  {
    param1->writeVarShort((int)this->bonesId);
    param1->writeShort((short)this->skins.size());
    uint _loc2_ = 0;
    while(_loc2_ < this->skins.size())
    {
      if(this->skins[_loc2_] < 0)
      {
        qDebug()<<"ERREUR - EntityLook -"<<"Forbidden value (" << this->skins[_loc2_] << ") on element 2 (starting at 1) of skins.";
      }
      else
      {
        param1->writeVarShort((int)this->skins[_loc2_]);
        _loc2_++;
        continue;
      }
    }
    param1->writeShort((short)this->indexedColors.size());
    uint _loc3_ = 0;
    while(_loc3_ < this->indexedColors.size())
    {
      param1->writeInt((int)this->indexedColors[_loc3_]);
      _loc3_++;
    }
    param1->writeShort((short)this->scales.size());
    uint _loc4_ = 0;
    while(_loc4_ < this->scales.size())
    {
      param1->writeVarShort((int)this->scales[_loc4_]);
      _loc4_++;
    }
    param1->writeShort((short)this->subentities.size());
    uint _loc5_ = 0;
    while(_loc5_ < this->subentities.size())
    {
      qSharedPointerCast<SubEntity>(this->subentities[_loc5_])->serializeAs_SubEntity(param1);
      _loc5_++;
    }
    return;
  }
}

void EntityLook::deserialize(Reader *param1)
{
  this->deserializeAs_EntityLook(param1);
}

void EntityLook::deserializeAs_EntityLook(Reader *param1)
{
  uint _loc10_ = 0;
  auto _loc11_ = 0;
  auto _loc12_ = 0;
  QSharedPointer<SubEntity> _loc13_ ;
  this->bonesId = param1->readVarUhShort();
  if(this->bonesId < 0)
  {
    qDebug()<<"ERREUR - EntityLook -"<<"Forbidden value (" << this->bonesId << ") on element of EntityLook.bonesId.";
  }
  else
  {
    uint _loc2_ = param1->readUShort();
    uint _loc3_ = 0;
    while(_loc3_ < _loc2_)
    {
      _loc10_ = param1->readVarUhShort();
      if(_loc10_ < 0)
      {
        qDebug()<<"ERREUR - EntityLook -"<<"Forbidden value (" << _loc10_ << ") on elements of skins.";
      }
      else
      {
        this->skins.append(_loc10_);
        _loc3_++;
        continue;
      }
    }
    uint _loc4_ = param1->readUShort();
    uint _loc5_ = 0;
    while(_loc5_ < _loc4_)
    {
      _loc11_ = param1->readInt();
      this->indexedColors.append(_loc11_);
      _loc5_++;
    }
    uint _loc6_ = param1->readUShort();
    uint _loc7_ = 0;
    while(_loc7_ < _loc6_)
    {
      _loc12_ = param1->readVarShort();
      this->scales.append(_loc12_);
      _loc7_++;
    }
    uint _loc8_ = param1->readUShort();
    uint _loc9_ = 0;
    while(_loc9_ < _loc8_)
    {
      _loc13_ = QSharedPointer<SubEntity>(new SubEntity() );
      _loc13_->deserialize(param1);
      this->subentities.append(_loc13_);
      _loc9_++;
    }
    return;
  }
}

EntityLook::EntityLook()
{
  m_types<<ClassEnum::ENTITYLOOK;
}

bool EntityLook::operator==(const EntityLook &compared)
{
  if(bonesId == compared.bonesId)
  if(skins == compared.skins)
  if(indexedColors == compared.indexedColors)
  if(scales == compared.scales)
  if(subentities == compared.subentities)
  return true;
  
  return false;
}

