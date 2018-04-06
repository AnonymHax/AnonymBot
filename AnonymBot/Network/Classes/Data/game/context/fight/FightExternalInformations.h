#ifndef FIGHTEXTERNALINFORMATIONS_H
#define FIGHTEXTERNALINFORMATIONS_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/context/fight/FightTeamLightInformations.h"
#include "Network/Classes/Data/game/context/fight/FightOptionsInformations.h"

class FightExternalInformations : public AbstractClass
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_FightExternalInformations(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_FightExternalInformations(Reader *param1);
  FightExternalInformations();
  bool operator==(const FightExternalInformations &compared);

  int fightId;
  uint fightType;
  uint fightStart;
  bool fightSpectatorLocked;
  QList<FightTeamLightInformations> fightTeams;
  QList<FightOptionsInformations> fightTeamsOptions;
};

#endif // FIGHTEXTERNALINFORMATIONS_H