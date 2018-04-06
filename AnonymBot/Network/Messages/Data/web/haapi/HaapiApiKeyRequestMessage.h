#ifndef HAAPIAPIKEYREQUESTMESSAGE_H
#define HAAPIAPIKEYREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class HaapiApiKeyRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_HaapiApiKeyRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_HaapiApiKeyRequestMessage(Reader *param1);
  HaapiApiKeyRequestMessage();

  uint keyType;
};

#endif // HAAPIAPIKEYREQUESTMESSAGE_H