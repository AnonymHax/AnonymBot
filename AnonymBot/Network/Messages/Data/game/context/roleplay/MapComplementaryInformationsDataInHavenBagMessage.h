#ifndef MAPCOMPLEMENTARYINFORMATIONSDATAINHAVENBAGMESSAGE_H
#define MAPCOMPLEMENTARYINFORMATIONSDATAINHAVENBAGMESSAGE_H

#include "Network/Classes/Data/game/character/CharacterMinimalInformations.h"
#include "Network/Classes/Data/game/house/HouseInformations.h"
#include "Network/Classes/Data/game/context/roleplay/GameRolePlayActorInformations.h"
#include "Network/Classes/Data/game/interactive/InteractiveElement.h"
#include "Network/Classes/Data/game/interactive/StatedElement.h"
#include "Network/Classes/Data/game/interactive/MapObstacle.h"
#include "Network/Classes/Data/game/context/fight/FightCommonInformations.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/context/roleplay/MapComplementaryInformationsDataMessage.h"
#include "Network/Classes/Data/game/character/CharacterMinimalInformations.h"
#include "Network/Classes/Data/game/house/HouseInformations.h"
#include "Network/Classes/Data/game/context/roleplay/GameRolePlayActorInformations.h"
#include "Network/Classes/Data/game/interactive/InteractiveElement.h"
#include "Network/Classes/Data/game/interactive/StatedElement.h"
#include "Network/Classes/Data/game/interactive/MapObstacle.h"
#include "Network/Classes/Data/game/context/fight/FightCommonInformations.h"

class MapComplementaryInformationsDataInHavenBagMessage : public MapComplementaryInformationsDataMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_MapComplementaryInformationsDataInHavenBagMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_MapComplementaryInformationsDataInHavenBagMessage(Reader *param1);
  MapComplementaryInformationsDataInHavenBagMessage();

  CharacterMinimalInformations ownerInformations;
  int theme;
  uint roomId;
  uint maxRoomId;
};

#endif // MAPCOMPLEMENTARYINFORMATIONSDATAINHAVENBAGMESSAGE_H