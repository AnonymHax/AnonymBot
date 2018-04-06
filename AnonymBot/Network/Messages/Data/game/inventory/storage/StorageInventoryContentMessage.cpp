#include "StorageInventoryContentMessage.h"

void StorageInventoryContentMessage::serialize(Writer *param1)
{
  this->serializeAs_StorageInventoryContentMessage(param1);
}

void StorageInventoryContentMessage::serializeAs_StorageInventoryContentMessage(Writer *param1)
{
  InventoryContentMessage::serializeAs_InventoryContentMessage(param1);
}

void StorageInventoryContentMessage::deserialize(Reader *param1)
{
  this->deserializeAs_StorageInventoryContentMessage(param1);
}

void StorageInventoryContentMessage::deserializeAs_StorageInventoryContentMessage(Reader *param1)
{
  InventoryContentMessage::deserialize(param1);
}

StorageInventoryContentMessage::StorageInventoryContentMessage()
{
  m_type = MessageEnum::STORAGEINVENTORYCONTENTMESSAGE;
}

