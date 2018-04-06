#ifndef GUILDPADDOCKTELEPORTREQUESTMESSAGE_H
#define GUILDPADDOCKTELEPORTREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class GuildPaddockTeleportRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GuildPaddockTeleportRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GuildPaddockTeleportRequestMessage(Reader *param1);
  GuildPaddockTeleportRequestMessage();

  int paddockId;
};

#endif // GUILDPADDOCKTELEPORTREQUESTMESSAGE_H