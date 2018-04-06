#ifndef ACHIEVEMENTREWARDABLE_H
#define ACHIEVEMENTREWARDABLE_H

#include "Network/Classes/AbstractClass.h"

class AchievementRewardable : public AbstractClass
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_AchievementRewardable(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_AchievementRewardable(Reader *param1);
  AchievementRewardable();
  bool operator==(const AchievementRewardable &compared);

  uint id;
  uint finishedlevel;
};

#endif // ACHIEVEMENTREWARDABLE_H