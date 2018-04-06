#ifndef EXCHANGEONHUMANVENDORREQUESTMESSAGE_H
#define EXCHANGEONHUMANVENDORREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class ExchangeOnHumanVendorRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ExchangeOnHumanVendorRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ExchangeOnHumanVendorRequestMessage(Reader *param1);
  ExchangeOnHumanVendorRequestMessage();

  double humanVendorId;
  uint humanVendorCell;
};

#endif // EXCHANGEONHUMANVENDORREQUESTMESSAGE_H