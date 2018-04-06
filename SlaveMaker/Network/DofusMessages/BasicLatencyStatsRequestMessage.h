#ifndef BASICLATENCYSTATSREQUESTMESSAGE_H
#define BASICLATENCYSTATSREQUESTMESSAGE_H

#include "AbstractDofusMessage.h"

class BasicLatencyStatsRequestMessage : public AbstractDofusMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_BasicLatencyStatsRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_BasicLatencyStatsRequestMessage(Reader *param1);
  BasicLatencyStatsRequestMessage();
};

#endif // BASICLATENCYSTATSREQUESTMESSAGE_H
