#ifndef OBJECTUSEONCHARACTERMESSAGE_H
#define OBJECTUSEONCHARACTERMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/inventory/items/ObjectUseMessage.h"

class ObjectUseOnCharacterMessage : public ObjectUseMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ObjectUseOnCharacterMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ObjectUseOnCharacterMessage(Reader *param1);
  ObjectUseOnCharacterMessage();

  double characterId;
};

#endif // OBJECTUSEONCHARACTERMESSAGE_H