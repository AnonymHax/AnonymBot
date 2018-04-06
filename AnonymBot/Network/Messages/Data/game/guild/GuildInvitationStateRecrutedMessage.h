#ifndef GUILDINVITATIONSTATERECRUTEDMESSAGE_H
#define GUILDINVITATIONSTATERECRUTEDMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class GuildInvitationStateRecrutedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GuildInvitationStateRecrutedMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GuildInvitationStateRecrutedMessage(Reader *param1);
  GuildInvitationStateRecrutedMessage();

  uint invitationState;
};

#endif // GUILDINVITATIONSTATERECRUTEDMESSAGE_H