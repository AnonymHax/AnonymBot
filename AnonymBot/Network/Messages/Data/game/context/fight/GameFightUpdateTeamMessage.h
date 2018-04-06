#ifndef GAMEFIGHTUPDATETEAMMESSAGE_H
#define GAMEFIGHTUPDATETEAMMESSAGE_H

#include "Network/Classes/Data/game/context/fight/FightTeamInformations.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/context/fight/FightTeamInformations.h"

class GameFightUpdateTeamMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameFightUpdateTeamMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameFightUpdateTeamMessage(Reader *param1);
  GameFightUpdateTeamMessage();

  uint fightId;
  QSharedPointer<FightTeamInformations> team;
};

#endif // GAMEFIGHTUPDATETEAMMESSAGE_H