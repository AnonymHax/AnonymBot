#ifndef TREASUREHUNTFLAGREQUESTANSWERMESSAGE_H
#define TREASUREHUNTFLAGREQUESTANSWERMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class TreasureHuntFlagRequestAnswerMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_TreasureHuntFlagRequestAnswerMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_TreasureHuntFlagRequestAnswerMessage(Reader *param1);
  TreasureHuntFlagRequestAnswerMessage();

  uint questType;
  uint result;
  uint index;
};

#endif // TREASUREHUNTFLAGREQUESTANSWERMESSAGE_H