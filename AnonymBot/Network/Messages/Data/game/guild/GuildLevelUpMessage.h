#ifndef GUILDLEVELUPMESSAGE_H
#define GUILDLEVELUPMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class GuildLevelUpMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GuildLevelUpMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GuildLevelUpMessage(Reader *param1);
  GuildLevelUpMessage();

  uint newLevel;
};

#endif // GUILDLEVELUPMESSAGE_H