#ifndef GUILDMEMBERSHIPMESSAGE_H
#define GUILDMEMBERSHIPMESSAGE_H

#include "Network/Classes/Data/game/context/roleplay/GuildInformations.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/guild/GuildJoinedMessage.h"
#include "Network/Classes/Data/game/context/roleplay/GuildInformations.h"

class GuildMembershipMessage : public GuildJoinedMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GuildMembershipMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GuildMembershipMessage(Reader *param1);
  GuildMembershipMessage();
};

#endif // GUILDMEMBERSHIPMESSAGE_H