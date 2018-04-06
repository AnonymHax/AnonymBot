#ifndef GAMEFIGHTTURNRESUMEMESSAGE_H
#define GAMEFIGHTTURNRESUMEMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/context/fight/GameFightTurnStartMessage.h"

class GameFightTurnResumeMessage : public GameFightTurnStartMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameFightTurnResumeMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameFightTurnResumeMessage(Reader *param1);
  GameFightTurnResumeMessage();

  uint remainingTime;
};

#endif // GAMEFIGHTTURNRESUMEMESSAGE_H