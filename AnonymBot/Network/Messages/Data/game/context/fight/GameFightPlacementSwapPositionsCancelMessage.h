#ifndef GAMEFIGHTPLACEMENTSWAPPOSITIONSCANCELMESSAGE_H
#define GAMEFIGHTPLACEMENTSWAPPOSITIONSCANCELMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class GameFightPlacementSwapPositionsCancelMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameFightPlacementSwapPositionsCancelMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameFightPlacementSwapPositionsCancelMessage(Reader *param1);
  GameFightPlacementSwapPositionsCancelMessage();

  uint requestId;
};

#endif // GAMEFIGHTPLACEMENTSWAPPOSITIONSCANCELMESSAGE_H