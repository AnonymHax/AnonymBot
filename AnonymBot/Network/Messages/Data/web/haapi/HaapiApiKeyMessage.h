#ifndef HAAPIAPIKEYMESSAGE_H
#define HAAPIAPIKEYMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class HaapiApiKeyMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_HaapiApiKeyMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_HaapiApiKeyMessage(Reader *param1);
  HaapiApiKeyMessage();

  uint returnType;
  uint keyType;
  QString token;
};

#endif // HAAPIAPIKEYMESSAGE_H