#ifndef STORAGEOBJECTREMOVEMESSAGE_H
#define STORAGEOBJECTREMOVEMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class StorageObjectRemoveMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_StorageObjectRemoveMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_StorageObjectRemoveMessage(Reader *param1);
  StorageObjectRemoveMessage();

  uint objectUID;
};

#endif // STORAGEOBJECTREMOVEMESSAGE_H