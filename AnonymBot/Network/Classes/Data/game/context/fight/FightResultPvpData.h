#ifndef FIGHTRESULTPVPDATA_H
#define FIGHTRESULTPVPDATA_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/context/fight/FightResultAdditionalData.h"
#include "Network/Classes/Data/game/context/fight/FightResultAdditionalData.h"

class FightResultPvpData : public FightResultAdditionalData
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_FightResultPvpData(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_FightResultPvpData(Reader *param1);
  FightResultPvpData();
  bool operator==(const FightResultPvpData &compared);

  uint grade;
  uint minHonorForGrade;
  uint maxHonorForGrade;
  uint honor;
  int honorDelta;
};

#endif // FIGHTRESULTPVPDATA_H