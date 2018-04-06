#ifndef STORAGEINVENTORYCONTENTMESSAGE_H
#define STORAGEINVENTORYCONTENTMESSAGE_H

#include "Network/Classes/Data/game/data/items/ObjectItem.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/inventory/items/InventoryContentMessage.h"
#include "Network/Classes/Data/game/data/items/ObjectItem.h"

class StorageInventoryContentMessage : public InventoryContentMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_StorageInventoryContentMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_StorageInventoryContentMessage(Reader *param1);
  StorageInventoryContentMessage();
};

#endif // STORAGEINVENTORYCONTENTMESSAGE_H