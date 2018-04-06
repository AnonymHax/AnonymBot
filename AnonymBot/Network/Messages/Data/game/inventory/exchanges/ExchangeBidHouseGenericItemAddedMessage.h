#ifndef EXCHANGEBIDHOUSEGENERICITEMADDEDMESSAGE_H
#define EXCHANGEBIDHOUSEGENERICITEMADDEDMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class ExchangeBidHouseGenericItemAddedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ExchangeBidHouseGenericItemAddedMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ExchangeBidHouseGenericItemAddedMessage(Reader *param1);
  ExchangeBidHouseGenericItemAddedMessage();

  uint objGenericId;
};

#endif // EXCHANGEBIDHOUSEGENERICITEMADDEDMESSAGE_H