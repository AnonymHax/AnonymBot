#ifndef GAMEROLEPLAYNAMEDACTORINFORMATIONS_H
#define GAMEROLEPLAYNAMEDACTORINFORMATIONS_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/context/roleplay/GameRolePlayActorInformations.h"
#include "Network/Classes/Data/game/context/roleplay/GameRolePlayActorInformations.h"
#include "Network/Classes/Data/game/look/EntityLook.h"
#include "Network/Classes/Data/game/context/EntityDispositionInformations.h"

class GameRolePlayNamedActorInformations : public GameRolePlayActorInformations
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameRolePlayNamedActorInformations(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameRolePlayNamedActorInformations(Reader *param1);
  GameRolePlayNamedActorInformations();
  bool operator==(const GameRolePlayNamedActorInformations &compared);

  QString name;
};

#endif // GAMEROLEPLAYNAMEDACTORINFORMATIONS_H