#ifndef GAMEROLEPLAYARENASWITCHTOGAMESERVERMESSAGE_H
#define GAMEROLEPLAYARENASWITCHTOGAMESERVERMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class GameRolePlayArenaSwitchToGameServerMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameRolePlayArenaSwitchToGameServerMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameRolePlayArenaSwitchToGameServerMessage(Reader *param1);
  GameRolePlayArenaSwitchToGameServerMessage();

  bool validToken;
  QList<int> ticket;
  int homeServerId;
};

#endif // GAMEROLEPLAYARENASWITCHTOGAMESERVERMESSAGE_H