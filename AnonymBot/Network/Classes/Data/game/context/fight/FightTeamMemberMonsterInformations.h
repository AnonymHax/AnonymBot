#ifndef FIGHTTEAMMEMBERMONSTERINFORMATIONS_H
#define FIGHTTEAMMEMBERMONSTERINFORMATIONS_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/context/fight/FightTeamMemberInformations.h"
#include "Network/Classes/Data/game/context/fight/FightTeamMemberInformations.h"

class FightTeamMemberMonsterInformations : public FightTeamMemberInformations
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_FightTeamMemberMonsterInformations(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_FightTeamMemberMonsterInformations(Reader *param1);
  FightTeamMemberMonsterInformations();
  bool operator==(const FightTeamMemberMonsterInformations &compared);

  int monsterId;
  uint grade;
};

#endif // FIGHTTEAMMEMBERMONSTERINFORMATIONS_H