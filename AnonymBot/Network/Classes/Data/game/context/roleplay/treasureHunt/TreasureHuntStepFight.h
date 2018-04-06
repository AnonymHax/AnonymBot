#ifndef TREASUREHUNTSTEPFIGHT_H
#define TREASUREHUNTSTEPFIGHT_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/context/roleplay/treasureHunt/TreasureHuntStep.h"
#include "Network/Classes/Data/game/context/roleplay/treasureHunt/TreasureHuntStep.h"

class TreasureHuntStepFight : public TreasureHuntStep
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_TreasureHuntStepFight(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_TreasureHuntStepFight(Reader *param1);
  TreasureHuntStepFight();
  bool operator==(const TreasureHuntStepFight &compared);
};

#endif // TREASUREHUNTSTEPFIGHT_H