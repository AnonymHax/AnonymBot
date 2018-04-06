#ifndef GAMEROLEPLAYMUTANTINFORMATIONS_H
#define GAMEROLEPLAYMUTANTINFORMATIONS_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/context/roleplay/GameRolePlayHumanoidInformations.h"
#include "Network/Classes/Data/game/context/roleplay/GameRolePlayHumanoidInformations.h"
#include "Network/Classes/Data/game/look/EntityLook.h"
#include "Network/Classes/Data/game/context/EntityDispositionInformations.h"

class GameRolePlayMutantInformations : public GameRolePlayHumanoidInformations
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameRolePlayMutantInformations(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameRolePlayMutantInformations(Reader *param1);
  GameRolePlayMutantInformations();
  bool operator==(const GameRolePlayMutantInformations &compared);

  uint monsterId;
  int powerLevel;
};

#endif // GAMEROLEPLAYMUTANTINFORMATIONS_H