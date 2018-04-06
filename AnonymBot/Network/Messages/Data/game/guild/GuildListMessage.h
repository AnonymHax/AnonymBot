#ifndef GUILDLISTMESSAGE_H
#define GUILDLISTMESSAGE_H

#include "Network/Classes/Data/game/context/roleplay/GuildInformations.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/context/roleplay/GuildInformations.h"

class GuildListMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GuildListMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GuildListMessage(Reader *param1);
  GuildListMessage();

  QList<QSharedPointer<GuildInformations>> guilds;
};

#endif // GUILDLISTMESSAGE_H