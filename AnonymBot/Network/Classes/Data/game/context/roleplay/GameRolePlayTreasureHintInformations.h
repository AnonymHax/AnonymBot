#ifndef GAMEROLEPLAYTREASUREHINTINFORMATIONS_H
#define GAMEROLEPLAYTREASUREHINTINFORMATIONS_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/context/roleplay/GameRolePlayActorInformations.h"
#include "Network/Classes/Data/game/context/roleplay/GameRolePlayActorInformations.h"
#include "Network/Classes/Data/game/look/EntityLook.h"
#include "Network/Classes/Data/game/context/EntityDispositionInformations.h"

class GameRolePlayTreasureHintInformations : public GameRolePlayActorInformations
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameRolePlayTreasureHintInformations(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameRolePlayTreasureHintInformations(Reader *param1);
  GameRolePlayTreasureHintInformations();
  bool operator==(const GameRolePlayTreasureHintInformations &compared);

  uint npcId;
};

#endif // GAMEROLEPLAYTREASUREHINTINFORMATIONS_H