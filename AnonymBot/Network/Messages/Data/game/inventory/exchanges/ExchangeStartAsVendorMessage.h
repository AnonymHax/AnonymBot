#ifndef EXCHANGESTARTASVENDORMESSAGE_H
#define EXCHANGESTARTASVENDORMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class ExchangeStartAsVendorMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ExchangeStartAsVendorMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ExchangeStartAsVendorMessage(Reader *param1);
  ExchangeStartAsVendorMessage();
};

#endif // EXCHANGESTARTASVENDORMESSAGE_H