#ifndef FIGHTRESULTFIGHTERLISTENTRY_H
#define FIGHTRESULTFIGHTERLISTENTRY_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/context/fight/FightResultListEntry.h"
#include "Network/Classes/Data/game/context/fight/FightResultListEntry.h"

class FightResultFighterListEntry : public FightResultListEntry
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_FightResultFighterListEntry(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_FightResultFighterListEntry(Reader *param1);
  FightResultFighterListEntry();
  bool operator==(const FightResultFighterListEntry &compared);

  double id;
  bool alive;
};

#endif // FIGHTRESULTFIGHTERLISTENTRY_H