#ifndef EMOTEADDMESSAGE_H
#define EMOTEADDMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class EmoteAddMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_EmoteAddMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_EmoteAddMessage(Reader *param1);
  EmoteAddMessage();

  uint emoteId;
};

#endif // EMOTEADDMESSAGE_H