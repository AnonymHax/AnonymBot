#ifndef HOUSEBUYRESULTMESSAGE_H
#define HOUSEBUYRESULTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class HouseBuyResultMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_HouseBuyResultMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_HouseBuyResultMessage(Reader *param1);
  HouseBuyResultMessage();

  uint houseId;
  bool bought;
  uint realPrice;
};

#endif // HOUSEBUYRESULTMESSAGE_H