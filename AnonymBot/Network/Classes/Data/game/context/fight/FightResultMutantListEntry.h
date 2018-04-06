#ifndef FIGHTRESULTMUTANTLISTENTRY_H
#define FIGHTRESULTMUTANTLISTENTRY_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/context/fight/FightResultFighterListEntry.h"
#include "Network/Classes/Data/game/context/fight/FightResultFighterListEntry.h"

class FightResultMutantListEntry : public FightResultFighterListEntry
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_FightResultMutantListEntry(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_FightResultMutantListEntry(Reader *param1);
  FightResultMutantListEntry();
  bool operator==(const FightResultMutantListEntry &compared);

  uint level;
};

#endif // FIGHTRESULTMUTANTLISTENTRY_H