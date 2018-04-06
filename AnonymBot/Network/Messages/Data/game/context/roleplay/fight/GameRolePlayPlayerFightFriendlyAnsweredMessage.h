#ifndef GAMEROLEPLAYPLAYERFIGHTFRIENDLYANSWEREDMESSAGE_H
#define GAMEROLEPLAYPLAYERFIGHTFRIENDLYANSWEREDMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class GameRolePlayPlayerFightFriendlyAnsweredMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameRolePlayPlayerFightFriendlyAnsweredMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameRolePlayPlayerFightFriendlyAnsweredMessage(Reader *param1);
  GameRolePlayPlayerFightFriendlyAnsweredMessage();

  int fightId;
  double sourceId;
  double targetId;
  bool accept;
};

#endif // GAMEROLEPLAYPLAYERFIGHTFRIENDLYANSWEREDMESSAGE_H