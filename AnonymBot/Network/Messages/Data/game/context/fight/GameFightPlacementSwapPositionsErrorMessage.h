#ifndef GAMEFIGHTPLACEMENTSWAPPOSITIONSERRORMESSAGE_H
#define GAMEFIGHTPLACEMENTSWAPPOSITIONSERRORMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class GameFightPlacementSwapPositionsErrorMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameFightPlacementSwapPositionsErrorMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameFightPlacementSwapPositionsErrorMessage(Reader *param1);
  GameFightPlacementSwapPositionsErrorMessage();
};

#endif // GAMEFIGHTPLACEMENTSWAPPOSITIONSERRORMESSAGE_H