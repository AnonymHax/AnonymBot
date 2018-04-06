#ifndef EXCHANGEISREADYMESSAGE_H
#define EXCHANGEISREADYMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class ExchangeIsReadyMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ExchangeIsReadyMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ExchangeIsReadyMessage(Reader *param1);
  ExchangeIsReadyMessage();

  double id;
  bool ready;
};

#endif // EXCHANGEISREADYMESSAGE_H