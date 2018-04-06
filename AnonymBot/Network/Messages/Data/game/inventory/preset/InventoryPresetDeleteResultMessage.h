#ifndef INVENTORYPRESETDELETERESULTMESSAGE_H
#define INVENTORYPRESETDELETERESULTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class InventoryPresetDeleteResultMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_InventoryPresetDeleteResultMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_InventoryPresetDeleteResultMessage(Reader *param1);
  InventoryPresetDeleteResultMessage();

  uint presetId;
  uint code;
};

#endif // INVENTORYPRESETDELETERESULTMESSAGE_H