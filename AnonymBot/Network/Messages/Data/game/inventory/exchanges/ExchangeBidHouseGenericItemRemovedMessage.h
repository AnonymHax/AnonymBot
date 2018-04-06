#ifndef EXCHANGEBIDHOUSEGENERICITEMREMOVEDMESSAGE_H
#define EXCHANGEBIDHOUSEGENERICITEMREMOVEDMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class ExchangeBidHouseGenericItemRemovedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ExchangeBidHouseGenericItemRemovedMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ExchangeBidHouseGenericItemRemovedMessage(Reader *param1);
  ExchangeBidHouseGenericItemRemovedMessage();

  uint objGenericId;
};

#endif // EXCHANGEBIDHOUSEGENERICITEMREMOVEDMESSAGE_H