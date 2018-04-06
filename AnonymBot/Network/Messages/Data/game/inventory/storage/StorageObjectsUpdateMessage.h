#ifndef STORAGEOBJECTSUPDATEMESSAGE_H
#define STORAGEOBJECTSUPDATEMESSAGE_H

#include "Network/Classes/Data/game/data/items/ObjectItem.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/data/items/ObjectItem.h"

class StorageObjectsUpdateMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_StorageObjectsUpdateMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_StorageObjectsUpdateMessage(Reader *param1);
  StorageObjectsUpdateMessage();

  QList<QSharedPointer<ObjectItem>> objectList;
};

#endif // STORAGEOBJECTSUPDATEMESSAGE_H