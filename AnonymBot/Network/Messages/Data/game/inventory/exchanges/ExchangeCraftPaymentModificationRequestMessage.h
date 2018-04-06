#ifndef EXCHANGECRAFTPAYMENTMODIFICATIONREQUESTMESSAGE_H
#define EXCHANGECRAFTPAYMENTMODIFICATIONREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class ExchangeCraftPaymentModificationRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ExchangeCraftPaymentModificationRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ExchangeCraftPaymentModificationRequestMessage(Reader *param1);
  ExchangeCraftPaymentModificationRequestMessage();

  uint quantity;
};

#endif // EXCHANGECRAFTPAYMENTMODIFICATIONREQUESTMESSAGE_H