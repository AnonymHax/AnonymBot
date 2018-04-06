#ifndef GUILDFIGHTTAKEPLACEREQUESTMESSAGE_H
#define GUILDFIGHTTAKEPLACEREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/guild/tax/GuildFightJoinRequestMessage.h"

class GuildFightTakePlaceRequestMessage : public GuildFightJoinRequestMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GuildFightTakePlaceRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GuildFightTakePlaceRequestMessage(Reader *param1);
  GuildFightTakePlaceRequestMessage();

  int replacedCharacterId;
};

#endif // GUILDFIGHTTAKEPLACEREQUESTMESSAGE_H