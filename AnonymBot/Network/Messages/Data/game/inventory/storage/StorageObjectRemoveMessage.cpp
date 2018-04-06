#include "StorageObjectRemoveMessage.h"

void StorageObjectRemoveMessage::serialize(Writer *param1)
{
  this->serializeAs_StorageObjectRemoveMessage(param1);
}

void StorageObjectRemoveMessage::serializeAs_StorageObjectRemoveMessage(Writer *param1)
{
  if(this->objectUID < 0)
  {
    qDebug()<<"ERREUR - StorageObjectRemoveMessage -"<<"Forbidden value (" << this->objectUID << ") on element objectUID.";
  }
  else
  {
    param1->writeVarInt((int)this->objectUID);
    return;
  }
}

void StorageObjectRemoveMessage::deserialize(Reader *param1)
{
  this->deserializeAs_StorageObjectRemoveMessage(param1);
}

void StorageObjectRemoveMessage::deserializeAs_StorageObjectRemoveMessage(Reader *param1)
{
  this->objectUID = param1->readVarUhInt();
  if(this->objectUID < 0)
  {
    qDebug()<<"ERREUR - StorageObjectRemoveMessage -"<<"Forbidden value (" << this->objectUID << ") on element of StorageObjectRemoveMessage.objectUID.";
  }
  else
  {
    return;
  }
}

StorageObjectRemoveMessage::StorageObjectRemoveMessage()
{
  m_type = MessageEnum::STORAGEOBJECTREMOVEMESSAGE;
}

