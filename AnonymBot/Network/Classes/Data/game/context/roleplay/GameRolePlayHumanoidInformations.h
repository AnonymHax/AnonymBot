#ifndef GAMEROLEPLAYHUMANOIDINFORMATIONS_H
#define GAMEROLEPLAYHUMANOIDINFORMATIONS_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/context/roleplay/HumanInformations.h"
#include "Network/Classes/Data/game/context/roleplay/GameRolePlayNamedActorInformations.h"
#include "Network/Classes/Data/game/context/roleplay/HumanInformations.h"
#include "Network/Classes/Data/game/context/roleplay/GameRolePlayNamedActorInformations.h"
#include "Network/Classes/Data/game/look/EntityLook.h"
#include "Network/Classes/Data/game/context/EntityDispositionInformations.h"
#include "Network/Classes/ClassManager.h"

class GameRolePlayHumanoidInformations : public GameRolePlayNamedActorInformations
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameRolePlayHumanoidInformations(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameRolePlayHumanoidInformations(Reader *param1);
  GameRolePlayHumanoidInformations();
  bool operator==(const GameRolePlayHumanoidInformations &compared);

  QSharedPointer<HumanInformations> humanoidInfo;
  uint accountId;
};

#endif // GAMEROLEPLAYHUMANOIDINFORMATIONS_H