#ifndef EXCHANGEBIDSEARCHOKMESSAGE_H
#define EXCHANGEBIDSEARCHOKMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class ExchangeBidSearchOkMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ExchangeBidSearchOkMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ExchangeBidSearchOkMessage(Reader *param1);
  ExchangeBidSearchOkMessage();
};

#endif // EXCHANGEBIDSEARCHOKMESSAGE_H