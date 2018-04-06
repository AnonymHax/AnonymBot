#ifndef ABSTRACTFIGHTTEAMINFORMATIONS_H
#define ABSTRACTFIGHTTEAMINFORMATIONS_H

#include "Network/Classes/AbstractClass.h"

class AbstractFightTeamInformations : public AbstractClass
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_AbstractFightTeamInformations(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_AbstractFightTeamInformations(Reader *param1);
  AbstractFightTeamInformations();
  bool operator==(const AbstractFightTeamInformations &compared);

  uint teamId;
  double leaderId;
  int teamSide;
  uint teamTypeId;
  uint nbWaves;
};

#endif // ABSTRACTFIGHTTEAMINFORMATIONS_H