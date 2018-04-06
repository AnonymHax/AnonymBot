#ifndef PADDOCKSELLREQUESTMESSAGE_H
#define PADDOCKSELLREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class PaddockSellRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_PaddockSellRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_PaddockSellRequestMessage(Reader *param1);
  PaddockSellRequestMessage();

  uint price;
  bool forSale;
};

#endif // PADDOCKSELLREQUESTMESSAGE_H