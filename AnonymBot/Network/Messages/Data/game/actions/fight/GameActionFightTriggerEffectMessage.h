#ifndef GAMEACTIONFIGHTTRIGGEREFFECTMESSAGE_H
#define GAMEACTIONFIGHTTRIGGEREFFECTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/actions/fight/GameActionFightDispellEffectMessage.h"

class GameActionFightTriggerEffectMessage : public GameActionFightDispellEffectMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameActionFightTriggerEffectMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameActionFightTriggerEffectMessage(Reader *param1);
  GameActionFightTriggerEffectMessage();
};

#endif // GAMEACTIONFIGHTTRIGGEREFFECTMESSAGE_H