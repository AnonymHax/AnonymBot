#include "StorageObjectUpdateMessage.h"

void StorageObjectUpdateMessage::serialize(Writer *param1)
{
  this->serializeAs_StorageObjectUpdateMessage(param1);
}

void StorageObjectUpdateMessage::serializeAs_StorageObjectUpdateMessage(Writer *param1)
{
  this->object->serializeAs_ObjectItem(param1);
}

void StorageObjectUpdateMessage::deserialize(Reader *param1)
{
  this->deserializeAs_StorageObjectUpdateMessage(param1);
}

void StorageObjectUpdateMessage::deserializeAs_StorageObjectUpdateMessage(Reader *param1)
{
  this->object = QSharedPointer<ObjectItem>(new ObjectItem() );
  this->object->deserialize(param1);
}

StorageObjectUpdateMessage::StorageObjectUpdateMessage()
{
  m_type = MessageEnum::STORAGEOBJECTUPDATEMESSAGE;
}

