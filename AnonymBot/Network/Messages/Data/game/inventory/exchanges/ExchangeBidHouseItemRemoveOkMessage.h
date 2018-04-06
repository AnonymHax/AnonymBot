#ifndef EXCHANGEBIDHOUSEITEMREMOVEOKMESSAGE_H
#define EXCHANGEBIDHOUSEITEMREMOVEOKMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class ExchangeBidHouseItemRemoveOkMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ExchangeBidHouseItemRemoveOkMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ExchangeBidHouseItemRemoveOkMessage(Reader *param1);
  ExchangeBidHouseItemRemoveOkMessage();

  int sellerId;
};

#endif // EXCHANGEBIDHOUSEITEMREMOVEOKMESSAGE_H