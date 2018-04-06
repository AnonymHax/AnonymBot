#ifndef GAMEROLEPLAYPLAYERFIGHTFRIENDLYANSWERMESSAGE_H
#define GAMEROLEPLAYPLAYERFIGHTFRIENDLYANSWERMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class GameRolePlayPlayerFightFriendlyAnswerMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameRolePlayPlayerFightFriendlyAnswerMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameRolePlayPlayerFightFriendlyAnswerMessage(Reader *param1);
  GameRolePlayPlayerFightFriendlyAnswerMessage();

  int fightId;
  bool accept;
};

#endif // GAMEROLEPLAYPLAYERFIGHTFRIENDLYANSWERMESSAGE_H