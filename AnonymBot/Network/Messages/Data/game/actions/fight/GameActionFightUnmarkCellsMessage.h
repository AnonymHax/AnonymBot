#ifndef GAMEACTIONFIGHTUNMARKCELLSMESSAGE_H
#define GAMEACTIONFIGHTUNMARKCELLSMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/actions/AbstractGameActionMessage.h"

class GameActionFightUnmarkCellsMessage : public AbstractGameActionMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameActionFightUnmarkCellsMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameActionFightUnmarkCellsMessage(Reader *param1);
  GameActionFightUnmarkCellsMessage();

  int markId;
};

#endif // GAMEACTIONFIGHTUNMARKCELLSMESSAGE_H