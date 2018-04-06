#ifndef LIVINGOBJECTMESSAGEMESSAGE_H
#define LIVINGOBJECTMESSAGEMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class LivingObjectMessageMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_LivingObjectMessageMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_LivingObjectMessageMessage(Reader *param1);
  LivingObjectMessageMessage();

  uint msgId;
  uint timeStamp;
  QString owner;
  uint objectGenericId;
};

#endif // LIVINGOBJECTMESSAGEMESSAGE_H