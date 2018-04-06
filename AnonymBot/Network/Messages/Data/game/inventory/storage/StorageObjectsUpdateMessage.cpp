#include "StorageObjectsUpdateMessage.h"

void StorageObjectsUpdateMessage::serialize(Writer *param1)
{
  this->serializeAs_StorageObjectsUpdateMessage(param1);
}

void StorageObjectsUpdateMessage::serializeAs_StorageObjectsUpdateMessage(Writer *param1)
{
  param1->writeShort((short)this->objectList.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->objectList.size())
  {
    qSharedPointerCast<ObjectItem>(this->objectList[_loc2_])->serializeAs_ObjectItem(param1);
    _loc2_++;
  }
}

void StorageObjectsUpdateMessage::deserialize(Reader *param1)
{
  this->deserializeAs_StorageObjectsUpdateMessage(param1);
}

void StorageObjectsUpdateMessage::deserializeAs_StorageObjectsUpdateMessage(Reader *param1)
{
  QSharedPointer<ObjectItem> _loc4_ ;
  uint _loc2_ = param1->readUShort();
  uint _loc3_ = 0;
  while(_loc3_ < _loc2_)
  {
    _loc4_ = QSharedPointer<ObjectItem>(new ObjectItem() );
    _loc4_->deserialize(param1);
    this->objectList.append(_loc4_);
    _loc3_++;
  }
}

StorageObjectsUpdateMessage::StorageObjectsUpdateMessage()
{
  m_type = MessageEnum::STORAGEOBJECTSUPDATEMESSAGE;
}

