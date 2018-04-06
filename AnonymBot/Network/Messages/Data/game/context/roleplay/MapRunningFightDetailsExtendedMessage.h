#ifndef MAPRUNNINGFIGHTDETAILSEXTENDEDMESSAGE_H
#define MAPRUNNINGFIGHTDETAILSEXTENDEDMESSAGE_H

#include "Network/Classes/Data/game/context/roleplay/party/NamedPartyTeam.h"
#include "Network/Classes/Data/game/context/fight/GameFightFighterLightInformations.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/context/roleplay/MapRunningFightDetailsMessage.h"
#include "Network/Classes/Data/game/context/roleplay/party/NamedPartyTeam.h"
#include "Network/Classes/Data/game/context/fight/GameFightFighterLightInformations.h"

class MapRunningFightDetailsExtendedMessage : public MapRunningFightDetailsMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_MapRunningFightDetailsExtendedMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_MapRunningFightDetailsExtendedMessage(Reader *param1);
  MapRunningFightDetailsExtendedMessage();

  QList<NamedPartyTeam> namedPartyTeams;
};

#endif // MAPRUNNINGFIGHTDETAILSEXTENDEDMESSAGE_H