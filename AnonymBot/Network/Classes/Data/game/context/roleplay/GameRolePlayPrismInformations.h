#ifndef GAMEROLEPLAYPRISMINFORMATIONS_H
#define GAMEROLEPLAYPRISMINFORMATIONS_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/prism/PrismInformation.h"
#include "Network/Classes/Data/game/context/roleplay/GameRolePlayActorInformations.h"
#include "Network/Classes/Data/game/prism/PrismInformation.h"
#include "Network/Classes/Data/game/context/roleplay/GameRolePlayActorInformations.h"
#include "Network/Classes/Data/game/prism/PrismInformation.h"
#include "Network/Classes/Data/game/look/EntityLook.h"
#include "Network/Classes/Data/game/context/EntityDispositionInformations.h"
#include "Network/Classes/ClassManager.h"

class GameRolePlayPrismInformations : public GameRolePlayActorInformations
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameRolePlayPrismInformations(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameRolePlayPrismInformations(Reader *param1);
  GameRolePlayPrismInformations();
  bool operator==(const GameRolePlayPrismInformations &compared);

  QSharedPointer<PrismInformation> prism;
};

#endif // GAMEROLEPLAYPRISMINFORMATIONS_H