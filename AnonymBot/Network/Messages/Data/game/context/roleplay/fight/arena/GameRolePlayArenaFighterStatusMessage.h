#ifndef GAMEROLEPLAYARENAFIGHTERSTATUSMESSAGE_H
#define GAMEROLEPLAYARENAFIGHTERSTATUSMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class GameRolePlayArenaFighterStatusMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameRolePlayArenaFighterStatusMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameRolePlayArenaFighterStatusMessage(Reader *param1);
  GameRolePlayArenaFighterStatusMessage();

  int fightId;
  int playerId;
  bool accepted;
};

#endif // GAMEROLEPLAYARENAFIGHTERSTATUSMESSAGE_H