#ifndef GUILDPADDOCKREMOVEDMESSAGE_H
#define GUILDPADDOCKREMOVEDMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class GuildPaddockRemovedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GuildPaddockRemovedMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GuildPaddockRemovedMessage(Reader *param1);
  GuildPaddockRemovedMessage();

  int paddockId;
};

#endif // GUILDPADDOCKREMOVEDMESSAGE_H