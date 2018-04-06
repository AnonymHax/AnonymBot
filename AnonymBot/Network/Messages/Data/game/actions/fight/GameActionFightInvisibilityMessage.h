#ifndef GAMEACTIONFIGHTINVISIBILITYMESSAGE_H
#define GAMEACTIONFIGHTINVISIBILITYMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/actions/AbstractGameActionMessage.h"

class GameActionFightInvisibilityMessage : public AbstractGameActionMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameActionFightInvisibilityMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameActionFightInvisibilityMessage(Reader *param1);
  GameActionFightInvisibilityMessage();

  double targetId;
  uint state;
};

#endif // GAMEACTIONFIGHTINVISIBILITYMESSAGE_H