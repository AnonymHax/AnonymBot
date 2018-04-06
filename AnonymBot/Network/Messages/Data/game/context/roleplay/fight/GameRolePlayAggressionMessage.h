#ifndef GAMEROLEPLAYAGGRESSIONMESSAGE_H
#define GAMEROLEPLAYAGGRESSIONMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class GameRolePlayAggressionMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameRolePlayAggressionMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameRolePlayAggressionMessage(Reader *param1);
  GameRolePlayAggressionMessage();

  double attackerId;
  double defenderId;
};

#endif // GAMEROLEPLAYAGGRESSIONMESSAGE_H