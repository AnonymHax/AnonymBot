#ifndef FIGHTTEAMMEMBERINFORMATIONS_H
#define FIGHTTEAMMEMBERINFORMATIONS_H

#include "Network/Classes/AbstractClass.h"

class FightTeamMemberInformations : public AbstractClass
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_FightTeamMemberInformations(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_FightTeamMemberInformations(Reader *param1);
  FightTeamMemberInformations();
  bool operator==(const FightTeamMemberInformations &compared);

  double id;
};

#endif // FIGHTTEAMMEMBERINFORMATIONS_H