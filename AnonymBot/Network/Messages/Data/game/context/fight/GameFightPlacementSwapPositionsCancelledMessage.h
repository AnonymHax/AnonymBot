#ifndef GAMEFIGHTPLACEMENTSWAPPOSITIONSCANCELLEDMESSAGE_H
#define GAMEFIGHTPLACEMENTSWAPPOSITIONSCANCELLEDMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class GameFightPlacementSwapPositionsCancelledMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameFightPlacementSwapPositionsCancelledMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameFightPlacementSwapPositionsCancelledMessage(Reader *param1);
  GameFightPlacementSwapPositionsCancelledMessage();

  uint requestId;
  double cancellerId;
};

#endif // GAMEFIGHTPLACEMENTSWAPPOSITIONSCANCELLEDMESSAGE_H