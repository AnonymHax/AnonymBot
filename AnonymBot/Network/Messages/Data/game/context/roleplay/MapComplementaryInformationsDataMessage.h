#ifndef MAPCOMPLEMENTARYINFORMATIONSDATAMESSAGE_H
#define MAPCOMPLEMENTARYINFORMATIONSDATAMESSAGE_H

#include "Network/Classes/Data/game/house/HouseInformations.h"
#include "Network/Classes/Data/game/context/roleplay/GameRolePlayActorInformations.h"
#include "Network/Classes/Data/game/interactive/InteractiveElement.h"
#include "Network/Classes/Data/game/interactive/StatedElement.h"
#include "Network/Classes/Data/game/interactive/MapObstacle.h"
#include "Network/Classes/Data/game/context/fight/FightCommonInformations.h"
#include "Network/Classes/ClassManager.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/house/HouseInformations.h"
#include "Network/Classes/Data/game/context/roleplay/GameRolePlayActorInformations.h"
#include "Network/Classes/Data/game/interactive/InteractiveElement.h"
#include "Network/Classes/Data/game/interactive/StatedElement.h"
#include "Network/Classes/Data/game/interactive/MapObstacle.h"
#include "Network/Classes/Data/game/context/fight/FightCommonInformations.h"
#include "Network/Classes/ClassManager.h"

class MapComplementaryInformationsDataMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_MapComplementaryInformationsDataMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_MapComplementaryInformationsDataMessage(Reader *param1);
  MapComplementaryInformationsDataMessage();

  uint subAreaId;
  uint mapId;
  QList<QSharedPointer<HouseInformations>> houses;
  QList<QSharedPointer<GameRolePlayActorInformations>> actors;
  QList<QSharedPointer<InteractiveElement>> interactiveElements;
  QList<StatedElement> statedElements;
  QList<MapObstacle> obstacles;
  QList<QSharedPointer<FightCommonInformations>> fights;
  bool hasAggressiveMonsters;
};

#endif // MAPCOMPLEMENTARYINFORMATIONSDATAMESSAGE_H