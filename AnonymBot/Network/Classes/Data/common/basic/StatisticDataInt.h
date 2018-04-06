#ifndef STATISTICDATAINT_H
#define STATISTICDATAINT_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/common/basic/StatisticData.h"
#include "Network/Classes/Data/common/basic/StatisticData.h"

class StatisticDataInt : public StatisticData
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_StatisticDataInt(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_StatisticDataInt(Reader *param1);
  StatisticDataInt();
  bool operator==(const StatisticDataInt &compared);

  int value;
};

#endif // STATISTICDATAINT_H