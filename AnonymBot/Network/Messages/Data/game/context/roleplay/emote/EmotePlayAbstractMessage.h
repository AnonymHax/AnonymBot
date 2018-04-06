#ifndef EMOTEPLAYABSTRACTMESSAGE_H
#define EMOTEPLAYABSTRACTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class EmotePlayAbstractMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_EmotePlayAbstractMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_EmotePlayAbstractMessage(Reader *param1);
  EmotePlayAbstractMessage();

  uint emoteId;
  double emoteStartTime;
};

#endif // EMOTEPLAYABSTRACTMESSAGE_H