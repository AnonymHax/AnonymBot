#ifndef GUILDCREATIONVALIDMESSAGE_H
#define GUILDCREATIONVALIDMESSAGE_H

#include "Network/Classes/Data/game/guild/GuildEmblem.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/guild/GuildEmblem.h"

class GuildCreationValidMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GuildCreationValidMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GuildCreationValidMessage(Reader *param1);
  GuildCreationValidMessage();

  QString guildName;
  GuildEmblem guildEmblem;
};

#endif // GUILDCREATIONVALIDMESSAGE_H