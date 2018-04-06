#ifndef OBJECTSQUANTITYMESSAGE_H
#define OBJECTSQUANTITYMESSAGE_H

#include "Network/Classes/Data/game/data/items/ObjectItemQuantity.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/data/items/ObjectItemQuantity.h"

class ObjectsQuantityMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ObjectsQuantityMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ObjectsQuantityMessage(Reader *param1);
  ObjectsQuantityMessage();

  QList<ObjectItemQuantity> objectsUIDAndQty;
};

#endif // OBJECTSQUANTITYMESSAGE_H