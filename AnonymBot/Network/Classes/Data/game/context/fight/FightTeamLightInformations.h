#ifndef FIGHTTEAMLIGHTINFORMATIONS_H
#define FIGHTTEAMLIGHTINFORMATIONS_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/context/fight/AbstractFightTeamInformations.h"
#include "System/Tools/IO/BooleanByteWrapper.h"

class FightTeamLightInformations : public AbstractFightTeamInformations
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_FightTeamLightInformations(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_FightTeamLightInformations(Reader *param1);
  FightTeamLightInformations();
  bool operator==(const FightTeamLightInformations &compared);

  uint teamMembersCount;
  uint meanLevel;
  bool hasFriend;
  bool hasGuildMember;
  bool hasAllianceMember;
  bool hasGroupMember;
  bool hasMyTaxCollector;
};

#endif // FIGHTTEAMLIGHTINFORMATIONS_H