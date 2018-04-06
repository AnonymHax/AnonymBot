#ifndef GUILDINVITATIONMESSAGE_H
#define GUILDINVITATIONMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class GuildInvitationMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GuildInvitationMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GuildInvitationMessage(Reader *param1);
  GuildInvitationMessage();

  double targetId;
};

#endif // GUILDINVITATIONMESSAGE_H