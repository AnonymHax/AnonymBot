#ifndef EXCHANGEOBJECTTRANSFERTLISTTOINVMESSAGE_H
#define EXCHANGEOBJECTTRANSFERTLISTTOINVMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class ExchangeObjectTransfertListToInvMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ExchangeObjectTransfertListToInvMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ExchangeObjectTransfertListToInvMessage(Reader *param1);
  ExchangeObjectTransfertListToInvMessage();

  QList<uint> ids;
};

#endif // EXCHANGEOBJECTTRANSFERTLISTTOINVMESSAGE_H