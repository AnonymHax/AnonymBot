#ifndef EXCHANGEHANDLEMOUNTSSTABLEMESSAGE_H
#define EXCHANGEHANDLEMOUNTSSTABLEMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class ExchangeHandleMountsStableMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ExchangeHandleMountsStableMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ExchangeHandleMountsStableMessage(Reader *param1);
  ExchangeHandleMountsStableMessage();

  int actionType;
  QList<uint> ridesId;
};

#endif // EXCHANGEHANDLEMOUNTSSTABLEMESSAGE_H