#ifndef TREASUREHUNTSTEPFOLLOWDIRECTION_H
#define TREASUREHUNTSTEPFOLLOWDIRECTION_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/context/roleplay/treasureHunt/TreasureHuntStep.h"
#include "Network/Classes/Data/game/context/roleplay/treasureHunt/TreasureHuntStep.h"

class TreasureHuntStepFollowDirection : public TreasureHuntStep
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_TreasureHuntStepFollowDirection(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_TreasureHuntStepFollowDirection(Reader *param1);
  TreasureHuntStepFollowDirection();
  bool operator==(const TreasureHuntStepFollowDirection &compared);

  uint direction;
  uint mapCount;
};

#endif // TREASUREHUNTSTEPFOLLOWDIRECTION_H