#ifndef FIGHTTEAMMEMBERCHARACTERINFORMATIONS_H
#define FIGHTTEAMMEMBERCHARACTERINFORMATIONS_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/context/fight/FightTeamMemberInformations.h"
#include "Network/Classes/Data/game/context/fight/FightTeamMemberInformations.h"

class FightTeamMemberCharacterInformations : public FightTeamMemberInformations
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_FightTeamMemberCharacterInformations(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_FightTeamMemberCharacterInformations(Reader *param1);
  FightTeamMemberCharacterInformations();
  bool operator==(const FightTeamMemberCharacterInformations &compared);

  QString name;
  uint level;
};

#endif // FIGHTTEAMMEMBERCHARACTERINFORMATIONS_H