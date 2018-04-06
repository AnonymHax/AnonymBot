#ifndef INVENTORYPRESETITEMUPDATEREQUESTMESSAGE_H
#define INVENTORYPRESETITEMUPDATEREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class InventoryPresetItemUpdateRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_InventoryPresetItemUpdateRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_InventoryPresetItemUpdateRequestMessage(Reader *param1);
  InventoryPresetItemUpdateRequestMessage();

  uint presetId;
  uint position;
  uint objUid;
};

#endif // INVENTORYPRESETITEMUPDATEREQUESTMESSAGE_H