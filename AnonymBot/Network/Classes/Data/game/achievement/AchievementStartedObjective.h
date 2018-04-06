#ifndef ACHIEVEMENTSTARTEDOBJECTIVE_H
#define ACHIEVEMENTSTARTEDOBJECTIVE_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/achievement/AchievementObjective.h"
#include "Network/Classes/Data/game/achievement/AchievementObjective.h"

class AchievementStartedObjective : public AchievementObjective
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_AchievementStartedObjective(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_AchievementStartedObjective(Reader *param1);
  AchievementStartedObjective();
  bool operator==(const AchievementStartedObjective &compared);

  uint value;
};

#endif // ACHIEVEMENTSTARTEDOBJECTIVE_H