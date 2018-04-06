#ifndef GUILDMOTDSETREQUESTMESSAGE_H
#define GUILDMOTDSETREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/social/SocialNoticeSetRequestMessage.h"

class GuildMotdSetRequestMessage : public SocialNoticeSetRequestMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GuildMotdSetRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GuildMotdSetRequestMessage(Reader *param1);
  GuildMotdSetRequestMessage();

  QString content;
};

#endif // GUILDMOTDSETREQUESTMESSAGE_H