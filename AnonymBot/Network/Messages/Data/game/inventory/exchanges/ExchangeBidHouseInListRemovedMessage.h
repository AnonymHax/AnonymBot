#ifndef EXCHANGEBIDHOUSEINLISTREMOVEDMESSAGE_H
#define EXCHANGEBIDHOUSEINLISTREMOVEDMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class ExchangeBidHouseInListRemovedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ExchangeBidHouseInListRemovedMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ExchangeBidHouseInListRemovedMessage(Reader *param1);
  ExchangeBidHouseInListRemovedMessage();

  int itemUID;
};

#endif // EXCHANGEBIDHOUSEINLISTREMOVEDMESSAGE_H