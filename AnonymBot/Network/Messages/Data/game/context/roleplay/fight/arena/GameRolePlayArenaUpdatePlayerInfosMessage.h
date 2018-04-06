#ifndef GAMEROLEPLAYARENAUPDATEPLAYERINFOSMESSAGE_H
#define GAMEROLEPLAYARENAUPDATEPLAYERINFOSMESSAGE_H

#include "Network/Classes/Data/game/context/roleplay/fight/arena/ArenaRankInfos.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/context/roleplay/fight/arena/ArenaRankInfos.h"

class GameRolePlayArenaUpdatePlayerInfosMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameRolePlayArenaUpdatePlayerInfosMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameRolePlayArenaUpdatePlayerInfosMessage(Reader *param1);
  GameRolePlayArenaUpdatePlayerInfosMessage();

  ArenaRankInfos solo;
};

#endif // GAMEROLEPLAYARENAUPDATEPLAYERINFOSMESSAGE_H