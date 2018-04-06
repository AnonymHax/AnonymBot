#ifndef LIVINGOBJECTCHANGESKINREQUESTMESSAGE_H
#define LIVINGOBJECTCHANGESKINREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class LivingObjectChangeSkinRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_LivingObjectChangeSkinRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_LivingObjectChangeSkinRequestMessage(Reader *param1);
  LivingObjectChangeSkinRequestMessage();

  uint livingUID;
  uint livingPosition;
  uint skinId;
};

#endif // LIVINGOBJECTCHANGESKINREQUESTMESSAGE_H