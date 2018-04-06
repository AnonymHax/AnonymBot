#ifndef GAMEROLEPLAYNPCINFORMATIONS_H
#define GAMEROLEPLAYNPCINFORMATIONS_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/context/roleplay/GameRolePlayActorInformations.h"
#include "Network/Classes/Data/game/context/roleplay/GameRolePlayActorInformations.h"
#include "Network/Classes/Data/game/look/EntityLook.h"
#include "Network/Classes/Data/game/context/EntityDispositionInformations.h"

class GameRolePlayNpcInformations : public GameRolePlayActorInformations
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameRolePlayNpcInformations(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameRolePlayNpcInformations(Reader *param1);
  GameRolePlayNpcInformations();
  bool operator==(const GameRolePlayNpcInformations &compared);

  uint npcId;
  bool sex;
  uint specialArtworkId;
};

#endif // GAMEROLEPLAYNPCINFORMATIONS_H