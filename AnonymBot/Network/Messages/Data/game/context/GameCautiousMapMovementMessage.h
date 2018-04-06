#ifndef GAMECAUTIOUSMAPMOVEMENTMESSAGE_H
#define GAMECAUTIOUSMAPMOVEMENTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/context/GameMapMovementMessage.h"

class GameCautiousMapMovementMessage : public GameMapMovementMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameCautiousMapMovementMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameCautiousMapMovementMessage(Reader *param1);
  GameCautiousMapMovementMessage();
};

#endif // GAMECAUTIOUSMAPMOVEMENTMESSAGE_H