#include "ObjectItemMinimalInformation.h"

void ObjectItemMinimalInformation::serialize(Writer *param1)
{
  this->serializeAs_ObjectItemMinimalInformation(param1);
}

void ObjectItemMinimalInformation::serializeAs_ObjectItemMinimalInformation(Writer *param1)
{
  Item::serializeAs_Item(param1);
  if(this->objectGID < 0)
  {
    qDebug()<<"ERREUR - ObjectItemMinimalInformation -"<<"Forbidden value (" << this->objectGID << ") on element objectGID.";
  }
  else
  {
    param1->writeVarShort((int)this->objectGID);
    param1->writeShort((short)this->effects.size());
    uint _loc2_ = 0;
    while(_loc2_ < this->effects.size())
    {
      param1->writeShort((short)qSharedPointerCast<ObjectEffect>(this->effects[_loc2_])->getTypes().last());
      qSharedPointerCast<ObjectEffect>(this->effects[_loc2_])->serialize(param1);
      _loc2_++;
    }
    return;
  }
}

void ObjectItemMinimalInformation::deserialize(Reader *param1)
{
  this->deserializeAs_ObjectItemMinimalInformation(param1);
}

void ObjectItemMinimalInformation::deserializeAs_ObjectItemMinimalInformation(Reader *param1)
{
  uint _loc4_ = 0;
  QSharedPointer<ObjectEffect> _loc5_ ;
  Item::deserialize(param1);
  this->objectGID = param1->readVarUhShort();
  if(this->objectGID < 0)
  {
    qDebug()<<"ERREUR - ObjectItemMinimalInformation -"<<"Forbidden value (" << this->objectGID << ") on element of ObjectItemMinimalInformation.objectGID.";
  }
  else
  {
    uint _loc2_ = param1->readUShort();
    uint _loc3_ = 0;
    while(_loc3_ < _loc2_)
    {
      _loc4_ = param1->readUShort();
      _loc5_ = qSharedPointerCast<ObjectEffect>(ClassManagerSingleton::get()->getClass(_loc4_));
      _loc5_->deserialize(param1);
      this->effects.append(_loc5_);
      _loc3_++;
    }
    return;
  }
}

ObjectItemMinimalInformation::ObjectItemMinimalInformation()
{
  m_types<<ClassEnum::OBJECTITEMMINIMALINFORMATION;
}

bool ObjectItemMinimalInformation::operator==(const ObjectItemMinimalInformation &compared)
{
  if(objectGID == compared.objectGID)
  if(effects == compared.effects)
  return true;
  
  return false;
}

