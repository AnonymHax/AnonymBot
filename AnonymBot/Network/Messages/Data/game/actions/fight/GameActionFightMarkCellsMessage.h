#ifndef GAMEACTIONFIGHTMARKCELLSMESSAGE_H
#define GAMEACTIONFIGHTMARKCELLSMESSAGE_H

#include "Network/Classes/Data/game/actions/fight/GameActionMark.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/actions/AbstractGameActionMessage.h"
#include "Network/Classes/Data/game/actions/fight/GameActionMark.h"

class GameActionFightMarkCellsMessage : public AbstractGameActionMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameActionFightMarkCellsMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameActionFightMarkCellsMessage(Reader *param1);
  GameActionFightMarkCellsMessage();

  GameActionMark mark;
};

#endif // GAMEACTIONFIGHTMARKCELLSMESSAGE_H