#ifndef GUILDMEMBERSETWARNONCONNECTIONMESSAGE_H
#define GUILDMEMBERSETWARNONCONNECTIONMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class GuildMemberSetWarnOnConnectionMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GuildMemberSetWarnOnConnectionMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GuildMemberSetWarnOnConnectionMessage(Reader *param1);
  GuildMemberSetWarnOnConnectionMessage();

  bool enable;
};

#endif // GUILDMEMBERSETWARNONCONNECTIONMESSAGE_H