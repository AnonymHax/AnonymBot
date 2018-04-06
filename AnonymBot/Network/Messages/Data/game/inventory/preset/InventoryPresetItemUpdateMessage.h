#ifndef INVENTORYPRESETITEMUPDATEMESSAGE_H
#define INVENTORYPRESETITEMUPDATEMESSAGE_H

#include "Network/Classes/Data/game/inventory/preset/PresetItem.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/inventory/preset/PresetItem.h"

class InventoryPresetItemUpdateMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_InventoryPresetItemUpdateMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_InventoryPresetItemUpdateMessage(Reader *param1);
  InventoryPresetItemUpdateMessage();

  uint presetId;
  PresetItem presetItem;
};

#endif // INVENTORYPRESETITEMUPDATEMESSAGE_H