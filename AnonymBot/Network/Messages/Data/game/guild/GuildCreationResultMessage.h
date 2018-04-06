#ifndef GUILDCREATIONRESULTMESSAGE_H
#define GUILDCREATIONRESULTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class GuildCreationResultMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GuildCreationResultMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GuildCreationResultMessage(Reader *param1);
  GuildCreationResultMessage();

  uint result;
};

#endif // GUILDCREATIONRESULTMESSAGE_H