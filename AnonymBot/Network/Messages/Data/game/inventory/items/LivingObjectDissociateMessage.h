#ifndef LIVINGOBJECTDISSOCIATEMESSAGE_H
#define LIVINGOBJECTDISSOCIATEMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class LivingObjectDissociateMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_LivingObjectDissociateMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_LivingObjectDissociateMessage(Reader *param1);
  LivingObjectDissociateMessage();

  uint livingUID;
  uint livingPosition;
};

#endif // LIVINGOBJECTDISSOCIATEMESSAGE_H