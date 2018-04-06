#ifndef MAPRUNNINGFIGHTDETAILSMESSAGE_H
#define MAPRUNNINGFIGHTDETAILSMESSAGE_H

#include "Network/Classes/Data/game/context/fight/GameFightFighterLightInformations.h"
#include "Network/Classes/ClassManager.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/context/fight/GameFightFighterLightInformations.h"
#include "Network/Classes/ClassManager.h"

class MapRunningFightDetailsMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_MapRunningFightDetailsMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_MapRunningFightDetailsMessage(Reader *param1);
  MapRunningFightDetailsMessage();

  uint fightId;
  QList<QSharedPointer<GameFightFighterLightInformations>> attackers;
  QList<QSharedPointer<GameFightFighterLightInformations>> defenders;
};

#endif // MAPRUNNINGFIGHTDETAILSMESSAGE_H