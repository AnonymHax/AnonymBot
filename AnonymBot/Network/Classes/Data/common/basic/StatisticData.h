#ifndef STATISTICDATA_H
#define STATISTICDATA_H

#include "Network/Classes/AbstractClass.h"

class StatisticData : public AbstractClass
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_StatisticData(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_StatisticData(Reader *param1);
  StatisticData();
  bool operator==(const StatisticData &compared);
};

#endif // STATISTICDATA_H