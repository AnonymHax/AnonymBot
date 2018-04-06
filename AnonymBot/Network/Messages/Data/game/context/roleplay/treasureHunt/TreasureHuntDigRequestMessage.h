#ifndef TREASUREHUNTDIGREQUESTMESSAGE_H
#define TREASUREHUNTDIGREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class TreasureHuntDigRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_TreasureHuntDigRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_TreasureHuntDigRequestMessage(Reader *param1);
  TreasureHuntDigRequestMessage();

  uint questType;
};

#endif // TREASUREHUNTDIGREQUESTMESSAGE_H