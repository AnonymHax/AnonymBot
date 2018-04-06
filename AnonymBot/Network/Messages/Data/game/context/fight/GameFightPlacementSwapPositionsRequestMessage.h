#ifndef GAMEFIGHTPLACEMENTSWAPPOSITIONSREQUESTMESSAGE_H
#define GAMEFIGHTPLACEMENTSWAPPOSITIONSREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/context/fight/GameFightPlacementPositionRequestMessage.h"

class GameFightPlacementSwapPositionsRequestMessage : public GameFightPlacementPositionRequestMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameFightPlacementSwapPositionsRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameFightPlacementSwapPositionsRequestMessage(Reader *param1);
  GameFightPlacementSwapPositionsRequestMessage();

  double requestedId;
};

#endif // GAMEFIGHTPLACEMENTSWAPPOSITIONSREQUESTMESSAGE_H