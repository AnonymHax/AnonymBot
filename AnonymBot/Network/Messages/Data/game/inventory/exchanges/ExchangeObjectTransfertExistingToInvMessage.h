#ifndef EXCHANGEOBJECTTRANSFERTEXISTINGTOINVMESSAGE_H
#define EXCHANGEOBJECTTRANSFERTEXISTINGTOINVMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class ExchangeObjectTransfertExistingToInvMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ExchangeObjectTransfertExistingToInvMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ExchangeObjectTransfertExistingToInvMessage(Reader *param1);
  ExchangeObjectTransfertExistingToInvMessage();
};

#endif // EXCHANGEOBJECTTRANSFERTEXISTINGTOINVMESSAGE_H