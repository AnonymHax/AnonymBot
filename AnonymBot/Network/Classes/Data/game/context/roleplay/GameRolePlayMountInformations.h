#ifndef GAMEROLEPLAYMOUNTINFORMATIONS_H
#define GAMEROLEPLAYMOUNTINFORMATIONS_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/context/roleplay/GameRolePlayNamedActorInformations.h"
#include "Network/Classes/Data/game/context/roleplay/GameRolePlayNamedActorInformations.h"
#include "Network/Classes/Data/game/look/EntityLook.h"
#include "Network/Classes/Data/game/context/EntityDispositionInformations.h"

class GameRolePlayMountInformations : public GameRolePlayNamedActorInformations
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameRolePlayMountInformations(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameRolePlayMountInformations(Reader *param1);
  GameRolePlayMountInformations();
  bool operator==(const GameRolePlayMountInformations &compared);

  QString ownerName;
  uint level;
};

#endif // GAMEROLEPLAYMOUNTINFORMATIONS_H