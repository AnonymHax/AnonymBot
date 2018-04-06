#ifndef GAMEFIGHTPLACEMENTSWAPPOSITIONSACCEPTMESSAGE_H
#define GAMEFIGHTPLACEMENTSWAPPOSITIONSACCEPTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class GameFightPlacementSwapPositionsAcceptMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameFightPlacementSwapPositionsAcceptMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameFightPlacementSwapPositionsAcceptMessage(Reader *param1);
  GameFightPlacementSwapPositionsAcceptMessage();

  uint requestId;
};

#endif // GAMEFIGHTPLACEMENTSWAPPOSITIONSACCEPTMESSAGE_H