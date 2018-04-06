#ifndef STATISTICDATABYTE_H
#define STATISTICDATABYTE_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/common/basic/StatisticData.h"
#include "Network/Classes/Data/common/basic/StatisticData.h"

class StatisticDataByte : public StatisticData
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_StatisticDataByte(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_StatisticDataByte(Reader *param1);
  StatisticDataByte();
  bool operator==(const StatisticDataByte &compared);

  int value;
};

#endif // STATISTICDATABYTE_H