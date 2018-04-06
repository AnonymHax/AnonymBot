#include "ObjectsDeletedMessage.h"

void ObjectsDeletedMessage::serialize(Writer *param1)
{
  this->serializeAs_ObjectsDeletedMessage(param1);
}

void ObjectsDeletedMessage::serializeAs_ObjectsDeletedMessage(Writer *param1)
{
  param1->writeShort((short)this->objectUID.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->objectUID.size())
  {
    if(this->objectUID[_loc2_] < 0)
    {
      qDebug()<<"ERREUR - ObjectsDeletedMessage -"<<"Forbidden value (" << this->objectUID[_loc2_] << ") on element 1 (starting at 1) of objectUID.";
    }
    else
    {
      param1->writeVarInt((int)this->objectUID[_loc2_]);
      _loc2_++;
      continue;
    }
  }
}

void ObjectsDeletedMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ObjectsDeletedMessage(param1);
}

void ObjectsDeletedMessage::deserializeAs_ObjectsDeletedMessage(Reader *param1)
{
  uint _loc4_ = 0;
  uint _loc2_ = param1->readUShort();
  uint _loc3_ = 0;
  while(_loc3_ < _loc2_)
  {
    _loc4_ = param1->readVarUhInt();
    if(_loc4_ < 0)
    {
      qDebug()<<"ERREUR - ObjectsDeletedMessage -"<<"Forbidden value (" << _loc4_ << ") on elements of objectUID.";
    }
    else
    {
      this->objectUID.append(_loc4_);
      _loc3_++;
      continue;
    }
  }
}

ObjectsDeletedMessage::ObjectsDeletedMessage()
{
  m_type = MessageEnum::OBJECTSDELETEDMESSAGE;
}

