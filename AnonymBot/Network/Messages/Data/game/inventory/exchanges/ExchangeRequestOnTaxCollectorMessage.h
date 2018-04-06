#ifndef EXCHANGEREQUESTONTAXCOLLECTORMESSAGE_H
#define EXCHANGEREQUESTONTAXCOLLECTORMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class ExchangeRequestOnTaxCollectorMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ExchangeRequestOnTaxCollectorMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ExchangeRequestOnTaxCollectorMessage(Reader *param1);
  ExchangeRequestOnTaxCollectorMessage();

  int taxCollectorId;
};

#endif // EXCHANGEREQUESTONTAXCOLLECTORMESSAGE_H