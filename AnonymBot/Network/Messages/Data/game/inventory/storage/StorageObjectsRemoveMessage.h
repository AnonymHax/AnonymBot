#ifndef STORAGEOBJECTSREMOVEMESSAGE_H
#define STORAGEOBJECTSREMOVEMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class StorageObjectsRemoveMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_StorageObjectsRemoveMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_StorageObjectsRemoveMessage(Reader *param1);
  StorageObjectsRemoveMessage();

  QList<uint> objectUIDList;
};

#endif // STORAGEOBJECTSREMOVEMESSAGE_H