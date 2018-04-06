#ifndef HOUSESOLDMESSAGE_H
#define HOUSESOLDMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class HouseSoldMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_HouseSoldMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_HouseSoldMessage(Reader *param1);
  HouseSoldMessage();

  uint houseId;
  uint realPrice;
  QString buyerName;
};

#endif // HOUSESOLDMESSAGE_H