#ifndef GUILDINVITATIONBYNAMEMESSAGE_H
#define GUILDINVITATIONBYNAMEMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class GuildInvitationByNameMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GuildInvitationByNameMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GuildInvitationByNameMessage(Reader *param1);
  GuildInvitationByNameMessage();

  QString name;
};

#endif // GUILDINVITATIONBYNAMEMESSAGE_H