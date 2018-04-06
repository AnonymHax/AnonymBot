#ifndef EXCHANGEOBJECTTRANSFERTEXISTINGFROMINVMESSAGE_H
#define EXCHANGEOBJECTTRANSFERTEXISTINGFROMINVMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class ExchangeObjectTransfertExistingFromInvMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ExchangeObjectTransfertExistingFromInvMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ExchangeObjectTransfertExistingFromInvMessage(Reader *param1);
  ExchangeObjectTransfertExistingFromInvMessage();
};

#endif // EXCHANGEOBJECTTRANSFERTEXISTINGFROMINVMESSAGE_H