#ifndef ACHIEVEMENTREWARDREQUESTMESSAGE_H
#define ACHIEVEMENTREWARDREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class AchievementRewardRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_AchievementRewardRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_AchievementRewardRequestMessage(Reader *param1);
  AchievementRewardRequestMessage();

  int achievementId;
};

#endif // ACHIEVEMENTREWARDREQUESTMESSAGE_H