#ifndef PADDOCKBUYRESULTMESSAGE_H
#define PADDOCKBUYRESULTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class PaddockBuyResultMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_PaddockBuyResultMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_PaddockBuyResultMessage(Reader *param1);
  PaddockBuyResultMessage();

  int paddockId;
  bool bought;
  uint realPrice;
};

#endif // PADDOCKBUYRESULTMESSAGE_H