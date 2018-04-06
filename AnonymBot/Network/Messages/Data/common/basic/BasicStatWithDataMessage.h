#ifndef BASICSTATWITHDATAMESSAGE_H
#define BASICSTATWITHDATAMESSAGE_H

#include "Network/Classes/Data/common/basic/StatisticData.h"
#include "Network/Classes/ClassManager.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/common/basic/BasicStatMessage.h"
#include "Network/Classes/Data/common/basic/StatisticData.h"
#include "Network/Classes/ClassManager.h"

class BasicStatWithDataMessage : public BasicStatMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_BasicStatWithDataMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_BasicStatWithDataMessage(Reader *param1);
  BasicStatWithDataMessage();

  QList<QSharedPointer<StatisticData>> datas;
};

#endif // BASICSTATWITHDATAMESSAGE_H