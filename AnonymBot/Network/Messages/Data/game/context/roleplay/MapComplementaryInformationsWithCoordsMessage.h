#ifndef MAPCOMPLEMENTARYINFORMATIONSWITHCOORDSMESSAGE_H
#define MAPCOMPLEMENTARYINFORMATIONSWITHCOORDSMESSAGE_H

#include "Network/Classes/Data/game/house/HouseInformations.h"
#include "Network/Classes/Data/game/context/roleplay/GameRolePlayActorInformations.h"
#include "Network/Classes/Data/game/interactive/InteractiveElement.h"
#include "Network/Classes/Data/game/interactive/StatedElement.h"
#include "Network/Classes/Data/game/interactive/MapObstacle.h"
#include "Network/Classes/Data/game/context/fight/FightCommonInformations.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/context/roleplay/MapComplementaryInformationsDataMessage.h"
#include "Network/Classes/Data/game/house/HouseInformations.h"
#include "Network/Classes/Data/game/context/roleplay/GameRolePlayActorInformations.h"
#include "Network/Classes/Data/game/interactive/InteractiveElement.h"
#include "Network/Classes/Data/game/interactive/StatedElement.h"
#include "Network/Classes/Data/game/interactive/MapObstacle.h"
#include "Network/Classes/Data/game/context/fight/FightCommonInformations.h"

class MapComplementaryInformationsWithCoordsMessage : public MapComplementaryInformationsDataMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_MapComplementaryInformationsWithCoordsMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_MapComplementaryInformationsWithCoordsMessage(Reader *param1);
  MapComplementaryInformationsWithCoordsMessage();

  int worldX;
  int worldY;
};

#endif // MAPCOMPLEMENTARYINFORMATIONSWITHCOORDSMESSAGE_H