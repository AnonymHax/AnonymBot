#include "ObjectsQuantityMessage.h"

void ObjectsQuantityMessage::serialize(Writer *param1)
{
  this->serializeAs_ObjectsQuantityMessage(param1);
}

void ObjectsQuantityMessage::serializeAs_ObjectsQuantityMessage(Writer *param1)
{
  param1->writeShort((short)this->objectsUIDAndQty.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->objectsUIDAndQty.size())
  {
    (this->objectsUIDAndQty[_loc2_]).serializeAs_ObjectItemQuantity(param1);
    _loc2_++;
  }
}

void ObjectsQuantityMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ObjectsQuantityMessage(param1);
}

void ObjectsQuantityMessage::deserializeAs_ObjectsQuantityMessage(Reader *param1)
{
  ObjectItemQuantity _loc4_ ;
  uint _loc2_ = param1->readUShort();
  uint _loc3_ = 0;
  while(_loc3_ < _loc2_)
  {
    _loc4_ = ObjectItemQuantity();
    _loc4_.deserialize(param1);
    this->objectsUIDAndQty.append(_loc4_);
    _loc3_++;
  }
}

ObjectsQuantityMessage::ObjectsQuantityMessage()
{
  m_type = MessageEnum::OBJECTSQUANTITYMESSAGE;
}

