#ifndef GAMEFIGHTTURNENDMESSAGE_H
#define GAMEFIGHTTURNENDMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class GameFightTurnEndMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameFightTurnEndMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameFightTurnEndMessage(Reader *param1);
  GameFightTurnEndMessage();

  double id;
};

#endif // GAMEFIGHTTURNENDMESSAGE_H