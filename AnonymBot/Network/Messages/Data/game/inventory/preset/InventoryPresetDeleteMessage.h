#ifndef INVENTORYPRESETDELETEMESSAGE_H
#define INVENTORYPRESETDELETEMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class InventoryPresetDeleteMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_InventoryPresetDeleteMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_InventoryPresetDeleteMessage(Reader *param1);
  InventoryPresetDeleteMessage();

  uint presetId;
};

#endif // INVENTORYPRESETDELETEMESSAGE_H