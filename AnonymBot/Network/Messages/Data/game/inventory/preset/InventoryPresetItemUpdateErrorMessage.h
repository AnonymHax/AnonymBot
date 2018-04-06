#ifndef INVENTORYPRESETITEMUPDATEERRORMESSAGE_H
#define INVENTORYPRESETITEMUPDATEERRORMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class InventoryPresetItemUpdateErrorMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_InventoryPresetItemUpdateErrorMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_InventoryPresetItemUpdateErrorMessage(Reader *param1);
  InventoryPresetItemUpdateErrorMessage();

  uint code;
};

#endif // INVENTORYPRESETITEMUPDATEERRORMESSAGE_H