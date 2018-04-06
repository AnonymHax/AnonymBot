#ifndef GAMEROLEPLAYDELAYEDACTIONFINISHEDMESSAGE_H
#define GAMEROLEPLAYDELAYEDACTIONFINISHEDMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class GameRolePlayDelayedActionFinishedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameRolePlayDelayedActionFinishedMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameRolePlayDelayedActionFinishedMessage(Reader *param1);
  GameRolePlayDelayedActionFinishedMessage();

  double delayedCharacterId;
  uint delayTypeId;
};

#endif // GAMEROLEPLAYDELAYEDACTIONFINISHEDMESSAGE_H