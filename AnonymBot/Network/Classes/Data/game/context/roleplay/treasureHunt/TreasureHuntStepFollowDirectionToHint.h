#ifndef TREASUREHUNTSTEPFOLLOWDIRECTIONTOHINT_H
#define TREASUREHUNTSTEPFOLLOWDIRECTIONTOHINT_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/context/roleplay/treasureHunt/TreasureHuntStep.h"
#include "Network/Classes/Data/game/context/roleplay/treasureHunt/TreasureHuntStep.h"

class TreasureHuntStepFollowDirectionToHint : public TreasureHuntStep
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_TreasureHuntStepFollowDirectionToHint(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_TreasureHuntStepFollowDirectionToHint(Reader *param1);
  TreasureHuntStepFollowDirectionToHint();
  bool operator==(const TreasureHuntStepFollowDirectionToHint &compared);

  uint direction;
  uint npcId;
};

#endif // TREASUREHUNTSTEPFOLLOWDIRECTIONTOHINT_H