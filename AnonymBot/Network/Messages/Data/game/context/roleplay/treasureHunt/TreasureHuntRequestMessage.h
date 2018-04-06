#ifndef TREASUREHUNTREQUESTMESSAGE_H
#define TREASUREHUNTREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class TreasureHuntRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_TreasureHuntRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_TreasureHuntRequestMessage(Reader *param1);
  TreasureHuntRequestMessage();

  uint questLevel;
  uint questType;
};

#endif // TREASUREHUNTREQUESTMESSAGE_H