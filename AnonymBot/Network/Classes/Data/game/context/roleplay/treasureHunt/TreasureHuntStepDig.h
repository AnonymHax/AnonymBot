#ifndef TREASUREHUNTSTEPDIG_H
#define TREASUREHUNTSTEPDIG_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/context/roleplay/treasureHunt/TreasureHuntStep.h"
#include "Network/Classes/Data/game/context/roleplay/treasureHunt/TreasureHuntStep.h"

class TreasureHuntStepDig : public TreasureHuntStep
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_TreasureHuntStepDig(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_TreasureHuntStepDig(Reader *param1);
  TreasureHuntStepDig();
  bool operator==(const TreasureHuntStepDig &compared);
};

#endif // TREASUREHUNTSTEPDIG_H