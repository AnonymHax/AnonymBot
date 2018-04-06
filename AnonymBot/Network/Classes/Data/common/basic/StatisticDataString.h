#ifndef STATISTICDATASTRING_H
#define STATISTICDATASTRING_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/common/basic/StatisticData.h"
#include "Network/Classes/Data/common/basic/StatisticData.h"

class StatisticDataString : public StatisticData
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_StatisticDataString(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_StatisticDataString(Reader *param1);
  StatisticDataString();
  bool operator==(const StatisticDataString &compared);

  QString value;
};

#endif // STATISTICDATASTRING_H