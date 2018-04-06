#ifndef OBJECTUSEONCELLMESSAGE_H
#define OBJECTUSEONCELLMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/inventory/items/ObjectUseMessage.h"

class ObjectUseOnCellMessage : public ObjectUseMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ObjectUseOnCellMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ObjectUseOnCellMessage(Reader *param1);
  ObjectUseOnCellMessage();

  uint cells;
};

#endif // OBJECTUSEONCELLMESSAGE_H