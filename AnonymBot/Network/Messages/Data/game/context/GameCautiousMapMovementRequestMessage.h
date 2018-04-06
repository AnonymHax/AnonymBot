#ifndef GAMECAUTIOUSMAPMOVEMENTREQUESTMESSAGE_H
#define GAMECAUTIOUSMAPMOVEMENTREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/context/GameMapMovementRequestMessage.h"

class GameCautiousMapMovementRequestMessage : public GameMapMovementRequestMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameCautiousMapMovementRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameCautiousMapMovementRequestMessage(Reader *param1);
  GameCautiousMapMovementRequestMessage();
};

#endif // GAMECAUTIOUSMAPMOVEMENTREQUESTMESSAGE_H