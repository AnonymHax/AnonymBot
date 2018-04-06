#ifndef ACHIEVEMENTFINISHEDINFORMATIONMESSAGE_H
#define ACHIEVEMENTFINISHEDINFORMATIONMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/achievement/AchievementFinishedMessage.h"

class AchievementFinishedInformationMessage : public AchievementFinishedMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_AchievementFinishedInformationMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_AchievementFinishedInformationMessage(Reader *param1);
  AchievementFinishedInformationMessage();

  QString name;
  double playerId;
};

#endif // ACHIEVEMENTFINISHEDINFORMATIONMESSAGE_H