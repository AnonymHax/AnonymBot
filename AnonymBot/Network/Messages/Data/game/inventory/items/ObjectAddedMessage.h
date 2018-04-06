#ifndef OBJECTADDEDMESSAGE_H
#define OBJECTADDEDMESSAGE_H

#include "Network/Classes/Data/game/data/items/ObjectItem.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/data/items/ObjectItem.h"

class ObjectAddedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ObjectAddedMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ObjectAddedMessage(Reader *param1);
  ObjectAddedMessage();

  QSharedPointer<ObjectItem> object;
};

#endif // OBJECTADDEDMESSAGE_H