#ifndef GAMEFIGHTPLACEMENTPOSSIBLEPOSITIONSMESSAGE_H
#define GAMEFIGHTPLACEMENTPOSSIBLEPOSITIONSMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class GameFightPlacementPossiblePositionsMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameFightPlacementPossiblePositionsMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameFightPlacementPossiblePositionsMessage(Reader *param1);
  GameFightPlacementPossiblePositionsMessage();

  QList<uint> positionsForChallengers;
  QList<uint> positionsForDefenders;
  uint teamNumber;
};

#endif // GAMEFIGHTPLACEMENTPOSSIBLEPOSITIONSMESSAGE_H