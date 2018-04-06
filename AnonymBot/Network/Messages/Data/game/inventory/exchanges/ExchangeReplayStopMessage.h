#ifndef EXCHANGEREPLAYSTOPMESSAGE_H
#define EXCHANGEREPLAYSTOPMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class ExchangeReplayStopMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ExchangeReplayStopMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ExchangeReplayStopMessage(Reader *param1);
  ExchangeReplayStopMessage();
};

#endif // EXCHANGEREPLAYSTOPMESSAGE_H