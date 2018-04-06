#ifndef AGGREGATESTATMESSAGE_H
#define AGGREGATESTATMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class AggregateStatMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_AggregateStatMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_AggregateStatMessage(Reader *param1);
  AggregateStatMessage();

  uint statId;
};

#endif // AGGREGATESTATMESSAGE_H