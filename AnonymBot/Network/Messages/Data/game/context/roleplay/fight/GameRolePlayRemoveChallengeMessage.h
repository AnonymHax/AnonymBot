#ifndef GAMEROLEPLAYREMOVECHALLENGEMESSAGE_H
#define GAMEROLEPLAYREMOVECHALLENGEMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class GameRolePlayRemoveChallengeMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameRolePlayRemoveChallengeMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameRolePlayRemoveChallengeMessage(Reader *param1);
  GameRolePlayRemoveChallengeMessage();

  int fightId;
};

#endif // GAMEROLEPLAYREMOVECHALLENGEMESSAGE_H