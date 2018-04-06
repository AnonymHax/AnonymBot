#ifndef EXCHANGEMOUNTSTABLEERRORMESSAGE_H
#define EXCHANGEMOUNTSTABLEERRORMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class ExchangeMountStableErrorMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ExchangeMountStableErrorMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ExchangeMountStableErrorMessage(Reader *param1);
  ExchangeMountStableErrorMessage();
};

#endif // EXCHANGEMOUNTSTABLEERRORMESSAGE_H