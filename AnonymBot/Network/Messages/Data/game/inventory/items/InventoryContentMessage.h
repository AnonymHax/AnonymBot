#ifndef INVENTORYCONTENTMESSAGE_H
#define INVENTORYCONTENTMESSAGE_H

#include "Network/Classes/Data/game/data/items/ObjectItem.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/data/items/ObjectItem.h"

class InventoryContentMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_InventoryContentMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_InventoryContentMessage(Reader *param1);
  InventoryContentMessage();

  QList<QSharedPointer<ObjectItem>> objects;
  uint kamas;
};

#endif // INVENTORYCONTENTMESSAGE_H