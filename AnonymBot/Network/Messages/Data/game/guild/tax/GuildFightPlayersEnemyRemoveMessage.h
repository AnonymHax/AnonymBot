#ifndef GUILDFIGHTPLAYERSENEMYREMOVEMESSAGE_H
#define GUILDFIGHTPLAYERSENEMYREMOVEMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class GuildFightPlayersEnemyRemoveMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GuildFightPlayersEnemyRemoveMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GuildFightPlayersEnemyRemoveMessage(Reader *param1);
  GuildFightPlayersEnemyRemoveMessage();

  uint fightId;
  double playerId;
};

#endif // GUILDFIGHTPLAYERSENEMYREMOVEMESSAGE_H