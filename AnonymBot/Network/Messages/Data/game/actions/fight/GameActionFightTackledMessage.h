#ifndef GAMEACTIONFIGHTTACKLEDMESSAGE_H
#define GAMEACTIONFIGHTTACKLEDMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/actions/AbstractGameActionMessage.h"

class GameActionFightTackledMessage : public AbstractGameActionMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameActionFightTackledMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameActionFightTackledMessage(Reader *param1);
  GameActionFightTackledMessage();

  QList<double> tacklersIds;
};

#endif // GAMEACTIONFIGHTTACKLEDMESSAGE_H