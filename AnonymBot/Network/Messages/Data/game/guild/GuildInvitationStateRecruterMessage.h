#ifndef GUILDINVITATIONSTATERECRUTERMESSAGE_H
#define GUILDINVITATIONSTATERECRUTERMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class GuildInvitationStateRecruterMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GuildInvitationStateRecruterMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GuildInvitationStateRecruterMessage(Reader *param1);
  GuildInvitationStateRecruterMessage();

  QString recrutedName;
  uint invitationState;
};

#endif // GUILDINVITATIONSTATERECRUTERMESSAGE_H