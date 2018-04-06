#ifndef GAMEACTIONFIGHTDISPELLMESSAGE_H
#define GAMEACTIONFIGHTDISPELLMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/actions/AbstractGameActionMessage.h"

class GameActionFightDispellMessage : public AbstractGameActionMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameActionFightDispellMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameActionFightDispellMessage(Reader *param1);
  GameActionFightDispellMessage();

  double targetId;
};

#endif // GAMEACTIONFIGHTDISPELLMESSAGE_H