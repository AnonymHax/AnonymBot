#ifndef EXCHANGEOBJECTTRANSFERTLISTWITHQUANTITYTOINVMESSAGE_H
#define EXCHANGEOBJECTTRANSFERTLISTWITHQUANTITYTOINVMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class ExchangeObjectTransfertListWithQuantityToInvMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ExchangeObjectTransfertListWithQuantityToInvMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ExchangeObjectTransfertListWithQuantityToInvMessage(Reader *param1);
  ExchangeObjectTransfertListWithQuantityToInvMessage();

  QList<uint> ids;
  QList<uint> qtys;
};

#endif // EXCHANGEOBJECTTRANSFERTLISTWITHQUANTITYTOINVMESSAGE_H