#ifndef GAMEROLEPLAYARENASWITCHTOFIGHTSERVERMESSAGE_H
#define GAMEROLEPLAYARENASWITCHTOFIGHTSERVERMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class GameRolePlayArenaSwitchToFightServerMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameRolePlayArenaSwitchToFightServerMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameRolePlayArenaSwitchToFightServerMessage(Reader *param1);
  GameRolePlayArenaSwitchToFightServerMessage();

  QString address;
  uint port;
  QList<int> ticket;
};

#endif // GAMEROLEPLAYARENASWITCHTOFIGHTSERVERMESSAGE_H