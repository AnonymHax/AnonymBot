#ifndef GAMEACTIONFIGHTTRIGGERGLYPHTRAPMESSAGE_H
#define GAMEACTIONFIGHTTRIGGERGLYPHTRAPMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/actions/AbstractGameActionMessage.h"

class GameActionFightTriggerGlyphTrapMessage : public AbstractGameActionMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameActionFightTriggerGlyphTrapMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameActionFightTriggerGlyphTrapMessage(Reader *param1);
  GameActionFightTriggerGlyphTrapMessage();

  int markId;
  double triggeringCharacterId;
  uint triggeredSpellId;
};

#endif // GAMEACTIONFIGHTTRIGGERGLYPHTRAPMESSAGE_H