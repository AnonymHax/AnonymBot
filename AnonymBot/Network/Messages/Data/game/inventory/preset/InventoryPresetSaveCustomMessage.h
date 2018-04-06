#ifndef INVENTORYPRESETSAVECUSTOMMESSAGE_H
#define INVENTORYPRESETSAVECUSTOMMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class InventoryPresetSaveCustomMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_InventoryPresetSaveCustomMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_InventoryPresetSaveCustomMessage(Reader *param1);
  InventoryPresetSaveCustomMessage();

  uint presetId;
  uint symbolId;
  QList<uint> itemsPositions;
  QList<uint> itemsUids;
};

#endif // INVENTORYPRESETSAVECUSTOMMESSAGE_H