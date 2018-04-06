#ifndef TREASUREHUNTREQUESTANSWERMESSAGE_H
#define TREASUREHUNTREQUESTANSWERMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class TreasureHuntRequestAnswerMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_TreasureHuntRequestAnswerMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_TreasureHuntRequestAnswerMessage(Reader *param1);
  TreasureHuntRequestAnswerMessage();

  uint questType;
  uint result;
};

#endif // TREASUREHUNTREQUESTANSWERMESSAGE_H