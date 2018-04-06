#ifndef TREASUREHUNTSTEPFOLLOWDIRECTIONTOPOI_H
#define TREASUREHUNTSTEPFOLLOWDIRECTIONTOPOI_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/context/roleplay/treasureHunt/TreasureHuntStep.h"
#include "Network/Classes/Data/game/context/roleplay/treasureHunt/TreasureHuntStep.h"

class TreasureHuntStepFollowDirectionToPOI : public TreasureHuntStep
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_TreasureHuntStepFollowDirectionToPOI(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_TreasureHuntStepFollowDirectionToPOI(Reader *param1);
  TreasureHuntStepFollowDirectionToPOI();
  bool operator==(const TreasureHuntStepFollowDirectionToPOI &compared);

  uint direction;
  uint poiLabelId;
};

#endif // TREASUREHUNTSTEPFOLLOWDIRECTIONTOPOI_H