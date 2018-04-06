#ifndef AGGREGATESTATWITHDATAMESSAGE_H
#define AGGREGATESTATWITHDATAMESSAGE_H

#include "Network/Classes/Data/common/basic/StatisticData.h"
#include "Network/Classes/ClassManager.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/common/basic/AggregateStatMessage.h"
#include "Network/Classes/Data/common/basic/StatisticData.h"
#include "Network/Classes/ClassManager.h"

class AggregateStatWithDataMessage : public AggregateStatMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_AggregateStatWithDataMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_AggregateStatWithDataMessage(Reader *param1);
  AggregateStatWithDataMessage();

  QList<QSharedPointer<StatisticData>> datas;
};

#endif // AGGREGATESTATWITHDATAMESSAGE_H