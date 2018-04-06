#ifndef GUILDHOUSETELEPORTREQUESTMESSAGE_H
#define GUILDHOUSETELEPORTREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class GuildHouseTeleportRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GuildHouseTeleportRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GuildHouseTeleportRequestMessage(Reader *param1);
  GuildHouseTeleportRequestMessage();

  uint houseId;
};

#endif // GUILDHOUSETELEPORTREQUESTMESSAGE_H