#ifndef GAMEACTIONFIGHTMODIFYEFFECTSDURATIONMESSAGE_H
#define GAMEACTIONFIGHTMODIFYEFFECTSDURATIONMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/actions/AbstractGameActionMessage.h"

class GameActionFightModifyEffectsDurationMessage : public AbstractGameActionMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameActionFightModifyEffectsDurationMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameActionFightModifyEffectsDurationMessage(Reader *param1);
  GameActionFightModifyEffectsDurationMessage();

  double targetId;
  int delta;
};

#endif // GAMEACTIONFIGHTMODIFYEFFECTSDURATIONMESSAGE_H