#include "StorageKamasUpdateMessage.h"

void StorageKamasUpdateMessage::serialize(Writer *param1)
{
  this->serializeAs_StorageKamasUpdateMessage(param1);
}

void StorageKamasUpdateMessage::serializeAs_StorageKamasUpdateMessage(Writer *param1)
{
  param1->writeInt((int)this->kamasTotal);
}

void StorageKamasUpdateMessage::deserialize(Reader *param1)
{
  this->deserializeAs_StorageKamasUpdateMessage(param1);
}

void StorageKamasUpdateMessage::deserializeAs_StorageKamasUpdateMessage(Reader *param1)
{
  this->kamasTotal = param1->readInt();
}

StorageKamasUpdateMessage::StorageKamasUpdateMessage()
{
  m_type = MessageEnum::STORAGEKAMASUPDATEMESSAGE;
}

