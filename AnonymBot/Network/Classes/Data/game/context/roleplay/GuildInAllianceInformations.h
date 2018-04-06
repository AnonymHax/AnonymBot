#ifndef GUILDINALLIANCEINFORMATIONS_H
#define GUILDINALLIANCEINFORMATIONS_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/context/roleplay/GuildInformations.h"
#include "Network/Classes/Data/game/context/roleplay/GuildInformations.h"
#include "Network/Classes/Data/game/guild/GuildEmblem.h"

class GuildInAllianceInformations : public GuildInformations
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GuildInAllianceInformations(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GuildInAllianceInformations(Reader *param1);
  GuildInAllianceInformations();
  bool operator==(const GuildInAllianceInformations &compared);

  uint nbMembers;
};

#endif // GUILDINALLIANCEINFORMATIONS_H