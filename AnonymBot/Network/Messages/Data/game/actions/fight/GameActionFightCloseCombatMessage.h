#ifndef GAMEACTIONFIGHTCLOSECOMBATMESSAGE_H
#define GAMEACTIONFIGHTCLOSECOMBATMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/actions/fight/AbstractGameActionFightTargetedAbilityMessage.h"

class GameActionFightCloseCombatMessage : public AbstractGameActionFightTargetedAbilityMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameActionFightCloseCombatMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameActionFightCloseCombatMessage(Reader *param1);
  GameActionFightCloseCombatMessage();

  uint weaponGenericId;
};

#endif // GAMEACTIONFIGHTCLOSECOMBATMESSAGE_H