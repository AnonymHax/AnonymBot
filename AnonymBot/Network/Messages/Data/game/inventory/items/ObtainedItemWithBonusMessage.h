#ifndef OBTAINEDITEMWITHBONUSMESSAGE_H
#define OBTAINEDITEMWITHBONUSMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/inventory/items/ObtainedItemMessage.h"

class ObtainedItemWithBonusMessage : public ObtainedItemMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ObtainedItemWithBonusMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ObtainedItemWithBonusMessage(Reader *param1);
  ObtainedItemWithBonusMessage();

  uint bonusQuantity;
};

#endif // OBTAINEDITEMWITHBONUSMESSAGE_H