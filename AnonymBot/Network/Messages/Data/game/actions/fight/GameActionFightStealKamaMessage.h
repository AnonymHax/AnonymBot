#ifndef GAMEACTIONFIGHTSTEALKAMAMESSAGE_H
#define GAMEACTIONFIGHTSTEALKAMAMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/actions/AbstractGameActionMessage.h"

class GameActionFightStealKamaMessage : public AbstractGameActionMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameActionFightStealKamaMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameActionFightStealKamaMessage(Reader *param1);
  GameActionFightStealKamaMessage();

  double targetId;
  uint amount;
};

#endif // GAMEACTIONFIGHTSTEALKAMAMESSAGE_H