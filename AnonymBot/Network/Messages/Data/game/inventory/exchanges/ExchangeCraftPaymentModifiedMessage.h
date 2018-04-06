#ifndef EXCHANGECRAFTPAYMENTMODIFIEDMESSAGE_H
#define EXCHANGECRAFTPAYMENTMODIFIEDMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class ExchangeCraftPaymentModifiedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ExchangeCraftPaymentModifiedMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ExchangeCraftPaymentModifiedMessage(Reader *param1);
  ExchangeCraftPaymentModifiedMessage();

  uint goldSum;
};

#endif // EXCHANGECRAFTPAYMENTMODIFIEDMESSAGE_H