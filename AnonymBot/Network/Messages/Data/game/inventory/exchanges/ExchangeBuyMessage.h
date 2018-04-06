#ifndef EXCHANGEBUYMESSAGE_H
#define EXCHANGEBUYMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class ExchangeBuyMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ExchangeBuyMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ExchangeBuyMessage(Reader *param1);
  ExchangeBuyMessage();

  uint objectToBuyId;
  uint quantity;
};

#endif // EXCHANGEBUYMESSAGE_H