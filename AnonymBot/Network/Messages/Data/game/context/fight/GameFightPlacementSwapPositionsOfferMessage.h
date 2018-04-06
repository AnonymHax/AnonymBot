#ifndef GAMEFIGHTPLACEMENTSWAPPOSITIONSOFFERMESSAGE_H
#define GAMEFIGHTPLACEMENTSWAPPOSITIONSOFFERMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class GameFightPlacementSwapPositionsOfferMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameFightPlacementSwapPositionsOfferMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameFightPlacementSwapPositionsOfferMessage(Reader *param1);
  GameFightPlacementSwapPositionsOfferMessage();

  uint requestId;
  double requesterId;
  uint requesterCellId;
  double requestedId;
  uint requestedCellId;
};

#endif // GAMEFIGHTPLACEMENTSWAPPOSITIONSOFFERMESSAGE_H