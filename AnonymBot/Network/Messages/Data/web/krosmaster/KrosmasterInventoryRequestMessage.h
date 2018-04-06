#ifndef KROSMASTERINVENTORYREQUESTMESSAGE_H
#define KROSMASTERINVENTORYREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class KrosmasterInventoryRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_KrosmasterInventoryRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_KrosmasterInventoryRequestMessage(Reader *param1);
  KrosmasterInventoryRequestMessage();
};

#endif // KROSMASTERINVENTORYREQUESTMESSAGE_H