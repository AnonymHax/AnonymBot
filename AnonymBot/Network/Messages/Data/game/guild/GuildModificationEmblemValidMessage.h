#ifndef GUILDMODIFICATIONEMBLEMVALIDMESSAGE_H
#define GUILDMODIFICATIONEMBLEMVALIDMESSAGE_H

#include "Network/Classes/Data/game/guild/GuildEmblem.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/guild/GuildEmblem.h"

class GuildModificationEmblemValidMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GuildModificationEmblemValidMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GuildModificationEmblemValidMessage(Reader *param1);
  GuildModificationEmblemValidMessage();

  GuildEmblem guildEmblem;
};

#endif // GUILDMODIFICATIONEMBLEMVALIDMESSAGE_H