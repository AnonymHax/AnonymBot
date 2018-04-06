#ifndef TREASUREHUNTDIGREQUESTANSWERFAILEDMESSAGE_H
#define TREASUREHUNTDIGREQUESTANSWERFAILEDMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/context/roleplay/treasureHunt/TreasureHuntDigRequestAnswerMessage.h"

class TreasureHuntDigRequestAnswerFailedMessage : public TreasureHuntDigRequestAnswerMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_TreasureHuntDigRequestAnswerFailedMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_TreasureHuntDigRequestAnswerFailedMessage(Reader *param1);
  TreasureHuntDigRequestAnswerFailedMessage();

  uint wrongFlagCount;
};

#endif // TREASUREHUNTDIGREQUESTANSWERFAILEDMESSAGE_H