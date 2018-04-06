#ifndef GAMEROLEPLAYDELAYEDOBJECTUSEMESSAGE_H
#define GAMEROLEPLAYDELAYEDOBJECTUSEMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/context/roleplay/delay/GameRolePlayDelayedActionMessage.h"

class GameRolePlayDelayedObjectUseMessage : public GameRolePlayDelayedActionMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameRolePlayDelayedObjectUseMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameRolePlayDelayedObjectUseMessage(Reader *param1);
  GameRolePlayDelayedObjectUseMessage();

  uint objectGID;
};

#endif // GAMEROLEPLAYDELAYEDOBJECTUSEMESSAGE_H