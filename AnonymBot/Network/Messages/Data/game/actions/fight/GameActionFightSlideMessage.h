#ifndef GAMEACTIONFIGHTSLIDEMESSAGE_H
#define GAMEACTIONFIGHTSLIDEMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/actions/AbstractGameActionMessage.h"

class GameActionFightSlideMessage : public AbstractGameActionMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameActionFightSlideMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameActionFightSlideMessage(Reader *param1);
  GameActionFightSlideMessage();

  double targetId;
  int startCellId;
  int endCellId;
};

#endif // GAMEACTIONFIGHTSLIDEMESSAGE_H