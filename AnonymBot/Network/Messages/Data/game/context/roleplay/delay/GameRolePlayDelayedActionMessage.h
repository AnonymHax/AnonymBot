#ifndef GAMEROLEPLAYDELAYEDACTIONMESSAGE_H
#define GAMEROLEPLAYDELAYEDACTIONMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class GameRolePlayDelayedActionMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameRolePlayDelayedActionMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameRolePlayDelayedActionMessage(Reader *param1);
  GameRolePlayDelayedActionMessage();

  double delayedCharacterId;
  uint delayTypeId;
  double delayEndTime;
};

#endif // GAMEROLEPLAYDELAYEDACTIONMESSAGE_H