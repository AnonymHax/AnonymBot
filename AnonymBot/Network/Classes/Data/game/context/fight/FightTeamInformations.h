#ifndef FIGHTTEAMINFORMATIONS_H
#define FIGHTTEAMINFORMATIONS_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/context/fight/FightTeamMemberInformations.h"
#include "Network/Classes/Data/game/context/fight/AbstractFightTeamInformations.h"
#include "Network/Classes/Data/game/context/fight/FightTeamMemberInformations.h"
#include "Network/Classes/Data/game/context/fight/AbstractFightTeamInformations.h"
#include "Network/Classes/ClassManager.h"

class FightTeamInformations : public AbstractFightTeamInformations
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_FightTeamInformations(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_FightTeamInformations(Reader *param1);
  FightTeamInformations();
  bool operator==(const FightTeamInformations &compared);

  QList<QSharedPointer<FightTeamMemberInformations>> teamMembers;
};

#endif // FIGHTTEAMINFORMATIONS_H