#ifndef GUILDMEMBERLEAVINGMESSAGE_H
#define GUILDMEMBERLEAVINGMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class GuildMemberLeavingMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GuildMemberLeavingMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GuildMemberLeavingMessage(Reader *param1);
  GuildMemberLeavingMessage();

  bool kicked;
  double memberId;
};

#endif // GUILDMEMBERLEAVINGMESSAGE_H