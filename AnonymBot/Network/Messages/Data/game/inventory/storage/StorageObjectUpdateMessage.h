#ifndef STORAGEOBJECTUPDATEMESSAGE_H
#define STORAGEOBJECTUPDATEMESSAGE_H

#include "Network/Classes/Data/game/data/items/ObjectItem.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/data/items/ObjectItem.h"

class StorageObjectUpdateMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_StorageObjectUpdateMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_StorageObjectUpdateMessage(Reader *param1);
  StorageObjectUpdateMessage();

  QSharedPointer<ObjectItem> object;
};

#endif // STORAGEOBJECTUPDATEMESSAGE_H