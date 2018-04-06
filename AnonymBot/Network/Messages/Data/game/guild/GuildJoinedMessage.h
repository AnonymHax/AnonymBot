#ifndef GUILDJOINEDMESSAGE_H
#define GUILDJOINEDMESSAGE_H

#include "Network/Classes/Data/game/context/roleplay/GuildInformations.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/context/roleplay/GuildInformations.h"

class GuildJoinedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GuildJoinedMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GuildJoinedMessage(Reader *param1);
  GuildJoinedMessage();

  QSharedPointer<GuildInformations> guildInfo;
  uint memberRights;
};

#endif // GUILDJOINEDMESSAGE_H