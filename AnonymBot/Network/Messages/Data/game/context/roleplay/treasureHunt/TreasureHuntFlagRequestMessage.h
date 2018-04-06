#ifndef TREASUREHUNTFLAGREQUESTMESSAGE_H
#define TREASUREHUNTFLAGREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class TreasureHuntFlagRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_TreasureHuntFlagRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_TreasureHuntFlagRequestMessage(Reader *param1);
  TreasureHuntFlagRequestMessage();

  uint questType;
  uint index;
};

#endif // TREASUREHUNTFLAGREQUESTMESSAGE_H