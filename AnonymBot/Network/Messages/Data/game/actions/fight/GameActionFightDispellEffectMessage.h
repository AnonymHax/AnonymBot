#ifndef GAMEACTIONFIGHTDISPELLEFFECTMESSAGE_H
#define GAMEACTIONFIGHTDISPELLEFFECTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/actions/fight/GameActionFightDispellMessage.h"
#include "Network/Messages/Data/game/actions/fight/GameActionFightDispellMessage.h"

class GameActionFightDispellEffectMessage : public GameActionFightDispellMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameActionFightDispellEffectMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameActionFightDispellEffectMessage(Reader *param1);
  GameActionFightDispellEffectMessage();

  uint boostUID;
};

#endif // GAMEACTIONFIGHTDISPELLEFFECTMESSAGE_H