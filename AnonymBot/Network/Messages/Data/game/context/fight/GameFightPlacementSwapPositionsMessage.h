#ifndef GAMEFIGHTPLACEMENTSWAPPOSITIONSMESSAGE_H
#define GAMEFIGHTPLACEMENTSWAPPOSITIONSMESSAGE_H

#include "Network/Classes/Data/game/context/IdentifiedEntityDispositionInformations.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/context/IdentifiedEntityDispositionInformations.h"

class GameFightPlacementSwapPositionsMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameFightPlacementSwapPositionsMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameFightPlacementSwapPositionsMessage(Reader *param1);
  GameFightPlacementSwapPositionsMessage();

  QList<QSharedPointer<IdentifiedEntityDispositionInformations>> dispositions;
};

#endif // GAMEFIGHTPLACEMENTSWAPPOSITIONSMESSAGE_H