#ifndef EXCHANGEOBJECTTRANSFERTLISTFROMINVMESSAGE_H
#define EXCHANGEOBJECTTRANSFERTLISTFROMINVMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class ExchangeObjectTransfertListFromInvMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ExchangeObjectTransfertListFromInvMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ExchangeObjectTransfertListFromInvMessage(Reader *param1);
  ExchangeObjectTransfertListFromInvMessage();

  QList<uint> ids;
};

#endif // EXCHANGEOBJECTTRANSFERTLISTFROMINVMESSAGE_H