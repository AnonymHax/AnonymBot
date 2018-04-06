#ifndef MAPCOMPLEMENTARYINFORMATIONSDATAINHOUSEMESSAGE_H
#define MAPCOMPLEMENTARYINFORMATIONSDATAINHOUSEMESSAGE_H

#include "Network/Classes/Data/game/house/HouseInformationsInside.h"
#include "Network/Classes/Data/game/house/HouseInformations.h"
#include "Network/Classes/Data/game/context/roleplay/GameRolePlayActorInformations.h"
#include "Network/Classes/Data/game/interactive/InteractiveElement.h"
#include "Network/Classes/Data/game/interactive/StatedElement.h"
#include "Network/Classes/Data/game/interactive/MapObstacle.h"
#include "Network/Classes/Data/game/context/fight/FightCommonInformations.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/context/roleplay/MapComplementaryInformationsDataMessage.h"
#include "Network/Classes/Data/game/house/HouseInformationsInside.h"
#include "Network/Classes/Data/game/house/HouseInformations.h"
#include "Network/Classes/Data/game/context/roleplay/GameRolePlayActorInformations.h"
#include "Network/Classes/Data/game/interactive/InteractiveElement.h"
#include "Network/Classes/Data/game/interactive/StatedElement.h"
#include "Network/Classes/Data/game/interactive/MapObstacle.h"
#include "Network/Classes/Data/game/context/fight/FightCommonInformations.h"

class MapComplementaryInformationsDataInHouseMessage : public MapComplementaryInformationsDataMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_MapComplementaryInformationsDataInHouseMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_MapComplementaryInformationsDataInHouseMessage(Reader *param1);
  MapComplementaryInformationsDataInHouseMessage();

  HouseInformationsInside currentHouse;
};

#endif // MAPCOMPLEMENTARYINFORMATIONSDATAINHOUSEMESSAGE_H