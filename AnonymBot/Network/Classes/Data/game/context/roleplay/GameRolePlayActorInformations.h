#ifndef GAMEROLEPLAYACTORINFORMATIONS_H
#define GAMEROLEPLAYACTORINFORMATIONS_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/context/GameContextActorInformations.h"
#include "Network/Classes/Data/game/context/GameContextActorInformations.h"
#include "Network/Classes/Data/game/context/GameContextActorInformations.h"
#include "Network/Classes/Data/game/look/EntityLook.h"
#include "Network/Classes/Data/game/context/EntityDispositionInformations.h"

class GameRolePlayActorInformations : public GameContextActorInformations
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameRolePlayActorInformations(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameRolePlayActorInformations(Reader *param1);
  GameRolePlayActorInformations();
  bool operator==(const GameRolePlayActorInformations &compared);
};

#endif // GAMEROLEPLAYACTORINFORMATIONS_H