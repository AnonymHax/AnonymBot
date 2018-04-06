#ifndef STATISTICDATABOOLEAN_H
#define STATISTICDATABOOLEAN_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/common/basic/StatisticData.h"
#include "Network/Classes/Data/common/basic/StatisticData.h"

class StatisticDataBoolean : public StatisticData
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_StatisticDataBoolean(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_StatisticDataBoolean(Reader *param1);
  StatisticDataBoolean();
  bool operator==(const StatisticDataBoolean &compared);

  bool value;
};

#endif // STATISTICDATABOOLEAN_H