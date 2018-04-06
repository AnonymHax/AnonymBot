#ifndef INVENTORYPRESETUSERESULTMESSAGE_H
#define INVENTORYPRESETUSERESULTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class InventoryPresetUseResultMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_InventoryPresetUseResultMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_InventoryPresetUseResultMessage(Reader *param1);
  InventoryPresetUseResultMessage();

  uint presetId;
  uint code;
  QList<uint> unlinkedPosition;
};

#endif // INVENTORYPRESETUSERESULTMESSAGE_H