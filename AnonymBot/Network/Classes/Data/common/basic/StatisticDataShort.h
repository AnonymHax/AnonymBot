#ifndef STATISTICDATASHORT_H
#define STATISTICDATASHORT_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/common/basic/StatisticData.h"
#include "Network/Classes/Data/common/basic/StatisticData.h"

class StatisticDataShort : public StatisticData
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_StatisticDataShort(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_StatisticDataShort(Reader *param1);
  StatisticDataShort();
  bool operator==(const StatisticDataShort &compared);

  int value;
};

#endif // STATISTICDATASHORT_H