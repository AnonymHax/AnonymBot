#ifndef STORAGEKAMASUPDATEMESSAGE_H
#define STORAGEKAMASUPDATEMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class StorageKamasUpdateMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_StorageKamasUpdateMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_StorageKamasUpdateMessage(Reader *param1);
  StorageKamasUpdateMessage();

  int kamasTotal;
};

#endif // STORAGEKAMASUPDATEMESSAGE_H