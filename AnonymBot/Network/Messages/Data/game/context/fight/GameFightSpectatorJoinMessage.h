#ifndef GAMEFIGHTSPECTATORJOINMESSAGE_H
#define GAMEFIGHTSPECTATORJOINMESSAGE_H

#include "Network/Classes/Data/game/context/roleplay/party/NamedPartyTeam.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/context/fight/GameFightJoinMessage.h"
#include "Network/Classes/Data/game/context/roleplay/party/NamedPartyTeam.h"

class GameFightSpectatorJoinMessage : public GameFightJoinMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameFightSpectatorJoinMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameFightSpectatorJoinMessage(Reader *param1);
  GameFightSpectatorJoinMessage();

  QList<NamedPartyTeam> namedPartyTeams;
};

#endif // GAMEFIGHTSPECTATORJOINMESSAGE_H