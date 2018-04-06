#ifndef EMOTEPLAYMESSAGE_H
#define EMOTEPLAYMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/context/roleplay/emote/EmotePlayAbstractMessage.h"

class EmotePlayMessage : public EmotePlayAbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_EmotePlayMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_EmotePlayMessage(Reader *param1);
  EmotePlayMessage();

  double actorId;
  uint accountId;
};

#endif // EMOTEPLAYMESSAGE_H