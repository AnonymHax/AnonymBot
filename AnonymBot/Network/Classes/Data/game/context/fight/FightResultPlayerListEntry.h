#ifndef FIGHTRESULTPLAYERLISTENTRY_H
#define FIGHTRESULTPLAYERLISTENTRY_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/context/fight/FightResultAdditionalData.h"
#include "Network/Classes/Data/game/context/fight/FightResultFighterListEntry.h"
#include "Network/Classes/Data/game/context/fight/FightResultAdditionalData.h"
#include "Network/Classes/Data/game/context/fight/FightResultFighterListEntry.h"
#include "Network/Classes/ClassManager.h"

class FightResultPlayerListEntry : public FightResultFighterListEntry
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_FightResultPlayerListEntry(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_FightResultPlayerListEntry(Reader *param1);
  FightResultPlayerListEntry();
  bool operator==(const FightResultPlayerListEntry &compared);

  uint level;
  QList<QSharedPointer<FightResultAdditionalData>> additional;
};

#endif // FIGHTRESULTPLAYERLISTENTRY_H