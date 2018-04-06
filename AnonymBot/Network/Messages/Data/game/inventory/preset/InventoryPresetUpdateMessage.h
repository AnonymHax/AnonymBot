#ifndef INVENTORYPRESETUPDATEMESSAGE_H
#define INVENTORYPRESETUPDATEMESSAGE_H

#include "Network/Classes/Data/game/inventory/preset/Preset.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/inventory/preset/Preset.h"

class InventoryPresetUpdateMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_InventoryPresetUpdateMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_InventoryPresetUpdateMessage(Reader *param1);
  InventoryPresetUpdateMessage();

  Preset preset;
};

#endif // INVENTORYPRESETUPDATEMESSAGE_H