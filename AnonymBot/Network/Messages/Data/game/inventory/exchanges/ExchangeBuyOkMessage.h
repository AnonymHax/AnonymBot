#ifndef EXCHANGEBUYOKMESSAGE_H
#define EXCHANGEBUYOKMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class ExchangeBuyOkMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ExchangeBuyOkMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ExchangeBuyOkMessage(Reader *param1);
  ExchangeBuyOkMessage();
};

#endif // EXCHANGEBUYOKMESSAGE_H