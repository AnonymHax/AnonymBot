#ifndef ACHIEVEMENTFINISHEDMESSAGE_H
#define ACHIEVEMENTFINISHEDMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class AchievementFinishedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_AchievementFinishedMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_AchievementFinishedMessage(Reader *param1);
  AchievementFinishedMessage();

  uint id;
  uint finishedlevel;
};

#endif // ACHIEVEMENTFINISHEDMESSAGE_H