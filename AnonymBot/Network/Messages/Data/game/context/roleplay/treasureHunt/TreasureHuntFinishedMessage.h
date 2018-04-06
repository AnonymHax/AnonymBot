#ifndef TREASUREHUNTFINISHEDMESSAGE_H
#define TREASUREHUNTFINISHEDMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class TreasureHuntFinishedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_TreasureHuntFinishedMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_TreasureHuntFinishedMessage(Reader *param1);
  TreasureHuntFinishedMessage();

  uint questType;
};

#endif // TREASUREHUNTFINISHEDMESSAGE_H