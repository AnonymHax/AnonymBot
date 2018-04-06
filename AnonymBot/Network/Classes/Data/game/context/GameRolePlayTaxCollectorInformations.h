#ifndef GAMEROLEPLAYTAXCOLLECTORINFORMATIONS_H
#define GAMEROLEPLAYTAXCOLLECTORINFORMATIONS_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/context/TaxCollectorStaticInformations.h"
#include "Network/Classes/Data/game/context/roleplay/GameRolePlayActorInformations.h"
#include "Network/Classes/Data/game/context/TaxCollectorStaticInformations.h"
#include "Network/Classes/Data/game/context/roleplay/GameRolePlayActorInformations.h"
#include "Network/Classes/Data/game/context/roleplay/GameRolePlayActorInformations.h"
#include "Network/Classes/Data/game/look/EntityLook.h"
#include "Network/Classes/ClassManager.h"

class GameRolePlayTaxCollectorInformations : public GameRolePlayActorInformations
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameRolePlayTaxCollectorInformations(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameRolePlayTaxCollectorInformations(Reader *param1);
  GameRolePlayTaxCollectorInformations();
  bool operator==(const GameRolePlayTaxCollectorInformations &compared);

  QSharedPointer<TaxCollectorStaticInformations> identification;
  uint guildLevel;
  int taxCollectorAttack;
};

#endif // GAMEROLEPLAYTAXCOLLECTORINFORMATIONS_H