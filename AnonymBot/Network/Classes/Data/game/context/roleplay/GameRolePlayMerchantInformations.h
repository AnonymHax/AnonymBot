#ifndef GAMEROLEPLAYMERCHANTINFORMATIONS_H
#define GAMEROLEPLAYMERCHANTINFORMATIONS_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/context/roleplay/HumanOption.h"
#include "Network/Classes/Data/game/context/roleplay/GameRolePlayNamedActorInformations.h"
#include "Network/Classes/Data/game/context/roleplay/HumanOption.h"
#include "Network/Classes/Data/game/context/roleplay/GameRolePlayNamedActorInformations.h"
#include "Network/Classes/Data/game/look/EntityLook.h"
#include "Network/Classes/Data/game/context/EntityDispositionInformations.h"
#include "Network/Classes/ClassManager.h"

class GameRolePlayMerchantInformations : public GameRolePlayNamedActorInformations
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameRolePlayMerchantInformations(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameRolePlayMerchantInformations(Reader *param1);
  GameRolePlayMerchantInformations();
  bool operator==(const GameRolePlayMerchantInformations &compared);

  uint sellType;
  QList<QSharedPointer<HumanOption>> options;
};

#endif // GAMEROLEPLAYMERCHANTINFORMATIONS_H