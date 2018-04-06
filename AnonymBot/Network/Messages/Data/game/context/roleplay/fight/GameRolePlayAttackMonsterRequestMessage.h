#ifndef GAMEROLEPLAYATTACKMONSTERREQUESTMESSAGE_H
#define GAMEROLEPLAYATTACKMONSTERREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class GameRolePlayAttackMonsterRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameRolePlayAttackMonsterRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameRolePlayAttackMonsterRequestMessage(Reader *param1);
  GameRolePlayAttackMonsterRequestMessage();

  double monsterGroupId;
};

#endif // GAMEROLEPLAYATTACKMONSTERREQUESTMESSAGE_H