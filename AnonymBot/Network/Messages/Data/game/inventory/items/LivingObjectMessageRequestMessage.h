#ifndef LIVINGOBJECTMESSAGEREQUESTMESSAGE_H
#define LIVINGOBJECTMESSAGEREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class LivingObjectMessageRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_LivingObjectMessageRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_LivingObjectMessageRequestMessage(Reader *param1);
  LivingObjectMessageRequestMessage();

  uint msgId;
  QList<QString> parameters;
  uint livingObject;
};

#endif // LIVINGOBJECTMESSAGEREQUESTMESSAGE_H