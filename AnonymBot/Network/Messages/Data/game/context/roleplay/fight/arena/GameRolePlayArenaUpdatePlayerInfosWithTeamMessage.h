#ifndef GAMEROLEPLAYARENAUPDATEPLAYERINFOSWITHTEAMMESSAGE_H
#define GAMEROLEPLAYARENAUPDATEPLAYERINFOSWITHTEAMMESSAGE_H

#include "Network/Classes/Data/game/context/roleplay/fight/arena/ArenaRankInfos.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/context/roleplay/fight/arena/GameRolePlayArenaUpdatePlayerInfosMessage.h"
#include "Network/Classes/Data/game/context/roleplay/fight/arena/ArenaRankInfos.h"

class GameRolePlayArenaUpdatePlayerInfosWithTeamMessage : public GameRolePlayArenaUpdatePlayerInfosMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameRolePlayArenaUpdatePlayerInfosWithTeamMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameRolePlayArenaUpdatePlayerInfosWithTeamMessage(Reader *param1);
  GameRolePlayArenaUpdatePlayerInfosWithTeamMessage();

  ArenaRankInfos team;
};

#endif // GAMEROLEPLAYARENAUPDATEPLAYERINFOSWITHTEAMMESSAGE_H