#ifndef EXCHANGESTOPPEDMESSAGE_H
#define EXCHANGESTOPPEDMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class ExchangeStoppedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ExchangeStoppedMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ExchangeStoppedMessage(Reader *param1);
  ExchangeStoppedMessage();

  double id;
};

#endif // EXCHANGESTOPPEDMESSAGE_H