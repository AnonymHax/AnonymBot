#ifndef GAMEROLEPLAYPORTALINFORMATIONS_H
#define GAMEROLEPLAYPORTALINFORMATIONS_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/context/roleplay/treasureHunt/PortalInformation.h"
#include "Network/Classes/Data/game/context/roleplay/GameRolePlayActorInformations.h"
#include "Network/Classes/Data/game/context/roleplay/treasureHunt/PortalInformation.h"
#include "Network/Classes/Data/game/context/roleplay/GameRolePlayActorInformations.h"
#include "Network/Classes/Data/game/context/roleplay/treasureHunt/PortalInformation.h"
#include "Network/Classes/Data/game/look/EntityLook.h"
#include "Network/Classes/Data/game/context/EntityDispositionInformations.h"
#include "Network/Classes/ClassManager.h"

class GameRolePlayPortalInformations : public GameRolePlayActorInformations
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameRolePlayPortalInformations(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameRolePlayPortalInformations(Reader *param1);
  GameRolePlayPortalInformations();
  bool operator==(const GameRolePlayPortalInformations &compared);

  QSharedPointer<PortalInformation> portal;
};

#endif // GAMEROLEPLAYPORTALINFORMATIONS_H