#ifndef FIGHTTEAMMEMBERCOMPANIONINFORMATIONS_H
#define FIGHTTEAMMEMBERCOMPANIONINFORMATIONS_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/context/fight/FightTeamMemberInformations.h"
#include "Network/Classes/Data/game/context/fight/FightTeamMemberInformations.h"

class FightTeamMemberCompanionInformations : public FightTeamMemberInformations
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_FightTeamMemberCompanionInformations(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_FightTeamMemberCompanionInformations(Reader *param1);
  FightTeamMemberCompanionInformations();
  bool operator==(const FightTeamMemberCompanionInformations &compared);

  uint companionId;
  uint level;
  double masterId;
};

#endif // FIGHTTEAMMEMBERCOMPANIONINFORMATIONS_H