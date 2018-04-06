#ifndef INVENTORYCONTENTANDPRESETMESSAGE_H
#define INVENTORYCONTENTANDPRESETMESSAGE_H

#include "Network/Classes/Data/game/inventory/preset/Preset.h"
#include "Network/Classes/Data/game/inventory/preset/IdolsPreset.h"
#include "Network/Classes/Data/game/data/items/ObjectItem.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/inventory/items/InventoryContentMessage.h"
#include "Network/Classes/Data/game/inventory/preset/Preset.h"
#include "Network/Classes/Data/game/inventory/preset/IdolsPreset.h"
#include "Network/Classes/Data/game/data/items/ObjectItem.h"

class InventoryContentAndPresetMessage : public InventoryContentMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_InventoryContentAndPresetMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_InventoryContentAndPresetMessage(Reader *param1);
  InventoryContentAndPresetMessage();

  QList<Preset> presets;
  QList<IdolsPreset> idolsPresets;
};

#endif // INVENTORYCONTENTANDPRESETMESSAGE_H