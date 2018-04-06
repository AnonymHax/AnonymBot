#ifndef INVENTORYPRESETUSEMESSAGE_H
#define INVENTORYPRESETUSEMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class InventoryPresetUseMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_InventoryPresetUseMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_InventoryPresetUseMessage(Reader *param1);
  InventoryPresetUseMessage();

  uint presetId;
};

#endif // INVENTORYPRESETUSEMESSAGE_H