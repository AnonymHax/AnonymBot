#ifndef FIGHTCOMMONINFORMATIONS_H
#define FIGHTCOMMONINFORMATIONS_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/context/fight/FightTeamInformations.h"
#include "Network/Classes/Data/game/context/fight/FightOptionsInformations.h"
#include "Network/Classes/ClassManager.h"

class FightCommonInformations : public AbstractClass
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_FightCommonInformations(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_FightCommonInformations(Reader *param1);
  FightCommonInformations();
  bool operator==(const FightCommonInformations &compared);

  int fightId;
  uint fightType;
  QList<QSharedPointer<FightTeamInformations>> fightTeams;
  QList<uint> fightTeamsPositions;
  QList<FightOptionsInformations> fightTeamsOptions;
};

#endif // FIGHTCOMMONINFORMATIONS_H