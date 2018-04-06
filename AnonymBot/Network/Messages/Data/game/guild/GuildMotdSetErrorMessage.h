#ifndef GUILDMOTDSETERRORMESSAGE_H
#define GUILDMOTDSETERRORMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/social/SocialNoticeSetErrorMessage.h"

class GuildMotdSetErrorMessage : public SocialNoticeSetErrorMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GuildMotdSetErrorMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GuildMotdSetErrorMessage(Reader *param1);
  GuildMotdSetErrorMessage();
};

#endif // GUILDMOTDSETERRORMESSAGE_H