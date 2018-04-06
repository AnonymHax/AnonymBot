#ifndef EXCHANGEREPLYTAXVENDORMESSAGE_H
#define EXCHANGEREPLYTAXVENDORMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class ExchangeReplyTaxVendorMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ExchangeReplyTaxVendorMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ExchangeReplyTaxVendorMessage(Reader *param1);
  ExchangeReplyTaxVendorMessage();

  uint objectValue;
  uint totalTaxValue;
};

#endif // EXCHANGEREPLYTAXVENDORMESSAGE_H