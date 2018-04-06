#ifndef GUILDKICKREQUESTMESSAGE_H
#define GUILDKICKREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class GuildKickRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GuildKickRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GuildKickRequestMessage(Reader *param1);
  GuildKickRequestMessage();

  double kickedId;
};

#endif // GUILDKICKREQUESTMESSAGE_H