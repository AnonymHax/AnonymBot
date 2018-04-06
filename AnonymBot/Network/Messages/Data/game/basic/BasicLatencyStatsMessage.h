#ifndef BASICLATENCYSTATSMESSAGE_H
#define BASICLATENCYSTATSMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class BasicLatencyStatsMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_BasicLatencyStatsMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_BasicLatencyStatsMessage(Reader *param1);
  BasicLatencyStatsMessage();

  uint latency;
  uint sampleCount;
  uint max;
};

#endif // BASICLATENCYSTATSMESSAGE_H