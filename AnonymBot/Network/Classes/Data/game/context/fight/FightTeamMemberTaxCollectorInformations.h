#ifndef FIGHTTEAMMEMBERTAXCOLLECTORINFORMATIONS_H
#define FIGHTTEAMMEMBERTAXCOLLECTORINFORMATIONS_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/context/fight/FightTeamMemberInformations.h"
#include "Network/Classes/Data/game/context/fight/FightTeamMemberInformations.h"

class FightTeamMemberTaxCollectorInformations : public FightTeamMemberInformations
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_FightTeamMemberTaxCollectorInformations(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_FightTeamMemberTaxCollectorInformations(Reader *param1);
  FightTeamMemberTaxCollectorInformations();
  bool operator==(const FightTeamMemberTaxCollectorInformations &compared);

  uint firstNameId;
  uint lastNameId;
  uint level;
  uint guildId;
  uint uid;
};

#endif // FIGHTTEAMMEMBERTAXCOLLECTORINFORMATIONS_H