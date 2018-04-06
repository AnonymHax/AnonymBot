#ifndef GAMEACTIONFIGHTINVISIBLEDETECTEDMESSAGE_H
#define GAMEACTIONFIGHTINVISIBLEDETECTEDMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/actions/AbstractGameActionMessage.h"

class GameActionFightInvisibleDetectedMessage : public AbstractGameActionMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameActionFightInvisibleDetectedMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameActionFightInvisibleDetectedMessage(Reader *param1);
  GameActionFightInvisibleDetectedMessage();

  double targetId;
  int cellId;
};

#endif // GAMEACTIONFIGHTINVISIBLEDETECTEDMESSAGE_H