#ifndef EXCHANGESHOWVENDORTAXMESSAGE_H
#define EXCHANGESHOWVENDORTAXMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class ExchangeShowVendorTaxMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ExchangeShowVendorTaxMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ExchangeShowVendorTaxMessage(Reader *param1);
  ExchangeShowVendorTaxMessage();
};

#endif // EXCHANGESHOWVENDORTAXMESSAGE_H