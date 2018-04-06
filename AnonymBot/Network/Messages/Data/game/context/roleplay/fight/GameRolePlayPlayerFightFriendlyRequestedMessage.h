#ifndef GAMEROLEPLAYPLAYERFIGHTFRIENDLYREQUESTEDMESSAGE_H
#define GAMEROLEPLAYPLAYERFIGHTFRIENDLYREQUESTEDMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class GameRolePlayPlayerFightFriendlyRequestedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameRolePlayPlayerFightFriendlyRequestedMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameRolePlayPlayerFightFriendlyRequestedMessage(Reader *param1);
  GameRolePlayPlayerFightFriendlyRequestedMessage();

  uint fightId;
  double sourceId;
  double targetId;
};

#endif // GAMEROLEPLAYPLAYERFIGHTFRIENDLYREQUESTEDMESSAGE_H