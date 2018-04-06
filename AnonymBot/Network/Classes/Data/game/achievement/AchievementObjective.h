#ifndef ACHIEVEMENTOBJECTIVE_H
#define ACHIEVEMENTOBJECTIVE_H

#include "Network/Classes/AbstractClass.h"

class AchievementObjective : public AbstractClass
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_AchievementObjective(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_AchievementObjective(Reader *param1);
  AchievementObjective();
  bool operator==(const AchievementObjective &compared);

  uint id;
  uint maxValue;
};

#endif // ACHIEVEMENTOBJECTIVE_H