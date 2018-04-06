#ifndef GUILDINALLIANCEVERSATILEINFORMATIONS_H
#define GUILDINALLIANCEVERSATILEINFORMATIONS_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/social/GuildVersatileInformations.h"
#include "Network/Classes/Data/game/social/GuildVersatileInformations.h"

class GuildInAllianceVersatileInformations : public GuildVersatileInformations
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GuildInAllianceVersatileInformations(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GuildInAllianceVersatileInformations(Reader *param1);
  GuildInAllianceVersatileInformations();
  bool operator==(const GuildInAllianceVersatileInformations &compared);

  uint allianceId;
};

#endif // GUILDINALLIANCEVERSATILEINFORMATIONS_H