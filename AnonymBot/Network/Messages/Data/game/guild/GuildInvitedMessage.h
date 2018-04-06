#ifndef GUILDINVITEDMESSAGE_H
#define GUILDINVITEDMESSAGE_H

#include "Network/Classes/Data/game/context/roleplay/BasicGuildInformations.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/context/roleplay/BasicGuildInformations.h"

class GuildInvitedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GuildInvitedMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GuildInvitedMessage(Reader *param1);
  GuildInvitedMessage();

  double recruterId;
  QString recruterName;
  QSharedPointer<BasicGuildInformations> guildInfo;
};

#endif // GUILDINVITEDMESSAGE_H