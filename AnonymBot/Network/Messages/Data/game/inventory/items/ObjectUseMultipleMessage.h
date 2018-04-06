#ifndef OBJECTUSEMULTIPLEMESSAGE_H
#define OBJECTUSEMULTIPLEMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/inventory/items/ObjectUseMessage.h"

class ObjectUseMultipleMessage : public ObjectUseMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ObjectUseMultipleMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ObjectUseMultipleMessage(Reader *param1);
  ObjectUseMultipleMessage();

  uint quantity;
};

#endif // OBJECTUSEMULTIPLEMESSAGE_H