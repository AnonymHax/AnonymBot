#ifndef HOUSEGUILDRIGHTSMESSAGE_H
#define HOUSEGUILDRIGHTSMESSAGE_H

#include "Network/Classes/Data/game/context/roleplay/GuildInformations.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/context/roleplay/GuildInformations.h"

class HouseGuildRightsMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_HouseGuildRightsMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_HouseGuildRightsMessage(Reader *param1);
  HouseGuildRightsMessage();

  uint houseId;
  QSharedPointer<GuildInformations> guildInfo;
  uint rights;
};

#endif // HOUSEGUILDRIGHTSMESSAGE_H