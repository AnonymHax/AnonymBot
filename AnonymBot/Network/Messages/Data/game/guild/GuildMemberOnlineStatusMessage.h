#ifndef GUILDMEMBERONLINESTATUSMESSAGE_H
#define GUILDMEMBERONLINESTATUSMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class GuildMemberOnlineStatusMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GuildMemberOnlineStatusMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GuildMemberOnlineStatusMessage(Reader *param1);
  GuildMemberOnlineStatusMessage();

  double memberId;
  bool online;
};

#endif // GUILDMEMBERONLINESTATUSMESSAGE_H