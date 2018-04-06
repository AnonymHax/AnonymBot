#ifndef INVENTORYPRESETSAVERESULTMESSAGE_H
#define INVENTORYPRESETSAVERESULTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class InventoryPresetSaveResultMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_InventoryPresetSaveResultMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_InventoryPresetSaveResultMessage(Reader *param1);
  InventoryPresetSaveResultMessage();

  uint presetId;
  uint code;
};

#endif // INVENTORYPRESETSAVERESULTMESSAGE_H