#ifndef EMOTEPLAYMASSIVEMESSAGE_H
#define EMOTEPLAYMASSIVEMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/context/roleplay/emote/EmotePlayAbstractMessage.h"

class EmotePlayMassiveMessage : public EmotePlayAbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_EmotePlayMassiveMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_EmotePlayMassiveMessage(Reader *param1);
  EmotePlayMassiveMessage();

  QList<double> actorIds;
};

#endif // EMOTEPLAYMASSIVEMESSAGE_H