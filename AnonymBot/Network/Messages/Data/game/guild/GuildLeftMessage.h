#ifndef GUILDLEFTMESSAGE_H
#define GUILDLEFTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class GuildLeftMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GuildLeftMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GuildLeftMessage(Reader *param1);
  GuildLeftMessage();
};

#endif // GUILDLEFTMESSAGE_H