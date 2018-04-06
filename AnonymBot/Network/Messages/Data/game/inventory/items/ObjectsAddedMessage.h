#ifndef OBJECTSADDEDMESSAGE_H
#define OBJECTSADDEDMESSAGE_H

#include "Network/Classes/Data/game/data/items/ObjectItem.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/data/items/ObjectItem.h"

class ObjectsAddedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ObjectsAddedMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ObjectsAddedMessage(Reader *param1);
  ObjectsAddedMessage();

  QList<QSharedPointer<ObjectItem>> object;
};

#endif // OBJECTSADDEDMESSAGE_H