#ifndef TREASUREHUNTGIVEUPREQUESTMESSAGE_H
#define TREASUREHUNTGIVEUPREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class TreasureHuntGiveUpRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_TreasureHuntGiveUpRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_TreasureHuntGiveUpRequestMessage(Reader *param1);
  TreasureHuntGiveUpRequestMessage();

  uint questType;
};

#endif // TREASUREHUNTGIVEUPREQUESTMESSAGE_H