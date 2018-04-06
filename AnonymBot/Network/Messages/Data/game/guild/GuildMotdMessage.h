#ifndef GUILDMOTDMESSAGE_H
#define GUILDMOTDMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/social/SocialNoticeMessage.h"

class GuildMotdMessage : public SocialNoticeMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GuildMotdMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GuildMotdMessage(Reader *param1);
  GuildMotdMessage();
};

#endif // GUILDMOTDMESSAGE_H