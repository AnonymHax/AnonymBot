#ifndef FIGHTRESULTTAXCOLLECTORLISTENTRY_H
#define FIGHTRESULTTAXCOLLECTORLISTENTRY_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/context/roleplay/BasicGuildInformations.h"
#include "Network/Classes/Data/game/context/fight/FightResultFighterListEntry.h"
#include "Network/Classes/Data/game/context/roleplay/BasicGuildInformations.h"
#include "Network/Classes/Data/game/context/fight/FightResultFighterListEntry.h"
#include "Network/Classes/Data/game/context/roleplay/BasicGuildInformations.h"

class FightResultTaxCollectorListEntry : public FightResultFighterListEntry
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_FightResultTaxCollectorListEntry(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_FightResultTaxCollectorListEntry(Reader *param1);
  FightResultTaxCollectorListEntry();
  bool operator==(const FightResultTaxCollectorListEntry &compared);

  uint level;
  QSharedPointer<BasicGuildInformations> guildInfo;
  int experienceForGuild;
};

#endif // FIGHTRESULTTAXCOLLECTORLISTENTRY_H