#ifndef INVENTORYWEIGHTMESSAGE_H
#define INVENTORYWEIGHTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class InventoryWeightMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_InventoryWeightMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_InventoryWeightMessage(Reader *param1);
  InventoryWeightMessage();

  uint weight;
  uint weightMax;
};

#endif // INVENTORYWEIGHTMESSAGE_H