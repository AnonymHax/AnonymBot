#ifndef TREASUREHUNTDIGREQUESTANSWERMESSAGE_H
#define TREASUREHUNTDIGREQUESTANSWERMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class TreasureHuntDigRequestAnswerMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_TreasureHuntDigRequestAnswerMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_TreasureHuntDigRequestAnswerMessage(Reader *param1);
  TreasureHuntDigRequestAnswerMessage();

  uint questType;
  uint result;
};

#endif // TREASUREHUNTDIGREQUESTANSWERMESSAGE_H