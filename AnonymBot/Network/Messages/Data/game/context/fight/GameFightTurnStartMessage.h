#ifndef GAMEFIGHTTURNSTARTMESSAGE_H
#define GAMEFIGHTTURNSTARTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class GameFightTurnStartMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameFightTurnStartMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameFightTurnStartMessage(Reader *param1);
  GameFightTurnStartMessage();

  double id;
  uint waitTime;
};

#endif // GAMEFIGHTTURNSTARTMESSAGE_H