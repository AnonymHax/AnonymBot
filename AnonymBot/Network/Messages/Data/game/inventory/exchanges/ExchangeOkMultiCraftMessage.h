#ifndef EXCHANGEOKMULTICRAFTMESSAGE_H
#define EXCHANGEOKMULTICRAFTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class ExchangeOkMultiCraftMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ExchangeOkMultiCraftMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ExchangeOkMultiCraftMessage(Reader *param1);
  ExchangeOkMultiCraftMessage();

  double initiatorId;
  double otherId;
  int role;
};

#endif // EXCHANGEOKMULTICRAFTMESSAGE_H