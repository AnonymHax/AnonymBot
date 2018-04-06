#include "StorageObjectsRemoveMessage.h"

void StorageObjectsRemoveMessage::serialize(Writer *param1)
{
  this->serializeAs_StorageObjectsRemoveMessage(param1);
}

void StorageObjectsRemoveMessage::serializeAs_StorageObjectsRemoveMessage(Writer *param1)
{
  param1->writeShort((short)this->objectUIDList.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->objectUIDList.size())
  {
    if(this->objectUIDList[_loc2_] < 0)
    {
      qDebug()<<"ERREUR - StorageObjectsRemoveMessage -"<<"Forbidden value (" << this->objectUIDList[_loc2_] << ") on element 1 (starting at 1) of objectUIDList.";
    }
    else
    {
      param1->writeVarInt((int)this->objectUIDList[_loc2_]);
      _loc2_++;
      continue;
    }
  }
}

void StorageObjectsRemoveMessage::deserialize(Reader *param1)
{
  this->deserializeAs_StorageObjectsRemoveMessage(param1);
}

void StorageObjectsRemoveMessage::deserializeAs_StorageObjectsRemoveMessage(Reader *param1)
{
  uint _loc4_ = 0;
  uint _loc2_ = param1->readUShort();
  uint _loc3_ = 0;
  while(_loc3_ < _loc2_)
  {
    _loc4_ = param1->readVarUhInt();
    if(_loc4_ < 0)
    {
      qDebug()<<"ERREUR - StorageObjectsRemoveMessage -"<<"Forbidden value (" << _loc4_ << ") on elements of objectUIDList.";
    }
    else
    {
      this->objectUIDList.append(_loc4_);
      _loc3_++;
      continue;
    }
  }
}

StorageObjectsRemoveMessage::StorageObjectsRemoveMessage()
{
  m_type = MessageEnum::STORAGEOBJECTSREMOVEMESSAGE;
}

