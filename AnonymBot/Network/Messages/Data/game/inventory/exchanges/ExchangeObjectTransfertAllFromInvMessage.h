#ifndef EXCHANGEOBJECTTRANSFERTALLFROMINVMESSAGE_H
#define EXCHANGEOBJECTTRANSFERTALLFROMINVMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class ExchangeObjectTransfertAllFromInvMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ExchangeObjectTransfertAllFromInvMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ExchangeObjectTransfertAllFromInvMessage(Reader *param1);
  ExchangeObjectTransfertAllFromInvMessage();
};

#endif // EXCHANGEOBJECTTRANSFERTALLFROMINVMESSAGE_H