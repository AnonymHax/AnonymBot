#ifndef OBJECTMODIFIEDMESSAGE_H
#define OBJECTMODIFIEDMESSAGE_H

#include "Network/Classes/Data/game/data/items/ObjectItem.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/data/items/ObjectItem.h"

class ObjectModifiedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ObjectModifiedMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ObjectModifiedMessage(Reader *param1);
  ObjectModifiedMessage();

  QSharedPointer<ObjectItem> object;
};

#endif // OBJECTMODIFIEDMESSAGE_H