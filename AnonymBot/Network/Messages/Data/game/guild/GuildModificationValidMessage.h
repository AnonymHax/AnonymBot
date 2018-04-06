#ifndef GUILDMODIFICATIONVALIDMESSAGE_H
#define GUILDMODIFICATIONVALIDMESSAGE_H

#include "Network/Classes/Data/game/guild/GuildEmblem.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/guild/GuildEmblem.h"

class GuildModificationValidMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GuildModificationValidMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GuildModificationValidMessage(Reader *param1);
  GuildModificationValidMessage();

  QString guildName;
  GuildEmblem guildEmblem;
};

#endif // GUILDMODIFICATIONVALIDMESSAGE_H