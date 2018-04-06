#ifndef FIGHTALLIANCETEAMINFORMATIONS_H
#define FIGHTALLIANCETEAMINFORMATIONS_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/context/fight/FightTeamInformations.h"
#include "Network/Classes/Data/game/context/fight/FightTeamInformations.h"

class FightAllianceTeamInformations : public FightTeamInformations
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_FightAllianceTeamInformations(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_FightAllianceTeamInformations(Reader *param1);
  FightAllianceTeamInformations();
  bool operator==(const FightAllianceTeamInformations &compared);

  uint relation;
};

#endif // FIGHTALLIANCETEAMINFORMATIONS_H