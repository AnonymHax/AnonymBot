#ifndef FIGHTRESULTLISTENTRY_H
#define FIGHTRESULTLISTENTRY_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/context/fight/FightLoot.h"
#include "Network/Classes/Data/game/context/fight/FightLoot.h"

class FightResultListEntry : public AbstractClass
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_FightResultListEntry(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_FightResultListEntry(Reader *param1);
  FightResultListEntry();
  bool operator==(const FightResultListEntry &compared);

  uint outcome;
  uint wave;
  FightLoot rewards;
};

#endif // FIGHTRESULTLISTENTRY_H