#ifndef GAMEACTIONFIGHTACTIVATEGLYPHTRAPMESSAGE_H
#define GAMEACTIONFIGHTACTIVATEGLYPHTRAPMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/actions/AbstractGameActionMessage.h"

class GameActionFightActivateGlyphTrapMessage : public AbstractGameActionMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameActionFightActivateGlyphTrapMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameActionFightActivateGlyphTrapMessage(Reader *param1);
  GameActionFightActivateGlyphTrapMessage();

  int markId;
  bool active;
};

#endif // GAMEACTIONFIGHTACTIVATEGLYPHTRAPMESSAGE_H