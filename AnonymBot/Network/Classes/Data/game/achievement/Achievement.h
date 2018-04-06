#ifndef ACHIEVEMENT_H
#define ACHIEVEMENT_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/achievement/AchievementObjective.h"
#include "Network/Classes/Data/game/achievement/AchievementStartedObjective.h"

class Achievement : public AbstractClass
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_Achievement(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_Achievement(Reader *param1);
  Achievement();
  bool operator==(const Achievement &compared);

  uint id;
  QList<AchievementObjective> finishedObjective;
  QList<AchievementStartedObjective> startedObjectives;
};

#endif // ACHIEVEMENT_H