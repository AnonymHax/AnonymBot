#ifndef HOUSESELLREQUESTMESSAGE_H
#define HOUSESELLREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class HouseSellRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_HouseSellRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_HouseSellRequestMessage(Reader *param1);
  HouseSellRequestMessage();

  uint amount;
  bool forSale;
};

#endif // HOUSESELLREQUESTMESSAGE_H