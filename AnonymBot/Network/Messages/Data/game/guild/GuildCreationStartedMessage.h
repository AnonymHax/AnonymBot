#ifndef GUILDCREATIONSTARTEDMESSAGE_H
#define GUILDCREATIONSTARTEDMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class GuildCreationStartedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GuildCreationStartedMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GuildCreationStartedMessage(Reader *param1);
  GuildCreationStartedMessage();
};

#endif // GUILDCREATIONSTARTEDMESSAGE_H