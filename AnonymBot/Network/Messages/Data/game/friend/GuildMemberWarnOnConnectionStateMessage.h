#ifndef GUILDMEMBERWARNONCONNECTIONSTATEMESSAGE_H
#define GUILDMEMBERWARNONCONNECTIONSTATEMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class GuildMemberWarnOnConnectionStateMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GuildMemberWarnOnConnectionStateMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GuildMemberWarnOnConnectionStateMessage(Reader *param1);
  GuildMemberWarnOnConnectionStateMessage();

  bool enable;
};

#endif // GUILDMEMBERWARNONCONNECTIONSTATEMESSAGE_H