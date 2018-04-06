#ifndef GUILDINVITATIONANSWERMESSAGE_H
#define GUILDINVITATIONANSWERMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class GuildInvitationAnswerMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GuildInvitationAnswerMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GuildInvitationAnswerMessage(Reader *param1);
  GuildInvitationAnswerMessage();

  bool accept;
};

#endif // GUILDINVITATIONANSWERMESSAGE_H