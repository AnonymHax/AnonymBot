#ifndef INVENTORYPRESETSAVEMESSAGE_H
#define INVENTORYPRESETSAVEMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class InventoryPresetSaveMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_InventoryPresetSaveMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_InventoryPresetSaveMessage(Reader *param1);
  InventoryPresetSaveMessage();

  uint presetId;
  uint symbolId;
  bool saveEquipment;
};

#endif // INVENTORYPRESETSAVEMESSAGE_H