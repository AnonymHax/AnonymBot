#ifndef TREASUREHUNTFLAGREMOVEREQUESTMESSAGE_H
#define TREASUREHUNTFLAGREMOVEREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class TreasureHuntFlagRemoveRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_TreasureHuntFlagRemoveRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_TreasureHuntFlagRemoveRequestMessage(Reader *param1);
  TreasureHuntFlagRemoveRequestMessage();

  uint questType;
  uint index;
};

#endif // TREASUREHUNTFLAGREMOVEREQUESTMESSAGE_H