#ifndef FIGHTTEAMMEMBERWITHALLIANCECHARACTERINFORMATIONS_H
#define FIGHTTEAMMEMBERWITHALLIANCECHARACTERINFORMATIONS_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/context/roleplay/BasicAllianceInformations.h"
#include "Network/Classes/Data/game/context/fight/FightTeamMemberCharacterInformations.h"
#include "Network/Classes/Data/game/context/roleplay/BasicAllianceInformations.h"
#include "Network/Classes/Data/game/context/fight/FightTeamMemberCharacterInformations.h"
#include "Network/Classes/Data/game/context/roleplay/BasicAllianceInformations.h"

class FightTeamMemberWithAllianceCharacterInformations : public FightTeamMemberCharacterInformations
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_FightTeamMemberWithAllianceCharacterInformations(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_FightTeamMemberWithAllianceCharacterInformations(Reader *param1);
  FightTeamMemberWithAllianceCharacterInformations();
  bool operator==(const FightTeamMemberWithAllianceCharacterInformations &compared);

  QSharedPointer<BasicAllianceInformations> allianceInfos;
};

#endif // FIGHTTEAMMEMBERWITHALLIANCECHARACTERINFORMATIONS_H