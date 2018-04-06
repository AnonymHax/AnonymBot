#ifndef EXCHANGEOBJECTTRANSFERTALLTOINVMESSAGE_H
#define EXCHANGEOBJECTTRANSFERTALLTOINVMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class ExchangeObjectTransfertAllToInvMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ExchangeObjectTransfertAllToInvMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ExchangeObjectTransfertAllToInvMessage(Reader *param1);
  ExchangeObjectTransfertAllToInvMessage();
};

#endif // EXCHANGEOBJECTTRANSFERTALLTOINVMESSAGE_H