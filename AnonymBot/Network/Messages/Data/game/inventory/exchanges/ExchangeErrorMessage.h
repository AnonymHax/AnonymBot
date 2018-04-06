#ifndef EXCHANGEERRORMESSAGE_H
#define EXCHANGEERRORMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class ExchangeErrorMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ExchangeErrorMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ExchangeErrorMessage(Reader *param1);
  ExchangeErrorMessage();

  int errorType;
};

#endif // EXCHANGEERRORMESSAGE_H