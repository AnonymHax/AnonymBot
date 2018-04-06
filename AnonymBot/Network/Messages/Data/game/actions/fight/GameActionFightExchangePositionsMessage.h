#ifndef GAMEACTIONFIGHTEXCHANGEPOSITIONSMESSAGE_H
#define GAMEACTIONFIGHTEXCHANGEPOSITIONSMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/actions/AbstractGameActionMessage.h"

class GameActionFightExchangePositionsMessage : public AbstractGameActionMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameActionFightExchangePositionsMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameActionFightExchangePositionsMessage(Reader *param1);
  GameActionFightExchangePositionsMessage();

  double targetId;
  int casterCellId;
  int targetCellId;
};

#endif // GAMEACTIONFIGHTEXCHANGEPOSITIONSMESSAGE_H